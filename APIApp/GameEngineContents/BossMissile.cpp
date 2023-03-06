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
	AnimationRender = CreateRender(MegamanX4PlayRenderOrder::PLAYERUPPEREFFECT);
	AnimationRender->SetScale({ 704, 704 });

	AnimationRender->CreateAnimation({ .AnimationName = "MissileAnim",  .ImageName = "BossMissile.bmp", .FilterName = "BossMissileRoll.bmp",.Start = 0, .End = 1, .InterTime = 0.1f });
	AnimationRender->ChangeAnimation("MissileAnim");

	//float4 Angle = Player::MainPlayer->GetPos() - GetPos();
	//float Rad = Angle.GetAnagleRad();

	SetPos({6275, 4974});
	OriginalDirection = float4::Up;
}

void BossMissile::Update(float _DeltaTime)
{
	float4 Angle = Player::MainPlayer->GetPos() - GetPos();
	float Deg =  Angle.NormalizeReturn().GetAnagleDeg();

	AnimationRender->SetAngle(-Deg);
}

void BossMissile::Render(float _DeltaTime)
{
	HDC DoubleDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
	float4 ActorPos = GetPos() - GetLevel()->GetCameraPos();

	if (Player::MainPlayer == nullptr)
	{
		return;
	}

	float4 Angle = Player::MainPlayer->GetPos() - GetPos();
	float Rad = Angle.GetAnagleDeg();

	std::string AngleText = "Angle : ";
	AngleText += std::to_string(Rad);
	GameEngineLevel::DebugTextPush(AngleText);

	Rectangle(DoubleDC,
		ActorPos.ix() - 5,
		ActorPos.iy() - 5,
		ActorPos.ix() + 5,
		ActorPos.iy() + 5
	);

}
