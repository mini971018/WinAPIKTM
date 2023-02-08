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
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LeftPlayer.bmp"));
		Image->Cut(10, 23);
	}
	{
		//�÷��̾� ���� ���� �̹���
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("RightPlayer.bmp"));
		Image->Cut(10, 23);
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
