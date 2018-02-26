
#include "Game.h"
  /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#define _CRTDBG_MAP_ALLOC

#include <crtdbg.h>
#include <windows.h>
#include <tchar.h>


void StartHeapControl();

int main()
{
	StartHeapControl();
	srand(UINT(time(NULL)));

	Game game;

	game.Run();

	return 0;
}

void StartHeapControl()
{
#if defined(DEBUG) | defined(_DEBUG)
	// Notify user if heap is corrupt
	HeapSetInformation(NULL, HeapEnableTerminationOnCorruption, NULL, 0);

	// Report detected leaks when the program exits
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// Set a breakpoint on the specified object allocation order number
	//_CrtSetBreakAlloc(198);
#endif
}