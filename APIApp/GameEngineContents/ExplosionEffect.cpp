#include "ExplosionEffect.h"

#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnums.h"

ExplosionEffect::ExplosionEffect() 
{
}

ExplosionEffect::~ExplosionEffect() 
{
}


void ExplosionEffect::Start()
{
	AnimationRender = CreateRender(MegamanX4PlayRenderOrder::PLAYERUPPEREFFECT);
	AnimationRender->SetScale({ 704, 704 });

	AnimationRender->CreateAnimation({ .AnimationName = "EffectNull",  .ImageName = "Explosion.bmp", .Start = 34, .End = 34, .InterTime = 0.05f });
	AnimationRender->CreateAnimation({ .AnimationName = "ExplosionEffect",  .ImageName = "Explosion.bmp", .Start = 0, .End = 34, .InterTime = 0.05f });
	AnimationRender->ChangeAnimation("EffectNull");
	
}

void ExplosionEffect::Update(float _DeltaTime)
{
	if (AnimationRender->IsAnimationEnd())
	{
		Death();
	}
}

void ExplosionEffect::ExplosionEffectOn(float4 _Pos)
{
	SetPos(_Pos);
	AnimationRender->ChangeAnimation("ExplosionEffect");
}