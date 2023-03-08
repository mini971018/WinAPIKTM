#pragma once
#include <GameEngineCore/GameEngineActor.h>

class ExplosionEffect : public GameEngineActor
{
public:
	// constrcuter destructer
	ExplosionEffect();
	~ExplosionEffect();

	// delete Function
	ExplosionEffect(const ExplosionEffect& _Other) = delete;
	ExplosionEffect(ExplosionEffect&& _Other) noexcept = delete;
	ExplosionEffect& operator=(const ExplosionEffect& _Other) = delete;
	ExplosionEffect& operator=(ExplosionEffect&& _Other) noexcept = delete;

	void ExplosionEffectOn(float4 _Pos);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* AnimationRender = nullptr;

};

