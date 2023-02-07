#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// Ό³Έν :
class Player;
class GameEngineImage;
class PrologueLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	PrologueLevel();
	~PrologueLevel();

	// delete Function
	PrologueLevel(const PrologueLevel& _Other) = delete;
	PrologueLevel(PrologueLevel&& _Other) noexcept = delete;
	PrologueLevel& operator=(const PrologueLevel& _Other) = delete;
	PrologueLevel& operator=(PrologueLevel&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {}
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;


private:
	Player* PrologueLevelPlayer = nullptr;
};

