#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class BossHitEffect : public GameEngineActor
{
public:
	// constrcuter destructer
	BossHitEffect();
	~BossHitEffect();

	// delete Function
	BossHitEffect(const BossHitEffect& _Other) = delete;
	BossHitEffect(BossHitEffect&& _Other) noexcept = delete;
	BossHitEffect& operator=(const BossHitEffect& _Other) = delete;
	BossHitEffect& operator=(BossHitEffect&& _Other) noexcept = delete;

	void SetHitEffect(const std::string value, float4 Pos);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* AnimationRender;
};

