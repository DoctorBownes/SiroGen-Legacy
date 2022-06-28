#include <SiroGen/core.h>
#include "floor.h"

int main(void)
{
	Core core;

	//Test* testScene = new Test();
	Floor* floor1 = new Floor();
	//core.Start(testScene);
	//delete testScene;
	core.Start(floor1);
	return 0;
}