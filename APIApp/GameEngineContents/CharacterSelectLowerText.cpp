#include "CharacterSelectLowerText.h"
#include "ContentsEnums.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>

CharacterSelectLowerText::CharacterSelectLowerText() 
{
}

CharacterSelectLowerText::~CharacterSelectLowerText() 
{
}

void CharacterSelectLowerText::Start()
{
	Render = CreateRender("PlayerSelectText.bmp", MegamanX4RenderOrder::SELECTTEXT);

	float4 WindowSize = GameEngineWindow::GetScreenSize();
	Render->SetScaleToImage();
	float4 ImageSize = Render->GetScale();

	Render->SetPosition({ -(ImageSize.x / 2), (WindowSize.y - 68) });

}

void CharacterSelectLowerText::Update(float _DeltaTime)
{
	Render->SetMove(float4::Right * MoveSpeed * _DeltaTime);

	float4 WindowSize = GameEngineWindow::GetScreenSize();
	float4 ImageSize = Render->GetScale();

	if (Render->GetPosition().x > WindowSize.x + (ImageSize.x / 2))
	{
		Render->SetPosition({ -(ImageSize.x / 2), (WindowSize.y - 68) });
	}
}
