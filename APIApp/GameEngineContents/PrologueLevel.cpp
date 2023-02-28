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

	//�̹��� �ε�
	{
		//�÷��̾� ���� ���� �̹���
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

	}
	{
		//�÷��̾� ���� ���� �̹���
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
	}
	{
		//�� �̹���
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Prologue.bmp"));
	}
	{
		//ColMap �̹���
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PrologueColmap.bmp"));
	}
	{
		//ȭ��� ���� �տ� �ִ� ���������� �̹���
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PrologueStructure.bmp"));
	}


	//���� ����
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
