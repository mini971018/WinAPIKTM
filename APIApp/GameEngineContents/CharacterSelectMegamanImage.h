#pragma once
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν :
class CharacterSelectMegamanImage : public GameEngineActor
{
public:
	// constrcuter destructer
	CharacterSelectMegamanImage();
	~CharacterSelectMegamanImage();

	// delete Function
	CharacterSelectMegamanImage(const CharacterSelectMegamanImage& _Other) = delete;
	CharacterSelectMegamanImage(CharacterSelectMegamanImage&& _Other) noexcept = delete;
	CharacterSelectMegamanImage& operator=(const CharacterSelectMegamanImage& _Other) = delete;
	CharacterSelectMegamanImage& operator=(CharacterSelectMegamanImage&& _Other) noexcept = delete;

protected:
	void Start() override;

private:

};

