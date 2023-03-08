#include "BossRoomDoor.h"

#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineRender.h>
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

	AnimationRender->CreateAnimation({ .AnimationName = "Door",  .ImageName = "BossDoorOpen.bmp", .Start = 0, .End = 0, .InterTime = 0.2f, .Loop = false});
	AnimationRender->CreateAnimation({ .AnimationName = "BossDoorOpen",  .ImageName = "BossDoorOpen.bmp", .Start = 0, .End = 12, .InterTime = 0.2f,. Loop = false});
	AnimationRender->CreateAnimation({ .AnimationName = "BossDoorClose",  .ImageName = "BossDoorClose.bmp", .Start = 0, .End = 12, .InterTime = 0.2f, . Loop = false });
	AnimationRender->ChangeAnimation("Door");

}

void BossRoomDoor::Update(float _DeltaTime)
{
	
}

