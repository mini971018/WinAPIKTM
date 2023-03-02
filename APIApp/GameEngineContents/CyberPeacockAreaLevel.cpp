#include "CyberPeacockAreaLevel.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>

#include "Player.h"
#include "CyberPeacockAreaMap.h"
#include "ContentsEnums.h"
#include "BossRoomWallCollision.h"

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
		//�� �̹���
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("CyberPeacockArea.bmp"));
	}
	{
		//ColMap �̹���
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("CyberPeacockAreaColmap.bmp"));
	}
	{
		//ȭ��� ���� �տ� �ִ� ���������� �̹���
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("CyberPeacockAreaStructure.bmp"));
	}


	//���� ����
	{
		CyberPeacockAreaLevelPlayer = CreateActor<Player>();
		CyberPeacockAreaLevelPlayer->SetPos({ 6203, 4800 });
		SetCameraPos({ 5763, 4659 });
		CyberPeacockAreaLevelPlayer->SetColImage("CyberPeacockAreaColmap.bmp");
	}
	{
		CyberPeacockAreaMap* Actor = CreateActor<CyberPeacockAreaMap>();
	}
	{
		{
			GameEngineActor* Wall = CreateActor<BossRoomWallCollision>();
		}
	}
}

void CyberPeacockAreaLevel::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("DebugRenderSwitch"))
	{
		DebugRenderSwitch();
	}
}

void CyberPeacockAreaLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	Player::SetMainPlayer(*CyberPeacockAreaLevelPlayer);
}


