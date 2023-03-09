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
	STAGESTART, //�������� ���� �� �÷��̾ �ٴڿ� ��� �� ������ ����
	STAGESTARTPOSE, //�������� ���� �� �÷��̾ �ٴڿ� ���� �� �ִϸ��̼� ����

	WALLCLIMB,
	WALLKICKJUMP,
	WALLKICKDASHJUMP,

	OPENDOOR1,
	OPENDOOR2,
	IDLEINANIMATION,

	DAMAGED,
	ENDFIGHT,
	ENDANIM1,
	ENDANIM2,
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
class PlayerHPBar;
class CyberPeacockBoss;
class Player : public GameEngineActor
{
public:
	static Player* MainPlayer;
	// ���� ���� ��, ������ ���� �÷��̾ �־� ��.
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

	void SetPowerOverWhelming(bool value)
	{
		PowerOverWhelming = value;
	}

	void SetFightEndState()
	{
		PowerOverWhelming = true;
		ChangeState(PlayerState::ENDFIGHT);
	}

	void SetEndAnimState()
	{
		ChangeState(PlayerState::ENDANIM1);
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
	void DamagedCheck(float _Damage, const std::string_view& _Dir);
	void SetBoss(CyberPeacockBoss* _Boss);

protected: 
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;

private:
	float MoveSpeed = 300.0f; //�Ϲ� �̵� �ӵ�
	float DashSpeed = MoveSpeed * 2.0f; //�뽬�� �̵��ӵ�

	float Gravity = 500.0f;
	float GravityInWallClimb = 250.0f;
	float JumpForce = 900.0f;
	float WallKickJumpForce = 700.0f;
	float WallKickDashJumpForce = WallKickJumpForce * 1.5f;

	float JumpCalTime = 0.0f; //���ʵ��� �����ߴ��� ����� ���� ����
	float MinimumJumpTimeToClimbWall = 0.15f; //���� Ÿ������ �ּ� �����ð�
	float MaxJumpTime = 0.23f; //�ִ� ���� ������ �ð�
	float MoveSpeedInStageChange = 1000.0f; //�������� ����, ����� ���������·� �̵��� ���� �ӷ�
	float DashCalTime = 0.0f; //���ʵ��� �뽬�ߴ��� ����� ���� ����
	float MaxDashTime = 0.7f; //�ִ� �뽬 ������ �ð�

	float ReadyCalTime = 0.0f;

	bool StartFallState = false;

	bool IsGround = false;
	char FirstMoveFrame = 0;
	bool PowerOverWhelming = false;

	bool InAnimationState = false;

	float4 MoveDir = float4::Zero;
	std::string DirString = "Right_";
	std::string CurrentDir = "";
	void DirCheck(const std::string_view& _AnimationName);
	PlayerState CurrentState;
	float4 RaiseUpCharacter(float4 _NextPos, float _DeltaTime);

	bool EndAnim1Sound = false;
	bool EndAnim2Sound = false;
	bool EndAnim3Sound = false;
	bool EndAnimBool = false;

	GameEngineRender* AnimationRender = nullptr;
	PlayerHPBar* PlayerHPBarUI = nullptr;
	//ĳ���� ����Ʈ ����
	WallClimbDustEffect* WallClimbDust;
	WallKickJumpEffect* WallKickEffect;
	DashEffect* PlayerDashEffect;

	CyberPeacockBoss* CyberPeacockBossPointer;
	GameEngineCollision* BodyCollision = nullptr; //���� �޾Ҵ��� ���θ� Ȯ���ϱ� ���� �ݸ���

	//���� ���� ���� ��ܿ��� ���� ��Ҵ��� üũ�ϴ� �ݸ���
	GameEngineCollision* LeftWallCheckCollision = nullptr;
	GameEngineCollision* RightWallCheckCollision = nullptr;
	GameEngineCollision* UpperWallCheckCollision = nullptr;

	GameEngineCollision* PlayerLeftAttackCollision = nullptr;
	GameEngineCollision* PlayerRightAttackCollision = nullptr;

	void CheckAttackCollision();

	bool LeftWallCheck;
	bool RightWallCheck;
	bool UpperWallCheck;

	bool OpenDoorState = false; //���� ���� ������Ʈ �߿��� ī�޶� �Ǵ� �÷��̾��� �̵��� ���´�.
	bool OpenDoorBool1 = false; //���� ��Ҵ��� Ȯ��
	bool OpenDoorBool2 = false;
	bool OpenDoorMoveState = false; // true �� �̵�
	float OpenDoorCalTime = 0.0f; //������Ʈ�� �� ���Ǵ� �ð�
	float OpenDoorCalTime2 = 0.0f; //1�ʵ� �̵��ϴ� ���� ���Ǵ� �ð�
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

	float PlayerHP = 100.0f;
	float DamagedTime = 0.0f;
	std::string_view DamagedDirection;
	
	float DamagedCalTime = 0.0f;

	//FSM ���� ���� �ӽ� : ����Ǵ� �͵��� �Ѱ��� ���� �� ��, ���ÿ� �ٸ� ���� �� �� ����.
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

	void DamagedStart();
	void DamagedUpdate(float _DeltaTime);
	void DamagedEnd();

	void EndFightStart();
	void EndFightUpdate(float _DeltaTime);
	void EndFightEnd();

	void EndAnim1Start();
	void EndAnim1Update(float _DeltaTime);
	void EndAnim1End();

	void EndAnim2Start();
	void EndAnim2Update(float _DeltaTime);
	void EndAnim2End();

	GameEngineImage* ColImage = nullptr;

};

