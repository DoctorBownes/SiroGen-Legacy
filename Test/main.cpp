#include <SiroGen/core.h>
//#include "test.h"
#include "wackem.h"

int main(void)
{
	Core core;

	//Test* testScene = new Test();
	Wackem* testScene2 = new Wackem();
	//core.Start(testScene);
	//delete testScene;
	core.Start(testScene2);
	return 0;
}