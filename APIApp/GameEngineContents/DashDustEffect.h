#pragma once
#include <GameEngineCore/GameEngineActor.h>

class DashDustEffect : public GameEngineActor
{
public:
	// constrcuter destructer
	DashDustEffect();
	~DashDustEffect();

	// delete Function
	DashDustEffect(const DashDustEffect& _Other) = delete;
	DashDustEffect(DashDustEffect&& _Other) noexcept = delete;
	DashDustEffect& operator=(const DashDustEffect& _Other) = delete;
	DashDustEffect& operator=(DashDustEffect&& _Other) noexcept = delete;

	void SetDashDust(const std::string value, float4 Pos);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* AnimationRender = nullptr;
};

