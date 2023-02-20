#include "Player.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
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
		GameEngineInput::CreateKey("Attack", 'J');

		GameEngineInput::CreateKey("NextLevel", 'P');

		GameEngineInput::CreateKey("FreeMoveSwitch", '1');
	}

	{
		AnimationRender = CreateRender(MegamanX4PlayRenderOrder::PLAYER);
		AnimationRender->SetScale({ 704, 704 });

		AnimationRender->CreateAnimation({ .AnimationName = "Right_Idle", .ImageName = "RightPlayerIdle.bmp", .Start = 0, .End = 5, .InterTime = 0.25f });
		AnimationRender->CreateAnimation({ .AnimationName = "Right_EnterMove", .ImageName = "RightPlayerMove.bmp", .Start = 0, .End = 2, .InterTime = 0.05f });
		AnimationRender->CreateAnimation({ .AnimationName = "Right_Move", .ImageName = "RightPlayerMove.bmp", .Start = 3, .End = 15, .InterTime = 0.05f });
		AnimationRender->CreateAnimation({ .AnimationName = "Right_JumpStart", .ImageName = "RightPlayerJump.bmp", .Start = 0, .End = 0, .InterTime = 0.05f, .Loop = false });
		AnimationRender->CreateAnimation({ .AnimationName = "Right_Jump", .ImageName = "RightPlayerJump.bmp", .Start = 1, .End = 2, .InterTime = 0.05f });
		AnimationRender->CreateAnimation({ .AnimationName = "Right_FallStart", .ImageName = "RightPlayerJump.bmp", .Start = 3, .End = 7, .InterTime = 0.05f, .Loop = false });
		AnimationRender->CreateAnimation({ .AnimationName = "Right_Fall", .ImageName = "RightPlayerJump.bmp", .Start = 8, .End = 11, .InterTime = 0.05f});
		AnimationRender->CreateAnimation({ .AnimationName = "Right_Landing", .ImageName = "RightPlayerJump.bmp", .Start = 12, .End = 13, .InterTime = 0.09f, .Loop = false });
		AnimationRender->CreateAnimation({ .AnimationName = "Right_Attack1", .ImageName = "RightPlayerAttack.bmp", .Start = 0, .End = 13, .InterTime = 0.03f,. Loop = false });
		AnimationRender->CreateAnimation({ .AnimationName = "Right_Attack2", .ImageName = "RightPlayerAttack.bmp", .Start = 19, .End = 30, .InterTime = 0.03f,. Loop = false });
		AnimationRender->CreateAnimation({ .AnimationName = "Right_Attack3", .ImageName = "RightPlayerAttack.bmp", .Start = 31, .End = 45, .InterTime = 0.03f,. Loop = false });
		AnimationRender->CreateAnimation({ .AnimationName = "Right_AttackEnd", .ImageName = "RightPlayerAttack.bmp", .Start = 14, .End = 18, .InterTime = 0.1f,. Loop = false });

		AnimationRender->CreateAnimation({ .AnimationName = "Left_Idle",      .ImageName = "LeftPlayerIdle.bmp", .Start = 0, .End = 5, .InterTime = 0.25f });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_EnterMove", .ImageName = "LeftPlayerMove.bmp", .Start = 0, .End = 2, .InterTime = 0.05f });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_Move",      .ImageName = "LeftPlayerMove.bmp", .Start = 3, .End = 15, .InterTime = 0.05f });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_JumpStart", .ImageName = "LeftPlayerJump.bmp", .Start = 0, .End = 0, .InterTime = 0.05f, .Loop = false });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_Jump",      .ImageName = "LeftPlayerJump.bmp", .Start = 1, .End = 2, .InterTime = 0.05f });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_FallStart", .ImageName = "LeftPlayerJump.bmp", .Start = 3, .End = 7, .InterTime = 0.05f, .Loop = false });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_Fall",      .ImageName = "LeftPlayerJump.bmp", .Start = 8, .End = 11, .InterTime = 0.05f });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_Landing",   .ImageName = "LeftPlayerJump.bmp", .Start = 12, .End = 13, .InterTime = 0.09f, .Loop = false });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_Attack1",   .ImageName = "LeftPlayerAttack.bmp", .Start = 0, .End = 13, .InterTime = 0.03f,. Loop = false });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_Attack2",   .ImageName = "LeftPlayerAttack.bmp", .Start = 19, .End = 30, .InterTime = 0.03f,. Loop = false });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_Attack3",   .ImageName = "LeftPlayerAttack.bmp", .Start = 31, .End = 45, .InterTime = 0.03f,. Loop = false });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_AttackEnd", .ImageName = "LeftPlayerAttack.bmp", .Start = 14, .End = 18, .InterTime = 0.1f,. Loop = false });

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