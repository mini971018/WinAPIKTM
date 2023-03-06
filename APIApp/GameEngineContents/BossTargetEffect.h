#pragma once
#include <GameEngineCore/GameEngineActor.h>

class BossTargetEffect : public GameEngineActor
{
public:
	// constrcuter destructer
	BossTargetEffect();
	~BossTargetEffect();

	// delete Function
	BossTargetEffect(const BossTargetEffect& _Other) = delete;
	BossTargetEffect(BossTargetEffect&& _Other) noexcept = delete;
	BossTargetEffect& operator=(const BossTargetEffect& _Other) = delete;
	BossTargetEffect& operator=(BossTargetEffect&& _Other) noexcept = delete;

	void TargetEffectOn();
	void TargetEffectOff();

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* ImageRender;
	float MoveSpeed = 1000.0f;
	bool OnOffState = false;

};

