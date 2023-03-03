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
		AnimationRender->CreateAnimation({ .AnimationName = "Right_WallClimbDustEnd", .ImageName = "RightPlayerWallClimbDust.bmp", .Start = 5, .End = 8, .InterTime = 0.045f, .Loop = false });
	}
	//Left
	{
		AnimationRender->CreateAnimation({ .AnimationName = "Left_WallClimbDustStart", .ImageName = "LeftPlayerWallClimbDust.bmp", .Start = 0, .End = 1, .InterTime = 0.045f,  .Loop = false });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_WallClimbDustLoop", .ImageName = "LeftPlayerWallClimbDust.bmp", .Start = 2, .End = 4, .InterTime = 0.045f });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_WallClimbDustEnd", .ImageName = "LeftPlayerWallClimbDust.bmp", .Start = 5, .End = 8, .InterTime = 0.045f, .Loop = false });
	}

	AnimationRender->Off();
}

void WallClimbDustEffect::Update(float _DeltaTime)
{
	if (nullptr == AnimationRender)
	{
		return;
	}

	if (IsOn == true && AnimationRender->IsAnimationEnd())
	{
		DirCheck("WallClimbDustLoop");
	}

}

void WallClimbDustEffect::OnWallClimbDustEffect(const std::string _DirString)
{
	DirString = _DirString;
	DirCheck("WallClimbDustStart");
	AnimationRender->On();
	IsOn = true;
}

void WallClimbDustEffect::OffWallClimbDustEffect()
{
	DirCheck("WallClimbDustEnd");
	IsOn = false;
}

void WallClimbDustEffect::DirCheck(const std::string_view& _AnimationName)
{
	AnimationRender->ChangeAnimation(DirString + _AnimationName.data());
}