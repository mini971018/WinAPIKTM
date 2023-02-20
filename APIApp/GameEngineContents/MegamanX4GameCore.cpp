#include "MegamanX4GameCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>

#include "TitleLevel.h"
#include "CharacterSelectLevel.h"
#include "PrologueLevel.h"
#include "CyberPeacockAreaLevel.h"
#include "MagmaDragoonAreaLevel.h"
#include "SpacePortLevel.h"

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
	CreateLevel<PrologueLevel>("Prologue");
	CreateLevel<CharacterSelectLevel>("CharacterSelect");
	CreateLevel<CyberPeacockAreaLevel>("CyberPeacockArea");
	CreateLevel<MagmaDragoonAreaLevel>("MagmaDragoonArea");
	CreateLevel<SpacePortLevel>("SpacePort");

	ChangeLevel("Title");
}

void MegamanX4GameCore::Update()
{

}
void MegamanX4GameCore::End()
{

}
