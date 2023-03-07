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

	//ü���� ���� �ð��� Ȯ���ϱ� ���� ����
	float LevelChangeTime = 0.0f;
	//ü���� ���� ���� �ҿ�Ǵ� �ð�
	float ChangeLevelElapsedTime = 1.3f; 
	//ü���� ���� Ȯ���� ���� �Ұ� ����
	bool LevelChangeState = false;
};

