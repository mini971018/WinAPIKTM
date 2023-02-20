#include "CharacterSelectUpperText.h"
#include "ContentsEnums.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>

CharacterSelectUpperText::CharacterSelectUpperText() 
{
}

CharacterSelectUpperText::~CharacterSelectUpperText() 
{
}

void CharacterSelectUpperText::Start()
{
	GameEngineRender* Render = CreateRender("PlayerSelectText.bmp", MegamanX4RenderOrder::SELECTTEXT);

	Render->SetPosition({GameEngineWindow::GetScreenSize().hx(), 68});
	Render->SetScaleToImage();
}

void CharacterSelectUpperText::Update(float _DeltaTime)
{

}