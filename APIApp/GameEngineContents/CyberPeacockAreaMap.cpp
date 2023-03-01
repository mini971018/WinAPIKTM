#include "CyberPeacockAreaMap.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnums.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>

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
			CyberPeacockMapRender = CreateRender(MegamanX4PlayRenderOrder::MAP);
			CyberPeacockMapRender->SetImage("CyberPeacockArea.bmp");
			CyberPeacockMapRender->SetPosition(CyberPeacockMapRender->GetImage()->GetImageScale().half());
			CyberPeacockMapRender->SetScaleToImage();
		}

		{
			CyberPeacockMapStructureRender = CreateRender(MegamanX4PlayRenderOrder::STRUCTURE);
			CyberPeacockMapStructureRender->SetImage("CyberPeacockAreaStructure.bmp");
			CyberPeacockMapStructureRender->SetPosition(CyberPeacockMapStructureRender->GetImage()->GetImageScale().half());
			CyberPeacockMapStructureRender->SetScaleToImage();
		}

		{
			CyberPeacockMapColmapRender = CreateRender(MegamanX4PlayRenderOrder::COLMAP);
			CyberPeacockMapColmapRender->SetImage("CyberPeacockAreaColmap.bmp");
			CyberPeacockMapColmapRender->SetPosition(CyberPeacockMapColmapRender->GetImage()->GetImageScale().half());
			CyberPeacockMapColmapRender->SetScaleToImage();
			CyberPeacockMapColmapRender->Off();
		}
	}

}

void CyberPeacockAreaMap::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("ColMapMode"))
	{
		SwitchRenderMode();
	}
}

void CyberPeacockAreaMap::SwitchRenderMode()
{
	if (CyberPeacockMapColmapRender->IsUpdate() == false)
	{
		CyberPeacockMapRender->Off();
		CyberPeacockMapStructureRender->Off();
		CyberPeacockMapColmapRender->On();
	}
	else
	{
		CyberPeacockMapRender->On();
		CyberPeacockMapStructureRender->On();
		CyberPeacockMapColmapRender->Off();
	}
}