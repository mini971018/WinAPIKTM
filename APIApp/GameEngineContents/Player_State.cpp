#include "Player.h"
#include "ContentsEnums.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>

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
		MoveStart();
		break;
	}
	case PlayerState::JUMP:
	{
		JumpStart();
		break;
	}
	case PlayerState::FALL:
	{
		FallStart();
		break;
	}
	case PlayerState::LANDING:
	{
		LandingStart();
		break;
	}
	case PlayerState::ATTACK1:
	{
		Attack1Start();
		break;
	}
	case PlayerState::ATTACK2:
	{
		Attack2Start();
		break;
	}
	case PlayerState::ATTACK3:
	{
		Attack3Start();
		break;
	}
	case PlayerState::ATTACKEND:
	{
		AttackEndStart();
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
	case PlayerState::JUMP:
	{
		JumpEnd();
		break;
	}
	case PlayerState::FALL:
	{
		FallEnd();
		break;
	}
	case PlayerState::LANDING:
	{
		LandingEnd();
		break;
	}
	case PlayerState::ATTACK1:
	{
		Attack1End();
		break;
	}
	case PlayerState::ATTACK2:
	{
		Attack2End();
		break;
	}
	case PlayerState::ATTACK3:
	{
		Attack3End();
		break;
	}
	case PlayerState::ATTACKEND:
	{
		AttackEndEnd();
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
	case PlayerState::JUMP:
	{
		JumpUpdate(_DeltaTime);
		break;
	}
	case PlayerState::FALL:
	{
		FallUpdate(_DeltaTime);
		break;
	}
	case PlayerState::LANDING:
	{
		LandingUpdate(_DeltaTime);
		break;
	}
	case PlayerState::ATTACK1:
	{
		Attack1Update(_DeltaTime);
		break;
	}
	case PlayerState::ATTACK2:
	{
		Attack2Update(_DeltaTime);
		break;
	}
	case PlayerState::ATTACK3:
	{
		Attack3Update(_DeltaTime);
		break;
	}
	case PlayerState::ATTACKEND:
	{
		AttackEndUpdate(_DeltaTime);
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

	if (GameEngineInput::IsDown("Jump"))
	{
		ChangeState(PlayerState::JUMP);
		return;
	}

	if (GameEngineInput::IsDown("Attack"))
	{
		ChangeState(PlayerState::ATTACK1);
		return;
	}
}

void Player::IdleEnd()
{

}

void Player::MoveStart()
{
	DirCheck("Move");
	FirstMoveFrame = 0;
}

void Player::MoveUpdate(float _DeltaTime)
{
	if (GameEngineInput::IsPress("MoveLeft") == false && GameEngineInput::IsPress("MoveRight") == false)
	{
		ChangeState(PlayerState::IDLE);
		return;
	}

	if (GameEngineInput::IsDown("Jump"))
	{
		ChangeState(PlayerState::JUMP);
		return;
	}

	if (GameEngineInput::IsDown("Attack"))
	{
		ChangeState(PlayerState::ATTACK1);
		return;
	}

	if (GameEngineInput::IsPress("MoveLeft"))
	{
		MoveDir += float4::Left * MoveSpeed;
	}
	else if (GameEngineInput::IsPress("MoveRight"))
	{
		MoveDir += float4::Right * MoveSpeed;
	}

	if (IsGround == false)
	{
		ChangeState(PlayerState::FALL);
	}


	DirCheck("Move");
}

void Player::MoveEnd()
{

}


void Player::JumpStart()
{
	DirCheck("JumpStart");
	JumpCalTime = 0.0f;
	IsGround = false;
}

void Player::JumpUpdate(float _DeltaTime)
{
	if (AnimationRender->IsAnimationEnd())
	{
		DirCheck("Jump");
	}

	if (JumpCalTime > MaxJumpTime || GameEngineInput::IsUp("Jump"))
	{
		ChangeState(PlayerState::FALL);
	}
	else
	{
		MoveDir += float4::Up * JumpForce;
	}

	if (GameEngineInput::IsPress("MoveLeft"))
	{
		MoveDir += float4::Left * MoveSpeed;
	}
	else if (GameEngineInput::IsPress("MoveRight"))
	{
		MoveDir += float4::Right * MoveSpeed;
	}

	//Debug용
	JumpCalTime += _DeltaTime;

	std::string PlayerJumpTime = "PlayerJumpTime : ";

	PlayerJumpTime += std::to_string(JumpCalTime);

	GameEngineLevel::DebugTextPush(PlayerJumpTime);
}

void Player::JumpEnd()
{

}

void Player::FallStart()
{
	DirCheck("FallStart");
	StartFallState = false;
}

void Player::FallUpdate(float _DeltaTime)
{
	if (AnimationRender->IsAnimationEnd())
	{
		StartFallState = true;
		DirCheck("Fall");
	}

	if (StartFallState == true)
	{
		DirCheck("Fall");
	}
	else
	{
		DirCheck("FallStart");
	}

	if (GameEngineInput::IsPress("MoveLeft"))
	{
		MoveDir += float4::Left * MoveSpeed;
	}
	else if (GameEngineInput::IsPress("MoveRight"))
	{
		MoveDir += float4::Right * MoveSpeed;
	}

	if (IsGround == true)
	{
		if (GameEngineInput::IsPress("MoveLeft") || GameEngineInput::IsPress("MoveRight"))
		{
			ChangeState(PlayerState::MOVE);
		}
		else
		{
			ChangeState(PlayerState::LANDING);
		}
	}
}

void Player::FallEnd()
{

}

void Player::LandingStart()
{
	DirCheck("Landing");
}

void Player::LandingUpdate(float _DeltaTime)
{
	if (AnimationRender->IsAnimationEnd())
	{
		ChangeState(PlayerState::IDLE);
	}
}

void Player::LandingEnd()
{
}

void Player::Attack1Start()
{
	DirCheck("Attack1");
}
void Player::Attack1Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("Attack"))
	{
		ChangeState(PlayerState::ATTACK2);
	}

	if (AnimationRender->IsAnimationEnd())
	{
		ChangeState(PlayerState::ATTACKEND);
	}
}
void Player::Attack1End()
{

}

void Player::Attack2Start()
{
	DirCheck("Attack2");
}
void Player::Attack2Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("Attack"))
	{
		ChangeState(PlayerState::ATTACK3);
	}

	if (AnimationRender->IsAnimationEnd())
	{
		ChangeState(PlayerState::ATTACKEND);
	}


}
void Player::Attack2End()
{

}

void Player::Attack3Start()
{
	DirCheck("Attack3");
}
void Player::Attack3Update(float _DeltaTime)
{
	if (AnimationRender->IsAnimationEnd())
	{
		ChangeState(PlayerState::ATTACKEND);
	}
}
void Player::Attack3End()
{

}

void Player::AttackEndStart()
{
	DirCheck("AttackEnd");
}

void Player::AttackEndUpdate(float _DeltaTime)
{
	if (AnimationRender->IsAnimationEnd())
	{
		ChangeState(PlayerState::IDLE);
	}

	if (GameEngineInput::IsPress("MoveLeft") || GameEngineInput::IsPress("MoveRight"))
	{
		ChangeState(PlayerState::MOVE);
	}
}

void Player::AttackEndEnd()
{

}