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

	void OnWallClimbDustEffect(const std::string _DirString);
	void OffWallClimbDustEffect();
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	void DirCheck(const std::string_view& _AnimationName);
	std::string DirString = "";
	GameEngineRender* AnimationRender = nullptr;
	bool IsOn;
};

