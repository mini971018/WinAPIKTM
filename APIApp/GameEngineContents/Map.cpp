#include "Map.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnums.h"

Map* Map::MainMap = nullptr;

Map::Map() 
{
	MainMap = this;
}

Map::~Map() 
{
}

void Map::Start()
{
	{
		{
			PrologueRender = CreateRender(MegamanX4RenderOrder::MAP);
			PrologueRender->SetImage("Prologue.bmp");
			PrologueRender->SetPosition(PrologueRender->GetImage()->GetImageScale().half());
			PrologueRender->SetScaleToImage();
		}

		/*AnimationRender->SetImage("Map_Spaceport.Bmp");
		AnimationRender->SetPosition(AnimationRender->GetImage()->GetImageScale().half());
		AnimationRender->SetScaleToImage();*/
		// AnimationRender->ChangeAnimation("Loop");
	}

}

void Map::Update(float _DeltaTime)
{

}
