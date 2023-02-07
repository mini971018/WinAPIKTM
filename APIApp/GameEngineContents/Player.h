#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class PlayerState
{
	IDLE,
	MOVE,
};

class GameEngineImage;
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
	float MoveSpeed = 200.0f;
	float Gravity = 10.0f;

	char FirstMoveFrame = 0;

	float4 MoveDir = float4::Zero;
	std::string DirString = "Right_";
	void DirCheck(const std::string_view& _AnimationName);

	GameEngineRender* AnimationRender = nullptr;

	PlayerState StateValue = PlayerState::IDLE;

	void MoveCalculation(float _DeltaTime);

	bool FreeMoveState(float _DeltaTime);

	//FSM 유한 상태 머신 : 적용되는 것들은 한가지 일을 할 때, 동시에 다른 일을 할 수 없다.
	void ChangeState(PlayerState _State);
	void UpdateState(float _Time);

	void IdleStart();
	void IdleUpdate(float _DeltaTime);
	void IdleEnd();

	void MoveStart();
	void MoveUpdate(float _DeltaTime);
	void MoveEnd();

	GameEngineImage* ColImage = nullptr;

};

