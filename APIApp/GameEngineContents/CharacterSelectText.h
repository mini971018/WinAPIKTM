#pragma once
#include <GameEngineCore/GameEngineActor.h>

class CharacterSelectText : public GameEngineActor
{
public:
	// constrcuter destructer
	CharacterSelectText();
	~CharacterSelectText();

	// delete Function
	CharacterSelectText(const CharacterSelectText& _Other) = delete;
	CharacterSelectText(CharacterSelectText&& _Other) noexcept = delete;
	CharacterSelectText& operator=(const CharacterSelectText& _Other) = delete;
	CharacterSelectText& operator=(CharacterSelectText&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:

};

