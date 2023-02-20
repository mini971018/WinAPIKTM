#pragma once

#include <GameEngineCore/GameEngineActor.h>

class CharacterSelectZeroImage : public GameEngineActor
{
public:
	// constrcuter destructer
	CharacterSelectZeroImage();
	~CharacterSelectZeroImage();

	// delete Function
	CharacterSelectZeroImage(const CharacterSelectZeroImage& _Other) = delete;
	CharacterSelectZeroImage(CharacterSelectZeroImage&& _Other) noexcept = delete;
	CharacterSelectZeroImage& operator=(const CharacterSelectZeroImage& _Other) = delete;
	CharacterSelectZeroImage& operator=(CharacterSelectZeroImage&& _Other) noexcept = delete;

protected:
	void Start() override;

private:

};

