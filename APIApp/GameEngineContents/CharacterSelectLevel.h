#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineResources.h>

class CharacterSelectMegamanIcon;
class CharacterSelectZeroIcon;
class CharacterSelectZeroModel;
class CharacterSelectLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	CharacterSelectLevel();
	~CharacterSelectLevel();

	// delete Function
	CharacterSelectLevel(const CharacterSelectLevel& _Other) = delete;
	CharacterSelectLevel(CharacterSelectLevel&& _Other) noexcept = delete;
	CharacterSelectLevel& operator=(const CharacterSelectLevel& _Other) = delete;
	CharacterSelectLevel& operator=(CharacterSelectLevel&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeStart(GameEngineLevel* _PrevLevel);
	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {}

private:
	CharacterSelectZeroIcon* SelectZeroIcon;
	CharacterSelectMegamanIcon* SelectMegamanIcon;
	CharacterSelectZeroModel* ZeroModel;
	GameEngineSoundPlayer BGMPlayer;

	void SwitchIcon(const std::string_view& _Name);

	//체인지 레벨 시간을 확인하기 위한 변수
	float LevelChangeTime = 0.0f;
	//체인지 레벨 까지 소요되는 시간
	float ChangeLevelElapsedTime = 1.3f; 
	//체인지 레벨 확인을 위한 불값 변수
	bool LevelChangeState = false;
};

