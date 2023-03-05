#include "CyberPeacockBoss.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "ContentsEnums.h"
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <vector>


CyberPeacockBoss::CyberPeacockBoss() 
{
}

CyberPeacockBoss::~CyberPeacockBoss() 
{
}

void CyberPeacockBoss::Start()
{
	SetMove(GameEngineWindow::GetScreenSize().half());

	GameEngineInput::CreateKey("TestButton1", '1');
	GameEngineInput::CreateKey("TestButton2", '2');
	GameEngineInput::CreateKey("TestButton3", '3');
	GameEngineInput::CreateKey("TestButton4", '4');
	GameEngineInput::CreateKey("TestButton5", '5');

	AnimationRender = CreateRender(MegamanX4PlayRenderOrder::BOSS);
	AnimationRender->SetScale({ 704, 704 });
	SetPos({ 6500, 5275 });

	//시작 및 종료 애니메이션
	AnimationRender->CreateAnimation({ .AnimationName = "NoAnim", .ImageName = "LeftBossDisappear1.bmp", .Start = 13, .End = 13, .InterTime = 0.055f, .Loop = false });
	AnimationRender->CreateAnimation({ .AnimationName = "StartAnim", .ImageName = "StartAnim.bmp", .Start = 0, .End = 41, .InterTime = 0.055f, .Loop = false });

	//우측 애니메이션
	AnimationRender->CreateAnimation({ .AnimationName = "Right_Appear", .ImageName = "RightBossAppear.bmp", .Start = 0, .End = 12, .InterTime = 0.03f, .Loop = false});
	AnimationRender->CreateAnimation({ .AnimationName = "Right_Disappear", .ImageName = "RightBossDisappear1.bmp", .Start = 0, .End = 13, .InterTime = 0.03f, .Loop = false });
	AnimationRender->CreateAnimation({ .AnimationName = "Right_Attack1", .ImageName = "RightBossAttack1.bmp", .Start = 0, .End = 3, .InterTime = 0.05f, .Loop = false });
	AnimationRender->CreateAnimation({ .AnimationName = "Right_Attack1Loop", .ImageName = "RightBossAttack1.bmp", .Start = 3, .End = 6, .InterTime = 0.02f});
	AnimationRender->CreateAnimation({ .AnimationName = "Right_Attack2", .ImageName = "RightBossAttack2.bmp", .Start = 0, .End = 15, .InterTime = 0.055f, .Loop = false });
	AnimationRender->CreateAnimation({ .AnimationName = "Right_Disappear2", .ImageName = "RightBossDisappear2.bmp", .Start = 0, .End = 5, .InterTime = 0.03f, .Loop = false });
	AnimationRender->CreateAnimation({ .AnimationName = "Right_Attack3", .ImageName = "RightBossAttack3.bmp", .Start = 0, .End = 14, .InterTime = 0.09f, .Loop = false });
	AnimationRender->CreateAnimation({ .AnimationName = "Right_Attack3Missile", .ImageName = "RightBossAttack3.bmp", .Start = 14, .End = 15, .InterTime = 0.1f, .Loop = false });
	AnimationRender->CreateAnimation({ .AnimationName = "Right_Disappear3", .ImageName = "RightBossDisappear3.bmp", .Start = 0, .End = 5, .InterTime = 0.03f, .Loop = false });
	//좌측 애니메이션
	AnimationRender->CreateAnimation({ .AnimationName = "Left_Appear", .ImageName = "LeftBossAppear.bmp", .Start = 0, .End = 12, .InterTime = 0.03f,  .Loop = false });
	AnimationRender->CreateAnimation({ .AnimationName = "Left_Disappear", .ImageName = "LeftBossDisappear1.bmp", .Start = 0, .End = 13, .InterTime = 0.03f, .Loop = false });
	AnimationRender->CreateAnimation({ .AnimationName = "Left_Attack1", .ImageName = "LeftBossAttack1.bmp", .Start = 0, .End = 3, .InterTime = 0.05f, .Loop = false });
	AnimationRender->CreateAnimation({ .AnimationName = "Left_Attack1Loop", .ImageName = "LeftBossAttack1.bmp", .Start = 3, .End = 6, .InterTime = 0.02f});
	AnimationRender->CreateAnimation({ .AnimationName = "Left_Attack2", .ImageName = "LeftBossAttack2.bmp", .Start = 0, .End = 15, .InterTime = 0.055f, .Loop = false });
	AnimationRender->CreateAnimation({ .AnimationName = "Left_Disappear2", .ImageName = "LeftBossDisappear2.bmp", .Start = 0, .End = 5, .InterTime = 0.03f, .Loop = false });
	AnimationRender->CreateAnimation({ .AnimationName = "Left_Attack3", .ImageName = "LeftBossAttack3.bmp", .Start = 0, .End = 13, .InterTime = 0.09f, .Loop = false });
	AnimationRender->CreateAnimation({ .AnimationName = "Left_Attack3Missile", .ImageName = "LeftBossAttack3.bmp", .Start = 14, .End = 15, .InterTime = 0.1f, .Loop = false });
	AnimationRender->CreateAnimation({ .AnimationName = "Left_Disappear3", .ImageName = "LeftBossDisappear3.bmp", .Start = 0, .End = 5, .InterTime = 0.03f, .Loop = false });
	ChangeState(CyberPeacockState::IDLE);
	AnimationRender->ChangeAnimation("NoAnim");

	PatternList.push_back(CyberPeacockState::STARTANIMATION);
	PatternList.push_back(CyberPeacockState::DISAPPEAR1);
	PatternList.push_back(CyberPeacockState::WAITASECOND);
	BasicPatternCount = PatternList.size();
	SetRandomPattern();
}

void CyberPeacockBoss::SetRandomPattern()
{
	for (int i = 0; i < 10; ++i)
	{
		int randomInt = GameEngineRandom::MainRandom.RandomInt(0, 3);

		switch (randomInt)
		{
		case 0:
			PatternList.push_back(CyberPeacockState::APPEAR);
			PatternList.push_back(CyberPeacockState::ATTACK1);
			PatternList.push_back(CyberPeacockState::DISAPPEAR3);
			PatternList.push_back(CyberPeacockState::WAITASECOND);
			break;
		case 1:
			PatternList.push_back(CyberPeacockState::APPEAR);
			PatternList.push_back(CyberPeacockState::ATTACK2);
			PatternList.push_back(CyberPeacockState::DISAPPEAR2);
			PatternList.push_back(CyberPeacockState::WAITASECOND);
			break;
		case 2:
			PatternList.push_back(CyberPeacockState::APPEAR);
			PatternList.push_back(CyberPeacockState::ATTACK3);
			PatternList.push_back(CyberPeacockState::DISAPPEAR1);
			PatternList.push_back(CyberPeacockState::WAITASECOND);
			break;
		case 3:
			PatternList.push_back(CyberPeacockState::APPEAR);
			PatternList.push_back(CyberPeacockState::DISAPPEAR1);
			PatternList.push_back(CyberPeacockState::WAITASECOND);
			break;
		default:
			break;
		}
	}
	PatternCountSize = PatternList.size();

}

void CyberPeacockBoss::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("TestButton1"))
	{
		DoNextPattern = true;
	}

	UpdateState(_DeltaTime);
	if (DoNextPattern == true)
	{
		SetNextPattern();
	}
}

void CyberPeacockBoss::DirCheck(const std::string_view& _AnimationName)
{
	AnimationRender->ChangeAnimation(DirString + _AnimationName.data());
}

void CyberPeacockBoss::SetNextPattern()
{
	if (CurrentPatternNumber >= PatternCountSize)
	{
		CurrentPatternNumber = BasicPatternCount;
	}

	ChangeState(PatternList[CurrentPatternNumber]);
	CurrentPatternNumber++;
	DoNextPattern = false;
}

void CyberPeacockBoss::Render(float _DeltaTime)
{
	float4 NextPos = GetPos();

	HDC DoubleDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
	float4 ActorPos = NextPos - GetLevel()->GetCameraPos();

	//위치 확인용
	Rectangle(DoubleDC,
		ActorPos.ix() - 5,
		ActorPos.iy() - 5,
		ActorPos.ix() + 5,
		ActorPos.iy() + 5
	);
}