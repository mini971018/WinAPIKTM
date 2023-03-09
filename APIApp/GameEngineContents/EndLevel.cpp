#include "EndLevel.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include "EndLevelBackground.h"

EndLevel::EndLevel() 
{
}

EndLevel::~EndLevel() 
{
}

void EndLevel::Loading()
{
	GameEngineDirectory Dir;

	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("End");

	{
		//화면 이미지
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("EndScreen.bmp"));
	}
	{
		CreateActor<EndLevelBackground>();
	}
}

void EndLevel::Update(float _DeltaTime)
{

}

void EndLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	GameEngineSoundPlayer EndLevelBGM = GameEngineResources::GetInst().SoundPlayToControl("EndLevelBGM.mp3");
	EndLevelBGM.LoopCount(100);
}
