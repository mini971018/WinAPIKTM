#pragma once
#include <GameEngineCore/GameEngineActor.h>

class WallClimbDustEffect : public GameEngineActor
{
public:
	// constrcuter destructer
	WallClimbDustEffect();
	~WallClimbDustEffect();

	// delete Function
	WallClimbDustEffect(const WallClimbDustEffect& _Other) = delete;
	WallClimbDustEffect(WallClimbDustEffect&& _Other) noexcept = delete;
	WallClimbDustEffect& operator=(const WallClimbDustEffect& _Other) = delete;
	WallClimbDustEffect& operator=(WallClimbDustEffect&& _Other) noexcept = delete;

	void OnWallClimbDustEffect();
	void OffWallClimbDustEffect();
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* AnimationRender = nullptr;
	bool IsOn;
};

