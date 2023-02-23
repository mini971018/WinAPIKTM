#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class CharacterSelectMegamanText : public GameEngineActor
{
public:
	// constrcuter destructer
	CharacterSelectMegamanText();
	~CharacterSelectMegamanText();

	// delete Function
	CharacterSelectMegamanText(const CharacterSelectMegamanText& _Other) = delete;
	CharacterSelectMegamanText(CharacterSelectMegamanText&& _Other) noexcept = delete;
	CharacterSelectMegamanText& operator=(const CharacterSelectMegamanText& _Other) = delete;
	CharacterSelectMegamanText& operator=(CharacterSelectMegamanText&& _Other) noexcept = delete;

protected:
	void Start() override;

private:

};

