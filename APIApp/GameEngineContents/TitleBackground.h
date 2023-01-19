#pragma once
#include <GameEngineCore/GameEngineActor.h>

class TitleBackground : public GameEngineActor
{
public:
	// constrcuter destructer
	TitleBackground();
	~TitleBackground();

	// delete Function
	TitleBackground(const TitleBackground& _Other) = delete;
	TitleBackground(TitleBackground&& _Other) noexcept = delete;
	TitleBackground& operator=(const TitleBackground& _Other) = delete;
	TitleBackground& operator=(TitleBackground&& _Other) noexcept = delete;

protected:
	void Start() override;

private:

};

