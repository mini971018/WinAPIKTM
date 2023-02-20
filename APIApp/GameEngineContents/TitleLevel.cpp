#include "TitleLevel.h"

#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "TitleBackground.h"
#include "TitleStartObject.h"

TitleLevel::TitleLevel() 
{
}

TitleLevel::~TitleLevel() 
{
}

void TitleLevel::Loading()
{
	//디렉토리 이동 후 
	GameEngineDirectory Dir;

	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Title");

	//이미지를 로드한다.
	{
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("TitleBackground.bmp"));

		GameEngineImage* ButtonObject = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("TitleButtonObject.bmp"));
		ButtonObject->Cut(2, 1);
	}

	CreateActor<TitleBackground>();
	CreateActor<TitleStartObject>();
}

void TitleLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("NextLevel"))
	{
		GameEngineCore::GetInst()->ChangeLevel("CharacterSelect");
	}
}