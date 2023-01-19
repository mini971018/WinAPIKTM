#include <Windows.h>
#include <GameEngineContents/MegamanX4GameCore.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	MegamanX4GameCore::GetInst().CoreStart(hInstance);
	return 1;
}