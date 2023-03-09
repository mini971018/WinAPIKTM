#pragma once
#include <GameEngineCore/GameEngineLevel.h>

class EndLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	EndLevel();
	~EndLevel();

	// delete Function
	EndLevel(const EndLevel& _Other) = delete;
	EndLevel(EndLevel&& _Other) noexcept = delete;
	EndLevel& operator=(const EndLevel& _Other) = delete;
	EndLevel& operator=(EndLevel&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update(float _DeltaTime) override;

private:
	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {}
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;

};

