#pragma once
#include <GameEngineCore/GameEngineActor.h>

class DashEffect : public GameEngineActor
{
public:
	// constrcuter destructer
	DashEffect();
	~DashEffect();

	// delete Function
	DashEffect(const DashEffect& _Other) = delete;
	DashEffect(DashEffect&& _Other) noexcept = delete;
	DashEffect& operator=(const DashEffect& _Other) = delete;
	DashEffect& operator=(DashEffect&& _Other) noexcept = delete;
	
	void OnDashEffect(const std::string _DirString);
	void OffDashEffect();

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	void DirCheck(const std::string_view& _AnimationName);
	std::string DirString = "";
	GameEngineRender* AnimationRender = nullptr;
	bool IsOn;
};

