#include "PlayerHPBar.h"
#include "ContentsEnums.h"
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>

PlayerHPBar::PlayerHPBar() 
{
}

PlayerHPBar::~PlayerHPBar() 
{
}

void PlayerHPBar::Start()
{
	HPBar = CreateRender(MegamanX4PlayRenderOrder::UI);
	HPBar->SetImage("HPUI.bmp");
	HPBar->SetScale({ 704, 704 });
	HPBar->SetPosition({ 5847, 4880 });

	HPBarUI = CreateRender(MegamanX4PlayRenderOrder::UI);
	HPBarUI->SetImage("PlayerHPBar.bmp");
	HPBarUI->SetScale({ 96.25, 148.5 });
	HPBarUI->SetPosition({ 5864, 4859 });

}

void PlayerHPBar::GetDamaged()
{
	float4 Scale = HPBar->GetScale();
	HPBar->SetScale({ Scale.x, Scale.y - 70.4f });
}

void PlayerHPBar::Update(float _DeltaTime)
{

}

