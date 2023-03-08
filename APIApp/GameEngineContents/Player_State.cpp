#include "Player.h"
#include "ContentsEnums.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineBase/GameEngineRandom.h>

#include "WallClimbDustEffect.h"
#include "WallKickJumpEffect.h"
#include "DashEffect.h"
#include "BossRoomDoor.h"
#include "CyberPeacockBoss.h"
#include <vector>

void Player::ChangeState(PlayerState _State)
{
	PlayerState NextState = _State;
	PlayerState PrevState = StateValue;

	CurrentState = PrevState;
	StateValue = NextState;

	//���°� ������ ��, ���� �� �ʿ��� �ڵ�, ������ �� �ʿ��� �ڵ带 ����ϱ� ����
	switch (NextState)
	{
	case PlayerState::READY:
	{
		ReadyStart();
		break;
	}
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
	case PlayerState::OPENDOOR1:
	{
		OpenDoor1Start();
		break;
	}
	case PlayerState::OPENDOOR2:
	{
		OpenDoor2Start();
		break;
	}


	default:
		break;

	}

	switch (PrevState)
	{
	case PlayerState::READY:
	{
		ReadyEnd();
		break;
	}
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
	case PlayerState::OPENDOOR1:
	{
		OpenDoor1End();
		break;
	}
	case PlayerState::OPENDOOR2:
	{
		OpenDoor2End();
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
	case PlayerState::READY:
	{
		ReadyUpdate(_DeltaTime);
		break;
	}
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
	case PlayerState::OPENDOOR1:
	{
		OpenDoor1Update(_DeltaTime);
		break;
	}
	case PlayerState::OPENDOOR2:
	{
		OpenDoor2Update(_DeltaTime);
		break;
	}


	default:
		break;
	}
}


void Player::ReadyStart()
{
	ReadyCalTime = 0.0f;
	AnimationRender->Off();
}
void Player::ReadyUpdate(float _DeltaTime)
{
	ReadyCalTime += _DeltaTime;

	if (ReadyCalTime >= 1.5f)
	{
		ChangeState(PlayerState::STAGESTART);
	}
}
void Player::ReadyEnd()
{

}

void Player::IdleStart()
{
	DirCheck("Idle");
}

void Player::IdleUpdate(float _DeltaTime)
{
	//�ƾ� �������̸� �������� ����
	if (InAnimationState == true)
	{
		return;
	}

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

	if (GameEngineInput::IsPress("MoveRight") && OpenDoorBool1 == true)
	{
		ChangeState(PlayerState::OPENDOOR1);
		return;
	}


	if (GameEngineInput::IsPress("MoveRight") && OpenDoorBool2 == true)
	{
		ChangeState(PlayerState::OPENDOOR2);
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

	if (CurrentState != PlayerState::WALLKICKJUMP && CurrentState != PlayerState::WALLKICKDASHJUMP)
	{
		GameEngineSoundPlayer JumpSound = GameEngineResources::GetInst().SoundPlayToControl("JumpSound.mp3");
		JumpSound.LoopCount(1);

		int RandomVoice = GameEngineRandom::MainRandom.RandomInt(0, 2);

		if (RandomVoice == 0)
		{
			GameEngineSoundPlayer VoiceSound = GameEngineResources::GetInst().SoundPlayToControl("Attack2.mp3");
			VoiceSound.LoopCount(1);
		}
		else if (RandomVoice == 1)
		{
			GameEngineSoundPlayer VoiceSound = GameEngineResources::GetInst().SoundPlayToControl("Jump2Voice.mp3");
			VoiceSound.LoopCount(1);
		}
		else
		{
			GameEngineSoundPlayer VoiceSound = GameEngineResources::GetInst().SoundPlayToControl("Jump3Voice.mp3");
			VoiceSound.LoopCount(1);
		}
	}
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
	GameEngineSoundPlayer AttackSound = GameEngineResources::GetInst().SoundPlayToControl("Attack1.mp3");
	AttackSound.LoopCount(1);
	GameEngineSoundPlayer BladeSound = GameEngineResources::GetInst().SoundPlayToControl("BladeSound.mp3");
	BladeSound.LoopCount(1);
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
	GameEngineSoundPlayer AttackSound = GameEngineResources::GetInst().SoundPlayToControl("Attack2.mp3");
	AttackSound.LoopCount(1);
	GameEngineSoundPlayer BladeSound = GameEngineResources::GetInst().SoundPlayToControl("BladeSound.mp3");
	BladeSound.LoopCount(1);
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
	GameEngineSoundPlayer AttackSound = GameEngineResources::GetInst().SoundPlayToControl("Attack3.mp3");
	AttackSound.LoopCount(1);
	GameEngineSoundPlayer BladeSound = GameEngineResources::GetInst().SoundPlayToControl("BladeSound.mp3");
	BladeSound.LoopCount(1);
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
	AnimationRender->On();
	DirCheck("StageStartLoopAnim");

	GameEngineSoundPlayer ReadySound = GameEngineResources::GetInst().SoundPlayToControl("PlayerStartSound.mp3");
	ReadySound.LoopCount(1);
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
	GameEngineSoundPlayer BladeSound = GameEngineResources::GetInst().SoundPlayToControl("BladeSound.mp3");
	BladeSound.LoopCount(1);
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
	PlayerDashEffect->OnDashEffect(CurrentDir);
	PlayerDashSound = GameEngineResources::GetInst().SoundPlayToControl("DashSound.mp3");
	PlayerDashSound.LoopCount(1);

	float4 MyPos = GetPos();
	float4 EffectPos = { 70.0f, 30.0f };
	if (DirString == "Left_")
	{
		PlayerDashEffect->SetPos({ MyPos.x + EffectPos.x, MyPos.y - EffectPos.y });
	}
	else
	{
		PlayerDashEffect->SetPos({ MyPos.x - EffectPos.x, MyPos.y - EffectPos.y });
	}
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
		if (OpenDoorBool1 == true)
		{
			ChangeState(PlayerState::OPENDOOR1);
			return;
		}

		if (OpenDoorBool2 == true)
		{
			ChangeState(PlayerState::OPENDOOR2);
			return;
		}

		if (RightWallCheck == true)
		{
			ChangeState(PlayerState::DASHEND);
			return;
		}

		PlayerDashEffect->SetMove(float4::Right * DashSpeed * _DeltaTime);

		MoveDir += float4::Right * DashSpeed;
	}
	else
	{
		if (LeftWallCheck == true)
		{
			ChangeState(PlayerState::DASHEND);
			return;
		}

		PlayerDashEffect->SetMove(float4::Left * DashSpeed * _DeltaTime);

		MoveDir += float4::Left * DashSpeed;
	}

}
void Player::DashEnd()
{
	PlayerDashEffect->OffDashEffect();
	PlayerDashSound.PauseOn();
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

	if (CurrentDir == "Left_")
	{
		if (LeftWallCheck == true)
		{
			return;
		}

		MoveDir += float4::Left * DashSpeed * 0.3f;
	}
	else
	{
		if (RightWallCheck == true)
		{
			return;
		}

		MoveDir += float4::Right * DashSpeed * 0.3f;
	
	}
}
void Player::DashEndEnd()
{

}

void Player::DashJumpStart()
{
	if (CurrentState != PlayerState::WALLKICKJUMP && CurrentState != PlayerState::WALLKICKDASHJUMP)
	{
		GameEngineSoundPlayer JumpSound = GameEngineResources::GetInst().SoundPlayToControl("JumpSound.mp3");
		JumpSound.LoopCount(1);

		int RandomVoice = GameEngineRandom::MainRandom.RandomInt(0, 2);

		if (RandomVoice == 0)
		{
			GameEngineSoundPlayer VoiceSound = GameEngineResources::GetInst().SoundPlayToControl("Attack2.mp3");
			VoiceSound.LoopCount(1);
		}
		else if (RandomVoice == 1)
		{
			GameEngineSoundPlayer VoiceSound = GameEngineResources::GetInst().SoundPlayToControl("Jump2Voice.mp3");
			VoiceSound.LoopCount(1);
		}
		else
		{
			GameEngineSoundPlayer VoiceSound = GameEngineResources::GetInst().SoundPlayToControl("Jump3Voice.mp3");
			VoiceSound.LoopCount(1);
		}
	}

	DirCheck("JumpStart");
	JumpCalTime = 0.0f;
	IsGround = false;
}
void Player::DashJumpUpdate(float _DeltaTime)
{
	JumpCalTime += _DeltaTime;

	if (UpperWallCheck == true)
	{
		ChangeState(PlayerState::DASHFALL);
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
	

	GameEngineSoundPlayer StickSound = GameEngineResources::GetInst().SoundPlayToControl("StickWall.mp3");
	StickSound.LoopCount(1);

	CurrentDir = DirString;
	DirCheck("WallClimbStart");
	float4 MyPos = GetPos();
	if (DirString == "Left_")
	{
		WallClimbDust->SetPos( {MyPos.x - 40, MyPos.y });
	}
	else
	{
		WallClimbDust->SetPos({ MyPos.x + 40, MyPos.y });
	}
	WallClimbDust->OnWallClimbDustEffect(DirString);
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
	//����Ʈ�� �÷��̾�� ���� �ӵ��� ������
	WallClimbDust->SetMove(float4::Down * GravityInWallClimb * _DeltaTime);
}
void Player::WallClimbEnd()
{
	WallClimbDust->OffWallClimbDustEffect();


}

void Player::WallKickJumpStart()
{
	GameEngineSoundPlayer VoiceSound = GameEngineResources::GetInst().SoundPlayToControl("Jump3Voice.mp3");
	VoiceSound.LoopCount(1);

	CurrentDir = DirString;
	DirCheck("WallKickJump");
	float4 MyPos = GetPos();
	if (DirString == "Left_")
	{
		WallKickEffect->SetPos({ MyPos.x - 40, MyPos.y - 15});
	}
	else
	{
		WallKickEffect->SetPos({ MyPos.x + 40, MyPos.y - 15 });
	}
	WallKickEffect->OnWallKickJumpEffect(CurrentDir);
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
		MoveDir += (float4::Up  + (float4::Right * 0.5f)) * WallKickJumpForce;
	}
	else
	{
		MoveDir += (float4::Up + (float4::Left * 0.5f)) * WallKickJumpForce;
	}

	if (AnimationRender->IsAnimationEnd())
	{
		ChangeState(PlayerState::JUMP);
		return;
	}
}
void Player::WallKickJumpEnd()
{
	WallKickEffect->OffWallKickJumpEffect();
}

void Player::WallKickDashJumpStart()
{
	GameEngineSoundPlayer VoiceSound = GameEngineResources::GetInst().SoundPlayToControl("Jump3Voice.mp3");
	VoiceSound.LoopCount(1);
	CurrentDir = DirString;
	DirCheck("WallKickJump");
	float4 MyPos = GetPos();
	if (DirString == "Left_")
	{
		WallKickEffect->SetPos({ MyPos.x - 40, MyPos.y - 15});
	}
	else
	{
		WallKickEffect->SetPos({ MyPos.x + 40, MyPos.y - 15});
	}
	WallKickEffect->OnWallKickJumpEffect(CurrentDir);

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
		MoveDir += (float4::Up + (float4::Right * 0.5f)) * WallKickDashJumpForce;
	}
	else
	{
		MoveDir += (float4::Up + (float4::Left * 0.5f)) * WallKickDashJumpForce;
	}

	if (AnimationRender->IsAnimationEnd())
	{
		ChangeState(PlayerState::DASHJUMP);
		return;
	}
}

void Player::WallKickDashJumpEnd()
{
	WallKickEffect->OffWallKickJumpEffect();
}


//bool OpenDoorMoveState = false; // true �� �̵�
//float OpenDoorCalTime = 0.0f; //������Ʈ�� �� ���Ǵ� �ð�
//float OpenDoorCalTime2 = 0.0f; //1�ʵ� �̵��ϴ� ���� ���Ǵ� �ð�
float4 PlayerStart;
float4 CameraStart;
float4 PlayerEnd;
float4 CameraEnd;

void Player::OpenDoor1Start()
{
	PlayerStart = GetPos();
	CameraStart = GetLevel()->GetCameraPos();
	PlayerEnd = { 7074.0f, PlayerStart.y };
	CameraEnd = { 6950.0f , CameraStart.y };
	Time = 0.0f;
	OpenDoorState = true;
	OpenDoorCalTime = 0.0f;
	OpenDoorCalTime2 = 0.0f;
	OpenDoorMoveState = false;
	Door1->Open();
	
}
void Player::OpenDoor1Update(float _DeltaTime)
{
	OpenDoorCalTime += _DeltaTime;
	OpenDoorCalTime2 += _DeltaTime;

	if (OpenDoorCalTime2 >= 1.0f && OpenDoorCalTime2 <= 3.0f)
	{
		OpenDoorMoveState = true;
	}
	else
	{
		OpenDoorMoveState = false;
	}

	if (OpenDoorMoveState == true)
	{
		Time += _DeltaTime * 0.5f;
		float4 PlayerPos = float4::LerpClamp(PlayerStart, PlayerEnd, Time);
		float4 CameraPos = float4::LerpClamp(CameraStart, CameraEnd, Time);

		if (Time >= 2.0f)
		{
			OpenDoorMoveState = false;
			Time = 0.0f;

		}

		SetPos(PlayerPos);
		GetLevel()->SetCameraPos(CameraPos);
	}

	if (OpenDoorCalTime >= 4.0f)
	{
		ChangeState(PlayerState::IDLE);

	}
}

void Player::OpenDoor1End()
{
	OpenDoorState = false;
	CameraLockState = PlayerCameraLock::CyberPeacockBossRoom2;

}

void Player::OpenDoor2Start()
{
	PlayerStart = GetPos();
	CameraStart = GetLevel()->GetCameraPos();
	PlayerEnd = { 7905.0f, PlayerStart.y };
	CameraEnd = { 7789.0f , CameraStart.y };
	Time = 0.0f;
	OpenDoorState = true;
	OpenDoorCalTime = 0.0f;
	OpenDoorCalTime2 = 0.0f;
	OpenDoorMoveState = false;
	Door2->Open();
}
void Player::OpenDoor2Update(float _DeltaTime)
{
	OpenDoorCalTime += _DeltaTime;
	OpenDoorCalTime2 += _DeltaTime;

	if (OpenDoorCalTime2 >= 1.0f && OpenDoorCalTime2 <= 3.0f)
	{
		OpenDoorMoveState = true;
	}
	else
	{
		OpenDoorMoveState = false;
	}

	if (OpenDoorMoveState == true)
	{
		Time += _DeltaTime * 0.5f;
		float4 PlayerPos = float4::LerpClamp(PlayerStart, PlayerEnd, Time);
		float4 CameraPos = float4::LerpClamp(CameraStart, CameraEnd, Time);

		if (Time >= 2.0f)
		{
			OpenDoorMoveState = false;
			Time = 0.0f;

		}

		SetPos(PlayerPos);
		GetLevel()->SetCameraPos(CameraPos);
	}

	if (OpenDoorCalTime >= 3.5f)
	{
		ChangeState(PlayerState::IDLE);
	}
}
void Player::OpenDoor2End()
{
	OpenDoorState = false;
	CameraLockState = PlayerCameraLock::CyberPeacockInBoss;
	CyberPeacockAreaBGMStop();
	InAnimationState = true;

}
