#include "MagamDragoonMap.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnums.h"

MagamDragoonMap* MagamDragoonMap::MainMagamDragoonAreaMap = nullptr;

MagamDragoonMap::MagamDragoonMap()
{
	MainMagamDragoonAreaMap = this;
}

MagamDragoonMap::~MagamDragoonMap()
{
}

void MagamDragoonMap::Start()
{
	{
		{
			MagamDragoonMapRender = CreateRender(MegamanX4RenderOrder::MAP);
			MagamDragoonMapRender->SetImage("MagmaDragoonArea.bmp");
			MagamDragoonMapRender->SetPosition(MagamDragoonMapRender->GetImage()->GetImageScale().half());
			MagamDragoonMapRender->SetScaleToImage();
		}
	}
}

void MagamDragoonMap::Update(float _DeltaTime)
{

}