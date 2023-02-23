#include "CharacterSelectZeroImage.h"
#include<GameEngineCore/GameEngineRender.h>
#include<GameEnginePlatform/GameEngineWindow.h>
#include "ContentsEnums.h"

CharacterSelectZeroImage::CharacterSelectZeroImage() 
{
}

CharacterSelectZeroImage::~CharacterSelectZeroImage() 
{
}

void CharacterSelectZeroImage::Start()
{
	GameEngineRender* Render = CreateRender("ZeroImage.bmp", MegamanX4RenderOrder::CHARACTERIMAGE);
	
	Render->SetScaleToImage();
	float4 ScreenSize = GameEngineWindow::GetScreenSize();
	float4 ImageSize = Render->GetScale();

	Render->SetPosition({ ScreenSize.x - (ImageSize.x / 2), ScreenSize.y / 2});
}
