#include "PrologueMap.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>


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
			PrologueMapRender = CreateRender(MegamanX4RenderOrder::MAP);
			PrologueMapRender->SetImage("Prologue.bmp");
			PrologueMapRender->SetPosition(PrologueMapRender->GetImage()->GetImageScale().half());
			PrologueMapRender->SetScaleToImage();
		}
	}
}

void PrologueMap::Update(float _DeltaTime)
{

}