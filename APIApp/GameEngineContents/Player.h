#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class PlayerState
{
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
	WALLKICKDASHJUMP
};

enum class PlayerCameraLock
{
	CyberPeacockBoss,
};

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

	bool StartFallState = false;

	bool IsGround = false;
	char FirstMoveFrame = 0;

	float4 MoveDir = float4::Zero;
	std::string DirString = "Right_";
	std::string CurrentDir = "";
	void DirCheck(const std::string_view& _AnimationName);
	
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

	PlayerState StateValue = PlayerState::IDLE;

	void MoveCalculation(float _DeltaTime);

	bool FreeMoveState(float _DeltaTime);

	void CheckWall();

	void CameraLock(float4 _MoveDir, float _DeltaTime);
	PlayerCameraLock CameraLockState = PlayerCameraLock::CyberPeacockBoss;

	//FSM 유한 상태 머신 : 적용되는 것들은 한가지 일을 할 때, 동시에 다른 일을 할 수 없다.
	void ChangeState(PlayerState _State);
	void UpdateState(float _Time);

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

	GameEngineImage* ColImage = nullptr;

};

