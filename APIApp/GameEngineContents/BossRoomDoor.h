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

	void Open();
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	void PlaySoundOnce(const std::string_view& _Text);

	
	bool OpenState = false;
	bool DoorOpenSound = false;
	bool DoorOpening = false;
	bool DoorClosing = false;
	float OpenCalTime = 0.0f; //Âß ½Ã°£ È®ÀÎ

	GameEngineRender* AnimationRender = nullptr;
	GameEngineCollision* CheckCollision = nullptr;
};

