#include "CyberPeacockAreaLevel.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>

#include "Player.h"
#include "CyberPeacockAreaMap.h"
#include "ContentsEnums.h"
#include "BossRoomWallCollision.h"
#include "CyberPeacockBoss.h"

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
	{
		//ColMap 이미지
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("CyberPeacockAreaColmap.bmp"));
	}
	{
		//화면상 가장 앞에 있는 구조물들의 이미지
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("CyberPeacockAreaStructure.bmp"));
	}
	{
		//보스 이미지
		//시작 및 종료
		{
			GameEngineImage* AppearImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("StartAnim.bmp"));
			AppearImage->Cut(10, 5);
		}
		//좌측
		{
			GameEngineImage* AppearImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftBossAppear.bmp"));
			AppearImage->Cut(10, 2);
			GameEngineImage* DisappearImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftBossDisappear1.bmp"));
			DisappearImage->Cut(10, 2);
			GameEngineImage* Attack1Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftBossAttack1.bmp"));
			Attack1Image->Cut(10, 1);
			GameEngineImage* Attack2Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftBossAttack2.bmp"));
			Attack2Image->Cut(10, 2);
			GameEngineImage* Disappear2Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftBossDisappear2.bmp"));
			Disappear2Image->Cut(10, 1);
			GameEngineImage* Attack3Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftBossAttack3.bmp"));
			Attack3Image->Cut(10, 2);
			GameEngineImage* Disappear3Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftBossDisappear3.bmp"));
			Disappear3Image->Cut(10, 1);
		}
		//우측
		{
			GameEngineImage* AppearImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightBossAppear.bmp"));
			AppearImage->Cut(10, 2);
			GameEngineImage* DisappearImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightBossDisappear1.bmp"));
			DisappearImage->Cut(10, 2);
			GameEngineImage* Attack1Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightBossAttack1.bmp"));
			Attack1Image->Cut(10, 1);
			GameEngineImage* Attack2Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightBossAttack2.bmp"));
			Attack2Image->Cut(10, 2);
			GameEngineImage* Disappear2Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightBossDisappear2.bmp"));
			Disappear2Image->Cut(10, 1);
			GameEngineImage* Attack3Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightBossAttack3.bmp"));
			Attack3Image->Cut(10, 2);
			GameEngineImage* Disappear3Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightBossDisappear3.bmp"));
			Disappear3Image->Cut(10, 1);
		}
	}
	//액터 생성
	{
		//플레이어
		CyberPeacockAreaLevelPlayer = CreateActor<Player>();
		CyberPeacockAreaLevelPlayer->SetPos({ 6203, 4800 });
		SetCameraPos({ 5763, 4659 });
		CyberPeacockAreaLevelPlayer->SetColImage("CyberPeacockAreaColmap.bmp");
	}
	{
		//보스
		CyberPeacockBoss* Actor = CreateActor<CyberPeacockBoss>();
	}
	{
		//맵
		CyberPeacockAreaMap* Actor = CreateActor<CyberPeacockAreaMap>();
	}
	{
		//콜리전
		{
			GameEngineActor* Wall = CreateActor<BossRoomWallCollision>(); //보스쪽 벽 콜리전
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


