#include "MagmaDragoonAreaLevel.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>

#include "Player.h"
#include "CyberPeacockAreaMap.h"
#include "ContentsEnums.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>
#include "MagamDragoonMap.h"
MagmaDragoonAreaLevel::MagmaDragoonAreaLevel() 
{
}

MagmaDragoonAreaLevel::~MagmaDragoonAreaLevel() 
{
}

void MagmaDragoonAreaLevel::Loading()
{
	GameEngineDirectory Dir;

	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("MagmaDragoonArea");

	{
		//맵 이미지
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MagmaDragoonArea.bmp"));
	}

	//액터 생성
	{
		Player* Actor = CreateActor<Player>();
		Actor->SetPos({ 285,450 });
	}
	{
		MagamDragoonMap* Actor = CreateActor<MagamDragoonMap>();
	}
}

void MagmaDragoonAreaLevel::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("NextLevel"))
	{
		GameEngineCore::GetInst()->ChangeLevel("SpacePort");
	}
}

