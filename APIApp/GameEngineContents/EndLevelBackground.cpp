#include "EndLevelBackground.h"
#include <GameEngineCore/GameEngineRender.h>

EndLevelBackground::EndLevelBackground() 
{
}

EndLevelBackground::~EndLevelBackground() 
{
}

void EndLevelBackground::Start()
{
	GameEngineRender* EndScreen = CreateRender();
	EndScreen->SetImage("EndScreen.bmp");
	EndScreen->SetPosition({ 440, 330 });
	EndScreen->SetScaleToImage();
}