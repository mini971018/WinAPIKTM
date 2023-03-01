#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class CyberPeacockAreaMap : public GameEngineActor
{
public:
	static CyberPeacockAreaMap* MainCyberPeacockAreaMap;

	// constrcuter destructer
	CyberPeacockAreaMap();
	~CyberPeacockAreaMap();

	// delete Function
	CyberPeacockAreaMap(const CyberPeacockAreaMap& _Other) = delete;
	CyberPeacockAreaMap(CyberPeacockAreaMap&& _Other) noexcept = delete;
	CyberPeacockAreaMap& operator=(const CyberPeacockAreaMap& _Other) = delete;
	CyberPeacockAreaMap& operator=(CyberPeacockAreaMap&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* CyberPeacockMapRender;
	GameEngineRender* CyberPeacockMapStructureRender;
	GameEngineRender* CyberPeacockMapColmapRender;

	void SwitchRenderMode();

};

