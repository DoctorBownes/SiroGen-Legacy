#include <SiroGen/core.h>
//#include "test.h"
#include "shootout.h"

int main(void)
{
	Core core;

	//Test* testScene = new Test();
	ShootOut* Game = new ShootOut();
	//core.Start(testScene);
	//delete testScene;
	core.Start(Game);
	return 0;
}