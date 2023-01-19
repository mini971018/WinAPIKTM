#pragma once
#include <GameEngineCore/GameEngineCore.h>

// Ό³Έν :
class MegamanX4GameCore : public GameEngineCore
{
public:
	// delete Function
	MegamanX4GameCore(const MegamanX4GameCore& _Other) = delete;
	MegamanX4GameCore(MegamanX4GameCore&& _Other) noexcept = delete;
	MegamanX4GameCore& operator=(const MegamanX4GameCore& _Other) = delete;
	MegamanX4GameCore& operator=(MegamanX4GameCore&& _Other) noexcept = delete;

	static MegamanX4GameCore& GetInst()
	{
		return Core;
	}

protected:
	void Start() override;
	void Update() override;
	void End() override;

private:
	MegamanX4GameCore();
	~MegamanX4GameCore();

	static MegamanX4GameCore Core;
};

