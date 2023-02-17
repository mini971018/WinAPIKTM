#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class StartObject
{
public:
	// constrcuter destructer
	StartObject();
	~StartObject();

	// delete Function
	StartObject(const StartObject& _Other) = delete;
	StartObject(StartObject&& _Other) noexcept = delete;
	StartObject& operator=(const StartObject& _Other) = delete;
	StartObject& operator=(StartObject&& _Other) noexcept = delete;

protected:

private:

};

