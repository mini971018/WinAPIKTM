#include "CharacterSelectMegamanIcon.h"
#include "ContentsEnums.h"
#include<GameEngineCore/GameEngineRender.h>
#include<GameEnginePlatform/GameEngineWindow.h>

CharacterSelectMegamanIcon::CharacterSelectMegamanIcon() 
{
}

CharacterSelectMegamanIcon::~CharacterSelectMegamanIcon() 
{
}

void CharacterSelectMegamanIcon::Start()
{
	float4 ScreenSize = GameEngineWindow::GetScreenSize();

	GameEngineRender* Render = CreateRender("MegamanSelectIcon.bmp", MegamanX4RenderOrder::SELECTICON);
	Render->SetScaleToImage();
	Render->SetPosition({(537 / 2), ScreenSize.y / 2 });
	Off();
}
