#include "TitleBackground.h"
#include "ContentsEnums.h"
#include<GameEngineCore/GameEngineRender.h>
#include<GameEnginePlatform/GameEngineWindow.h>

TitleBackground::TitleBackground() 
{
}

TitleBackground::~TitleBackground() 
{
}

void TitleBackground::Start()
{
	float4 Size = GameEngineWindow::GetScreenSize();

	GameEngineRender* Render = CreateRender("TitleBackground.bmp", MegamanX4RenderOrder::BACKGROUND);
	Render->SetPosition(GameEngineWindow::GetScreenSize().half());
	Render->SetScale(GameEngineWindow::GetScreenSize());
}
