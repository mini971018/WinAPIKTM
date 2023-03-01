#pragma once
#include <GameEngineCore/GameEngineActor.h>

class GameEngineImage;
class TestLevelMap : public GameEngineActor
{
public:

	static TestLevelMap* MainTestLevelMap;
	// constrcuter destructer
	TestLevelMap();
	~TestLevelMap();

	// delete Function
	TestLevelMap(const TestLevelMap& _Other) = delete;
	TestLevelMap(TestLevelMap&& _Other) noexcept = delete;
	TestLevelMap& operator=(const TestLevelMap& _Other) = delete;
	TestLevelMap& operator=(TestLevelMap&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override {}

private:
	GameEngineRender* TestMapRender;
};

