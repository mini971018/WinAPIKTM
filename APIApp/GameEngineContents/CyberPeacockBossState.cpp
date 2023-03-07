#include "CyberPeacockBoss.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BossTargetEffect.h"
#include "BossMissile.h"

void CyberPeacockBoss::ChangeState(CyberPeacockState _State)
{
	CyberPeacockState NextState = _State;
	CyberPeacockState PrevState = StateValue;

	StateValue = NextState;

	//상태가 변했을 때, 끝날 때 필요한 코드, 시작할 때 필요한 코드를 출력하기 위함
	switch (NextState)
	{
	case CyberPeacockState::STARTANIMATION:
	{
		StartAnimationStart();
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
	case CyberPeacockState::STARTANIMATION:
	{
		StartAnimationEnd();
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

void CyberPeacockBoss::UpdateState(float _DeltaTime)
{
	switch (StateValue)
	{
	case CyberPeacockState::STARTANIMATION:
	{
		StartAnimationUpdate(_DeltaTime);
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

void CyberPeacockBoss::StartAnimationStart()
{
	AnimationRender->ChangeAnimation("StartAnim");
}

void CyberPeacockBoss::StartAnimationUpdate(float _DeltaTime)
{
	if (AnimationRender->IsAnimationEnd())
	{
		DoNextPattern = true;
	}
}

void CyberPeacockBoss::StartAnimationEnd()
{

}


void CyberPeacockBoss::DisAppear1Start()
{
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

}


void CyberPeacockBoss::DisAppear2Start()
{
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

}


void CyberPeacockBoss::DisAppear3Start()
{
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

}


void CyberPeacockBoss::AppearStart()
{
	SetBossPos(100.0f);
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

}

void CyberPeacockBoss::Attack3AppearStart()
{
	SetBossPosInAttack3();
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

}



void CyberPeacockBoss::Attack1Start()
{
	CheckTime = 0.0f;
	CheckBool = false;
	DirCheck("Attack1");
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

}


void CyberPeacockBoss::Attack2Start()
{
	DirCheck("Attack2");
}

void CyberPeacockBoss::Attack2Update(float _DeltaTime)
{
	if (AnimationRender->IsAnimationEnd())
	{
		DoNextPattern = true;
	}
}

void CyberPeacockBoss::Attack2End()
{

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
	CheckTime = 0.0f;
	MissileCount = 0;
	MissileCalTime = 0.0f;
}
void CyberPeacockBoss::Attack3TargetMissileUpdate(float _DeltaTime)
{
	CheckTime += _DeltaTime;
	MissileCalTime += _DeltaTime;

	if (CheckTime > 12.5f)
	{
		DoNextPattern = true;
	}

	if (MissileCalTime > MissileRateTime && MissileCount <= 6)
	{
		DirCheck("Attack3Missile");
		BossMissile* CurrentMissile = GetBossMissile();

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
		}


		CurrentMissile->BossMissileOn();
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
	AnimationRender->ChangeAnimation("Dead");
}

void CyberPeacockBoss::DeadUpdate(float _DeltaTime)
{

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

	if (CheckTime >= 0.35f)
	{
		DoNextPattern = true;
	}
}


void CyberPeacockBoss::WaitASecondInAttackEnd()
{

}
