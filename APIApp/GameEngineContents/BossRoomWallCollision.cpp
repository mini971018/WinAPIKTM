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
}