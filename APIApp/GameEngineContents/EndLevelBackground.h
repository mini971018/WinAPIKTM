#pragma once
#include <GameEngineCore/GameEngineActor.h>

class EndLevelBackground : public GameEngineActor
{
public:
	// constrcuter destructer
	EndLevelBackground();
	~EndLevelBackground();

	// delete Function
	EndLevelBackground(const EndLevelBackground& _Other) = delete;
	EndLevelBackground(EndLevelBackground&& _Other) noexcept = delete;
	EndLevelBackground& operator=(const EndLevelBackground& _Other) = delete;
	EndLevelBackground& operator=(EndLevelBackground&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override {}

private:

};

