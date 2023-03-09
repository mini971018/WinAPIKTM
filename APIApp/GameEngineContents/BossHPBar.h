#pragma once
#include <GameEngineCore/GameEngineActor.h>

class BossHPBar : public GameEngineActor
{
public:
	// constrcuter destructer
	BossHPBar();
	~BossHPBar();

	// delete Function
	BossHPBar(const BossHPBar& _Other) = delete;
	BossHPBar(BossHPBar&& _Other) noexcept = delete;
	BossHPBar& operator=(const BossHPBar& _Other) = delete;
	BossHPBar& operator=(BossHPBar&& _Other) noexcept = delete;

	void GetDamaged();
	void StartFight();

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* HPBarUI;
	GameEngineRender* HPBar;
};

