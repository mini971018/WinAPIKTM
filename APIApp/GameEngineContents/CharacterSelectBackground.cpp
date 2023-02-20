#include "CharacterSelectBackground.h"
#include "ContentsEnums.h"
#include<GameEngineCore/GameEngineRender.h>
#include<GameEnginePlatform/GameEngineWindow.h>

CharacterSelectBackground::CharacterSelectBackground() 
{
}

CharacterSelectBackground::~CharacterSelectBackground() 
{
}

void CharacterSelectBackground::Start()
{
	GameEngineRender* Render = CreateRender("CharacterSelectBackground.bmp", MegamanX4RenderOrder::BACKGROUND);

	Render->SetPosition(GameEngineWindow::GetScreenSize().half());
	Render->SetScaleToImage();
}