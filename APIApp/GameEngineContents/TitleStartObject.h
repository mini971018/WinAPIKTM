#pragma once
#include <GameEngineCore/GameEngineActor.h>

// 설명 : 타이틀 화면에 깜빡거리는 애니메이션이 있는 스타트 안내 오브젝트
class TitleStartObject : public GameEngineActor
{
public:
	// constrcuter destructer
	TitleStartObject();
	~TitleStartObject();

	// delete Function
	TitleStartObject(const TitleStartObject& _Other) = delete;
	TitleStartObject(TitleStartObject&& _Other) noexcept = delete;
	TitleStartObject& operator=(const TitleStartObject& _Other) = delete;
	TitleStartObject& operator=(TitleStartObject&& _Other) noexcept = delete;

protected:
	void Start() override;

private:

};

