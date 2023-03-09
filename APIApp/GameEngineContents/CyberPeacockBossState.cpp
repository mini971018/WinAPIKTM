#include "CyberPeacockBoss.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "BossTargetEffect.h"
#include "BossMissile.h"
#include "ExplosionEffect.h"
#include "Player.h"
#include "BossHPBar.h"

void CyberPeacockBoss::ChangeState(CyberPeacockState _State)
{
	CyberPeacockState NextState = _State;
	CyberPeacockState PrevState = StateValue;

	StateValue = NextState;

	//상태가 변했을 때, 끝날 때 필요한 코드, 시작할 때 필요한 코드를 출력하기 위함
	switch (NextState)
	{
	case CyberPeacockState::WARNING:
	{
		WarningStart();
		break;
	}
	case CyberPeacockState::STARTANIMATION1:
	{
		StartAnimation1Start();
		break;
	}
	case CyberPeacockState::STARTANIMATION2:
	{
		StartAnimation2Start();
		break;
	}
	case CyberPeacockState::STARTANIMATION3:
	{
		StartAnimation3Start();
		break;
	}
	case CyberPeacockState::STARTFIGHT:
	{
		StartFightStart();
		break;
	}
	case CyberPeacockState::DISAPPEAR1:
	{
		DisAppear1Start();
		break;
	}
	case CyberPeacockState::DISAPPEAR2:
	{
		DisAppear2Start();
		break;
	}
	case CyberPeacockState::DISAPPEAR3:
	{
		DisAppear3Start();
		break;
	}
	case CyberPeacockState::APPEAR:
	{
		AppearStart();
		break;
	}
	case CyberPeacockState::ATTACK3APPEAR:
	{
		Attack3AppearStart();
		break;
	}
	case CyberPeacockState::ATTACK1:
	{
		Attack1Start();
		break;
	}
	case CyberPeacockState::ATTACK2:
	{
		Attack2Start();
		break;
	}
	case CyberPeacockState::ATTACK3:
	{
		Attack3Start();
		break;
	}

	case CyberPeacockState::ATTACK3TARGETMISSILE:
	{
		Attack3TargetMissileStart();
		break;
	}

	case CyberPeacockState::DEAD:
	{
		DeadStart();
		break;
	}
	case CyberPeacockState::WAITASECOND:
	{
		WaitASecondStart();
		break;
	}
	case CyberPeacockState::WAITASECONDINATTACK:
	{
		WaitASecondInAttackStart();
		break;
	}
	default:
		break;

	}

	switch (PrevState)
	{
	case CyberPeacockState::WARNING:
	{
		WarningEnd();
		break;
	}
	case CyberPeacockState::STARTANIMATION1:
	{
		StartAnimation1End();
		break;
	}
	case CyberPeacockState::STARTANIMATION2:
	{
		StartAnimation2End();
		break;
	case CyberPeacockState::STARTANIMATION3:
	{
		StartAnimation3End();
		break;
	}
	case CyberPeacockState::STARTFIGHT:
	{
		StartFightEnd();
		break;
	}
	case CyberPeacockState::DISAPPEAR1:
	{
		DisAppear1End();
		break;
	}
	case CyberPeacockState::DISAPPEAR2:
	{
		DisAppear2End();
		break;
	}
	case CyberPeacockState::DISAPPEAR3:
	{
		DisAppear3End();
		break;
	}
	case CyberPeacockState::APPEAR:
	{
		AppearEnd();
		break;
	}
	case CyberPeacockState::ATTACK3APPEAR:
	{
		Attack3AppearEnd();
		break;
	}
	case CyberPeacockState::ATTACK1:
	{
		Attack1End();
		break;
	}
	case CyberPeacockState::ATTACK2:
	{
		Attack2End();
		break;
	}
	case CyberPeacockState::ATTACK3:
	{
		Attack3End();
		break;
	}
	case CyberPeacockState::ATTACK3TARGETMISSILE:
	{
		Attack3TargetMissileEnd();
		break;
	}

	case CyberPeacockState::DEAD:
	{
		DeadEnd();
		break;
	}
	case CyberPeacockState::WAITASECOND:
	{
		WaitASecondEnd();
		break;
	}
	case CyberPeacockState::WAITASECONDINATTACK:
	{
		WaitASecondInAttackEnd();
		break;
	}
	default:
		break;
	}
	}
}

void CyberPeacockBoss::UpdateState(float _DeltaTime)
{
	switch (StateValue)
	{
	case CyberPeacockState::WARNING:
	{
		WarningUpdate(_DeltaTime);
		break;
	}
	case CyberPeacockState::STARTANIMATION1:
	{
		StartAnimation1Update(_DeltaTime);
		break;
	}
	case CyberPeacockState::STARTANIMATION2:
	{
		StartAnimation2Update(_DeltaTime);
		break;
	}
	case CyberPeacockState::STARTANIMATION3:
	{
		StartAnimation3Update(_DeltaTime);
		break;
	}
	case CyberPeacockState::STARTFIGHT:
	{
		StartFightUpdate(_DeltaTime);
		break;
	}
	case CyberPeacockState::DISAPPEAR1:
	{
		DisAppear1Update(_DeltaTime);
		break;
	}
	case CyberPeacockState::DISAPPEAR2:
	{
		DisAppear2Update(_DeltaTime);
		break;
	}
	case CyberPeacockState::DISAPPEAR3:
	{
		DisAppear3Update(_DeltaTime);
		break;
	}
	case CyberPeacockState::APPEAR:
	{
		AppearUpdate(_DeltaTime);
		break;
	}
	case CyberPeacockState::ATTACK3APPEAR:
	{
		Attack3AppearUpdate(_DeltaTime);
		break;
	}
	case CyberPeacockState::ATTACK1:
	{
		Attack1Update(_DeltaTime);
		break;
	}
	case CyberPeacockState::ATTACK2:
	{
		Attack2Update(_DeltaTime);
		break;
	}
	case CyberPeacockState::ATTACK3:
	{
		Attack3Update(_DeltaTime);
		break;
	}
	case CyberPeacockState::ATTACK3TARGETMISSILE:
	{
		Attack3TargetMissileUpdate(_DeltaTime);
		break;
	}
	case CyberPeacockState::DEAD:
	{
		DeadUpdate(_DeltaTime);
		break;
	}
	case CyberPeacockState::WAITASECOND:
	{
		WaitASecondUpdate(_DeltaTime);
		break;
	}
	case CyberPeacockState::WAITASECONDINATTACK:
	{
		WaitASecondInAttackUpdate(_DeltaTime);
		break;
	}
	default:
		break;
	}
}

void CyberPeacockBoss::WarningStart()
{
	GameEngineSoundPlayer Sound = GameEngineResources::GetInst().SoundPlayToControl("WarningSound.mp3");
	Sound.LoopCount(3);
	CheckTime = 0.0f;
}

void CyberPeacockBoss::WarningUpdate(float _DeltaTime)
{
	CheckTime += _DeltaTime;

	if (CheckTime >= 3.0f)
	{
		DoNextPattern = true;
	}
}

void CyberPeacockBoss::WarningEnd()
{

}

void CyberPeacockBoss::StartAnimation1Start()
{
	AnimationRender->ChangeAnimation("StartAnim1");
}

void CyberPeacockBoss::StartAnimation1Update(float _DeltaTime)
{
	if (AnimationRender->IsAnimationEnd())
	{
		DoNextPattern = true;
	}
}

void CyberPeacockBoss::StartAnimation1End()
{

}

void CyberPeacockBoss::StartAnimation2Start()
{
	AnimationRender->ChangeAnimation("StartAnim2");
	PlaySoundOnce("BossAnimSound.mp3");
}

void CyberPeacockBoss::StartAnimation2Update(float _DeltaTime)
{
	if (AnimationRender->IsAnimationEnd())
	{
		DoNextPattern = true;
	}
}

void CyberPeacockBoss::StartAnimation2End()
{

}

void CyberPeacockBoss::StartAnimation3Start()
{
	AnimationRender->ChangeAnimation("StartAnim3");
	PlaySoundOnce("BossAttack2Sound.mp3");
}

void CyberPeacockBoss::StartAnimation3Update(float _DeltaTime)
{
	if (AnimationRender->IsAnimationEnd())
	{
		DoNextPattern = true;
	}
}

void CyberPeacockBoss::StartAnimation3End()
{
}

void CyberPeacockBoss::StartFightStart()
{
	CheckTime = 0.0f;

}
void CyberPeacockBoss::StartFightUpdate(float _DeltaTime)
{
	CheckTime += _DeltaTime;

	if (CheckTime >= 1.0f)
	{
		DoNextPattern = true;

	}
}
void CyberPeacockBoss::StartFightEnd()
{
	BossHPBarUI->SetPos({ 2025.0f, 0.0f });
	BossHPBarUI->StartFight();
	
	Player::MainPlayer->SetBossBGM();
	Player::MainPlayer->SetInAnimationState(false);

}


void CyberPeacockBoss::DisAppear1Start()
{
	PlaySoundOnce("BossStealth.mp3");
	DirCheck("Disappear");

}



void CyberPeacockBoss::DisAppear1Update(float _DeltaTime)
{
	if (AnimationRender->IsAnimationEnd())
	{
		DoNextPattern = true;
	}
}

void CyberPeacockBoss::DisAppear1End()
{
	BossBodyCollision->Off();
}


void CyberPeacockBoss::DisAppear2Start()
{
	PlaySoundOnce("BossStealth.mp3");
	DirCheck("Disappear2");
}

void CyberPeacockBoss::DisAppear2Update(float _DeltaTime)
{
	if (AnimationRender->IsAnimationEnd())
	{
		DoNextPattern = true;
	}
}

void CyberPeacockBoss::DisAppear2End()
{
	BossBodyCollision->Off();
}


void CyberPeacockBoss::DisAppear3Start()
{
	PlaySoundOnce("BossStealth.mp3");
	DirCheck("Disappear3");
}

void CyberPeacockBoss::DisAppear3Update(float _DeltaTime)
{
	if (AnimationRender->IsAnimationEnd())
	{
		DoNextPattern = true;
	}
}

void CyberPeacockBoss::DisAppear3End()
{
	BossBodyCollision->Off();
}


void CyberPeacockBoss::AppearStart()
{
	SetBossPos(100.0f);
	PlaySoundOnce("BossStealth.mp3");
	DirCheck("Appear");

}

void CyberPeacockBoss::AppearUpdate(float _DeltaTime)
{
	if (AnimationRender->IsAnimationEnd())
	{
		DoNextPattern = true;
	}
}

void CyberPeacockBoss::AppearEnd()
{
	BossBodyCollision->On();
}

void CyberPeacockBoss::Attack3AppearStart()
{
	SetBossPosInAttack3();
	PlaySoundOnce("BossStealth.mp3");
	DirCheck("Appear");

}

void CyberPeacockBoss::Attack3AppearUpdate(float _DeltaTime)
{
	if (AnimationRender->IsAnimationEnd())
	{
		DoNextPattern = true;
	}
}

void CyberPeacockBoss::Attack3AppearEnd()
{
	BossBodyCollision->On();
}



void CyberPeacockBoss::Attack1Start()
{
	CheckTime = 0.0f;
	CheckBool = false;
	DirCheck("Attack1");
	BossAttack1Collision->On();
}

void CyberPeacockBoss::Attack1Update(float _DeltaTime)
{
	CheckTime += _DeltaTime;

	if (AnimationRender->IsAnimationEnd())
	{
		DirCheck("Attack1Loop");
		CheckBool = true;
	}

	if (CheckTime >= 0.25f)
	{
		DoNextPattern = true;
	}

	if (CheckBool = true)
	{
		SetMove(float4::Up * Attack1Speed * _DeltaTime);
	}
}

void CyberPeacockBoss::Attack1End()
{
	BossAttack1Collision->Off();
}


void CyberPeacockBoss::Attack2Start()
{
	DirCheck("Attack2");
	PlaySoundOnce("BossAttack2Sound.mp3");

	CalTime = 0.0f;
}

void CyberPeacockBoss::Attack2Update(float _DeltaTime)
{
	CalTime += _DeltaTime;

	if (CalTime >= 0.4f)
	{
		BossAttack2_1Collision->On();
		BossAttack2_2Collision->On();
		BossAttack2_3Collision->On();
		BossAttack2_4Collision->On();
	}

	if (AnimationRender->IsAnimationEnd())
	{
		DoNextPattern = true;
	}

	
}

void CyberPeacockBoss::Attack2End()
{
	BossAttack2_1Collision->Off();
	BossAttack2_2Collision->Off();
	BossAttack2_3Collision->Off();
	BossAttack2_4Collision->Off();
}


void CyberPeacockBoss::Attack3Start()
{
	DirCheck("Attack3");
}

void CyberPeacockBoss::Attack3Update(float _DeltaTime)
{
	if (AnimationRender->IsAnimationEnd())
	{
		if (DirString == "Left_")
		{
			TargetEffect->SetPos({8477, 4958});
		}
		else
		{
			TargetEffect->SetPos({ 8112, 4958 });
		}
		TargetEffect->TargetEffectOn();
		DoNextPattern = true;
	}

}

void CyberPeacockBoss::Attack3End()
{

}

void CyberPeacockBoss::Attack3TargetMissileStart()
{
	PlaySoundOnce("TargetSound.mp3");
	CheckTime = 0.0f;
	MissileCount = 0;
	MissileCalTime = 0.0f;
}
void CyberPeacockBoss::Attack3TargetMissileUpdate(float _DeltaTime)
{
	CheckTime += _DeltaTime;
	MissileCalTime += _DeltaTime;

	if (CheckTime > 16.5f)
	{
		DoNextPattern = true;
	}

	if (MissileCalTime > MissileRateTime && MissileCount <= 6)
	{
		DirCheck("Attack3Missile");
		BossMissile* CurrentMissile = GetLevel()->CreateActor<BossMissile>();

		float4 LeftUpUp = float4::Left + (float4::Up * 2);
		float4 LeftUpLow = (float4::Left * 2) + float4::Up;
		float4 RightUpUp = float4::Right + (float4::Up * 2);
		float4 RightUpLow = (float4::Right) * 2 + float4::Up;

		if (DirString == "Left_")
		{
			if (MissileCount < 4)
			{
				CurrentMissile->SetPos(GetPos() - MissilesPos[MissileCount]);
			}
			else
			{
				float4 Pos = { GetPos().x + MissilesPos[MissileCount].x, GetPos().y - MissilesPos[MissileCount].y };

				CurrentMissile->SetPos(Pos);
			}

			switch (MissileCount)
			{
			case 0:
				CurrentMissile->BossMissileOn(float4::Left);
				break;
			case 1:
				CurrentMissile->BossMissileOn(LeftUpLow);
				break;
			case 2:
				CurrentMissile->BossMissileOn(LeftUpUp);
				break;
			case 3:
				CurrentMissile->BossMissileOn(float4::Up);
				break;
			case 4:
				CurrentMissile->BossMissileOn(RightUpUp);
				break;
			case 5:
				CurrentMissile->BossMissileOn(float4::Right + float4::Up);
				break;
			case 6:
				CurrentMissile->BossMissileOn(RightUpLow);
				break;
			default:
				break;
			}
		}
		else
		{
			if (MissileCount < 4)
			{
				float4 Pos = { GetPos().x + MissilesPos[MissileCount].x, GetPos().y - MissilesPos[MissileCount].y };

				CurrentMissile->SetPos(Pos);
			}
			else
			{
				CurrentMissile->SetPos(GetPos() - MissilesPos[MissileCount]);
			}

			switch (MissileCount)
			{
			case 0:
				CurrentMissile->BossMissileOn(float4::Right);
				break;
			case 1:
				CurrentMissile->BossMissileOn(RightUpLow);
				break;
			case 2:
				CurrentMissile->BossMissileOn(RightUpUp);
				break;
			case 3:
				CurrentMissile->BossMissileOn(float4::Up);
				break;
			case 4:
				CurrentMissile->BossMissileOn(LeftUpUp);
				break;
			case 5:
				CurrentMissile->BossMissileOn(float4::Left + float4::Up);
				break;
			case 6:
				CurrentMissile->BossMissileOn(LeftUpLow);
				break;
			default:
				break;
			}
		}
		PlaySoundOnce("BossAttack3Sound.mp3");
		++MissileCount;
		MissileCalTime -= MissileRateTime;
	}
}
void CyberPeacockBoss::Attack3TargetMissileEnd()
{
	TargetEffect->TargetEffectOff();
}


void CyberPeacockBoss::DeadStart()
{
	DirCheck("BossDead");
	Player::MainPlayer->BossBGMStop();
}

void CyberPeacockBoss::DeadUpdate(float _DeltaTime)
{
	ExplosionCalTime += _DeltaTime;

	if (ExplosionCalTime >= 0.3f)
	{
		ExplosionEffect* Explosion = GetLevel()->CreateActor<ExplosionEffect>();
		
		float4 ExplosionCenter = { (GetPos().x), GetPos().y - 137.5f };
		float ExplosionRandomX = GameEngineRandom::MainRandom.RandomFloat(-150.0f, 150.0f);
		float ExplosionRandomY = GameEngineRandom::MainRandom.RandomFloat(-150.0f, 150.0f);

		Explosion->ExplosionEffectOn({(ExplosionCenter.x + ExplosionRandomX), (ExplosionCenter.y + ExplosionRandomY)});

		ExplosionCalTime = 0.0f;
	}

}

void CyberPeacockBoss::DeadEnd()
{

}


void CyberPeacockBoss::WaitASecondStart()
{
	CheckTime = 0.0f;
}

void CyberPeacockBoss::WaitASecondUpdate(float _DeltaTime)
{
	CheckTime += _DeltaTime;

	if (CheckTime >= 2.0f)
	{
		DoNextPattern = true;
	}
}

void CyberPeacockBoss::WaitASecondEnd()
{
}



void CyberPeacockBoss::WaitASecondInAttackStart()
{
	CheckTime = 0.0f;
}

void CyberPeacockBoss::WaitASecondInAttackUpdate(float _DeltaTime)
{
	CheckTime += _DeltaTime;

	if (CheckTime >= 0.75f)
	{
		DoNextPattern = true;
	}
}


void CyberPeacockBoss::WaitASecondInAttackEnd()
{

}
