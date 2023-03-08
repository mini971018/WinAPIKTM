#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineResources.h>

enum class PlayerState
{
	READY,
	IDLE,
	MOVE,
	JUMP,
	FALL,
	LANDING,
	ATTACK1,
	ATTACK2,
	ATTACK3,
	ATTACKEND,
	JUMPATTACK,
	DASH,
	DASHEND,
	DASHJUMP,
	DASHFALL,
	STAGESTART, //스테이지 시작 시 플레이어가 바닥에 닿기 전 레이저 상태
	STAGESTARTPOSE, //스테이지 시작 시 플레이어가 바닥에 닿은 후 애니메이션 상태
	STAGEEND, //스테이지 종료 후 플레이어가 바닥에 떠서 날아가는 레이저 상태
	STAGEENDPOSE, //스테이지 종료 후 플레이어가 바닥에서 하는 애니메이션 상태

	WALLCLIMB,
	WALLKICKJUMP,
	WALLKICKDASHJUMP,

	OPENDOOR1,
	OPENDOOR2,
	IDLEINANIMATION,
};

enum class PlayerCameraLock
{
	CyberPeacockBossRoom,
	CyberPeacockBossRoom2,
	CyberPeacockInBoss,
};

class BossRoomDoor;
class GameEngineImage;
class WallClimbDustEffect;
class WallKickJumpEffect;
class DashEffect;
class Player : public GameEngineActor
{
public:
	static Player* MainPlayer;
	// 레벨 변경 시, 레벨의 메인 플레이어를 넣어 줌.
	static void SetMainPlayer(Player& _Player);

	// constrcuter destructer
	Player();
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

	void SetColImage(const std::string_view& _Name);

	void SetCameraLockState(PlayerCameraLock _CameraState)
	{
		CameraLockState = _CameraState;
	}

	void SetDoor(BossRoomDoor* _Door1, BossRoomDoor* _Door2)
	{
		Door1 = _Door1;
		Door2 = _Door2;
	}

	void SetCyberPeacockAreaBGM();
	void CyberPeacockAreaBGMStop();
	void SetBossBGM();
	void BossBGMStop();
	void SetInAnimationState(bool _Value)
	{
		InAnimationState = _Value;
	}

protected: 
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;

private:
	float MoveSpeed = 300.0f; //일반 이동 속도
	float DashSpeed = MoveSpeed * 2.0f; //대쉬시 이동속도

	float Gravity = 500.0f;
	float GravityInWallClimb = 250.0f;
	float JumpForce = 900.0f;
	float WallKickJumpForce = 700.0f;
	float WallKickDashJumpForce = WallKickJumpForce * 1.5f;

	float JumpCalTime = 0.0f; //몇초동안 점프했는지 계산을 위한 변수
	float MinimumJumpTimeToClimbWall = 0.15f; //벽을 타기위한 최소 점프시간
	float MaxJumpTime = 0.23f; //최대 점프 가능한 시간
	float MoveSpeedInStageChange = 1000.0f; //스테이지 시작, 종료등 레이저상태로 이동할 때의 속력
	float DashCalTime = 0.0f; //몇초동안 대쉬했는지 계산을 위한 변수
	float MaxDashTime = 0.7f; //최대 대쉬 가능한 시간

	float ReadyCalTime = 0.0f;

	bool StartFallState = false;

	bool IsGround = false;
	char FirstMoveFrame = 0;

	bool InAnimationState = false;

	float4 MoveDir = float4::Zero;
	std::string DirString = "Right_";
	std::string CurrentDir = "";
	void DirCheck(const std::string_view& _AnimationName);
	PlayerState CurrentState;
	float4 RaiseUpCharacter(float4 _NextPos, float _DeltaTime);

	GameEngineRender* AnimationRender = nullptr;

	//캐릭터 이펙트 관련
	WallClimbDustEffect* WallClimbDust;
	WallKickJumpEffect* WallKickEffect;
	DashEffect* PlayerDashEffect;

	GameEngineCollision* BodyCollision = nullptr; //공격 받았는지 여부를 확인하기 위한 콜리전

	//각각 좌측 우측 상단에서 벽이 닿았는지 체크하는 콜리전
	GameEngineCollision* LeftWallCheckCollision = nullptr;
	GameEngineCollision* RightWallCheckCollision = nullptr;
	GameEngineCollision* UpperWallCheckCollision = nullptr;

	bool LeftWallCheck;
	bool RightWallCheck;
	bool UpperWallCheck;

	bool OpenDoorState = false; //오픈 도어 스테이트 중에는 카메라 또는 플레이어의 이동을 막는다.
	bool OpenDoorBool1 = false; //문에 닿았는지 확인
	bool OpenDoorBool2 = false;
	bool OpenDoorMoveState = false; // true 면 이동
	float OpenDoorCalTime = 0.0f; //스테이트의 총 사용되는 시간
	float OpenDoorCalTime2 = 0.0f; //1초뒤 이동하는 데에 사용되는 시간
	float Time = 0.0f;

	BossRoomDoor* Door1;
	BossRoomDoor* Door2;

	GameEngineSoundPlayer CyberPeacockAreaBGMPlayer;
	GameEngineSoundPlayer BossBGMPlayer;

	PlayerState StateValue = PlayerState::IDLE;

	void MoveCalculation(float _DeltaTime);

	bool FreeMoveState(float _DeltaTime);

	void CheckWall();

	void CameraLock(float4 _MoveDir, float _DeltaTime);
	PlayerCameraLock CameraLockState = PlayerCameraLock::CyberPeacockBossRoom;

	GameEngineSoundPlayer PlayerDashSound;

	//FSM 유한 상태 머신 : 적용되는 것들은 한가지 일을 할 때, 동시에 다른 일을 할 수 없다.
	void ChangeState(PlayerState _State);
	void UpdateState(float _Time);

	void ReadyStart();
	void ReadyUpdate(float _DeltaTime);
	void ReadyEnd();

	void IdleStart();
	void IdleUpdate(float _DeltaTime);
	void IdleEnd();

	void MoveStart();
	void MoveUpdate(float _DeltaTime);
	void MoveEnd();

	void JumpStart();
	void JumpUpdate(float _DeltaTime);
	void JumpEnd();

	void FallStart();
	void FallUpdate(float _DeltaTime);
	void FallEnd();

	void LandingStart();
	void LandingUpdate(float _DeltaTime);
	void LandingEnd();

	void Attack1Start();
	void Attack1Update(float _DeltaTime);
	void Attack1End();

	void Attack2Start();
	void Attack2Update(float _DeltaTime);
	void Attack2End();

	void Attack3Start();
	void Attack3Update(float _DeltaTime);
	void Attack3End();

	void AttackEndStart();
	void AttackEndUpdate(float _DeltaTime);
	void AttackEndEnd();

	void JumpAttackStart();
	void JumpAttackUpdate(float _DeltaTime);
	void JumpAttackEnd();

	void DashStart();
	void DashUpdate(float _DeltaTime);
	void DashEnd();

	void DashEndStart();
	void DashEndUpdate(float _DeltaTime);
	void DashEndEnd();

	void DashJumpStart();
	void DashJumpUpdate(float _DeltaTime);
	void DashJumpEnd();

	void DashFallStart();
	void DashFallUpdate(float _DeltaTime);
	void DashFallEnd();

	void StageStartStart();
	void StageStartUpdate(float _DeltaTime);
	void StageStartEnd();

	void StageStartPoseStart();
	void StageStartPoseUpdate(float _DeltaTime);
	void StageStartPoseEnd();

	void StageEndStart();
	void StageEndUpdate(float _DeltaTime);
	void StageEndEnd();

	void StageEndPoseStart();
	void StageEndPoseUpdate(float _DeltaTime);
	void StageEndPoseEnd();

	void WallClimbStart();
	void WallClimbUpdate(float _DeltaTime);
	void WallClimbEnd();

	void WallKickJumpStart();
	void WallKickJumpUpdate(float _DeltaTime);
	void WallKickJumpEnd();

	void WallKickDashJumpStart();
	void WallKickDashJumpUpdate(float _DeltaTime);
	void WallKickDashJumpEnd();

	void OpenDoor1Start();
	void OpenDoor1Update(float _DeltaTime);
	void OpenDoor1End();

	void OpenDoor2Start();
	void OpenDoor2Update(float _DeltaTime);
	void OpenDoor2End();

	void IdleInAnimationStart();
	void IdleInAnimationUpdate(float _DeltaTime);
	void IdleInAnimationEnd();

	GameEngineImage* ColImage = nullptr;

};

