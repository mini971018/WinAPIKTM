#include "BossRoomWallCollision.h"
#include "ContentsEnums.h"
#include <GameEngineCore/GameEngineCollision.h>

BossRoomWallCollision::BossRoomWallCollision() 
{
}

BossRoomWallCollision::~BossRoomWallCollision() 
{
}

void BossRoomWallCollision::Start()
{
	{
		GameEngineCollision* WallCollision = CreateCollision(MegamanX4CollisionOrder::WALL);
		WallCollision->SetMove({ 5788, 5055 });
		WallCollision->SetScale({ 44 , 528 });
	}

	{
		GameEngineCollision* WallCollision = CreateCollision(MegamanX4CollisionOrder::WALL);
		WallCollision->SetMove({ 6248, 4725 });
		WallCollision->SetScale({ 968 , 132 });
	}

	{
		GameEngineCollision* WallCollision = CreateCollision(MegamanX4CollisionOrder::WALL);
		WallCollision->SetMove({ 7280.5, 4879 });
		WallCollision->SetScale({ 1097 , 440 });
	}

	{
		GameEngineCollision* WallCollision = CreateCollision(MegamanX4CollisionOrder::WALL);
		WallCollision->SetMove({ 8295.5, 4654 });
		WallCollision->SetScale({ 965 , 10 });
	}

	{
		GameEngineCollision* WallCollision = CreateCollision(MegamanX4CollisionOrder::WALL);
		WallCollision->SetMove({ 8822, 4989 });
		WallCollision->SetScale({ 132 , 660 });
	}



	{
		GameEngineCollision* WallCollision = CreateCollision(MegamanX4CollisionOrder::WALL);
		WallCollision->SetMove({ 6952, 5187 });
		WallCollision->SetScale({ 80 , 176 });
	}

	{
		GameEngineCollision* WallCollision = CreateCollision(MegamanX4CollisionOrder::WALL);
		WallCollision->SetMove({ 7788, 5187 });
		WallCollision->SetScale({ 84 , 176 });
	}

	{
		GameEngineCollision* DoorOpenCollision = CreateCollision(MegamanX4CollisionOrder::OPENDOOR1);
		DoorOpenCollision->SetMove({ 6912, 5187 });
		DoorOpenCollision->SetScale({ 10 , 176 });
	}
	{
		GameEngineCollision* DoorOpenCollision = CreateCollision(MegamanX4CollisionOrder::OPENDOOR2);
		DoorOpenCollision->SetMove({ 7748, 5187 });
		DoorOpenCollision->SetScale({ 10 , 176 });
	}
}