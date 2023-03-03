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
	STAGESTART, //�������� ���� �� �÷��̾ �ٴڿ� ��� �� ������ ����
	STAGESTARTPOSE, //�������� ���� �� �÷��̾ �ٴڿ� ���� �� �ִϸ��̼� ����
	STAGEEND, //�������� ���� �� �÷��̾ �ٴڿ� ���� ���ư��� ������ ����
	STAGEENDPOSE, //�������� ���� �� �÷��̾ �ٴڿ��� �ϴ� �ִϸ��̼� ����

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

	bool StartFallState = false;

	bool IsGround = false;
	char FirstMoveFrame = 0;

	float4 MoveDir = float4::Zero;
	std::string DirString = "Right_";
	std::string CurrentDir = "";
	void DirCheck(const std::string_view& _AnimationName);
	
	float4 RaiseUpCharacter(float4 _NextPos, float _DeltaTime);

	GameEngineRender* AnimationRender = nullptr;

	//ĳ���� ����Ʈ ����
	WallClimbDustEffect* WallClimbDust;
	WallKickJumpEffect* WallKickEffect;
	DashEffect* PlayerDashEffect;

	GameEngineCollision* BodyCollision = nullptr; //���� �޾Ҵ��� ���θ� Ȯ���ϱ� ���� �ݸ���

	//���� ���� ���� ��ܿ��� ���� ��Ҵ��� üũ�ϴ� �ݸ���
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

	//FSM ���� ���� �ӽ� : ����Ǵ� �͵��� �Ѱ��� ���� �� ��, ���ÿ� �ٸ� ���� �� �� ����.
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

