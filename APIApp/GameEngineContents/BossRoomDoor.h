#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "ContentsEnums.h"
class BossRoomDoor : public GameEngineActor
{
public:
	// constrcuter destructer
	BossRoomDoor();
	~BossRoomDoor();

	// delete Function
	BossRoomDoor(const BossRoomDoor& _Other) = delete;
	BossRoomDoor(BossRoomDoor&& _Other) noexcept = delete;
	BossRoomDoor& operator=(const BossRoomDoor& _Other) = delete;
	BossRoomDoor& operator=(BossRoomDoor&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* AnimationRender = nullptr;
};

