#include "CharacterSelectZeroText.h"
#include<GameEngineCore/GameEngineRender.h>
#include<GameEnginePlatform/GameEngineWindow.h>
#include "ContentsEnums.h"

CharacterSelectZeroText::CharacterSelectZeroText() 
{
}

CharacterSelectZeroText::~CharacterSelectZeroText() 
{
}

void CharacterSelectZeroText::Start()
{
	GameEngineRender* Render = CreateRender("ZeroText.bmp", MegamanX4RenderOrder::CHARACTERTEXT);

	Render->SetScaleToImage();
	Render->SetPosition({695, 510});
}