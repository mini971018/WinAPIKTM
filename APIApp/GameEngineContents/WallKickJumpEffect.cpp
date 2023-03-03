#include "WallKickJumpEffect.h"
#include "ContentsEnums.h"
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>

WallKickJumpEffect::WallKickJumpEffect() 
{
}

WallKickJumpEffect::~WallKickJumpEffect() 
{
}


void WallKickJumpEffect::Start()
{
	AnimationRender = CreateRender(MegamanX4PlayRenderOrder::PLAYERUPPEREFFECT);
	AnimationRender->SetScale({ 704, 704 });

	//Right
	{
		AnimationRender->CreateAnimation({ .AnimationName = "Right_WallKickJump", .ImageName = "RightPlayerKickJumpEffect.bmp", .Start = 0, .End = 4, .InterTime = 0.03f,  .Loop = false });
	}
	//Left
	{
		AnimationRender->CreateAnimation({ .AnimationName = "Left_WallKickJump", .ImageName = "LeftPlayerKickJumpEffect.bmp", .Start = 0, .End = 4, .InterTime = 0.03f,  .Loop = false });
	}

	AnimationRender->Off();
}

void WallKickJumpEffect::Update(float _DeltaTime)
{

}

void WallKickJumpEffect::OnWallKickJumpEffect(const std::string _DirString)
{
	DirString = _DirString;
	DirCheck("WallKickJump");
	AnimationRender->On();
}

void WallKickJumpEffect::OffWallKickJumpEffect()
{
	AnimationRender->Off();
}

void WallKickJumpEffect::DirCheck(const std::string_view& _AnimationName)
{
	AnimationRender->ChangeAnimation(DirString + _AnimationName.data(), true);
}