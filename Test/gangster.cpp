#include "gangster.h"

Gangster::Gangster()
{
	
	static char bulletcanvas1[]
	{
		0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,
		0xd,0xd,0x0,0x0,
		0x0,0x0,0x0,0x0
	};

	static char bulletcanvas2[]
	{
		0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,
		0xe,0x1,0x0,0x0,
		0x0,0x0,0x0,0x0
	};

	static char bulletcanvas3[]
	{
		0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,
		0x0,0x1,0x0,0x0,
		0x0,0x0,0x0,0x0
	};

	bulletAnim = new SpriteAnimation();
	this->bulletAnim->AddSprite(bulletcanvas1, 4, 4);
	this->bulletAnim->AddSprite(bulletcanvas2, 4, 4);
	this->bulletAnim->AddSprite(bulletcanvas3, 4, 4);

	static char doncanvas1[]
	{
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0xe,0xe,0xe,0x1,0x1,0x0,0x0,
		0x0,0x0,0xf,0xf,0xe,0xe,0xe,0x0,
		0x0,0x0,0xf,0xf,0x1,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0xf,0xf,0xf,0x0,
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0x0,0x0,0xf,0xf,0x0,0x0,0x0,
		0x0,0xf,0xe,0xf,0x1,0xf,0xe,0x0,
		0xf,0xf,0xf,0xe,0x1,0xe,0xf,0xf,
		0xf,0xf,0xf,0xf,0xe,0xf,0xf,0xf,
		0xf,0xf,0xf,0xf,0xe,0xf,0xf,0xf,
		0xe,0xe,0xf,0xf,0xf,0xf,0xf,0xe,
		0x0,0xf,0xf,0xf,0xf,0xf,0xf,0x0,
		0x0,0xf,0xf,0xf,0x0,0xf,0xf,0x0,
		0x0,0xf,0xf,0x0,0x0,0xf,0xf,0x0,
		0x0,0xf,0xf,0xf,0x0,0xf,0xf,0xf
	};

	static char doncanvas2[]
	{
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0xe,0xe,0xe,0x1,0x1,0x0,0x0,
		0x0,0x0,0xf,0xf,0xe,0xe,0xe,0x0,
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0x0,0xf,0xf,0xf,0xf,0xf,0x0,
		0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,
		0x0,0x0,0x0,0xf,0xf,0x0,0x0,0x0,
		0x0,0xf,0xe,0xf,0x1,0xf,0xe,0x0,
		0xf,0xf,0xf,0xe,0x1,0xe,0xf,0xf,
		0xf,0xf,0xf,0xf,0xe,0xf,0xf,0xf,
		0xf,0xf,0xf,0xf,0xe,0xf,0xf,0xf,
		0xe,0xe,0xf,0xf,0xf,0xf,0xf,0xe,
		0x0,0xf,0xf,0xf,0xf,0xf,0xf,0x0,
		0x0,0xf,0xf,0xf,0x0,0xf,0xf,0x0,
		0x0,0xf,0xf,0x0,0x0,0xf,0xf,0x0,
		0x0,0xf,0xf,0xf,0x0,0xf,0xf,0xf
	};

	this->blinkAnim = new SpriteAnimation();
	this->blinkAnim->AddSprite(doncanvas1, 8, 16);
	this->blinkAnim->AddSprite(doncanvas2, 8, 16);

	static char drawcanvas1[] =
	{
		0x0,0x0,0x0,0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0xe,0xe,0xe,0x1,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0x0,0xf,0xf,0xe,0xe,0xe,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0x0,0xf,0xf,0x1,0xf,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0x0,0xf,0xf,0xf,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0x0,0x0,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0xf,0xe,0xf,0x1,0xf,0xe,0xf,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0xf,0xf,0xf,0xe,0x1,0xe,0xf,0xf,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0xf,0xf,0xf,0xf,0xe,0xe,0xf,0xf,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0xf,0xf,0xf,0xf,0xe,0xe,0xf,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0xe,0xe,0xf,0xf,0xf,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0xf,0xf,0xf,0xf,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0xf,0xf,0xf,0x0,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0xf,0xf,0x0,0x0,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0xf,0xf,0xf,0x0,0xf,0xf,0xf,0x0,0x0,0x0,0x0,0x0
	};

	static char drawcanvas2[] =
	{
		0x0,0x0,0x0,0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0xe,0xe,0xe,0x1,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0x0,0xf,0xf,0xe,0xe,0xe,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0x0,0xf,0xf,0x1,0xf,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0x0,0xf,0xf,0xf,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0x0,0x0,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0xf,0xe,0xf,0x1,0xf,0xe,0xf,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0xf,0xf,0xf,0xe,0x1,0xe,0x1,0x1,0xf,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0xf,0xf,0xf,0xf,0xe,0x1,0x1,0xe,0xf,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0xf,0xf,0xf,0xf,0xe,0xf,0xf,0xe,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0xe,0xe,0xf,0xf,0xf,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0xf,0xf,0xf,0xf,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0xf,0xf,0xf,0x0,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0xf,0xf,0x0,0x0,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0xf,0xf,0xf,0x0,0xf,0xf,0xf,0x0,0x0,0x0,0x0,0x0
	};

	static char drawcanvas3[] =
	{
		0x0,0x0,0x0,0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0xe,0xe,0xe,0x1,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0x0,0xf,0xf,0xe,0xe,0xe,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0x0,0xf,0xf,0x1,0xf,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0x0,0xf,0xf,0xf,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0x0,0xf,0xf,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0x0,0x0,0xf,0xf,0x0,0x0,0x0,0x0,0x1,0x1,0x1,0x1,
		0x0,0x0,0x0,0x0,0xf,0xe,0xf,0x1,0xf,0xe,0xf,0xf,0xe,0xe,0x0,0x0,
		0x0,0x0,0x0,0xf,0xf,0xf,0xe,0x1,0xe,0xf,0xf,0xf,0xe,0x0,0x0,0x0,
		0x0,0x0,0x0,0xf,0xf,0xf,0xf,0xe,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0xf,0xf,0xf,0xf,0xe,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0xe,0xe,0xf,0xf,0xf,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0xf,0xf,0xf,0xf,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0xf,0xf,0xf,0x0,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0xf,0xf,0x0,0x0,0xf,0xf,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x0,0x0,0x0,0xf,0xf,0xf,0x0,0xf,0xf,0xf,0x0,0x0,0x0,0x0,0x0
	};

	this->drawAnim = new SpriteAnimation();
	this->drawAnim->AddSprite(drawcanvas1, 16, 16);
	this->drawAnim->AddSprite(drawcanvas2, 16, 16);
	this->drawAnim->AddSprite(drawcanvas3, 16, 16);
	this->AddComponent<Animation>()->PlayAnimation(blinkAnim);

}

Gangster::~Gangster()
{
	delete drawAnim;
	delete blinkAnim;
	delete bulletAnim;
}

void Gangster::update(float deltaTime)
{
	//if (target != nullptr)
	//{
	//	if (transform->position->DistanceBetween(target->transform->position) <= 200.0f)
	//	{
	//		drawAnim->hasPriority = true;
	//		this->GetComponent<Animation>()->PlayAnimation(drawAnim);
	//		if (GetComponent<Animation>()->isAnimationFinished())
	//		{
	//			Entity* bullet = new Entity();
	//			bullet->transform->position->x = transform->position->x + 10;
	//			bullet->transform->position->y = transform->position->y + 2;
	//			bullets.push_back(bullet);
	//			Parent->Addchild(bullet);
	//			bullet->AddComponent<Animation>()->PlayAnimation(bulletAnim);
	//		}
	//	}
	//	else
	//	{
	//		blinkAnim->hasPriority = true;
	//		this->GetComponent<Animation>()->PlayAnimation(blinkAnim);
	//	}
	//	for (int i = 0; i < bullets.size(); i++)
	//	{
	//		bullets[i]->transform->position->x += 50 * deltaTime;
	//		if (bullets[i]->GetComponent<Animation>()->frame == 2)
	//		{
	//			bullets[i]->GetComponent<Animation>()->PauseAnimation(2);
	//		}
	//	}
	//	if (transform->position->x - target->transform->position->x < 0.0f)
	//	{
	//		this->transform->rotation->y = 0;
	//	}
	//	else
	//	{
	//		this->transform->rotation->y = 180;
	//	}
	//	transform->position->MoveTowards(target->transform->position, 10.0f * deltaTime);
	//}
}

void Gangster::SetColor(uint8_t color)
{
	blinkAnim->GetArray().at(0).first->blendColor = color;
	blinkAnim->GetArray().at(1).first->blendColor = color;
	drawAnim->GetArray().at(0).first->blendColor = color;
	drawAnim->GetArray().at(1).first->blendColor = color;
	drawAnim->GetArray().at(2).first->blendColor = color;
}