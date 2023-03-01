#pragma once
#include <GameEngineCore/GameEngineActor.h>

class TestWall : public GameEngineActor
{
public:
	// constrcuter destructer
	TestWall();
	~TestWall();

	// delete Function
	TestWall(const TestWall& _Other) = delete;
	TestWall(TestWall&& _Other) noexcept = delete;
	TestWall& operator=(const TestWall& _Other) = delete;
	TestWall& operator=(TestWall&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override {}

private:

};

