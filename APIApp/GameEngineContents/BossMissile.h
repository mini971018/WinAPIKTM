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

	void BossMissileOn(float4 _Dir);
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;

private:
	void CheckCollision();

	GameEngineRender* AnimationRender = nullptr;
	GameEngineCollision* MissileCollision = nullptr;
	GameEngineCollision* BoomCollision = nullptr;

	bool MissileIsBoom = false;
	float MissileMaxTime = 2.0f; //미사일이 살아있는 시간
	float BoomEffectRemainTime = 1.0f; //미사일 붐 이펙트가 남아있는 시간
	float CurrentAngle = 0.0f;
	float AngleTime = 0.0f;
	float4 Dir = float4::Up;
};

	