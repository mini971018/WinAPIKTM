#include "Player.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
//#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "ContentsEnums.h"
#include <GameEngineBase/GameEngineMath.h>

Player* Player::MainPlayer;

void Player::SetMainPlayer(Player& _Player)
{
	MainPlayer = &_Player;
}

Player::Player() 
{
}

Player::~Player() 
{
}



void Player::Start()
{
	SetMove(GameEngineWindow::GetScreenSize().half());

	if (GameEngineInput::IsKey("MoveLeft") == false)
	{
		//캐릭터 이동
		GameEngineInput::CreateKey("MoveLeft", 'A');
		GameEngineInput::CreateKey("MoveRight", 'D');
		GameEngineInput::CreateKey("MoveUp", 'W');
		GameEngineInput::CreateKey("MoveDown", 'S');
		GameEngineInput::CreateKey("Jump", 'K');
		

		GameEngineInput::CreateKey("NextLevel", 'P');

		GameEngineInput::CreateKey("FreeMoveSwitch", '1');
	}

	{
		AnimationRender = CreateRender(MegamanX4RenderOrder::PLAYER);
		AnimationRender->SetScale({ 704, 704 });

		AnimationRender->CreateAnimation({ .AnimationName = "Right_Idle", .ImageName = "RightPlayer.bmp", .Start = 31, .End = 35, .InterTime = 0.25f });
		AnimationRender->CreateAnimation({ .AnimationName = "Right_Move", .ImageName = "RightPlayer.bmp", .Start = 47, .End = 60, .InterTime = 0.05f});
		AnimationRender->CreateAnimation({ .AnimationName = "Right_EnterMove", .ImageName = "RightPlayer.bmp", .Start = 45, .End = 47, .InterTime = 0.05f });
		AnimationRender->CreateAnimation({ .AnimationName = "Right_JumpStart", .ImageName = "RightPlayer.bmp", .Start = 116, .End = 116, .InterTime = 0.05f, .Loop = false });
		AnimationRender->CreateAnimation({ .AnimationName = "Right_Jump", .ImageName = "RightPlayer.bmp", .Start = 117, .End = 118, .InterTime = 0.05f });
		AnimationRender->CreateAnimation({ .AnimationName = "Right_FallStart", .ImageName = "RightPlayer.bmp", .Start = 119, .End = 123, .InterTime = 0.05f, .Loop = false });
		AnimationRender->CreateAnimation({ .AnimationName = "Right_Fall", .ImageName = "RightPlayer.bmp", .Start = 124, .End = 127, .InterTime = 0.05f});
		AnimationRender->CreateAnimation({ .AnimationName = "Right_Landing", .ImageName = "RightPlayer.bmp", .Start = 128, .End = 129, .InterTime = 0.09f, .Loop = false });

		AnimationRender->CreateAnimation({ .AnimationName = "Left_Idle", .ImageName = "LeftPlayer.bmp", .Start = 31, .End = 35, .InterTime = 0.25f });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_Move", .ImageName = "LeftPlayer.bmp", .Start = 47, .End = 60, .InterTime = 0.05f });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_EnterMove", .ImageName = "LeftPlayer.bmp", .Start = 45, .End = 47, .InterTime = 0.05f });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_JumpStart", .ImageName = "LeftPlayer.bmp", .Start = 116, .End = 116, .InterTime = 0.05f, .Loop = false });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_Jump", .ImageName = "LeftPlayer.bmp", .Start = 117, .End = 118, .InterTime = 0.05f });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_FallStart", .ImageName = "LeftPlayer.bmp", .Start = 119, .End = 123, .InterTime = 0.05f, .Loop = false });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_Fall", .ImageName = "LeftPlayer.bmp", .Start = 124, .End = 127, .InterTime = 0.05f });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_Landing", .ImageName = "LeftPlayer.bmp", .Start = 128, .End = 129, .InterTime = 0.09f, .Loop = false });


		ChangeState(PlayerState::IDLE);
	}
}

//레벨마다 다른 colimage를 캐릭마다 넣음
void Player::SetColImage(const std::string_view& _Name)
{
	ColImage = GameEngineResources::GetInst().ImageFind(_Name.data());
}

void Player::MoveCalculation(float _DeltaTime)
{
	if (ColImage == nullptr)
	{
		MsgAssert("현재 스테이지의 플레이어 충돌용 맵 이미지가 없습니다.");
	}

	float4 NextPos = GetPos() + (MoveDir * _DeltaTime);

	if (RGB(0, 0, 0) == ColImage->GetPixelColor(GetPos() + float4::Down, RGB(0, 0, 0)))
	{
		IsGround = true;
	}
	else
	{
		MoveDir += (float4::Down * Gravity * _DeltaTime);
		IsGround = false;
	}

	SetMove(MoveDir * _DeltaTime);

	//카메라
	float4 CameraDir = float4(MoveDir.x, 0.0f);

	GetLevel()->SetCameraMove(CameraDir * _DeltaTime);
}

bool FreeMove = false;

bool Player::FreeMoveState(float _DeltaTime)
{
	if (true == GameEngineInput::IsPress("FreeMoveSwitch"))
	{
		FreeMove = !FreeMove;
	}

	if (true == FreeMove)
	{
		if (GameEngineInput::IsPress("MoveLeft"))
		{
			SetMove(float4::Left * 1000.0f * _DeltaTime);
			GetLevel()->SetCameraMove(float4::Left * 1000.0f * _DeltaTime);
		}
		else if (GameEngineInput::IsPress("MoveRight"))
		{
			SetMove(float4::Right * 1000.0f * _DeltaTime);
			GetLevel()->SetCameraMove(float4::Right * 1000.0f * _DeltaTime);
		}
		else if (GameEngineInput::IsPress("MoveUp"))
		{
			SetMove(float4::Up * 1000.0f * _DeltaTime);
			GetLevel()->SetCameraMove(float4::Up * 1000.0f * _DeltaTime);
		}
		else if (GameEngineInput::IsPress("MoveDown"))
		{
			SetMove(float4::Down * 1000.0f * _DeltaTime);
			GetLevel()->SetCameraMove(float4::Down * 1000.0f * _DeltaTime);
		}
	}

	if (true == FreeMove)
	{
		return true;
	}

	return false;
}

void Player::Update(float _DeltaTime)
{
	MoveDir = float4::Zero;

	if (true == FreeMoveState(_DeltaTime))
	{
		return;
	}

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
	float4 ActorPos = GetPos() - GetLevel()->GetCameraPos();;

	//위치 확인용
	Rectangle(DoubleDC,
		ActorPos.ix() - 5,
		ActorPos.iy() - 5,
		ActorPos.ix() + 5,
		ActorPos.iy() + 5
	);

	std::string CameraMouseText = "MousePositionCamera : ";
	CameraMouseText += GetLevel()->GetMousePosToCamera().ToString();

	GameEngineLevel::DebugTextPush(CameraMouseText);
}