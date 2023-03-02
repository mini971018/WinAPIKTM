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

	//���°� ������ ��, ���� �� �ʿ��� �ڵ�, ������ �� �ʿ��� �ڵ带 ����ϱ� ����
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
	case PlayerState::JUMPATTACK:
	{
		JumpAttackStart();
		break;
	}
	case PlayerState::DASH:
	{
		DashStart();
		break;
	}
	case PlayerState::DASHEND:
	{
		DashEndStart();
		break;
	}
	case PlayerState::DASHJUMP:
	{
		DashJumpStart();
		break;
	}
	case PlayerState::DASHFALL:
	{
		DashFallStart();
		break;
	}
	case PlayerState::STAGESTART:
	{
		StageStartStart();
		break;
	}
	case PlayerState::STAGESTARTPOSE:
	{
		StageStartPoseStart();
		break;
	}
	case PlayerState::STAGEEND:
	{
		StageEndStart();
		break;
	}
	case PlayerState::STAGEENDPOSE:
	{
		StageEndPoseStart();
		break;
	}
	case PlayerState::WALLCLIMB:
	{
		WallClimbStart();
		break;
	}
	case PlayerState::WALLKICKJUMP:
	{
		WallKickJumpStart();
		break;
	}
	case PlayerState::WALLKICKDASHJUMP:
	{
		WallKickDashJumpStart();
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
	case PlayerState::JUMPATTACK:
	{
		JumpAttackEnd();
		break;
	}
	case PlayerState::DASH:
	{
		DashEnd();
		break;
	}
	case PlayerState::DASHEND:
	{
		DashEndEnd();
		break;
	}
	case PlayerState::DASHJUMP:
	{
		DashJumpEnd();
		break;
	}
	case PlayerState::DASHFALL:
	{
		DashFallEnd();
		break;
	}
	case PlayerState::STAGESTART:
	{
		StageStartEnd();
		break;
	}
	case PlayerState::STAGESTARTPOSE:
	{
		StageStartPoseEnd();
		break;
	}
	case PlayerState::STAGEEND:
	{
		StageEndEnd();
		break;
	}
	case PlayerState::STAGEENDPOSE:
	{
		StageEndPoseEnd();
		break;
	}
	case PlayerState::WALLCLIMB:
	{
		WallClimbEnd();
		break;
	}
	case PlayerState::WALLKICKJUMP:
	{
		WallKickJumpEnd();
		break;
	}
	case PlayerState::WALLKICKDASHJUMP:
	{
		WallKickDashJumpEnd();
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
	case PlayerState::JUMPATTACK:
	{
		JumpAttackUpdate(_DeltaTime);
		break;
	}
	case PlayerState::DASH:
	{
		DashUpdate(_DeltaTime);
		break;
	}
	case PlayerState::DASHEND:
	{
		DashEndUpdate(_DeltaTime);
		break;
	}
	case PlayerState::DASHJUMP:
	{
		DashJumpUpdate(_DeltaTime);
		break;
	}
	case PlayerState::DASHFALL:
	{
		DashFallUpdate(_DeltaTime);
		break;
	}
	case PlayerState::STAGESTART:
	{
		StageStartUpdate(_DeltaTime);
		break;
	}
	case PlayerState::STAGESTARTPOSE:
	{
		StageStartPoseUpdate(_DeltaTime);
		break;
	}
	case PlayerState::STAGEEND:
	{
		StageEndUpdate(_DeltaTime);
		break;
	}
	case PlayerState::STAGEENDPOSE:
	{
		StageEndPoseUpdate(_DeltaTime);
		break;
	}
	case PlayerState::WALLCLIMB:
	{
		WallClimbUpdate(_DeltaTime);
		break;
	}
	case PlayerState::WALLKICKJUMP:
	{
		WallKickJumpUpdate(_DeltaTime);
		break;
	}
	case PlayerState::WALLKICKDASHJUMP:
	{
		WallKickDashJumpUpdate(_DeltaTime);
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
	//���ÿ� ������ �������� ����
	if (GameEngineInput::IsPress("MoveLeft") && GameEngineInput::IsPress("MoveRight"))
	{
		return;
	}

	if (GameEngineInput::IsPress("MoveLeft") && false == LeftWallCheck)
	{
		ChangeState(PlayerState::MOVE);
		return;
	}
	if (GameEngineInput::IsPress("MoveRight") && false == RightWallCheck)
	{
		ChangeState(PlayerState::MOVE);
		return;
	}

	if (GameEngineInput::IsDown("Jump"))
	{
		if (GameEngineInput::IsPress("Dash"))
		{
			ChangeState(PlayerState::DASHJUMP);
		}
		else
		{
			ChangeState(PlayerState::JUMP);
		}
		return;
	}

	if (GameEngineInput::IsDown("Attack"))
	{
		ChangeState(PlayerState::ATTACK1);
		return;
	}

	if (GameEngineInput::IsDown("Dash"))
	{
		ChangeState(PlayerState::DASH);
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

	//���ÿ� ������ �������� ����
	if (GameEngineInput::IsPress("MoveLeft") && GameEngineInput::IsPress("MoveRight"))
	{
		ChangeState(PlayerState::IDLE);
		return;
	}

	if (GameEngineInput::IsPress("MoveLeft") == false && GameEngineInput::IsPress("MoveRight") == false)
	{
		ChangeState(PlayerState::IDLE);
		return;
	}

	if (GameEngineInput::IsDown("Dash"))
	{
		ChangeState(PlayerState::DASH);
		return;
	}

	if (GameEngineInput::IsDown("Jump"))
	{
		if (GameEngineInput::IsPress("Dash"))
		{
			ChangeState(PlayerState::DASHJUMP);
		}
		else
		{
			ChangeState(PlayerState::JUMP);
		}

		return;
	}

	if (GameEngineInput::IsDown("Attack"))
	{
		ChangeState(PlayerState::ATTACK1);
		return;
	}

	//�����̶� ������ ���� �̵��߿� ���� ������ idle���·�
	if (GameEngineInput::IsPress("MoveLeft") && LeftWallCheck == true)
	{
		ChangeState(PlayerState::IDLE);
		return;
	}

	if (GameEngineInput::IsPress("MoveRight") && RightWallCheck == true)
	{
		ChangeState(PlayerState::IDLE);
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
		return;
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
	JumpCalTime += _DeltaTime;

	if (UpperWallCheck == true)
	{
		ChangeState(PlayerState::FALL);
		return;
	}

	if (AnimationRender->IsAnimationEnd())
	{
		DirCheck("Jump");
	}

	if (JumpCalTime > MaxJumpTime || GameEngineInput::IsUp("Jump"))
	{
		ChangeState(PlayerState::FALL);
		return;
	}
	else
	{
		MoveDir += float4::Up * JumpForce;
	}

	//�����ϸ� ���� �Ǵ� ���������� ���� ���� ���� ������ ��,
	if (GameEngineInput::IsPress("MoveLeft"))
	{
		if (LeftWallCheck == true)
		{
			if (JumpCalTime > MinimumJumpTimeToClimbWall)
			{
				ChangeState(PlayerState::WALLCLIMB);
				return;
			}
		}
		else
		{
			MoveDir += float4::Left * MoveSpeed;
		}
	}
	if (GameEngineInput::IsPress("MoveRight"))
	{
		if ( RightWallCheck == true)
		{
			if (JumpCalTime > MinimumJumpTimeToClimbWall)
			{
				ChangeState(PlayerState::WALLCLIMB);
				return;
			}
		}
		else
		{
			MoveDir += float4::Right * MoveSpeed;
		}
	}

	//���� ���� ���� ��ư ������ �Ϲݰ���
	if (GameEngineInput::IsDown("Attack"))
	{
		ChangeState(PlayerState::JUMPATTACK);
		return;
	}

	//Debug�� (�����ð� Ȯ��)
	{

		std::string PlayerJumpTime = "PlayerJumpTime : ";

		PlayerJumpTime += std::to_string(JumpCalTime);

		GameEngineLevel::DebugTextPush(PlayerJumpTime);
	}
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

	//�������� ���� �Ǵ� ���������� ���� ���� ���� ������ ��,
	if (GameEngineInput::IsPress("MoveLeft"))
	{
		if (LeftWallCheck == true)
		{
			ChangeState(PlayerState::WALLCLIMB);
			return;
		}
		else
		{
			MoveDir += float4::Left * MoveSpeed;
		}
	}
	if (GameEngineInput::IsPress("MoveRight"))
	{
		if (RightWallCheck == true)
		{
			ChangeState(PlayerState::WALLCLIMB);
			return;
		}
		else
		{
			MoveDir += float4::Right * MoveSpeed;
		}
	}

	//FALL ���� ���� ��ư ������ �Ϲݰ���
	if (GameEngineInput::IsDown("Attack"))
	{
		ChangeState(PlayerState::JUMPATTACK);
		return;
	}

	//Fall ���߿� �߷�����
	MoveDir += (float4::Down * Gravity);

	if (IsGround == true)
	{
		if (GameEngineInput::IsPress("MoveLeft") || GameEngineInput::IsPress("MoveRight"))
		{
			ChangeState(PlayerState::MOVE);
			return;
		}
		else
		{
			ChangeState(PlayerState::LANDING);
			return;
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
		return;
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
		return;
	}

	if (AnimationRender->IsAnimationEnd())
	{
		ChangeState(PlayerState::ATTACKEND);
		return;
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
		return;
	}

	if (AnimationRender->IsAnimationEnd())
	{
		ChangeState(PlayerState::ATTACKEND);
		return;
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
		return;
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
		return;
	}

	if (GameEngineInput::IsPress("MoveLeft") || GameEngineInput::IsPress("MoveRight"))
	{
		ChangeState(PlayerState::MOVE);
		return;
	}
}

void Player::AttackEndEnd()
{

}



void Player::StageStartStart()
{
	DirCheck("StageStartLoopAnim");
}
void Player::StageStartUpdate(float _DeltaTime)
{
	//�������� ü������ �̵�
	MoveDir += (float4::Down * MoveSpeedInStageChange);

	if (IsGround == true)
	{
		ChangeState(PlayerState::STAGESTARTPOSE);
		return;
	}
}
void Player::StageStartEnd()
{

}



void Player::StageStartPoseStart()
{
	DirCheck("StageStartAnim");
}
void Player::StageStartPoseUpdate(float _DeltaTime)
{
	if (AnimationRender->IsAnimationEnd())
	{
		ChangeState(PlayerState::IDLE);
		return;
	}
}
void Player::StageStartPoseEnd()
{

}



void Player::StageEndStart()
{

}
void Player::StageEndUpdate(float _DeltaTime)
{

}
void Player::StageEndEnd()
{

}



void Player::StageEndPoseStart()
{

}
void Player::StageEndPoseUpdate(float _DeltaTime)
{

}
void Player::StageEndPoseEnd()
{

}

void Player::JumpAttackStart()
{
	DirCheck("JumpAttack");
}

void Player::JumpAttackUpdate(float _DeltaTime)
{
	if (AnimationRender->IsAnimationEnd())
	{
		ChangeState(PlayerState::FALL);
		return;
	}

	if (IsGround == true)
	{
		ChangeState(PlayerState::LANDING);
		return;
	}

	//JUMPATTACK ���߿� �߷�����
	MoveDir += (float4::Down * Gravity);
}

void Player::JumpAttackEnd()
{

}

void Player::DashStart()
{
	DashCalTime = 0.0f;
	DirCheck("DashStart");
	CurrentDir = DirString;
}
void Player::DashUpdate(float _DeltaTime)
{
	DashCalTime += _DeltaTime;

	if (DashCalTime >= MaxDashTime || GameEngineInput::IsUp("Dash") || CurrentDir != DirString)
	{
		ChangeState(PlayerState::DASHEND);
		return;
	}

	if (GameEngineInput::IsDown("Jump"))
	{
		ChangeState(PlayerState::DASHJUMP);
		return;
	}

	if (AnimationRender->IsAnimationEnd())
	{
		DirCheck("DashLoop");
	}

	if (DirString == "Right_")
	{
		if (RightWallCheck == true)
		{
			ChangeState(PlayerState::DASHEND);
			return;
		}
		MoveDir += float4::Right * DashSpeed;
	}
	else
	{
		if (LeftWallCheck == true)
		{
			ChangeState(PlayerState::DASHEND);
			return;
		}

		MoveDir += float4::Left * DashSpeed;
	}

}
void Player::DashEnd()
{
	
}

void Player::DashEndStart()
{
	DirCheck("DashEnd");

}
void Player::DashEndUpdate(float _DeltaTime)
{
	if (AnimationRender->IsAnimationEnd())
	{
		ChangeState(PlayerState::IDLE);
		return;
	}

	if (GameEngineInput::IsDown("Dash"))
	{
		ChangeState(PlayerState::DASH);
		return;
	}
}
void Player::DashEndEnd()
{

}

void Player::DashJumpStart()
{
	DirCheck("JumpStart");
	JumpCalTime = 0.0f;
	IsGround = false;
}
void Player::DashJumpUpdate(float _DeltaTime)
{
	JumpCalTime += _DeltaTime;

	if (UpperWallCheck == true)
	{
		ChangeState(PlayerState::FALL);
		return;
	}

	if (AnimationRender->IsAnimationEnd())
	{
		DirCheck("Jump");
	}

	if (JumpCalTime > MaxJumpTime || GameEngineInput::IsUp("Jump"))
	{
		ChangeState(PlayerState::DASHFALL);
		return;
	}
	else
	{
		MoveDir += float4::Up * JumpForce;
	}

	//�����ϸ� ���� �Ǵ� ���������� ���� ���� ���� ������ ��,
	if (GameEngineInput::IsPress("MoveLeft"))
	{
		if (LeftWallCheck == true)
		{
			if (JumpCalTime > MinimumJumpTimeToClimbWall)
			{
				ChangeState(PlayerState::WALLCLIMB);
				return;
			}
		}
		else
		{
			MoveDir += float4::Left * DashSpeed;
		}
	}
	if (GameEngineInput::IsPress("MoveRight"))
	{
		if (RightWallCheck == true)
		{
			if (JumpCalTime > MinimumJumpTimeToClimbWall)
			{
				ChangeState(PlayerState::WALLCLIMB);
				return;
			}
		}
		else
		{
			MoveDir += float4::Right * DashSpeed;
		}
	}

	//���� ���� ���� ��ư ������ �Ϲݰ���
	if (GameEngineInput::IsDown("Attack"))
	{
		ChangeState(PlayerState::JUMPATTACK);
		return;
	}

	//Debug�� (�����ð� Ȯ��)
	{
		std::string PlayerJumpTime = "PlayerJumpTime : ";

		PlayerJumpTime += std::to_string(JumpCalTime);

		GameEngineLevel::DebugTextPush(PlayerJumpTime);
	}
}
void Player::DashJumpEnd()
{

}

void Player::DashFallStart()
{
	DirCheck("FallStart");
	StartFallState = false;
}

void Player::DashFallUpdate(float _DeltaTime)
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

	//�������� ���� �Ǵ� ���������� ���� ���� ���� ������ ��,
	if (GameEngineInput::IsPress("MoveLeft"))
	{
		if (LeftWallCheck == true)
		{
			ChangeState(PlayerState::WALLCLIMB);
			return;
		}
		else
		{
			MoveDir += float4::Left * DashSpeed;
		}
	}
	if (GameEngineInput::IsPress("MoveRight"))
	{
		if (RightWallCheck == true)
		{
			ChangeState(PlayerState::WALLCLIMB);
			return;
		}
		else
		{
			MoveDir += float4::Right * DashSpeed;
		}
	}

	//FALL ���� ���� ��ư ������ �Ϲݰ���
	if (GameEngineInput::IsDown("Attack"))
	{
		ChangeState(PlayerState::JUMPATTACK);
		return;
	}

	//Fall ���߿� �߷�����
	MoveDir += (float4::Down * Gravity);

	if (IsGround == true)
	{
		if (GameEngineInput::IsPress("MoveLeft") || GameEngineInput::IsPress("MoveRight"))
		{
			ChangeState(PlayerState::MOVE);
			return;
		}
		else
		{
			ChangeState(PlayerState::LANDING);
			return;
		}
	}

}
void Player::DashFallEnd()
{
}


void Player::WallClimbStart()
{
	CurrentDir = DirString;
	DirCheck("WallClimbStart");
}
void Player::WallClimbUpdate(float _DeltaTime)
{
	if (IsGround == true)
	{
		ChangeState(PlayerState::LANDING);
		return;
	}

	if (AnimationRender->IsAnimationEnd())
	{
		DirCheck("WallClimb");
	}

	if (CurrentDir == "Left_")
	{
		if(GameEngineInput::IsUp("MoveLeft"))
		{
			DirString = "Right_";
			ChangeState(PlayerState::FALL);
			return;
		}
		if (LeftWallCheck == false)
		{
			ChangeState(PlayerState::FALL);
			return;
		}
	}
	else
	{
		if (GameEngineInput::IsUp("MoveRight"))
		{
			{
				DirString = "Left_";
				ChangeState(PlayerState::FALL);
				return;
			}
		}
		if (RightWallCheck == false)
		{
			ChangeState(PlayerState::FALL);
			return;
		}
	}


	if (GameEngineInput::IsDown("Jump"))
	{
		if (GameEngineInput::IsPress("Dash"))
		{
			ChangeState(PlayerState::WALLKICKDASHJUMP);
		}
		else
		{
			ChangeState(PlayerState::WALLKICKJUMP);
		}
		return;
	}

	//��Ÿ�� �߿� �߷�����
	MoveDir += (float4::Down * GravityInWallClimb);
}
void Player::WallClimbEnd()
{
	
}

void Player::WallKickJumpStart()
{
	DirCheck("WallKickJump");
}
void Player::WallKickJumpUpdate(float _DeltaTime)
{
	if (UpperWallCheck == true)
	{
		ChangeState(PlayerState::FALL);
		return;
	}

	if (CurrentDir == "Left_")
	{
		MoveDir += (float4::Up + float4::Right) * WallKickJumpForce;
	}
	else
	{
		MoveDir += (float4::Up + float4::Left) * WallKickJumpForce;
	}

	if (AnimationRender->IsAnimationEnd())
	{
		ChangeState(PlayerState::JUMP);
		return;
	}
}
void Player::WallKickJumpEnd()
{
}

void Player::WallKickDashJumpStart()
{
	DirCheck("WallKickJump");
}

void Player::WallKickDashJumpUpdate(float _DeltaTime)
{
	if (UpperWallCheck == true)
	{
		ChangeState(PlayerState::FALL);
		return;
	}

	if (CurrentDir == "Left_")
	{
		MoveDir += (float4::Up + float4::Right) * WallKickDashJumpForce;
	}
	else
	{
		MoveDir += (float4::Up + float4::Left) * WallKickDashJumpForce;
	}

	if (AnimationRender->IsAnimationEnd())
	{
		ChangeState(PlayerState::DASHJUMP);
		return;
	}
}

void Player::WallKickDashJumpEnd()
{

}