#include "CharacterSelectMegamanImage.h"
#include<GameEngineCore/GameEngineRender.h>
#include<GameEnginePlatform/GameEngineWindow.h>
#include "ContentsEnums.h"

CharacterSelectMegamanImage::CharacterSelectMegamanImage() 
{
}

CharacterSelectMegamanImage::~CharacterSelectMegamanImage() 
{
}

void CharacterSelectMegamanImage::Start()
{
	GameEngineRender* Render = CreateRender("MegamanImage.bmp", MegamanX4RenderOrder::CHARACTERIMAGE);

	Render->SetScaleToImage();
	float4 ScreenSize = GameEngineWindow::GetScreenSize();
	float4 ImageSize = Render->GetScale();

	Render->SetPosition({(ImageSize.x / 2), ScreenSize.y / 2 });
}
