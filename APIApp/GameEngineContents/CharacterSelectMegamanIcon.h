#pragma once
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν :
class CharacterSelectMegamanIcon : public GameEngineActor
{
public:
	// constrcuter destructer
	CharacterSelectMegamanIcon();
	~CharacterSelectMegamanIcon();

	// delete Function
	CharacterSelectMegamanIcon(const CharacterSelectMegamanIcon& _Other) = delete;
	CharacterSelectMegamanIcon(CharacterSelectMegamanIcon&& _Other) noexcept = delete;
	CharacterSelectMegamanIcon& operator=(const CharacterSelectMegamanIcon& _Other) = delete;
	CharacterSelectMegamanIcon& operator=(CharacterSelectMegamanIcon&& _Other) noexcept = delete;

protected:
	void Start() override;

private:

};

