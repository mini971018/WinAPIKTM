#include "WallClimbDustEffect.h"
#include "ContentsEnums.h"
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>

WallClimbDustEffect::WallClimbDustEffect() 
{

}

WallClimbDustEffect::~WallClimbDustEffect() 
{

}

void WallClimbDustEffect::Start()
{
	AnimationRender = CreateRender(MegamanX4PlayRenderOrder::PLAYERUPPEREFFECT);
	AnimationRender->SetScale({ 704, 704 });

	//Right
	{
		AnimationRender->CreateAnimation({ .AnimationName = "Right_WallClimbDustStart", .ImageName = "RightPlayerWallClimbDust.bmp", .Start = 0, .End = 1, .InterTime = 0.045f, .Loop = false });
		AnimationRender->CreateAnimation({ .AnimationName = "Right_WallClimbDustLoop", .ImageName = "RightPlayerWallClimbDust.bmp", .Start = 2, .End = 4, .InterTime = 0.045f });
		AnimationRender->CreateAnimation({ .AnimationName = "Right_WallClimbDustEnd", .ImageName = "RightPlayerWallClimbDust.bmp", .Start = 5, .End = 7, .InterTime = 0.045f, .Loop = false });
	}
	//Left
	{
		AnimationRender->CreateAnimation({ .AnimationName = "Left_WallClimbDustStart", .ImageName = "LeftPlayerWallClimbDust.bmp", .Start = 0, .End = 1, .InterTime = 0.045f,  .Loop = false });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_WallClimbDustLoop", .ImageName = "LeftPlayerWallClimbDust.bmp", .Start = 2, .End = 4, .InterTime = 0.045f });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_WallClimbDustEnd", .ImageName = "LeftPlayerWallClimbDust.bmp", .Start = 5, .End = 7, .InterTime = 0.045f, .Loop = false });
	}

	AnimationRender->Off();
}

void WallClimbDustEffect::Update(float _DeltaTime)
{
	if (IsOn == true && AnimationRender->IsAnimationEnd())
	{
		AnimationRender->ChangeAnimation("Left_WallClimbDustLoop");
	}

	if (IsOn == false && AnimationRender->IsAnimationEnd())
	{
		AnimationRender->ChangeAnimation("Left_WallClimbDustEnd");
	}
}

void WallClimbDustEffect::OnWallClimbDustEffect()
{
	AnimationRender->ChangeAnimation("Left_WallClimbDustStart");
	AnimationRender->On();
	IsOn = true;
}

void WallClimbDustEffect::OffWallClimbDustEffect()
{
	AnimationRender->ChangeAnimation("Left_WallClimbDustEnd");
	IsOn = false;
}