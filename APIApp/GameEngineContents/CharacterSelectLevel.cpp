#include "CharacterSelectLevel.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>
#include "CharacterSelectBackground.h"
#include "CharacterSelectMegamanImage.h"
#include "CharacterSelectZeroImage.h"
#include "CharacterSelectUpperText.h"
#include "CharacterSelectLowerText.h"
#include "CharacterSelectZeroIcon.h"
#include "CharacterSelectMegamanIcon.h"
#include "CharacterSelectZeroText.h"
#include "CharacterSelectMegamanText.h"
#include "CharacterSelectZeroModel.h"

CharacterSelectLevel::CharacterSelectLevel() 
{

}

CharacterSelectLevel::~CharacterSelectLevel() 
{

}

void CharacterSelectLevel::Loading()
{
	GameEngineDirectory Dir;

	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("CharacterSelect");

	{
		// 백그라운드
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("CharacterSelectBackground.bmp"));

		// 이미지
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ZeroImage.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MegamanImage.bmp"));

		// 선택 오브젝트 이미지
		GameEngineImage* SelectZeroObject = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ZeroSelectIcon.bmp"));
		SelectZeroObject->Cut(3, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MegamanSelectIcon.bmp"));

		// 화면 상단 움직이는 플레이어 셀렉트 텍스트
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PlayerSelectText.bmp"));

		// 캐릭터 이미지 하단에 있는 텍스트 이미지
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MegamanText.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ZeroText.bmp"));

	}

	CreateActor<CharacterSelectBackground>();
	CreateActor<CharacterSelectMegamanImage>();
	CreateActor<CharacterSelectZeroImage>();
	CreateActor<CharacterSelectUpperText>();
	CreateActor<CharacterSelectLowerText>();
	SelectMegamanIcon = CreateActor<CharacterSelectMegamanIcon>();
	SelectZeroIcon = CreateActor<CharacterSelectZeroIcon>();
	CreateActor<CharacterSelectZeroText>();
	CreateActor<CharacterSelectMegamanText>();
	ZeroModel = CreateActor<CharacterSelectZeroModel>();
}

void CharacterSelectLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	BGMPlayer = GameEngineResources::GetInst().SoundPlayToControl("PlayerSelectBGM.mp3");
	BGMPlayer.LoopCount(100);
}

void CharacterSelectLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("NextLevel") && SelectZeroIcon->IsUpdate())
	{
		ZeroModel->SetModelAnimation(ZeroModelAnimation::CHANGELEVEL);
		LevelChangeState = true;
		GameEngineSoundPlayer SelectSound = GameEngineResources::GetInst().SoundPlayToControl("SelectCharacter.mp3");
		SelectSound.LoopCount(1);
	}

	if (GameEngineInput::IsDown("MoveLeft"))
	{
		SwitchIcon("MoveLeft");
	}
	else if (GameEngineInput::IsDown("MoveRight"))
	{
		SwitchIcon("MoveRight");
	}

	if (LevelChangeState)
	{
		LevelChangeTime += _DeltaTime;
	}

	if (LevelChangeTime > ChangeLevelElapsedTime)
	{
		BGMPlayer.PauseOn();
		GameEngineCore::GetInst()->ChangeLevel("CyberPeacockArea");
	}
}

void CharacterSelectLevel::SwitchIcon(const std::string_view& _Name)
{
	if (SelectZeroIcon->IsUpdate() && _Name == "MoveLeft")
	{
		SelectMegamanIcon->On();
		SelectZeroIcon->Off();
		GameEngineSoundPlayer SwitchSound = GameEngineResources::GetInst().SoundPlayToControl("SwitchCharacter.mp3");
		SwitchSound.LoopCount(1);
	}
	else if(SelectMegamanIcon->IsUpdate() && _Name == "MoveRight")
	{
		SelectMegamanIcon->Off();
		SelectZeroIcon->On();
		ZeroModel->SetModelAnimation(ZeroModelAnimation::ATTACK);
		GameEngineSoundPlayer SwitchSound = GameEngineResources::GetInst().SoundPlayToControl("SwitchCharacter.mp3");
		SwitchSound.LoopCount(1);
	}


}
