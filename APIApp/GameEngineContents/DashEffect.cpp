#include "DashEffect.h"
#include "ContentsEnums.h"
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>

DashEffect::DashEffect() 
{
}

DashEffect::~DashEffect() 
{
}

void DashEffect::Start()
{
	AnimationRender = CreateRender(MegamanX4PlayRenderOrder::PLAYERLOWEREFFECT);
	AnimationRender->SetScale({ 704, 704 });

	//Right
	{
		AnimationRender->CreateAnimation({ .AnimationName = "Right_DashEffect", .ImageName = "RightPlayerDashEffect.bmp", .Start = 0, .End = 7, .InterTime = 0.08f,  .Loop = false });
	}
	//Left
	{
		AnimationRender->CreateAnimation({ .AnimationName = "Left_DashEffect", .ImageName = "LeftPlayerDashEffect.bmp", .Start = 0, .End = 7, .InterTime = 0.08f,  .Loop = false });
	}

	AnimationRender->Off();
}

void DashEffect::Update(float _DeltaTime)
{

}

void DashEffect::OnDashEffect(const std::string _DirString)
{
	DirString = _DirString;
	DirCheck("DashEffect");
	AnimationRender->On();
}

void DashEffect::OffDashEffect()
{
	AnimationRender->Off();
}

void DashEffect::DirCheck(const std::string_view& _AnimationName)
{
	AnimationRender->ChangeAnimation(DirString + _AnimationName.data(), true);
}