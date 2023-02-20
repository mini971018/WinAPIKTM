#include "SpacePortMap.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include "ContentsEnums.h"

SpacePortMap* SpacePortMap::MainSpacePortMap = nullptr;

SpacePortMap::SpacePortMap() 
{
	MainSpacePortMap = this;
}

SpacePortMap::~SpacePortMap()
{

}

void SpacePortMap::Start()
{
	{
		SpacePortMap1Render = CreateRender(MegamanX4PlayRenderOrder::MAP);
		SpacePortMap1Render->SetImage("SpacePort1.bmp");


		SpacePortMap2Render = CreateRender(MegamanX4PlayRenderOrder::MAP);
		SpacePortMap2Render->SetImage("SpacePort2.bmp");

		//SpacePortMap1Render->SetPosition(SpacePortMap1Render->GetImage()->GetImageScale().half());
		//SpacePortMap1Render->SetScaleToImage();

		int a = -(SpacePortMap1Render->GetImage()->GetImageScale().hx() + GameEngineWindow::GetScreenSize().x);
		int b = SpacePortMap2Render->GetImage()->GetImageScale().y + SpacePortMap1Render->GetImage()->GetImageScale().hy() + GameEngineWindow::GetScreenSize().y;

		SpacePortMap1Render->SetScaleToImage();
		SpacePortMap1Render->SetPosition({ -(SpacePortMap1Render->GetImage()->GetImageScale().hx() - GameEngineWindow::GetScreenSize().x), SpacePortMap2Render->GetImage()->GetImageScale().y + SpacePortMap1Render->GetImage()->GetImageScale().hy()});
		
		SpacePortMap2Render->SetScaleToImage();
		SpacePortMap2Render->SetPosition(SpacePortMap2Render->GetImage()->GetImageScale().half());
	}
}

void SpacePortMap::Update(float _DeltaTime)
{

}