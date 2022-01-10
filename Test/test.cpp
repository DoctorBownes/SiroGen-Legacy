#include "test.h"
Entity* guy;
Entity* gal;
SpriteAnimation tippinghat;
SpriteAnimation galAnim;
SpriteAnimation testAnim;
float starttime = 0.0f;
bool test = 0;
Test::Test() : Scene()
{
	GetMainCamera()->SetZoom(10);
	char canvas[]
	{
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0xe,0xe,0xe,0xe,0xe,0xe,0x0,
		0x0,0x0,0xe,0xe,0x0,0xe,0x0,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0xe,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0x0,0x0,0xe,0xe,0x0,0x0,0x0,
		0x0,0xe,0xe,0xe,0x0,0xe,0xe,0x0,
		0xe,0xe,0xe,0xe,0xe,0xe,0xe,0xe,
		0xe,0x0,0xe,0xe,0x0,0xe,0x0,0xe,
		0xe,0x0,0xe,0xe,0x0,0xe,0x0,0xe,
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0x0,0xe,0xe,0x0,0xe,0x0,0x0,
		0x0,0x0,0xe,0x0,0x0,0xe,0x0,0x0,
		0x0,0x0,0xe,0xe,0x0,0xe,0xe,0x0,
	};
	char canvas2[]
	{
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0xe,0xe,0xe,0xe,0xe,0xe,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0xe,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0x0,0x0,0xe,0xe,0x0,0x0,0x0,
		0x0,0xe,0xe,0xe,0x0,0xe,0xe,0x0,
		0xe,0xe,0xe,0xe,0xe,0xe,0xe,0xe,
		0xe,0x0,0xe,0xe,0x0,0xe,0x0,0xe,
		0xe,0x0,0xe,0xe,0x0,0xe,0x0,0xe,
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0x0,0xe,0xe,0x0,0xe,0x0,0x0,
		0x0,0x0,0xe,0x0,0x0,0xe,0x0,0x0,
		0x0,0x0,0xe,0xe,0x0,0xe,0xe,0x0,
	};
	char canvas3[]
	{
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0xe,0xe,0xe,0xe,0xe,0xe,0x0,
		0x0,0x0,0xe,0xe,0x0,0xe,0x0,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0xe,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0x0,0x0,0xe,0xe,0x0,0x0,0x0,
		0x0,0xe,0xe,0xe,0x0,0xe,0xe,0xe,
		0xe,0xe,0xe,0xe,0xe,0xe,0x0,0x0,
		0xe,0x0,0xe,0xe,0x0,0xe,0x0,0x0,
		0xe,0x0,0xe,0xe,0x0,0xe,0x0,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0x0,0xe,0xe,0x0,0xe,0x0,0x0,
		0x0,0x0,0xe,0x0,0x0,0xe,0x0,0x0,
		0x0,0x0,0xe,0xe,0x0,0xe,0xe,0x0,
	};
	char canvas4[]
	{
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0xe,0xe,0xe,0xe,0xe,0xe,0x0,
		0x0,0x0,0xe,0xe,0x0,0xe,0x0,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0xe,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0xe,
		0x0,0x0,0x0,0xe,0xe,0x0,0x0,0xe,
		0x0,0xe,0xe,0xe,0x0,0xe,0xe,0xe,
		0xe,0xe,0xe,0xe,0xe,0xe,0x0,0x0,
		0xe,0x0,0xe,0xe,0x0,0xe,0x0,0x0,
		0xe,0x0,0xe,0xe,0x0,0xe,0x0,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0x0,0xe,0xe,0x0,0xe,0x0,0x0,
		0x0,0x0,0xe,0x0,0x0,0xe,0x0,0x0,
		0x0,0x0,0xe,0xe,0x0,0xe,0xe,0x0,
	};
	char canvas5[]
	{
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0xe,0xe,0xe,0xe,0xe,0xe,0x0,
		0x0,0x0,0xe,0xe,0x0,0xe,0x0,0xe,
		0x0,0x0,0xe,0xe,0xe,0xe,0xe,0xe,
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0xe,
		0x0,0x0,0x0,0xe,0xe,0x0,0x0,0xe,
		0x0,0xe,0xe,0xe,0x0,0xe,0xe,0xe,
		0xe,0xe,0xe,0xe,0xe,0xe,0x0,0x0,
		0xe,0x0,0xe,0xe,0x0,0xe,0x0,0x0,
		0xe,0x0,0xe,0xe,0x0,0xe,0x0,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0x0,0xe,0xe,0x0,0xe,0x0,0x0,
		0x0,0x0,0xe,0x0,0x0,0xe,0x0,0x0,
		0x0,0x0,0xe,0xe,0x0,0xe,0xe,0x0,
	};
	char galcanvas[]
	{
		0x0,0x0,0x6,0x6,0x6,0x0,0x0,0x0,
		0x0,0x6,0x0,0x6,0x6,0x6,0x0,0x0,
		0x6,0x0,0x6,0x6,0x6,0x6,0x0,0x0,
		0x6,0x6,0x6,0x6,0x0,0x6,0x0,0x0,
		0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x0,
		0x6,0x0,0x6,0x6,0x6,0x6,0x0,0x0,
		0x6,0x0,0x0,0x6,0x6,0x0,0x0,0x0,
		0x0,0x6,0x6,0x6,0x6,0x6,0x6,0x0,
		0x0,0x5,0x6,0x6,0x6,0x6,0x5,0x0,
		0x0,0x0,0x5,0x6,0x6,0x5,0x0,0x0,
		0x0,0x0,0x6,0x5,0x5,0x6,0x0,0x0,
		0x0,0x6,0x6,0x6,0x6,0x6,0x6,0x0,
		0x0,0x6,0x6,0x6,0x6,0x6,0x6,0x0,
		0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,
		0x0,0x0,0x6,0x0,0x0,0x6,0x0,0x0,
		0x0,0x0,0x6,0x6,0x0,0x6,0x6,0x0,
	};
	char galcanvas2[]
	{
		0x0,0x0,0x6,0x6,0x6,0x0,0x0,0x0,
		0x0,0x6,0x0,0x6,0x6,0x6,0x0,0x0,
		0x6,0x0,0x6,0x6,0x6,0x6,0x0,0x0,
		0x6,0x6,0x6,0x6,0x0,0x6,0x0,0x0,
		0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x0,
		0x6,0x0,0x6,0x6,0x5,0x5,0x0,0x0,
		0x6,0x0,0x0,0x6,0x6,0x0,0x0,0x0,
		0x0,0x6,0x6,0x6,0x6,0x6,0x6,0x0,
		0x0,0x5,0x6,0x6,0x6,0x6,0x5,0x0,
		0x0,0x0,0x5,0x6,0x6,0x5,0x0,0x0,
		0x0,0x0,0x6,0x5,0x5,0x6,0x0,0x0,
		0x0,0x6,0x6,0x6,0x6,0x6,0x6,0x0,
		0x0,0x6,0x6,0x6,0x6,0x6,0x6,0x0,
		0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,
		0x0,0x0,0x6,0x0,0x0,0x6,0x0,0x0,
		0x0,0x0,0x6,0x6,0x0,0x6,0x6,0x0,
	};
	char galcanvas3[]
	{
		0x0,0x0,0x6,0x6,0x6,0x0,0x0,0x0,
		0x0,0x6,0x0,0x6,0x6,0x6,0x0,0x0,
		0x6,0x0,0x6,0x6,0x6,0x6,0x0,0x0,
		0x6,0x6,0x6,0x6,0x0,0x6,0x0,0x0,
		0x6,0x6,0x6,0x5,0x6,0x6,0x6,0x0,
		0x6,0x0,0x6,0x6,0x5,0x5,0x0,0x0,
		0x6,0x0,0x0,0x6,0x6,0x0,0x0,0x0,
		0x0,0x6,0x6,0x6,0x6,0x6,0x6,0x0,
		0x0,0x5,0x6,0x6,0x6,0x6,0x5,0x0,
		0x0,0x0,0x5,0x6,0x6,0x5,0x0,0x0,
		0x0,0x0,0x6,0x5,0x5,0x6,0x0,0x0,
		0x0,0x6,0x6,0x6,0x6,0x6,0x6,0x0,
		0x0,0x6,0x6,0x6,0x6,0x6,0x6,0x0,
		0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,
		0x0,0x0,0x6,0x0,0x0,0x6,0x0,0x0,
		0x0,0x0,0x6,0x6,0x0,0x6,0x6,0x0,
	};

	char testcanvas[]
	{
		0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0xe,0xe,0xe,0xe,0x0,0x0,0x0,
		0x0,0xe,0xe,0xe,0xe,0xe,0xe,0xe,
		0x0,0xe,0xe,0xe,0xe,0xe,0xe,0xe,
		0x0,0xe,0xe,0xe,0xe,0xe,0x4,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0xe,0x3,
		0x0,0x0,0x0,0xe,0xe,0xe,0xe,0x0,
		0x0,0x0,0x0,0x0,0xe,0xe,0x0,0x0,
		0x0,0x0,0x0,0xe,0xd,0xe,0xe,0x0,
		0x0,0x0,0x0,0xe,0xd,0xe,0xe,0x0,
		0x0,0x0,0x4,0xe,0xe,0xe,0xe,0x0,
		0x0,0x4,0x0,0x4,0x0,0x4,0x0,0x0,
		0x0,0x0,0x0,0x4,0x4,0x4,0x4,0x0,
	};

	char testcanvas1[]
	{
		0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0xe,0xe,0xe,0xe,0x0,0x0,0x0,
		0x0,0xe,0xe,0xe,0xe,0xe,0xe,0xe,
		0x0,0xe,0xe,0xe,0xe,0xe,0xe,0xe,
		0x0,0xe,0xe,0xe,0xe,0xe,0xe,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0xe,0x3,
		0x0,0x0,0x0,0xe,0xe,0xe,0xe,0x0,
		0x0,0x0,0x0,0x0,0xe,0xe,0x0,0x0,
		0x0,0x0,0x0,0xe,0xd,0xe,0xe,0x0,
		0x0,0x0,0x0,0xe,0xd,0xe,0xe,0x0,
		0x0,0x0,0x4,0xe,0xe,0xe,0xe,0x0,
		0x0,0x4,0x0,0x4,0x0,0x4,0x0,0x0,
		0x0,0x0,0x0,0x4,0x4,0x4,0x4,0x0,
	};

	char testcanvas2[]
	{
		0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0xe,0xe,0xe,0x0,0x0,0x0,0x0,
		0x0,0xe,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0xe,0xe,0xe,0xe,0x2,0x0,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0x3,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0x0,0x0,0xe,0xe,0x0,0x0,0x0,
		0x0,0x0,0x0,0xe,0xe,0x0,0x0,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0x0,0xe,0xd,0xe,0xe,0x0,0x0,
		0x0,0x0,0xe,0xd,0xe,0xe,0x0,0x0,
		0x0,0x0,0xe,0xd,0xe,0xe,0x0,0x0,
		0x0,0x4,0xe,0xe,0xe,0xe,0x0,0x0,
		0x4,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0x0,0x4,0x0,0x4,0x0,0x0,0x0,
		0x0,0x0,0x4,0x4,0x4,0x4,0x0,0x0,
	};

	char testcanvas3[]
	{
		0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0xe,0xe,0xe,0x0,0x0,0x0,0x0,
		0x0,0xe,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0xe,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0x3,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0x0,0x0,0xe,0xe,0x0,0x0,0x0,
		0x0,0x0,0x0,0xe,0xe,0x0,0x0,0x0,
		0x0,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0x0,0xe,0xd,0xe,0xe,0x0,0x0,
		0x0,0x0,0xe,0xd,0xe,0xe,0x0,0x0,
		0x0,0x0,0xe,0xd,0xe,0xe,0x0,0x0,
		0x0,0x4,0xe,0xe,0xe,0xe,0x0,0x0,
		0x4,0x0,0xe,0xe,0xe,0xe,0x0,0x0,
		0x0,0x0,0x4,0x0,0x4,0x0,0x0,0x0,
		0x0,0x0,0x4,0x4,0x4,0x4,0x0,0x0,
	};

	tippinghat.AddSprite(canvas2, 8, 16, 0.1f);
	tippinghat.AddSprite(canvas3, 8, 16, 0.3f);
	tippinghat.AddSprite(canvas4, 8, 16, 0.6f);
	tippinghat.AddSprite(canvas5, 8, 16, 0.9f);
	//tippinghat.ReUseSprite(2);
	//tippinghat.ReUseSprite(1);
	//tippinghat.ReUseSprite(0);

	testAnim.AddSprite(testcanvas,8,16, 3);
	testAnim.AddSprite(testcanvas1,8,16, 0.1f);

	guy = new Entity;
	guy->AddComponent<PixelSprite>()->AddSprite(canvas, 8, 16);
	guy->transform->position = new Vector3(16.0f, 0.0f, 0.0f);
	//guy->AddComponent<Animation>();

	galAnim.AddSprite(testcanvas2, 8, 16,3);
	galAnim.AddSprite(testcanvas3, 8, 16,0.1f);
	gal = new Entity;
	gal->AddComponent<Animation>()->PlayAnimation(&galAnim, true);
	gal->transform->position = new Vector3(8.0f, 0.0f, 0.0f);
	guy->Addchild(gal);
	std::cout << guy->Getchildren().size() << std::endl;
	this->Addchild(guy);
}

void Test::update(float deltaTime)
{
	//if (glfwGetTime() - starttime >= 0.5f && glfwGetTime() - starttime < 0.6f)
	//{
	//}
	//if (glfwGetTime() - starttime >= 0.6f)
	//{
	//}
	//guy->GetComponent<Animation>()->PlayAnimation(&testAnim, false);
	//guy->GetComponent<Animation>()->PlayAnimation(&tippinghat, false);
	//guy->GetComponent<Animation>()->PlayAnimation(&galAnim, false);
}
