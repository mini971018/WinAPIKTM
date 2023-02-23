#include "CharacterSelectMegamanText.h"
#include<GameEngineCore/GameEngineRender.h>
#include<GameEnginePlatform/GameEngineWindow.h>
#include "ContentsEnums.h"

CharacterSelectMegamanText::CharacterSelectMegamanText() 
{
}

CharacterSelectMegamanText::~CharacterSelectMegamanText() 
{
}

void CharacterSelectMegamanText::Start()
{
	GameEngineRender* Render = CreateRender("MegamanText.bmp", MegamanX4RenderOrder::CHARACTERTEXT);

	Render->SetScaleToImage();
	Render->SetPosition({ 259, 510 });
}	