#include "TestLevel.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>

#include "Player.h"
#include "TestLevelMap.h"
#include "ContentsEnums.h"

#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>

TestLevel::TestLevel() 
{
}

TestLevel::~TestLevel() 
{
}

void TestLevel::Loading()
{
	GameEngineDirectory Dir;

	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Test");

	{
		//ColMap 이미지
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("TestColmap.bmp"));
	}


	//액터 생성
	{
		TestLevelPlayer = CreateActor<Player>();
		TestLevelPlayer->SetPos({ 440, 100 });
		TestLevelPlayer->SetColImage("TestColMap.bmp");
	}
	{
		TestLevelMap* Actor = CreateActor<TestLevelMap>();
	}
}

void TestLevel::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("DebugRenderSwitch"))
	{
		DebugRenderSwitch();
	}
}

void TestLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	Player::SetMainPlayer(*TestLevelPlayer);
}
