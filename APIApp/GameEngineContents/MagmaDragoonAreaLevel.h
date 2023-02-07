#pragma once
#include <GameEngineCore/GameEngineLevel.h>

class Player;
class MagmaDragoonAreaLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	MagmaDragoonAreaLevel();
	~MagmaDragoonAreaLevel();

	// delete Function
	MagmaDragoonAreaLevel(const MagmaDragoonAreaLevel& _Other) = delete;
	MagmaDragoonAreaLevel(MagmaDragoonAreaLevel&& _Other) noexcept = delete;
	MagmaDragoonAreaLevel& operator=(const MagmaDragoonAreaLevel& _Other) = delete;
	MagmaDragoonAreaLevel& operator=(MagmaDragoonAreaLevel&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {}
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;

private:
	Player* MagmaDragoonAreaLevelPlayer = nullptr;

};

