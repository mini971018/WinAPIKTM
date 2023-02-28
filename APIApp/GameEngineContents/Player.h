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
	STAGESTART, //�������� ���� �� �÷��̾ �ٴڿ� ��� �� ������ ����
	STAGESTARTPOSE, //�������� ���� �� �÷��̾ �ٴڿ� ���� �� �ִϸ��̼� ����
	STAGEEND, //�������� ���� �� �÷��̾ �ٴڿ� ���� ���ư��� ������ ����
	STAGEENDPOSE, //�������� ���� �� �÷��̾ �ٴڿ��� �ϴ� �ִϸ��̼� ����
};

class GameEngineImage;
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
	float MoveSpeed = 300.0f;
	float Gravity = 500.0f;
	float JumpForce = 900.0f;


	float JumpCalTime = 0.0f; //���ʵ��� �����ߴ��� ����� ���� ����
	float MaxJumpTime = 0.23f; //�ִ� ���� ������ �ð�
	float MoveSpeedInStageChange = 1000.0f; //�������� ����, ����� ���������·� �̵��� ���� �ӷ�

	bool StartFallState = false;

	bool IsGround = false;
	char FirstMoveFrame = 0;

	float4 MoveDir = float4::Zero;
	std::string DirString = "Right_";
	void DirCheck(const std::string_view& _AnimationName);
	

	GameEngineRender* AnimationRender = nullptr;

	PlayerState StateValue = PlayerState::IDLE;

	void MoveCalculation(float _DeltaTime);

	bool FreeMoveState(float _DeltaTime);

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

	GameEngineImage* ColImage = nullptr;

};

