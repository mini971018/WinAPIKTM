#include "Player.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnums.h"

Player* Player::MainPlayer;

Player::Player() 
{
}

Player::~Player() 
{
}

void Player::Start()
{
	MainPlayer = this;

	SetMove(GameEngineWindow::GetScreenSize().half());

	if (GameEngineInput::IsKey("MoveLeft") == false)
	{
		GameEngineInput::CreateKey("MoveLeft", 'A');
		GameEngineInput::CreateKey("MoveRight", 'D');
		GameEngineInput::CreateKey("MoveUp", 'W');
		GameEngineInput::CreateKey("MoveDown", 'S');
	}

	{
		AnimationRender = CreateRender(MegamanX4RenderOrder::PLAYER);
		AnimationRender->SetScale({ 704, 704 });

		AnimationRender->CreateAnimation({ .AnimationName = "Right_Idle", .ImageName = "RightPlayer.bmp", .Start = 31, .End = 35, .InterTime = 0.25f });
		AnimationRender->CreateAnimation({ .AnimationName = "Right_Move", .ImageName = "RightPlayer.bmp", .Start = 47, .End = 60, .InterTime = 0.05f});
		AnimationRender->CreateAnimation({ .AnimationName = "Right_EnterMove", .ImageName = "RightPlayer.bmp", .Start = 45, .End = 47, .InterTime = 0.05f });


		AnimationRender->CreateAnimation({ .AnimationName = "Left_Idle", .ImageName = "LeftPlayer.bmp", .Start = 31, .End = 35, .InterTime = 0.25f });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_Move", .ImageName = "LeftPlayer.bmp", .Start = 47, .End = 60, .InterTime = 0.05f });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_EnterMove", .ImageName = "LeftPlayer.bmp", .Start = 45, .End = 47, .InterTime = 0.05f });

		ChangeState(PlayerState::IDLE);
	}
}

void Player::MoveCalculation(float _DeltaTime)
{
	float4 NextPos = GetPos() + (MoveDir * _DeltaTime * MoveSpeed);

	SetPos(NextPos);
}

void Player::Update(float _DeltaTime)
{
	MoveDir = float4::Zero;

	UpdateState(_DeltaTime);
	MoveCalculation(_DeltaTime);
}

void Player::DirCheck(const std::string_view& _AnimationName)
{
	std::string PrevDirString = DirString;
	AnimationRender->ChangeAnimation(DirString + _AnimationName.data());

	if (GameEngineInput::IsPress("MoveLeft"))
	{
		DirString = "Left_";
	}
	else if (GameEngineInput::IsPress("MoveRight"))
	{
		DirString = "Right_";
	}

	if (PrevDirString != DirString)
	{
		AnimationRender->ChangeAnimation(DirString + _AnimationName.data());
	}
}

void Player::Render(float _DeltaTime)
{
	HDC DoubleDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
	float4 ActorPos = GetPos();

	//위치 확인용
	Rectangle(DoubleDC,
		ActorPos.ix() - 5,
		ActorPos.iy() - 5,
		ActorPos.ix() + 5,
		ActorPos.iy() + 5
	);

}