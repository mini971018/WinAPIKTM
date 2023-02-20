#include "CharacterSelectLowerText.h"
#include "ContentsEnums.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>

CharacterSelectLowerText::CharacterSelectLowerText() 
{
}

CharacterSelectLowerText::~CharacterSelectLowerText() 
{
}

void CharacterSelectLowerText::Start()
{
	GameEngineRender* Render = CreateRender("PlayerSelectText.bmp", MegamanX4RenderOrder::SELECTTEXT);

	float4 WindowSize = GameEngineWindow::GetScreenSize();

	Render->SetPosition({ WindowSize.x / 2, (WindowSize.y - 68 - Render->GetScale().y) });
	Render->SetScaleToImage();
}

void CharacterSelectLowerText::Update(float _DeltaTime)
{

}
