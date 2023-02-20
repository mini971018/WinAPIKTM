#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// Ό³Έν :
class CharacterSelectLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	CharacterSelectLevel();
	~CharacterSelectLevel();

	// delete Function
	CharacterSelectLevel(const CharacterSelectLevel& _Other) = delete;
	CharacterSelectLevel(CharacterSelectLevel&& _Other) noexcept = delete;
	CharacterSelectLevel& operator=(const CharacterSelectLevel& _Other) = delete;
	CharacterSelectLevel& operator=(CharacterSelectLevel&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeStart(GameEngineLevel* _PrevLevel) override {}
	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {}

private:

};

