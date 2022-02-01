#include "test.h"

Entity* guy;
Entity* gal;
Entity* don;
SpriteAnimation walkAnim;
SpriteAnimation smokeAnim;
SpriteAnimation galAnim;
SpriteAnimation waveAnim;
Player* jon;
float starttime = 0.0f;
bool test = 0;
int counter = 0;
Test::Test() : Scene()
{
	//GetMainCamera()->SetZoom(10);
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
	char waveCanvas[]
	{
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0xf,0xf,0xf,0xf,0xf,0xf,0x0,
		0x0,0x0,0xf,0xf,0x1,0xf,0x0,0xf,
		0x0,0x0,0xf,0xf,0xf,0xf,0xf,0xf,
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0xf,
		0x0,0x0,0x0,0xf,0xf,0x0,0x0,0xf,
		0x0,0xf,0xf,0xf,0x1,0xf,0xf,0xf,
		0xf,0xf,0xf,0xf,0xf,0xf,0x0,0x0,
		0xf,0x0,0xf,0xf,0x1,0xf,0x0,0x0,
		0xf,0x0,0xf,0xf,0x1,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0x0,0xf,0x0,0x0,
		0x0,0x0,0xf,0x0,0x0,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0x0,0xf,0xf,0x0,
	};
	char waveCanvas2[]
	{
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0xf,0xf,0xf,0xf,0xf,0xf,0x0,
		0x0,0x0,0x0,0xf,0xf,0x0,0x0,0xf,
		0x0,0x0,0xf,0xf,0x1,0xf,0x0,0xf,
		0x0,0x0,0xf,0xf,0xf,0xf,0xf,0xf,
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0xf,
		0x0,0x0,0x0,0xf,0xf,0x0,0x0,0xf,
		0x0,0xf,0xf,0xf,0x1,0xf,0xf,0xf,
		0xf,0xf,0xf,0xf,0xf,0xf,0x0,0x0,
		0xf,0x0,0xf,0xf,0x1,0xf,0x0,0x0,
		0xf,0x0,0xf,0xf,0x1,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0x0,0xf,0x0,0x0,
		0x0,0x0,0xf,0x0,0x0,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0x0,0xf,0xf,0x0,
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
	char doncanvas1[]
	{
		0x0,0x0,0xd,0xd,0xd,0xd,0x0,0x0,
		0x0,0xc,0xc,0xc,0x1,0x1,0x0,0x0,
		0x0,0x0,0xd,0xd,0xc,0xc,0xc,0x0,
		0x0,0x0,0xd,0xd,0xd,0xd,0x0,0x0,
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
	jon = new Player();
	walkAnim.AddSprite(canvas, 8, 16,  0.2f);
	walkAnim.AddSprite(canvas2, 8, 16, 0.2f);
	walkAnim.AddSprite(canvas3, 8, 16, 0.2f);

	waveAnim.AddSprite(waveCanvas, 8, 16, 0.5f);
	waveAnim.AddSprite(waveCanvas2, 8, 16, 0.5f);

	smokeAnim.AddSprite(canvas4, 8, 16, 0.1f);
	smokeAnim.AddSprite(canvas5, 8, 16, 0.1f);

	galAnim.AddSprite(doncanvas, 8, 16, 3.0f);
	galAnim.AddSprite(doncanvas1, 8, 16, 0.1f);

	guy = new Entity;
	guy->AddComponent<Animation>();
	//guy->AddComponent<Sprite>()->SetSprite(canvas, 8, 16);
	guy->transform->position = new Vector3(0.0f, 0.0f);
	guy->transform->scale->x = 10;
	guy->transform->scale->y = 10;
	don = new Entity;
	don->AddComponent<Animation>()->PlayAnimation(&galAnim);
	don->AddComponent<Text>()->SetText("Spaghetti", 5,10,5,0xd);
	don->transform->scale->x = 10;
	don->transform->scale->y = 10;
	don->transform->position->x = -300;
	//don->AddComponent<Text>()->printText2D("Mario Mario",2,15, 5.0f, 0xd);

	//galAnim.AddSprite(galcanvas, 8, 16, 0.6f);
	//galAnim.AddSprite(galcanvas2, 8, 16,0.6f);
	//galAnim.AddSprite(galcanvas3, 8, 16,0.6f);
	//galAnim.AddSprite(canvas4, 8, 16,0.6f);
	//galAnim.AddSprite(canvas5, 8, 16,0.6f);
	this->AddtoScene(jon);
	gal = new Entity;
	gal->AddComponent<Sprite>();
	gal->transform->position->x = 500;
	this->AddtoScene(gal);

	//gal->AddComponent<Text>()->printText2D("Something inspiring.", 0, 0, 10);
	//RemoveTextfromScene();
	//gal->transform->position = new Vector3(0.0f, 0.0f);
	//guy->Addchild(gal);
	//guy->Addchild(don);
	//this->AddtoScene(gal);
	//this->AddtoScene(guy);
	ShowSlide();
}

void Test::ShowSlide()
{
	SceneTextClear();
	switch (counter)
	{
	case 0:
	{
		AddSceneText("SiroGen: Framework", 500.0f, 540.0f, 8.0f, 0xb, "Assets/LucidaConsole.tga");
		AddSceneText("Door: Simon Roeloffs", 580.0f, 500.0f, 5.0f, 0xd);
		gal->GetComponent<Sprite>()->RemoveSprite();
		break;
	}
	case 1:
		AddSceneText("Inhoud: ", 100.0f, 840.0f, 8.0f, 5);
		AddSceneText("- Korte samenvatting", 100.0f, 640.0f, 6.0f, 3, "Assets/LucidaConsole.tga");
		AddSceneText("- Wat is er nu beschikbaar?", 100.0f, 540.0f, 6.0f, 7, "Assets/LucidaConsole.tga");
		AddSceneText("- Plannen voor de toekomst.", 100.0f, 440.0f, 6.0f, 9, "Assets/LucidaConsole.tga");
		gal->GetComponent<Sprite>()->SetSprite("assets/Thinking.tga");
		AddSceneText("https://www.kindpng.com/picc/m/", 1150.0f, 190.0f, 3.0f, 14, "Assets/LucidaConsole.tga");
		AddSceneText("72-721616_question-mark-clip-art", 1150.0f, 160.0f, 3.0f, 14, "Assets/LucidaConsole.tga");
		AddSceneText("-free-clipart-images-image.png", 1150.0f, 130.0f, 3.0f, 14, "Assets/LucidaConsole.tga");
		break;
	case 2:
		AddSceneText("Korte samenvatting.", 100.0f, 940.0f, 8.0f, 11, "Assets/LucidaConsole.tga");
		AddSceneText("- Component-based", 100.0f, 640.0f, 6.0f, 13, "Assets/LucidaConsole.tga");
		AddSceneText("- Scene bevat de ", 100.0f, 540.0f, 6.0f, 15, "Assets/LucidaConsole.tga");
		AddSceneText("camera.", 190.0f, 490.0f, 6.0f, 15, "Assets/LucidaConsole.tga");
		AddSceneText("- Renderer checkt op ", 100.0f, 390.0f, 6.0f, 7, "Assets/LucidaConsole.tga");
		AddSceneText("components.", 190.0f, 340.0f, 6.0f, 7, "Assets/LucidaConsole.tga");
		gal->GetComponent<Sprite>()->SetSprite("assets/ccomponents2.tga");
		AddSceneText("https://www.merinternationalusa.com/wp-", 1000.0f, 160.0f, 3.0f, 14, "Assets/LucidaConsole.tga");
		AddSceneText("content/uploads/2016/10/ccomponents2.jpg", 1000.0f, 130.0f, 3.0f, 14, "Assets/LucidaConsole.tga");
		this->RemovefromScene(guy);
		this->RemovefromScene(don);
		break;
	case 3:
		AddSceneText("Wat is er nu beschikbaar?", 100.0f, 940.0f, 8.0f, 8, "Assets/LucidaConsole.tga");
		this->AddtoScene(guy);
		this->AddtoScene(don);
		break;
	case 4:
		this->RemovefromScene(guy);
		this->RemovefromScene(don);
		guy->transform->position->x = 0;
		AddSceneText("Plannen voor de toekomst", 100.0f, 940.0f, 8.0f, 12, "Assets/LucidaConsole.tga");
		AddSceneText("- Colliders", 100.0f, 640.0f, 6.0f, 4, "Assets/LucidaConsole.tga");
		AddSceneText("- Bugs fixen", 100.0f, 540.0f, 6.0f, 6, "Assets/LucidaConsole.tga");
		AddSceneText("- Mafia Spel", 100.0f, 440.0f, 6.0f, 8, "Assets/LucidaConsole.tga");
		gal->GetComponent<Sprite>()->SetSprite("assets/future.tga");
		AddSceneText("https://i.ytimg.com/vi/MFEw", 1150.0f, 230.0f, 3.0f, 14, "Assets/LucidaConsole.tga");
		AddSceneText("37uMQyM/maxresdefault.jpg", 1150.0f, 180.0f, 3.0f, 14, "Assets/LucidaConsole.tga");
		break;
	case 5:
		gal->GetComponent<Sprite>()->RemoveSprite();
		AddSceneText("Einde", 800.0f, 840.0f, 10.0f, 15);
		AddtoScene(guy);
		break;
	}
}

void Test::update(float deltaTime)
{
	if (GetInput()->KeyDown(KeyCode::A))
	{
		guy->GetComponent<Animation>()->PlayAnimation(&walkAnim, false,1,2);
		guy->transform->rotation->y = -180;
		guy->transform->position->x -= 300.0f * deltaTime;
	}
	else if (GetInput()->KeyDown(KeyCode::D))
	{
		guy->GetComponent<Animation>()->PlayAnimation(&walkAnim, false,1,2);
		guy->transform->rotation->y = 0;
		guy->transform->position->x += 300.0f * deltaTime;
	}
	else
	{
		guy->GetComponent<Animation>()->PlayAnimation(&walkAnim, false,0,0);
	}
	if (GetInput()->KeyPressed(KeyCode::Space))
	{
		if (counter != 5)
		{
			guy->GetComponent<Animation>()->PlayAnimation(&smokeAnim, true);
		}
		else
		{
			guy->GetComponent<Animation>()->PlayAnimation(&waveAnim, true);
		}
	}
	if (GetInput()->KeyPressed(KeyCode::P))
	{
		if (counter < 5)
		{
			counter++;
			ShowSlide();
		}
	}
	else if (GetInput()->KeyPressed(KeyCode::O))
	{
		if (counter > 0)
		{
			counter--;
			ShowSlide();
		}
	}
	if (counter == 3)
	{
		gal->transform->rotation->z += 0.5f;
	}
	else
	{
		gal->transform->rotation->z = 0.0f;
	}
	GetMainCamera()->position.x = guy->transform->position->x;
}
