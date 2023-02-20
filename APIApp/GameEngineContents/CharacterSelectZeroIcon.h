#pragma once
#include <GameEngineCore/GameEngineActor.h>

class CharacterSelectZeroIcon : public GameEngineActor
{
public:
	// constrcuter destructer
	CharacterSelectZeroIcon();
	~CharacterSelectZeroIcon();

	// delete Function
	CharacterSelectZeroIcon(const CharacterSelectZeroIcon& _Other) = delete;
	CharacterSelectZeroIcon(CharacterSelectZeroIcon&& _Other) noexcept = delete;
	CharacterSelectZeroIcon& operator=(const CharacterSelectZeroIcon& _Other) = delete;
	CharacterSelectZeroIcon& operator=(CharacterSelectZeroIcon&& _Other) noexcept = delete;

protected:
	void Start() override;

private:

};

