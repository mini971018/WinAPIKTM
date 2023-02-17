#pragma once
#include <GameEngineCore/GameEngineActor.h>

// ���� : Ÿ��Ʋ ȭ�鿡 �����Ÿ��� �ִϸ��̼��� �ִ� ��ŸƮ �ȳ� ������Ʈ
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

