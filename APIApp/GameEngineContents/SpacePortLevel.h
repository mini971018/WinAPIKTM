#pragma once
#include <GameEngineCore/GameEngineLevel.h>
// Ό³Έν :
class SpacePortLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	SpacePortLevel();
	~SpacePortLevel();

	// delete Function
	SpacePortLevel(const SpacePortLevel& _Other) = delete;
	SpacePortLevel(SpacePortLevel&& _Other) noexcept = delete;
	SpacePortLevel& operator=(const SpacePortLevel& _Other) = delete;
	SpacePortLevel& operator=(SpacePortLevel&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {}
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override {}

private:

};

