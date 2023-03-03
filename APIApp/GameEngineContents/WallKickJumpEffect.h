#pragma once
#include <GameEngineCore/GameEngineActor.h>

class WallKickJumpEffect : public GameEngineActor
{
public:
	// constrcuter destructer
	WallKickJumpEffect();
	~WallKickJumpEffect();

	// delete Function
	WallKickJumpEffect(const WallKickJumpEffect& _Other) = delete;
	WallKickJumpEffect(WallKickJumpEffect&& _Other) noexcept = delete;
	WallKickJumpEffect& operator=(const WallKickJumpEffect& _Other) = delete;
	WallKickJumpEffect& operator=(WallKickJumpEffect&& _Other) noexcept = delete;

	void OnWallKickJumpEffect(const std::string _DirString);
	void OffWallKickJumpEffect();

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	void DirCheck(const std::string_view& _AnimationName);
	std::string DirString = "";
	GameEngineRender* AnimationRender = nullptr;
};

