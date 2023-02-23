#include "CharacterSelectUpperText.h"
#include "ContentsEnums.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>

CharacterSelectUpperText::CharacterSelectUpperText() 
{
}

CharacterSelectUpperText::~CharacterSelectUpperText() 
{
}

void CharacterSelectUpperText::Start()
{
	Render = CreateRender("PlayerSelectText.bmp", MegamanX4RenderOrder::SELECTTEXT);
	Render->SetScaleToImage();

	float4 ImageSize = Render->GetScale();
	float4 WindowSize = GameEngineWindow::GetScreenSize();
	Render->SetPosition({ WindowSize.x + (ImageSize.x / 2), 68 });
}

void CharacterSelectUpperText::Update(float _DeltaTime)
{
	Render->SetMove(float4::Left * MoveSpeed * _DeltaTime);

	float4 ImageSize = Render->GetScale();
	float4 WindowSize = GameEngineWindow::GetScreenSize();

	if (Render->GetPosition().x < -(ImageSize.x / 2))
	{
		Render->SetPosition({ WindowSize.x + (ImageSize.x / 2), 68 });
	}
}