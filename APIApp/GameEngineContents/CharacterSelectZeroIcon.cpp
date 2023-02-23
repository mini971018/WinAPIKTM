#include "CharacterSelectZeroIcon.h"
#include "ContentsEnums.h"
#include<GameEngineCore/GameEngineRender.h>
#include<GameEnginePlatform/GameEngineWindow.h>

CharacterSelectZeroIcon::CharacterSelectZeroIcon() 
{
}

CharacterSelectZeroIcon::~CharacterSelectZeroIcon() 
{
}

void CharacterSelectZeroIcon::Start()
{
	float4 ScreenSize = GameEngineWindow::GetScreenSize();

	GameEngineRender* Render = CreateRender("ZeroSelectIcon.bmp", MegamanX4RenderOrder::SELECTICON);
	Render->SetScale({ 550, 457 });
	Render->SetPosition({ ScreenSize.x - (537 / 2), ScreenSize.y / 2 });

	Render->CreateAnimation({ .AnimationName = "SelectIconIdle", .ImageName = "ZeroSelectIcon.bmp", .Start = 0, .End = 2, .InterTime = 0.05f });
	Render->ChangeAnimation("SelectIconIdle");
}
