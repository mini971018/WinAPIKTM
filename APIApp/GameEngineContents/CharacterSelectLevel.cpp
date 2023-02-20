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
		// ��׶���
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("CharacterSelectBackground.bmp"));

		// �̹���
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ZeroImage.bmp"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MegamanImage.bmp"));

		// ���� ������Ʈ �̹���
		GameEngineImage* SelectZeroObject = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ZeroSelectIcon.bmp"));
		SelectZeroObject->Cut(3, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MegamanSelectIcon.bmp"));

		// ȭ�� ��� �����̴� �÷��̾� ����Ʈ �ؽ�Ʈ
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PlayerSelectText.bmp"));
	}

	CreateActor<CharacterSelectBackground>();
	CreateActor<CharacterSelectMegamanImage>();
	CreateActor<CharacterSelectZeroImage>();
	CreateActor<CharacterSelectUpperText>();
	CreateActor<CharacterSelectLowerText>();
	CreateActor<CharacterSelectZeroIcon>();
}

void CharacterSelectLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("NextLevel"))
	{
		GameEngineCore::GetInst()->ChangeLevel("Prologue");
	}
}
