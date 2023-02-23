#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class ZeroModelAnimation
{
	ATTACK,
	CHANGELEVEL
};

// Ό³Έν :
class CharacterSelectZeroModel : public GameEngineActor
{
public:
	// constrcuter destructer
	CharacterSelectZeroModel();
	~CharacterSelectZeroModel();

	// delete Function
	CharacterSelectZeroModel(const CharacterSelectZeroModel& _Other) = delete;
	CharacterSelectZeroModel(CharacterSelectZeroModel&& _Other) noexcept = delete;
	CharacterSelectZeroModel& operator=(const CharacterSelectZeroModel& _Other) = delete;
	CharacterSelectZeroModel& operator=(CharacterSelectZeroModel&& _Other) noexcept = delete;

	void SetModelAnimation(ZeroModelAnimation _Animation);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	bool ChangeLevelState = false;
	GameEngineRender* AnimationRender = nullptr;

};

