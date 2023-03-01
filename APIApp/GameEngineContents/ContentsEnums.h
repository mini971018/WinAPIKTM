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
	PLAYERCHECKWALL, //플레이어가 벽을 체크하는 콜리전
	WALL, //벽 콜리전
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

