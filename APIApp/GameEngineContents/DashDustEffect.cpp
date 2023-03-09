#include "DashDustEffect.h"

#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnums.h"

DashDustEffect::DashDustEffect() 
{
}

DashDustEffect::~DashDustEffect() 
{
}

void DashDustEffect::Start()
{
	AnimationRender = CreateRender(MegamanX4PlayRenderOrder::PLAYERUPPEREFFECT);
	AnimationRender->SetScale({ 704, 704 });

	//Right
	{
		AnimationRender->CreateAnimation({ .AnimationName = "Right_DashEffect", .ImageName = "RightPlayerDashDust.bmp", .Start = 0, .End = 8, .InterTime = 0.05f,  .Loop = false });
	}
	//Left
	{
		AnimationRender->CreateAnimation({ .AnimationName = "Left_DashEffect", .ImageName = "LeftPlayerDashDust.bmp", .Start = 0, .End = 8, .InterTime = 0.05f,  .Loop = false });
	}
	AnimationRender->CreateAnimation({ .AnimationName = "None", .ImageName = "LeftPlayerDashDust.bmp", .Start = 8, .End = 8, .InterTime = 0.08f,  .Loop = false });
	AnimationRender->ChangeAnimation("None");
}

void DashDustEffect::Update(float _DeltaTime)
{
	if (AnimationRender->IsAnimationEnd())
	{
		Death();
	}
}

void DashDustEffect::SetDashDust(const std::string value, float4 Pos)
{
	std::string Text = value + "DashEffect";

	AnimationRender->SetPosition({Pos});
	AnimationRender->ChangeAnimation(Text);
}