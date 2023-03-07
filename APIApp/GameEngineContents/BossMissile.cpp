#include "BossMissile.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "Player.h"
#include "ContentsEnums.h"

BossMissile::BossMissile() 
{
}

BossMissile::~BossMissile() 
{
}

void BossMissile::Start()
{
	AnimationRender = CreateRender(MegamanX4PlayRenderOrder::PLAYERLOWEREFFECT);
	AnimationRender->SetScale({ 704, 704 });

	AnimationRender->CreateAnimation({ .AnimationName = "MissileAnim",  .ImageName = "BossMissile.bmp", .FilterName = "BossMissileRoll.bmp",.Start = 0, .End = 1, .InterTime = 0.1f });
	AnimationRender->CreateAnimation({ .AnimationName = "MissileBoomAnim",  .ImageName = "BossMissileBoom.bmp", .Start = 0, .End = 2, .InterTime = 0.1f });
	AnimationRender->ChangeAnimation("MissileAnim");
	BossMissileOff();
	//float4 Angle = Player::MainPlayer->GetPos() - GetPos();
	//float Rad = Angle.GetAnagleRad();

	SetPos({6275, 4974});
}

void BossMissile::Update(float _DeltaTime)
{
	if (MissileOnOff == true)
	{
		MissileAliveTime += _DeltaTime;
		
		if (MissileAliveTime >= BoomEffectRemainTime + MissileMaxTime)
		{
			BossMissileOff();
		}
		else if (MissileAliveTime >= MissileMaxTime)
		{
			AnimationRender->SetAngle(0);

			AnimationRender->ChangeAnimation("MissileBoomAnim");
		}
		else
		{
			float4 Angle = Player::MainPlayer->GetPos() - GetPos();
			float Deg = Angle.NormalizeReturn().GetAnagleDeg();

			AnimationRender->SetAngle(-Deg);
		}
	}
}

void BossMissile::BossMissileOn()
{
	AnimationRender->ChangeAnimation("MissileAnim");
	MissileAliveTime = 0.0f;
	AnimationRender->On();
	MissileOnOff = true;
}

void BossMissile::BossMissileOff()
{
	AnimationRender->Off();
	MissileOnOff = false;
}

void BossMissile::Render(float _DeltaTime)
{
	//HDC DoubleDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
	//float4 ActorPos = GetPos() - GetLevel()->GetCameraPos();

	//if (Player::MainPlayer == nullptr)
	//{
	//	return;
	//}

	//float4 Angle = Player::MainPlayer->GetPos() - GetPos();
	//float Rad = Angle.GetAnagleDeg();

	//std::string AngleText = "Angle : ";
	//AngleText += std::to_string(Rad);
	//GameEngineLevel::DebugTextPush(AngleText);

	//Rectangle(DoubleDC,
	//	ActorPos.ix() - 5,
	//	ActorPos.iy() - 5,
	//	ActorPos.ix() + 5,
	//	ActorPos.iy() + 5
	//);

}
