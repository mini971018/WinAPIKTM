#include "PrologueMap.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>

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

	}
}

void PrologueMap::Update(float _DeltaTime)
{

}