#include "wall.h"

Wall::Wall()
{
	static char WallCanvas[]
	{
		0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,
		0xe,0xf,0xf,0xf,0xf,0xf,0xf,0x1,0xe,0xf,0xf,0xf,0xf,0xf,0xf,0x1,
		0xe,0xf,0xf,0xf,0xf,0xf,0xf,0x1,0xe,0xf,0xf,0xf,0xf,0xf,0xf,0x1,
		0xe,0xe,0xe,0xe,0xe,0xe,0xe,0x1,0xe,0xe,0xe,0xe,0xe,0xe,0xe,0x1,
		0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,
		0xf,0xf,0xf,0x1,0xe,0xf,0xf,0xf,0xf,0xf,0xf,0x1,0xe,0xf,0xf,0xf,
		0xf,0xf,0xf,0x1,0xe,0xf,0xf,0xf,0xf,0xf,0xf,0x1,0xe,0xf,0xf,0xf,
		0xe,0xe,0xe,0x1,0xe,0xe,0xe,0xe,0xe,0xe,0xe,0x1,0xe,0xe,0xe,0xe,
		0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,
		0xe,0xf,0xf,0xf,0xf,0xf,0xf,0x1,0xe,0xf,0xf,0xf,0xf,0xf,0xf,0x1,
		0xe,0xf,0xf,0xf,0xf,0xf,0xf,0x1,0xe,0xf,0xf,0xf,0xf,0xf,0xf,0x1,
		0xe,0xe,0xe,0xe,0xe,0xe,0xe,0x1,0xe,0xe,0xe,0xe,0xe,0xe,0xe,0x1,
		0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,
		0xf,0xf,0xf,0x1,0xe,0xf,0xf,0xf,0xf,0xf,0xf,0x1,0xe,0xf,0xf,0xf,
		0xf,0xf,0xf,0x1,0xe,0xf,0xf,0xf,0xf,0xf,0xf,0x1,0xe,0xf,0xf,0xf,
		0xe,0xe,0xe,0x1,0xe,0xe,0xe,0xe,0xe,0xe,0xe,0x1,0xe,0xe,0xe,0xe,
	};
	GetComponent<Sprite>()->SetSprite(WallCanvas, 16, 16);
	GetComponent<Sprite>()->blendColor = 3;
	walkable = false;
}
