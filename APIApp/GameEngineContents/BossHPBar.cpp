#include "BossHPBar.h"
#include "ContentsEnums.h"
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>

BossHPBar::BossHPBar() 
{
}

BossHPBar::~BossHPBar() 
{
}

void BossHPBar::Start()
{
	HPBar = CreateRender(MegamanX4PlayRenderOrder::UI);
	HPBar->SetImage("HPUI.bmp");
	HPBar->SetScale({ 704, 704 });
	HPBar->SetPosition({ 6542, 4879 });

	HPBarUI = CreateRender(MegamanX4PlayRenderOrder::UI);
	HPBarUI->SetImage("BossHPBar.bmp");
	HPBarUI->SetScale({ 71.5, 148.5 });
	HPBarUI->SetPosition({ 6544, 4858 });

	HPBar->Off();
	HPBarUI->Off();
}

void BossHPBar::GetDamaged()
{
	float4 Scale = HPBar->GetScale();
	HPBar->SetScale({ Scale.x, Scale.y - 35.2f });
}

void BossHPBar::StartFight()
{
	HPBar->On();
	HPBarUI->On();
}

void BossHPBar::Update(float _DeltaTime)
{

}