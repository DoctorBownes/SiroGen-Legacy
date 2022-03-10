#include <SiroGen/core.h>
//#include "test.h"
#include "whackem.h"

int main(void)
{
	Core core;

	//Test* testScene = new Test();
	Whackem* testScene2 = new Whackem();
	//core.Start(testScene);
	//delete testScene;
	core.Start(testScene2);
	return 0;
}