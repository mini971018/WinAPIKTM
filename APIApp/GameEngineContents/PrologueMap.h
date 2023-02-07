#pragma once
#include <GameEngineCore/GameEngineActor.h>

class GameEngineImage;
class PrologueMap : public GameEngineActor
{
public:

	static PrologueMap* MainPrologueMap;


	// constrcuter destructer
	PrologueMap();
	~PrologueMap();

	// delete Function
	PrologueMap(const PrologueMap& _Other) = delete;
	PrologueMap(PrologueMap&& _Other) noexcept = delete;
	PrologueMap& operator=(const PrologueMap& _Other) = delete;
	PrologueMap& operator=(PrologueMap&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* PrologueMapRender;
	GameEngineRender* PrologueMapStructureRender;
};

