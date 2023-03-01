#include "TestLevelMap.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include "ContentsEnums.h"

TestLevelMap* TestLevelMap::MainTestLevelMap = nullptr;

TestLevelMap::TestLevelMap() 
{
	MainTestLevelMap = this;
}

TestLevelMap::~TestLevelMap() 
{
}


void TestLevelMap::Start()
{
	{
		{
			TestMapRender = CreateRender(MegamanX4PlayRenderOrder::MAP);
			TestMapRender->SetImage("TestColMap.bmp");
			TestMapRender->SetPosition(TestMapRender->GetImage()->GetImageScale().half());
			TestMapRender->SetScaleToImage();
		}
	}
}
