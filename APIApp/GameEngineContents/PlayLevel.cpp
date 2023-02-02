#include "Player.h"
#include "PlayLevel.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>

#include "Map.h"
#include "ContentsEnums.h"

PlayLevel::PlayLevel() 
{
}

PlayLevel::~PlayLevel() 
{
}

void PlayLevel::Loading()
{
	GameEngineDirectory Dir;

	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");

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

	//���� ����
	{
		Player* Actor = CreateActor<Player>();

	}
	{
		Map* Actor = CreateActor<Map>();
	}
}

void PlayLevel::Update(float _DeltaTime)
{

}