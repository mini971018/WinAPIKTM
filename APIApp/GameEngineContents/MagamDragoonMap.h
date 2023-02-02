#pragma once
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν :
class MagamDragoonMap : public GameEngineActor
{
public:
	static MagamDragoonMap* MainMagamDragoonAreaMap;

	// constrcuter destructer
	MagamDragoonMap();
	~MagamDragoonMap();

	// delete Function
	MagamDragoonMap(const MagamDragoonMap& _Other) = delete;
	MagamDragoonMap(MagamDragoonMap&& _Other) noexcept = delete;
	MagamDragoonMap& operator=(const MagamDragoonMap& _Other) = delete;
	MagamDragoonMap& operator=(MagamDragoonMap&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	GameEngineRender* MagamDragoonMapRender;
};
