#pragma once
#include <GameEngineCore/GameEngineActor.h>


class PlayerHPBar : public GameEngineActor
{
public:
	// constrcuter destructer
	PlayerHPBar();
	~PlayerHPBar();

	// delete Function
	PlayerHPBar(const PlayerHPBar& _Other) = delete;
	PlayerHPBar(PlayerHPBar&& _Other) noexcept = delete;
	PlayerHPBar& operator=(const PlayerHPBar& _Other) = delete;
	PlayerHPBar& operator=(PlayerHPBar&& _Other) noexcept = delete;

	void GetDamaged();

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* HPBarUI;
	GameEngineRender* HPBar;
};

