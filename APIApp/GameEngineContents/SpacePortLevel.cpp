#include "SpacePortLevel.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>

#include "Player.h"
#include "SpacePortMap.h"
#include "ContentsEnums.h"

#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>

SpacePortLevel::SpacePortLevel() 
{
}

SpacePortLevel::~SpacePortLevel() 
{
}

void SpacePortLevel::Loading()
{
	GameEngineDirectory Dir;

	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("SpacePort");

	{
		//�� �̹���
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("SpacePort1.bmp"));
	}
	{
		//�� �̹���
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("SpacePort2.bmp"));
	}

	//���� ����
	{
		Player* Actor = CreateActor<Player>();
		Actor->SetPos({ -9520,4169 });
		SetCameraPos({ -9680, 3607 });
	}
	{
		SpacePortMap* Actor = CreateActor<SpacePortMap>();
	}
}

void SpacePortLevel::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("NextLevel"))
	{

	}
}