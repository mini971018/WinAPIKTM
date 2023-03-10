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
		//GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftPlayer.bmp"));
		//Image->Cut(10, 23);

		GameEngineImage* IdleImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftPlayerIdle.bmp"));
		IdleImage->Cut(10, 2);
		GameEngineImage* MoveImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftPlayerMove.bmp"));
		MoveImage->Cut(10, 2);
		GameEngineImage* AttackImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftPlayerAttack.bmp"));
		AttackImage->Cut(10, 5);
		GameEngineImage* JumpImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftPlayerJump.bmp"));
		JumpImage->Cut(10, 2);
		GameEngineImage* JumpAttackImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftPlayerJumpAttack.bmp"));
		JumpAttackImage->Cut(10, 1);
		GameEngineImage* StageChangeImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftPlayerStageChange.bmp"));
		StageChangeImage->Cut(10, 3);
		GameEngineImage* WallClimbImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftPlayerWallClimb.bmp"));
		WallClimbImage->Cut(10, 1);
		GameEngineImage* DashImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftPlayerDash.bmp"));
		DashImage->Cut(10, 1);
		GameEngineImage* DashDustImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftPlayerDashDust.bmp"));
		DashDustImage->Cut(10, 1);
		GameEngineImage* DashEffectImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftPlayerDashEffect.bmp"));
		DashEffectImage->Cut(10, 1);
		GameEngineImage* KickJumpEffectImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftPlayerKickJumpEffect.bmp"));
		KickJumpEffectImage->Cut(10, 1);
		GameEngineImage* WallClimbDust = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftPlayerWallClimbDust.bmp"));
		WallClimbDust->Cut(10, 1);
		GameEngineImage* GetDamaged = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftPlayerDamaged.bmp"));
		GetDamaged->Cut(8, 1);
	}
	{
		//플레이어 우측 방향 이미지
		//GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightPlayer.bmp"));
		//Image->Cut(10, 23);
		GameEngineImage* IdleImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightPlayerIdle.bmp"));
		IdleImage->Cut(10, 2);
		GameEngineImage* MoveImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightPlayerMove.bmp"));
		MoveImage->Cut(10, 2);
		GameEngineImage* AttackImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightPlayerAttack.bmp"));
		AttackImage->Cut(10, 5);
		GameEngineImage* JumpImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightPlayerJump.bmp"));
		JumpImage->Cut(10, 2);
		GameEngineImage* JumpAttackImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightPlayerJumpAttack.bmp"));
		JumpAttackImage->Cut(10, 1);
		GameEngineImage* StageChangeImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightPlayerStageChange.bmp"));
		StageChangeImage->Cut(10, 3);
		GameEngineImage* WallClimbImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightPlayerWallClimb.bmp"));
		WallClimbImage->Cut(10, 1);
		GameEngineImage* DashImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightPlayerDash.bmp"));
		DashImage->Cut(10, 1);
		GameEngineImage* DashDustImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightPlayerDashDust.bmp"));
		DashDustImage->Cut(10, 1);
		GameEngineImage* DashEffectImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightPlayerDashEffect.bmp"));
		DashEffectImage->Cut(10, 1);
		GameEngineImage* KickJumpEffectImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightPlayerKickJumpEffect.bmp"));
		KickJumpEffectImage->Cut(10, 1);
		GameEngineImage* WallClimbDust = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightPlayerWallClimbDust.bmp"));
		WallClimbDust->Cut(10, 1);
		GameEngineImage* GetDamaged = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightPlayerDamaged.bmp"));
		GetDamaged->Cut(8, 1);
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
	{
		//hb bar
		GameEngineImage* HPBar = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PlayerHPBar.bmp"));
	}
	{
		//hb bar
		GameEngineImage* HPUI = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("HPUI.bmp"));
	}
	//액터 생성
	{
		PrologueLevelPlayer = CreateActor<Player>();
		PrologueLevelPlayer->SetPos({ 400, 100 });
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
