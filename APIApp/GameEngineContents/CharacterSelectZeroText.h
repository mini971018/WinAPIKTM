#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class CharacterSelectZeroText : public GameEngineActor
{
public:
	// constrcuter destructer
	CharacterSelectZeroText();
	~CharacterSelectZeroText();

	// delete Function
	CharacterSelectZeroText(const CharacterSelectZeroText& _Other) = delete;
	CharacterSelectZeroText(CharacterSelectZeroText&& _Other) noexcept = delete;
	CharacterSelectZeroText& operator=(const CharacterSelectZeroText& _Other) = delete;
	CharacterSelectZeroText& operator=(CharacterSelectZeroText&& _Other) noexcept = delete;

protected:
	void Start() override;

private:

};

