#include "TestWall.h"
#include "ContentsEnums.h"
#include <GameEngineCore/GameEngineCollision.h>

TestWall::TestWall() 
{
}

TestWall::~TestWall() 
{
}

void TestWall::Start()
{
	{
		GameEngineCollision* TestWall = CreateCollision(MegamanX4CollisionOrder::WALL);
		TestWall->SetMove({ 0, 330 });
		TestWall->SetScale({ 30 , 660 });
	}

	{
		GameEngineCollision* TestWall = CreateCollision(MegamanX4CollisionOrder::WALL);
		TestWall->SetMove({ 880, 330 });
		TestWall->SetScale({ 30 , 660 });
	}

	{
		GameEngineCollision* TestWall = CreateCollision(MegamanX4CollisionOrder::WALL);
		TestWall->SetMove({ 0, 300 });
		TestWall->SetScale({ 300 , 60 });
	}

}
