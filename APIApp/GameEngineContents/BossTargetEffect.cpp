#include "BossTargetEffect.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEngineMath.h>
#include "ContentsEnums.h"
#include "Player.h"

BossTargetEffect::BossTargetEffect() 
{
}

BossTargetEffect::~BossTargetEffect() 
{
}

void BossTargetEffect::Start()
{
	ImageRender = CreateRender(MegamanX4PlayRenderOrder::PLAYERUPPEREFFECT);
	ImageRender->SetImage("BossTarget.bmp");
	ImageRender->SetScale({ 107.25f, 85.25f });
	ImageRender->Off();
}

void BossTargetEffect::Update(float _DeltaTime)
{
	if (OnOffState == true)
	{
		float4 PlayerPos = Player::MainPlayer->GetPos();
		PlayerPos += float4::Up * 60.0f;

		float4 Dir = PlayerPos - GetPos();

		if (Dir.Size() > 1.0f)
		{
			SetMove(Dir.NormalizeReturn() * MoveSpeed * _DeltaTime);
		}
	}
}

void BossTargetEffect::TargetEffectOn()
{
	OnOffState = true;
	ImageRender->On();
}

void BossTargetEffect::TargetEffectOff()
{
	OnOffState = false;
	ImageRender->Off();
}