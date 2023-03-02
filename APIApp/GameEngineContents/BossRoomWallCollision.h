#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class BossRoomWallCollision : public GameEngineActor
{
public:
	// constrcuter destructer
	BossRoomWallCollision();
	~BossRoomWallCollision();

	// delete Function
	BossRoomWallCollision(const BossRoomWallCollision& _Other) = delete;
	BossRoomWallCollision(BossRoomWallCollision&& _Other) noexcept = delete;
	BossRoomWallCollision& operator=(const BossRoomWallCollision& _Other) = delete;
	BossRoomWallCollision& operator=(BossRoomWallCollision&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override {}

private:

};

