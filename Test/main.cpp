#include <SiroGen/core.h>
#include "test.h"
#include "testnity.h"

int main(void)
{
	Core core;

	Test* testScene = new Test();
	Testnity* testScene2 = new Testnity();
	core.Start(testScene);
	delete testScene;
	core.Start(testScene2);
	return 0;
}