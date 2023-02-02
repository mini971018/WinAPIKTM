#include "CyberPeacockAreaMap.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnums.h"


CyberPeacockAreaMap* CyberPeacockAreaMap::MainCyberPeacockAreaMap = nullptr;

CyberPeacockAreaMap::CyberPeacockAreaMap()
{
	MainCyberPeacockAreaMap = this;
}

CyberPeacockAreaMap::~CyberPeacockAreaMap()
{
}

void CyberPeacockAreaMap::Start()
{
	{
		{
			CyberPeacockMapRender = CreateRender(MegamanX4RenderOrder::MAP);
			CyberPeacockMapRender->SetImage("CyberPeacockArea.bmp");
			CyberPeacockMapRender->SetPosition(CyberPeacockMapRender->GetImage()->GetImageScale().half());
			CyberPeacockMapRender->SetScaleToImage();
		}
	}
}

void CyberPeacockAreaMap::Update(float _DeltaTime)
{

}