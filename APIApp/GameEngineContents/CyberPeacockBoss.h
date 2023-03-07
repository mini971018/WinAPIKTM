#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class CyberPeacockState
{
	IDLE,
	STARTANIMATION,
	DISAPPEAR1, // 서서 사라짐
	DISAPPEAR2, // 앉아서 사라짐
	DISAPPEAR3, // 위로 올라가며 공격후 사라짐
	APPEAR,
	ATTACK3APPEAR,
	ATTACK1,  // 날개로 위로 올라가며 공격 -> DIS3
	ATTACK2,  // 날개 펼치기 -> DIS2
	ATTACK3,  // 미사일 공격 -> DIS1
	ATTACK3TARGETMISSILE, // 어택 3 이후 타겟이펙트가 나오고, 미사일이 발사됨.
	DEAD,
	WAITASECOND,
	WAITASECONDINATTACK,
};

class BossMissile;
class BossTargetEffect;
class CyberPeacockBoss : public GameEngineActor
{
public:
	// constrcuter destructer
	CyberPeacockBoss();
	~CyberPeacockBoss();

	// delete Function
	CyberPeacockBoss(const CyberPeacockBoss& _Other) = delete;
	CyberPeacockBoss(CyberPeacockBoss&& _Other) noexcept = delete;
	CyberPeacockBoss& operator=(const CyberPeacockBoss& _Other) = delete;
	CyberPeacockBoss& operator=(CyberPeacockBoss&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;

private:
	GameEngineRender* AnimationRender = nullptr;
	std::string DirString = "Left_";
	std::vector<CyberPeacockState> PatternList; 
	void DirCheck(const std::string_view& _AnimationName);

	void ChangeState(CyberPeacockState _State);
	void UpdateState(float _Time);
	void SetRandomPattern();

	int BasicPatternCount = 0;    //처음에 기본적으로 설정되어있는 스테이트 갯수
	int PatternCountSize = 0;     //들어간 총 패턴 갯수
	int CurrentPatternNumber = 0; //현재 몇번째 상태인지
	bool DoNextPattern = false;   //다음 상태로 넘어가는지 여부
	void SetNextPattern();        //다음 상태로 넘겨줌

	//패턴 관련
	float AttackXClampDistance = 100.0f;
	float MinBossRoomX = 7832.0f;
	float MaxBossRoomX = 8755.0f;
	float FloorY = 5280.0f;
	float4 LeftMissilePos = { 8043.0f, 5120.0f };
	float4 RightMissilePos = { 8545.0f, 5120.0f };
	float Attack1Speed = 1000.0f; //Attack1 속도

	bool CheckBool = false; //애니메이션 내에서 애니메이션이 끝난 이후에 움직이는 등의 행동을 하는 bool값
	float AttackXClamp(float _PosX);
	float CheckTime = 0.0f;
	void SetBossPos(float _Value); //랜덤한 범위 안에서 보스가 나올 값이 계산되고, dir이 바뀜
	void SetBossDir(); //보스의 dir 변경

	void SetBossPosInAttack3();

	//Attack3 관련
	std::vector<float4> MissilesPos;
	BossTargetEffect* TargetEffect;
	void SetBossAttack3();
	float MissileCalTime = 0.0f;
	float MissileRateTime = 1.5f;
	size_t MissileCount = 0;

	//FSM 유한 상태 머신
	CyberPeacockState StateValue = CyberPeacockState::IDLE; //시작 전

	void StartAnimationStart();
	void StartAnimationEnd();
	void StartAnimationUpdate(float _DeltaTime);

	void DisAppear1Start();
	void DisAppear1End();
	void DisAppear1Update(float _DeltaTime);

	void DisAppear2Start();
	void DisAppear2End();
	void DisAppear2Update(float _DeltaTime);

	void DisAppear3Start();
	void DisAppear3End();
	void DisAppear3Update(float _DeltaTime);

	void AppearStart();
	void AppearEnd();
	void AppearUpdate(float _DeltaTime);

	void Attack3AppearStart();
	void Attack3AppearEnd();
	void Attack3AppearUpdate(float _DeltaTime);

	void Attack1Start();
	void Attack1End();
	void Attack1Update(float _DeltaTime);

	void Attack2Start();
	void Attack2End();
	void Attack2Update(float _DeltaTime);

	void Attack3Start();
	void Attack3End();
	void Attack3Update(float _DeltaTime);

	void Attack3TargetMissileStart();
	void Attack3TargetMissileEnd();
	void Attack3TargetMissileUpdate(float _DeltaTime);

	void DeadStart();
	void DeadEnd();
	void DeadUpdate(float _DeltaTime);

	void WaitASecondStart();
	void WaitASecondEnd();
	void WaitASecondUpdate(float _DeltaTime);

	void WaitASecondInAttackStart();
	void WaitASecondInAttackEnd();
	void WaitASecondInAttackUpdate(float _DeltaTime);
};
