#include "Player.h"
#include "ContentsEnums.h"
#include <GameEnginePlatform/GameEngineInput.h>

void Player::ChangeState(PlayerState _State)
{
	PlayerState NextState = _State;
	PlayerState PrevState = StateValue;

	StateValue = NextState;

	//상태가 변했을 때, 끝날 때 필요한 코드, 시작할 때 필요한 코드를 출력하기 위함
	switch (NextState)
	{
	case PlayerState::IDLE:
	{
		IdleStart();
		break;
	}
	case PlayerState::MOVE:
	{
		MoveStart();;
		break;
	}
	default:
		break;

	}

	switch (PrevState)
	{
	case PlayerState::IDLE:
	{
		IdleEnd();
		break;
	}
	case PlayerState::MOVE:
	{
		MoveEnd();
		break;
	}
	default:
		break;
	}
}

void Player::UpdateState(float _DeltaTime)
{
	switch (StateValue)
	{
	case PlayerState::IDLE:
	{
		IdleUpdate(_DeltaTime);
		break;
	}
	case PlayerState::MOVE:
	{
		MoveUpdate(_DeltaTime);
		break;
	}
	default:
		break;
	}
}


void Player::IdleStart()
{
	DirCheck("Idle");
}

void Player::IdleUpdate(float _DeltaTime)
{
	if (GameEngineInput::IsPress("MoveLeft") || GameEngineInput::IsPress("MoveRight"))
	{
		ChangeState(PlayerState::MOVE);
		return;
	}
}

void Player::IdleEnd()
{

}

void Player::MoveStart()
{
	//DirCheck("Move");
	FirstMoveFrame = 0;
}

void Player::MoveUpdate(float _DeltaTime)
{
	if (GameEngineInput::IsPress("MoveLeft") == false && GameEngineInput::IsPress("MoveRight") == false)
	{
		ChangeState(PlayerState::IDLE);
		return;
	}

	if (GameEngineInput::IsPress("MoveLeft"))
	{
		MoveDir = float4::Left * MoveSpeed;
	}
	else if (GameEngineInput::IsPress("MoveRight"))
	{
		MoveDir = float4::Right * MoveSpeed;
	}

	//걷기 시작할 때 구분
	if (FirstMoveFrame < 120)
	{
		++FirstMoveFrame;
		DirCheck("EnterMove");
	}
	else
	{
		DirCheck("Move");

	}

}

void Player::MoveEnd()
{

}