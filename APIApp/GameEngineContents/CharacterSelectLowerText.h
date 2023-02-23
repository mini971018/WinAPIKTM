#pragma once
#include <GameEngineCore/GameEngineActor.h>

class CharacterSelectLowerText : public GameEngineActor
{
public:
	// constrcuter destructer
	CharacterSelectLowerText();
	~CharacterSelectLowerText();

	// delete Function
	CharacterSelectLowerText(const CharacterSelectLowerText& _Other) = delete;
	CharacterSelectLowerText(CharacterSelectLowerText&& _Other) noexcept = delete;
	CharacterSelectLowerText& operator=(const CharacterSelectLowerText& _Other) = delete;
	CharacterSelectLowerText& operator=(CharacterSelectLowerText&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* Render;
	float MoveSpeed = 200.0f;
};

