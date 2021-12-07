#include <SiroGen/core.h>
#include "test.h"

int main(void)
{
	Core core;

	Test* testScene = new Test();
	core.Start(testScene);
	return 0;
}