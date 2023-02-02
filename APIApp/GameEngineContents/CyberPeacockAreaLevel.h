#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// Ό³Έν :
class CyberPeacockAreaLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	CyberPeacockAreaLevel();
	~CyberPeacockAreaLevel();

	// delete Function
	CyberPeacockAreaLevel(const CyberPeacockAreaLevel& _Other) = delete;
	CyberPeacockAreaLevel(CyberPeacockAreaLevel&& _Other) noexcept = delete;
	CyberPeacockAreaLevel& operator=(const CyberPeacockAreaLevel& _Other) = delete;
	CyberPeacockAreaLevel& operator=(CyberPeacockAreaLevel&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {}
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override {}

private:
	int TestInt = 0;
};

