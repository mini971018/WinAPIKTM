#pragma once

enum class MegamanX4PlayRenderOrder
{
	BACKGROUND,
	MAP,
	COLMAP,
	PLAYER,
	MONSTER,
	BOSS,
	STRUCTURE
};

enum class MegamanX4RenderOrder
{
	BACKGROUND,
	SELECTTEXT,
	SELECTIMAGE,
	CHARACTERIMAGE,
	SELECTICON,
	CHARACTERMODEL,
	CHARACTERTEXT,
	GUIDEOBJECT,
};

enum class MegamanX4CollisionOrder
{
	PLAYER,
	PLAYERCHECKWALL, //�÷��̾ ���� üũ�ϴ� �ݸ���
	WALL, //�� �ݸ���
	MONSTER,
	PLAYERATTACK,
	MONSTERATTACK,
};

//enum class MegamanX4Stage
//{
//	PROLOGUE,
//	CYBERPEACOCK,
//	MAGMADRAGOONAREA,
//	SPACEPORT
//
//};

