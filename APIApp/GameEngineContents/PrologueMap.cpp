#include "PrologueMap.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include "ContentsEnums.h"


PrologueMap* PrologueMap::MainPrologueMap = nullptr;

PrologueMap::PrologueMap() 
{
	MainPrologueMap = this;
}

PrologueMap::~PrologueMap() 
{
}

void PrologueMap::Start()
{
	{
		{
			PrologueMapRender = CreateRender(MegamanX4PlayRenderOrder::MAP);
			PrologueMapRender->SetImage("Prologue.bmp");
			PrologueMapRender->SetPosition(PrologueMapRender->GetImage()->GetImageScale().half());
			PrologueMapRender->SetScaleToImage();
		}

		{
			PrologueMapStructureRender = CreateRender(MegamanX4PlayRenderOrder::STRUCTURE);
			PrologueMapStructureRender->SetImage("PrologueStructure.bmp");
			PrologueMapStructureRender->SetPosition(PrologueMapStructureRender->GetImage()->GetImageScale().half());
			PrologueMapStructureRender->SetScaleToImage();
		}

		{
			PrologueMapColmapRender = CreateRender(MegamanX4PlayRenderOrder::COLMAP);
			PrologueMapColmapRender->SetImage("PrologueColmap.bmp");
			PrologueMapColmapRender->SetPosition(PrologueMapColmapRender->GetImage()->GetImageScale().half());
			PrologueMapColmapRender->SetScaleToImage();
			PrologueMapColmapRender->Off();
		}
	}
}

void PrologueMap::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("ColMapMode"))
	{
		SwitchRenderMode();
	}
}

void PrologueMap::SwitchRenderMode()
{
	if (PrologueMapColmapRender->IsUpdate() == false)
	{
		PrologueMapRender->Off();
		PrologueMapStructureRender->Off();
		PrologueMapColmapRender->On();
	}
	else
	{
		PrologueMapRender->On();
		PrologueMapStructureRender->On();
		PrologueMapColmapRender->Off();
	}
}