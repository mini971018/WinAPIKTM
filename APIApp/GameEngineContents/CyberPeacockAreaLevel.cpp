#include "CyberPeacockAreaLevel.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>

#include "Player.h"
#include "CyberPeacockAreaMap.h"
#include "ContentsEnums.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>

CyberPeacockAreaLevel::CyberPeacockAreaLevel() 
{
}

CyberPeacockAreaLevel::~CyberPeacockAreaLevel() 
{
}

void CyberPeacockAreaLevel::Loading()
{
	GameEngineDirectory Dir;

	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("CyberPeacockArea");

	{
		//맵 이미지
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("CyberPeacockArea.bmp"));
	}

	//액터 생성
	{
		CyberPeacockAreaLevelPlayer = CreateActor<Player>();
		CyberPeacockAreaLevelPlayer->SetPos({ 200,610 });
	}
	{
		CyberPeacockAreaMap* Actor = CreateActor<CyberPeacockAreaMap>();
	}
}

void CyberPeacockAreaLevel::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("NextLevel"))
	{
		GameEngineCore::GetInst()->ChangeLevel("MagmaDragoonArea");
	}
}

void CyberPeacockAreaLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	Player::SetMainPlayer(*CyberPeacockAreaLevelPlayer);
}


