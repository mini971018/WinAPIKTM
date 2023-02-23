#include "CharacterSelectZeroModel.h"
#include<GameEngineCore/GameEngineRender.h>
#include<GameEnginePlatform/GameEngineWindow.h>
#include "ContentsEnums.h"

CharacterSelectZeroModel::CharacterSelectZeroModel() 
{
}

CharacterSelectZeroModel::~CharacterSelectZeroModel() 
{
}

void CharacterSelectZeroModel::Start()
{
	AnimationRender = CreateRender(MegamanX4RenderOrder::CHARACTERMODEL);
	AnimationRender->SetScale({ 704, 704 });
	AnimationRender->SetPosition({ 810, 500 });

	AnimationRender->CreateAnimation({ .AnimationName = "Idle", .ImageName = "LeftPlayerIdle.bmp", .Start = 0, .End = 0, .InterTime = 0.25f, .Loop = false });
	AnimationRender->CreateAnimation({ .AnimationName = "Attack",   .ImageName = "LeftPlayerAttack.bmp", .Start = 0, .End = 18, .InterTime = 0.03f,. Loop = false });
	AnimationRender->CreateAnimation({ .AnimationName = "ChangeLevel",   .ImageName = "LeftPlayerStageChange.bmp", .Start = 15, .End = 29, .InterTime = 0.05f,. Loop = false });

	AnimationRender->ChangeAnimation("Idle");
}

void CharacterSelectZeroModel::Update(float _DeltaTime)
{
	if (AnimationRender == nullptr)
	{
		return;
	}

	if (ChangeLevelState == false && AnimationRender->IsAnimationEnd() == true)
	{
		AnimationRender->ChangeAnimation("Idle");
	}
	else if (ChangeLevelState == true && AnimationRender->IsAnimationEnd() == true)
	{
		AnimationRender->SetMove(float4::Up * 1000.0f * _DeltaTime);
	}

}

void CharacterSelectZeroModel::SetModelAnimation(ZeroModelAnimation _Animation)
{
	switch (_Animation)
	{
	case ZeroModelAnimation::ATTACK:
		AnimationRender->ChangeAnimation("Attack");
		break;
	case ZeroModelAnimation::CHANGELEVEL:
		ChangeLevelState = true;
		AnimationRender->ChangeAnimation("ChangeLevel");
		break;
	}
}
