#include "MegamanX4GameCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>

#include "TitleLevel.h"
#include "PlayLevel.h"

MegamanX4GameCore MegamanX4GameCore::Core;

MegamanX4GameCore::MegamanX4GameCore() 
{
}

MegamanX4GameCore::~MegamanX4GameCore() 
{
}

void MegamanX4GameCore::Start()
{
	GameEngineWindow::SettingWindowSize({ 880.0f, 660.0f });

	CreateLevel<TitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");

	ChangeLevel("Title");
}

void MegamanX4GameCore::Update()
{

}
void MegamanX4GameCore::End()
{

}
