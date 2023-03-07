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

}

void BossMissile::Update(float _DeltaTime)
{
	if (GetLiveTime() >= BoomEffectRemainTime + MissileMaxTime)
	{
		Death();
	}
	else if (GetLiveTime() >= MissileMaxTime)
	{
		AnimationRender->SetAngle(0); //폭발 애니메이션에 회전을 넣지 않음

		AnimationRender->ChangeAnimation("MissileBoomAnim");
	}
	else
	{
		//미사일 날아가는 행동
		float4 PlayerPos = Player::MainPlayer->GetPos();
		PlayerPos = { PlayerPos.x, PlayerPos.y - 50.0f };
		float4 Angle = PlayerPos - GetPos();
		
		AngleTime += _DeltaTime;

		if (AngleTime >= 0.02f)
		{
			Dir = Angle.NormalizeReturn();
			AngleTime = 0.0f;
			float Deg = Angle.NormalizeReturn().GetAnagleDeg();
			AnimationRender->SetAngle(-Deg);
		}

		SetMove(Dir.NormalizeReturn() * 450.0f * _DeltaTime);
	}
}

void BossMissile::BossMissileOn(float4 _Dir)
{
	Dir = _Dir;
	CurrentAngle = Dir.NormalizeReturn().GetAnagleDeg();
	AnimationRender->ChangeAnimation("MissileAnim", true);
	AnimationRender->SetAngle(-CurrentAngle);

	AnimationRender->On();
}

void BossMissile::Render(float _DeltaTime)
{
	HDC DoubleDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
	float4 ActorPos = GetPos() - GetLevel()->GetCameraPos();

	//if (Player::MainPlayer == nullptr)
	//{
	//	return;
	//}

	float4 Angle = Player::MainPlayer->GetPos() - GetPos();
	float Deg = Angle.GetAnagleDeg();


	std::string AngleText = "Angle : ";
	AngleText += std::to_string(Deg);
	GameEngineLevel::DebugTextPush(AngleText);

	Rectangle(DoubleDC,
		ActorPos.ix() - 5,
		ActorPos.iy() - 5,
		ActorPos.ix() + 5,
		ActorPos.iy() + 5
	);

}
