#include "test.h"
Entity* guy;
Entity* gal;
Entity* don;
SpriteAnimation walkAnim;
SpriteAnimation smokeAnim;
SpriteAnimation galAnim;
float starttime = 0.0f;
bool test = 0;
Test::Test() : Scene()
{
	GetMainCamera()->SetZoom(10);
	char canvas[]
	{
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0xf,0xf,0xf,0xf,0xf,0xf,0x0,
		0x0,0x0,0xf,0xf,0x1,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0xf,0xf,0xf,0x0,
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0x0,0x0,0xf,0xf,0x0,0x0,0x0,
		0x0,0xf,0xf,0xf,0x1,0xf,0xf,0x0,
		0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,
		0xf,0x0,0xf,0xf,0x1,0xf,0x0,0xf,
		0xf,0x0,0xf,0xf,0x1,0xf,0x0,0xf,
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0x0,0xf,0x0,0x0,
		0x0,0x0,0xf,0x0,0x0,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0x0,0xf,0xf,0x0,
	};
	char canvas2[]
	{
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0xf,0xf,0xf,0xf,0xf,0xf,0x0,
		0x0,0x0,0xf,0xf,0x1,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0xf,0xf,0xf,0x0,
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0x0,0x0,0xf,0xf,0x0,0x0,0x0,
		0x0,0xf,0xf,0xf,0x1,0xf,0xf,0x0,
		0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,
		0xf,0x0,0xf,0xf,0x1,0xf,0x0,0xf,
		0xf,0x0,0xf,0xf,0x1,0xf,0x0,0xf,
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0x0,0xf,0x0,0x0,
		0x0,0x0,0xf,0x0,0x0,0xf,0xf,0x0,
		0x0,0x0,0xf,0xf,0x0,0x0,0x0,0x0,
	};
	char canvas3[]
	{
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0xf,0xf,0xf,0xf,0xf,0xf,0x0,
		0x0,0x0,0xf,0xf,0x1,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0xf,0xf,0xf,0x0,
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0x0,0x0,0xf,0xf,0x0,0x0,0x0,
		0x0,0xf,0xf,0xf,0x1,0xf,0xf,0x0,
		0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,
		0xf,0x0,0xf,0xf,0x1,0xf,0x0,0xf,
		0xf,0x0,0xf,0xf,0x1,0xf,0x0,0xf,
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0x0,0xf,0x0,0x0,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0x0,0xf,0x0,0x0,
		0x0,0x0,0x0,0x0,0x0,0xf,0xf,0x0,
	};
	char canvas4[]
	{
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0xf,0xf,0xf,0xf,0xf,0xf,0x0,
		0x0,0x0,0xf,0xf,0x1,0xf,0x0,0x1,
		0x0,0x0,0xf,0xf,0xf,0xf,0xf,0x0,
		0x0,0x0,0xf,0xf,0xf,0xf,0xe,0xe,
		0x0,0x0,0x0,0xf,0xf,0x0,0x0,0x0,
		0x0,0xf,0xf,0xf,0x1,0xf,0xf,0x0,
		0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,
		0xf,0x0,0xf,0xf,0x1,0xf,0x0,0xf,
		0xf,0x0,0xf,0xf,0x1,0xf,0x0,0xf,
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0x0,0xf,0x0,0x0,
		0x0,0x0,0xf,0x0,0x0,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0x0,0xf,0xf,0x0,
	};
	char canvas5[]
	{
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0xf,0xf,0xf,0xf,0xf,0xf,0x1,
		0x0,0x0,0xf,0xf,0x1,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0xf,0xf,0xf,0x1,
		0x0,0x0,0xf,0xf,0xf,0xf,0xe,0xe,
		0x0,0x0,0x0,0xf,0xf,0x0,0x0,0x0,
		0x0,0xf,0xf,0xf,0x1,0xf,0xf,0x0,
		0xf,0xf,0xf,0xf,0xf,0xf,0xf,0xf,
		0xf,0x0,0xf,0xf,0x1,0xf,0x0,0xf,
		0xf,0x0,0xf,0xf,0x1,0xf,0x0,0xf,
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0x0,0xf,0x0,0x0,
		0x0,0x0,0xf,0x0,0x0,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0x0,0xf,0xf,0x0,
	};
	char galcanvas[]
	{
		0x0,0x0,0x7,0x7,0x7,0x0,0x0,0x0,
		0x0,0x7,0x0,0x7,0x7,0x7,0x0,0x0,
		0x7,0x0,0x7,0x7,0x7,0x7,0x0,0x0,
		0x7,0x7,0x7,0x7,0x1,0x7,0x0,0x0,
		0x7,0x7,0x7,0x7,0x7,0x7,0x7,0x0,
		0x7,0x0,0x7,0x7,0x7,0x7,0x0,0x0,
		0x7,0x0,0x0,0x7,0x7,0x0,0x0,0x0,
		0x0,0x7,0x7,0x7,0x7,0x7,0x7,0x0,
		0x0,0x6,0x7,0x7,0x7,0x7,0x6,0x0,
		0x0,0x0,0x6,0x7,0x7,0x6,0x0,0x0,
		0x0,0x0,0x7,0x6,0x6,0x7,0x0,0x0,
		0x0,0x7,0x7,0x7,0x7,0x7,0x7,0x0,
		0x0,0x7,0x7,0x7,0x7,0x7,0x7,0x0,
		0x7,0x7,0x7,0x7,0x7,0x7,0x7,0x7,
		0x0,0x0,0x7,0x0,0x0,0x7,0x0,0x0,
		0x0,0x0,0x7,0x7,0x0,0x7,0x7,0x0,
	};
	char galcanvas2[]
	{
		0x0,0x0,0x7,0x7,0x7,0x0,0x0,0x0,
		0x0,0x7,0x0,0x7,0x7,0x7,0x0,0x0,
		0x7,0x0,0x7,0x7,0x7,0x7,0x0,0x0,
		0x7,0x7,0x7,0x7,0x1,0x7,0x0,0x0,
		0x7,0x7,0x7,0x7,0x7,0x7,0x7,0x0,
		0x7,0x0,0x7,0x7,0x6,0x6,0x0,0x0,
		0x7,0x0,0x0,0x7,0x7,0x0,0x0,0x0,
		0x0,0x7,0x7,0x7,0x7,0x7,0x7,0x0,
		0x0,0x6,0x7,0x7,0x7,0x7,0x6,0x0,
		0x0,0x0,0x6,0x7,0x7,0x6,0x0,0x0,
		0x0,0x0,0x7,0x6,0x6,0x7,0x0,0x0,
		0x0,0x7,0x7,0x7,0x7,0x7,0x7,0x0,
		0x0,0x7,0x7,0x7,0x7,0x7,0x7,0x0,
		0x7,0x7,0x7,0x7,0x7,0x7,0x7,0x7,
		0x0,0x0,0x7,0x0,0x0,0x7,0x0,0x0,
		0x0,0x0,0x7,0x7,0x0,0x7,0x7,0x0,
	};
	char galcanvas3[]
	{
		0x0,0x0,0x7,0x7,0x7,0x0,0x0,0x0,
		0x0,0x7,0x0,0x7,0x7,0x7,0x0,0x0,
		0x7,0x0,0x7,0x7,0x7,0x7,0x0,0x0,
		0x7,0x7,0x7,0x7,0x1,0x7,0x0,0x0,
		0x7,0x7,0x7,0x6,0x7,0x7,0x7,0x0,
		0x7,0x0,0x7,0x7,0x6,0x6,0x0,0x0,
		0x7,0x0,0x0,0x7,0x7,0x0,0x0,0x0,
		0x0,0x7,0x7,0x7,0x7,0x7,0x7,0x0,
		0x0,0x6,0x7,0x7,0x7,0x7,0x6,0x0,
		0x0,0x0,0x6,0x7,0x7,0x6,0x0,0x0,
		0x0,0x0,0x7,0x6,0x6,0x7,0x0,0x0,
		0x0,0x7,0x7,0x7,0x7,0x7,0x7,0x0,
		0x0,0x7,0x7,0x7,0x7,0x7,0x7,0x0,
		0x7,0x7,0x7,0x7,0x7,0x7,0x7,0x7,
		0x0,0x0,0x7,0x0,0x0,0x7,0x0,0x0,
		0x0,0x0,0x7,0x7,0x0,0x7,0x7,0x0,
	};

	char doncanvas[]
	{
		0x0,0x0,0xd,0xd,0xd,0xd,0x0,0x0,
		0x0,0xc,0xc,0xc,0x1,0x1,0x0,0x0,
		0x0,0x0,0xd,0xd,0xc,0xc,0xc,0x0,
		0x0,0x0,0xd,0xd,0x1,0xd,0x0,0x0,
		0x0,0x0,0xd,0xd,0xd,0xd,0xd,0x0,
		0x0,0x0,0xd,0xd,0xd,0xd,0x0,0x0,
		0x0,0x0,0x0,0xd,0xd,0x0,0x0,0x0,
		0x0,0xd,0xc,0xd,0x1,0xd,0xc,0x0,
		0xd,0xd,0xd,0xc,0x1,0xc,0xd,0xd,
		0xd,0xd,0xd,0xd,0xc,0xd,0xd,0xd,
		0xd,0xd,0xd,0xd,0xc,0xd,0xd,0xd,
		0xc,0xc,0xd,0xd,0xd,0xd,0xd,0xc,
		0x0,0xd,0xd,0xd,0xd,0xd,0xd,0x0,
		0x0,0xd,0xd,0xd,0x0,0xd,0xd,0x0,
		0x0,0xd,0xd,0x0,0x0,0xd,0xd,0x0,
		0x0,0xd,0xd,0xd,0x0,0xd,0xd,0xd,
	};
	walkAnim.AddSprite(canvas, 8, 16,  0.2f);
	walkAnim.AddSprite(canvas2, 8, 16, 0.2f);
	walkAnim.AddSprite(canvas3, 8, 16, 0.2f);

	smokeAnim.AddSprite(canvas4, 8, 16, 0.1f);
	smokeAnim.AddSprite(canvas5, 8, 16, 0.1f);

	guy = new Entity;
	guy->AddComponent<Animation>();
	//guy->AddComponent<Sprite>()->SetSprite(canvas, 8, 16);
	guy->transform->position = new Vector3(16.0f, 0.0f);
	//guy->transform->rotation->z = 90.0f;
	don = new Entity;
	don->AddComponent<Sprite>()->SetSprite(doncanvas, 8, 16);
	don->RemoveComponent<Sprite>();
	don->AddComponent<Text>()->printText2D("Mario Mario",7000,5000, 5.0f, 0xd, "assets/PixelFontWide.tga");
	//don->transform->position = new Vector3(-10.0f, 0.0f);

	galAnim.AddSprite(galcanvas, 8, 16, 0.6f);
	galAnim.AddSprite(galcanvas2, 8, 16,0.6f);
	galAnim.AddSprite(galcanvas3, 8, 16,0.6f);
	galAnim.AddSprite(canvas4, 8, 16,0.6f);
	galAnim.AddSprite(canvas5, 8, 16,0.6f);
	gal = new Entity;
	int score = 5;

	//gal->AddComponent<Text>()->printText2D("Something inspiring.", 0, 0, 10);
	AddTexttoScene("hello", 0.0f, 200.0f, 0.1f, 0xb, "assets/PixelFontWide.tga");
	AddTexttoScene("hijklmnop", 0.0f, 300.0f, 0.1f, 0x4, "assets/PixelFontWide.tga");
	RemoveTextfromScene();
	gal->transform->position = new Vector3(0.0f, 0.0f);
	//guy->Addchild(gal);
	//guy->Addchild(don);
	//this->AddtoScene(gal);
	this->AddtoScene(don);
	this->AddtoScene(guy);
}

void Test::update(float deltaTime)
{
	if (GetInput()->KeyDown(KeyCode::A))
	{
		guy->GetComponent<Animation>()->PlayAnimation(&walkAnim, false,1,2);
		guy->transform->rotation->y = -180;
		guy->transform->position->x -= 0.5f;
	}
	else if (GetInput()->KeyDown(KeyCode::D))
	{
		guy->GetComponent<Animation>()->PlayAnimation(&walkAnim, false,1,2);
		guy->transform->rotation->y = 0;
		guy->transform->position->x += 0.5f;
	}
	else
	{
		guy->GetComponent<Animation>()->PlayAnimation(&walkAnim, false,0,0);
	}
	if (GetInput()->KeyPressed(KeyCode::Space))
	{
		guy->GetComponent<Animation>()->PlayAnimation(&smokeAnim, true);
	}
	if (GetInput()->KeyPressed(KeyCode::LeftControl))
	{
		guy->GetComponent<Animation>()->RemoveAnimation();
	}

	if (GetInput()->MousePressed(MouseButton::MouseLeft))
	{
		std::cout << "You pressed Left!" << std::endl;
	}
	if (GetInput()->MouseReleased(MouseButton::MouseLeft))
	{
		std::cout << "You released Left!" << std::endl;
	}
	//guy->transform->position->x += 0.5f;
	GetMainCamera()->position.x = guy->transform->position->x;
	GetMainCamera()->position.y = guy->transform->position->y;
}
