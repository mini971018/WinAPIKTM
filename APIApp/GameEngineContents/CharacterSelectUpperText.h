#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class CharacterSelectUpperText : public GameEngineActor
{
public:
	// constrcuter destructer
	CharacterSelectUpperText();
	~CharacterSelectUpperText();

	// delete Function
	CharacterSelectUpperText(const CharacterSelectUpperText& _Other) = delete;
	CharacterSelectUpperText(CharacterSelectUpperText&& _Other) noexcept = delete;
	CharacterSelectUpperText& operator=(const CharacterSelectUpperText& _Other) = delete;
	CharacterSelectUpperText& operator=(CharacterSelectUpperText&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* Render;
	float MoveSpeed = 200.0f;
};

