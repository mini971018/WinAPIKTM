#include "TitleStartObject.h"
#include "ContentsEnums.h"
#include<GameEngineCore/GameEngineRender.h>
#include<GameEnginePlatform/GameEngineWindow.h>

TitleStartObject::TitleStartObject() 
{
}

TitleStartObject::~TitleStartObject() 
{
}

void TitleStartObject::Start()
{
	float4 Size = GameEngineWindow::GetScreenSize();

	GameEngineRender* Render = CreateRender("TitleButtonObject.bmp", MegamanX4RenderOrder::GUIDEOBJECT);
	Render->SetScale({ 420, 36 });
	float4 WindowSize = GameEngineWindow::GetScreenSize().half();
	Render->SetPosition({ WindowSize.x , WindowSize.y + 120});

	Render->CreateAnimation({ .AnimationName = "ButtonIdle", .ImageName = "TitleButtonObject.bmp", .Start = 0, .End = 1, .InterTime = 0.5f });
	Render->ChangeAnimation("ButtonIdle");
}