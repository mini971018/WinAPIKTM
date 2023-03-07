#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class CyberPeacockState
{
	IDLE,
	STARTANIMATION,
	DISAPPEAR1, // ���� �����
	DISAPPEAR2, // �ɾƼ� �����
	DISAPPEAR3, // ���� �ö󰡸� ������ �����
	APPEAR,
	ATTACK3APPEAR,
	ATTACK1,  // ������ ���� �ö󰡸� ���� -> DIS3
	ATTACK2,  // ���� ��ġ�� -> DIS2
	ATTACK3,  // �̻��� ���� -> DIS1
	ATTACK3TARGETMISSILE, // ���� 3 ���� Ÿ������Ʈ�� ������, �̻����� �߻��.
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

	int BasicPatternCount = 0;    //ó���� �⺻������ �����Ǿ��ִ� ������Ʈ ����
	int PatternCountSize = 0;     //�� �� ���� ����
	int CurrentPatternNumber = 0; //���� ���° ��������
	bool DoNextPattern = false;   //���� ���·� �Ѿ���� ����
	void SetNextPattern();        //���� ���·� �Ѱ���

	//���� ����
	float AttackXClampDistance = 100.0f;
	float MinBossRoomX = 7832.0f;
	float MaxBossRoomX = 8755.0f;
	float FloorY = 5280.0f;
	float4 LeftMissilePos = { 8043.0f, 5120.0f };
	float4 RightMissilePos = { 8545.0f, 5120.0f };
	float Attack1Speed = 1000.0f; //Attack1 �ӵ�

	bool CheckBool = false; //�ִϸ��̼� ������ �ִϸ��̼��� ���� ���Ŀ� �����̴� ���� �ൿ�� �ϴ� bool��
	float AttackXClamp(float _PosX);
	float CheckTime = 0.0f;
	void SetBossPos(float _Value); //������ ���� �ȿ��� ������ ���� ���� ���ǰ�, dir�� �ٲ�
	void SetBossDir(); //������ dir ����

	void SetBossPosInAttack3();

	//Attack3 ����
	std::vector<float4> MissilesPos;
	BossTargetEffect* TargetEffect;
	void SetBossAttack3();
	float MissileCalTime = 0.0f;
	float MissileRateTime = 1.5f;
	size_t MissileCount = 0;

	//FSM ���� ���� �ӽ�
	CyberPeacockState StateValue = CyberPeacockState::IDLE; //���� ��

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
