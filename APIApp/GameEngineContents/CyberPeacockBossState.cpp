#include "CyberPeacockBoss.h"
#include <GameEngineCore/GameEngineRender.h>

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


void CyberPeacockBoss::Attack1Start()
{
	CheckTime = 0.0f;
	DirCheck("Attack1");
}

void CyberPeacockBoss::Attack1Update(float _DeltaTime)
{
	CheckTime += _DeltaTime;

	if (AnimationRender->IsAnimationEnd())
	{
		DirCheck("Attack1Loop");
	}

	if (CheckTime >= 1.0f)
	{
		DoNextPattern = true;
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
		DoNextPattern = true;
	}
}


void CyberPeacockBoss::Attack3End()
{

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
