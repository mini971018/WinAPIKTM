#pragma once
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν :
class SpacePortMap : public GameEngineActor
{
public:
	static SpacePortMap* MainSpacePortMap;

	// constrcuter destructer
	SpacePortMap();
	~SpacePortMap();

	// delete Function
	SpacePortMap(const SpacePortMap& _Other) = delete;
	SpacePortMap(SpacePortMap&& _Other) noexcept = delete;
	SpacePortMap& operator=(const SpacePortMap& _Other) = delete;
	SpacePortMap& operator=(SpacePortMap&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* SpacePortMap1Render;
	GameEngineRender* SpacePortMap2Render;
};



