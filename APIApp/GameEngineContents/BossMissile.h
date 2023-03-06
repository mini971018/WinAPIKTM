#pragma once
#include <GameEngineCore/GameEngineActor.h>

class BossMissile : public GameEngineActor
{
public:
	// constrcuter destructer
	BossMissile();
	~BossMissile();

	// delete Function
	BossMissile(const BossMissile& _Other) = delete;
	BossMissile(BossMissile&& _Other) noexcept = delete;
	BossMissile& operator=(const BossMissile& _Other) = delete;
	BossMissile& operator=(BossMissile&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;

private:
	float4 OriginalDirection;
	GameEngineRender* AnimationRender = nullptr;
};

	