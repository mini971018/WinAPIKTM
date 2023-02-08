#include "PrologueLevel.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>

#include "Player.h"
#include "PrologueMap.h"
#include "ContentsEnums.h"

#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>

PrologueLevel::PrologueLevel() 
{
}

PrologueLevel::~PrologueLevel() 
{
}

void PrologueLevel::Loading()
{
	GameEngineDirectory Dir;

	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Prologue");

	//이미지 로드
	{
		//플레이어 좌측 방향 이미지
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftPlayer.bmp"));
		Image->Cut(10, 23);
	}
	{
		//플레이어 우측 방향 이미지
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightPlayer.bmp"));
		Image->Cut(10, 23);
	}
	{
		//맵 이미지
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Prologue.bmp"));

	}
	{
		//ColMap 이미지
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PrologueColmap.bmp"));
	}
	{
		//화면상 가장 앞에 있는 구조물들의 이미지
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PrologueStructure.bmp"));
	}


	//액터 생성
	{
		PrologueLevelPlayer = CreateActor<Player>();
		PrologueLevelPlayer->SetPos({ 300,500 });
		PrologueLevelPlayer->SetColImage("PrologueColmap.bmp");
	}
	{
		PrologueMap* Actor = CreateActor<PrologueMap>();
	}
}

void PrologueLevel::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("NextLevel"))
	{
		GameEngineCore::GetInst()->ChangeLevel("CyberPeacockArea");
	}
}

void PrologueLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	Player::SetMainPlayer(*PrologueLevelPlayer);
}
