#include "CharacterSelectText.h"
#include<GameEngineCore/GameEngineRender.h>
#include<GameEnginePlatform/GameEngineWindow.h>
#include "ContentsEnums.h"

CharacterSelectText::CharacterSelectText() 
{
}

CharacterSelectText::~CharacterSelectText() 
{
}

void CharacterSelectText::Start()
{
	GameEngineRender* Render = CreateRender("PlayerSelectText.bmp", MegamanX4RenderOrder::BACKGROUND);
	Render->SetScaleToImage();
	Render->SetPosition({440, 330});

}

void CharacterSelectText::Update(float _Deltatime)
{

}