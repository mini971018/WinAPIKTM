#include "BossRoomDoor.h"

#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include "ContentsEnums.h"

BossRoomDoor::BossRoomDoor() 
{
}

BossRoomDoor::~BossRoomDoor() 
{
}


void BossRoomDoor::Start()
{
	AnimationRender = CreateRender(MegamanX4PlayRenderOrder::OBJECT);
	AnimationRender->SetScale({ 704, 704 });

	AnimationRender->CreateAnimation({ .AnimationName = "Door",  .ImageName = "BossDoorOpen.bmp", .Start = 0, .End = 0, .InterTime = 0.1f, .Loop = false});
	AnimationRender->CreateAnimation({ .AnimationName = "BossDoorOpen",  .ImageName = "BossDoorOpen.bmp", .Start = 0, .End = 12, .InterTime = 0.05f,. Loop = false});
	AnimationRender->CreateAnimation({ .AnimationName = "BossDoorClose",  .ImageName = "BossDoorClose.bmp", .Start = 0, .End = 12, .InterTime = 0.05f, . Loop = false });
	AnimationRender->ChangeAnimation("Door");


	CheckCollision = CreateCollision(MegamanX4CollisionOrder::OPENDOOR1);
	CheckCollision->SetMove({ 6912, 5187 });
	CheckCollision->SetScale({ 10 , 176 });
}



void BossRoomDoor::Update(float _DeltaTime)
{
	std::vector<GameEngineCollision*> Collision;

	if (OpenState == true)
	{
		OpenCalTime += _DeltaTime;

		if (DoorOpening == false)
		{
			DoorOpening = true;
			AnimationRender->ChangeAnimation("BossDoorOpen");
			PlaySoundOnce("DoorScrew.mp3");
		}

		if (OpenCalTime >= 0.5f && DoorOpenSound == false)
		{
			PlaySoundOnce("DoorOpen.mp3");
			DoorOpenSound = true;
		}

		if (OpenCalTime >= 3.0f && DoorClosing == false)
		{
			DoorClosing = true;
			PlaySoundOnce("DoorOpen.mp3");
			AnimationRender->ChangeAnimation("BossDoorClose");
			PlaySoundOnce("DoorScrew.mp3");

		}

		if (OpenCalTime >= 4.0f)
		{
			OpenState = false;
			DoorOpenSound = false;
		}
	}
}

void BossRoomDoor::Open()
{
	OpenState = true;
}

void BossRoomDoor::PlaySoundOnce(const std::string_view& _Text)
{
	GameEngineSoundPlayer Sound = GameEngineResources::GetInst().SoundPlayToControl(_Text.data());
	Sound.LoopCount(1);
}