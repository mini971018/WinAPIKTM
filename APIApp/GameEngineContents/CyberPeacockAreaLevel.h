#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineResources.h>

class Player;
class BossRoomDoor;
class PlayerHPBar;
class CyberPeacockBoss;
class CyberPeacockAreaLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	CyberPeacockAreaLevel();
	~CyberPeacockAreaLevel();

	// delete Function
	CyberPeacockAreaLevel(const CyberPeacockAreaLevel& _Other) = delete;
	CyberPeacockAreaLevel(CyberPeacockAreaLevel&& _Other) noexcept = delete;
	CyberPeacockAreaLevel& operator=(const CyberPeacockAreaLevel& _Other) = delete;
	CyberPeacockAreaLevel& operator=(CyberPeacockAreaLevel&& _Other) noexcept = delete;


protected:
	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {}
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;

private:
	Player* CyberPeacockAreaLevelPlayer = nullptr;
	CyberPeacockBoss* CyberPeacockAreaLevelBoss = nullptr;
	BossRoomDoor* Door1;
	BossRoomDoor* Door2;

	void SoundLoad();
};

