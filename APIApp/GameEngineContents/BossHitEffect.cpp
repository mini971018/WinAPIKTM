#include "BossHitEffect.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnums.h"

BossHitEffect::BossHitEffect() 
{
}

BossHitEffect::~BossHitEffect() 
{
}

void BossHitEffect::Start()
{
	AnimationRender = CreateRender(MegamanX4PlayRenderOrder::PLAYERUPPEREFFECT);
	AnimationRender->SetScale({ 704, 704 });


	//Right
	{
		AnimationRender->CreateAnimation({ .AnimationName = "Right_Slashed", .ImageName = "RightPlayerKickJumpEffect.bmp", .Start = 0, .End = 4, .InterTime = 0.03f,  .Loop = false });
	}
	//Left
	{
		AnimationRender->CreateAnimation({ .AnimationName = "Left_Slashed", .ImageName = "LeftPlayerKickJumpEffect.bmp", .Start = 0, .End = 4, .InterTime = 0.03f,  .Loop = false });
	}

	AnimationRender->Off();
}

void BossHitEffect::Update(float _DeltaTime)
{
	if (AnimationRender->IsAnimationEnd() == true)
	{
		Death();
	}
}

void BossHitEffect::SetHitEffect(const std::string value, float4 Pos)
{
	std::string Text = value + "Slashed";

	AnimationRender->SetPosition({ Pos.x, Pos.y - 140.0f });
	AnimationRender->ChangeAnimation(Text);
	AnimationRender->On();
}