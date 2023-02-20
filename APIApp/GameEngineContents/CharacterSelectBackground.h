#pragma once
#include <GameEngineCore/GameEngineActor.h>

class CharacterSelectBackground : public GameEngineActor
{
public:
	// constrcuter destructer
	CharacterSelectBackground();
	~CharacterSelectBackground();

	// delete Function
	CharacterSelectBackground(const CharacterSelectBackground& _Other) = delete;
	CharacterSelectBackground(CharacterSelectBackground&& _Other) noexcept = delete;
	CharacterSelectBackground& operator=(const CharacterSelectBackground& _Other) = delete;
	CharacterSelectBackground& operator=(CharacterSelectBackground&& _Other) noexcept = delete;

protected:
	void Start() override;

private:

};

