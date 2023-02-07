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
		//�� �̹���
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MagmaDragoonArea.bmp"));
	}

	//���� ����
	{
		MagmaDragoonAreaLevelPlayer = CreateActor<Player>();
		MagmaDragoonAreaLevelPlayer->SetPos({ 285,450 });
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

void MagmaDragoonAreaLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	Player::SetMainPlayer(*MagmaDragoonAreaLevelPlayer);
}
