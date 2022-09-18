#include "player.h"

Player::Player()
{
	walkAnim = new SpriteAnimation();

	/*static char crawler1[]
	{
		BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,
		BKG,BKG,BKG,BKG,BKG,BKG,BKG,MGA,BKG,BKG,BKG,BKG,
		BKG,BKG,BKG,BKG,BKG,BKG,MGA,VLT,BKG,BKG,BKG,BKG,
		BKG,BKG,BKG,MGA,MGA,MGA,MGA,VLT,BKG,BKG,BKG,BKG,
		BKG,BKG,BKG,JAD,JAD,MGA,VLT,VLT,BKG,BKG,BKG,BKG,
		BKG,BKG,BKG,JAD,JAD,JAD,VLT,VLT,BKG,BKG,BKG,BKG,
		BKG,BKG,JAD,WHT,WHT,JAD,VLT,JAD,JAD,BKG,BKG,BKG,
		BKG,BKG,BKG,BLU,WHT,JAD,VLT,FOR,FOR,OLV,BKG,BKG,
		BKG,BKG,JAD,FOR,JAD,JAD,VLT,FOR,FOR,FOR,BKG,BKG,
		BKG,FOR,FOR,FOR,FOR,JAD,VLT,OLV,OLV,JAD,BKG,BKG,
		JAD,FOR,FOR,FOR,JAD,JAD,JAD,JAD,JAD,JAD,JAD,BKG,
		BKG,JAD,JAD,JAD,JAD,OLV,JAD,FOR,FOR,FOR,FOR,BKG,
		BKG,BKG,JAD,JAD,OLV,OLV,JAD,JAD,OLV,OLV,OLV,BKG,
		BKG,BKG,BKG,FOR,FOR,OLV,JAD,JAD,OLV,OLV,OLV,BKG,
		BKG,BKG,BKG,FOR,BKG,BKG,JAD,JAD,MRN,MRN,MRN,BKG,
		BKG,BKG,FOR,FOR,BKG,OLV,OLV,JAD,JAD,OLV,OLV,OLV,
		BKG,BKG,FOR,BKG,BKG,BKG,OLV,OLV,OLV,OLV,OLV,BKG,
		BKG,BKG,FOR,FOR,BKG,BKG,BKG,FOR,FOR,FOR,FOR,BKG,
		BKG,BKG,BKG,FOR,BKG,BKG,BKG,FOR,JAD,FOR,FOR,BKG,
		BKG,BKG,BKG,BKG,BKG,BKG,BKG,FOR,JAD,FOR,BKG,BKG,
		BKG,BKG,BKG,BKG,BKG,BKG,FOR,FOR,JAD,BKG,BKG,BKG,
		BKG,BKG,BKG,BKG,BKG,BKG,JAD,JAD,JAD,BKG,BKG,BKG,
	};

	static char crawler2[]
	{
		BKG,BKG,BKG,BKG,BKG,BKG,BKG,MGA,BKG,BKG,BKG,BKG,
		BKG,BKG,BKG,BKG,BKG,BKG,MGA,VLT,BKG,BKG,BKG,BKG,
		BKG,BKG,BKG,MGA,MGA,MGA,MGA,VLT,BKG,BKG,BKG,BKG,
		BKG,BKG,BKG,JAD,JAD,MGA,VLT,VLT,BKG,BKG,BKG,BKG,
		BKG,BKG,BKG,JAD,JAD,VLT,VLT,VLT,BKG,BKG,BKG,BKG,
		BKG,BKG,JAD,WHT,WHT,JAD,VLT,JAD,JAD,BKG,BKG,BKG,
		BKG,BKG,BKG,BLU,WHT,JAD,VLT,FOR,FOR,BKG,BKG,BKG,
		BKG,BKG,JAD,FOR,JAD,JAD,VLT,FOR,OLV,BKG,BKG,BKG,
		BKG,FOR,FOR,FOR,FOR,JAD,VLT,OLV,OLV,OLV,BKG,BKG,
		JAD,FOR,FOR,FOR,JAD,JAD,VLT,OLV,OLV,FOR,BKG,BKG,
		BKG,JAD,JAD,JAD,JAD,OLV,VLT,OLV,OLV,JAD,JAD,BKG,
		BKG,BKG,JAD,JAD,OLV,OLV,VLT,OLV,JAD,JAD,FOR,BKG,
		BKG,BKG,BKG,VLT,OLV,OLV,OLV,OLV,JAD,FOR,BKG,BKG,
		BKG,BKG,BKG,FOR,FOR,OLV,OLV,OLV,JAD,JAD,MRN,BKG,
		BKG,BKG,JAD,FOR,BKG,BKG,MRN,MRN,JAD,JAD,OLV,BKG,
		BKG,JAD,JAD,BKG,BKG,OLV,OLV,OLV,JAD,JAD,OLV,OLV,
		JAD,JAD,BKG,JAD,BKG,BKG,OLV,OLV,OLV,JAD,JAD,BKG,
		FOR,JAD,BKG,BKG,BKG,BKG,BKG,JAD,JAD,FOR,FOR,BKG,
		BKG,JAD,BKG,BKG,BKG,BKG,BKG,JAD,JAD,FOR,FOR,FOR,
		BKG,BKG,BKG,BKG,BKG,BKG,BKG,JAD,FOR,BKG,FOR,FOR,
		BKG,BKG,BKG,BKG,BKG,BKG,JAD,JAD,FOR,BKG,FOR,FOR,
		BKG,BKG,BKG,BKG,BKG,BKG,BKG,JAD,FOR,BKG,BKG,FOR,
	};

	static char crawler3[]
	{
		BKG,BKG,BKG,BKG,BKG,BKG,BKG,MGA,BKG,BKG,BKG,BKG,
		BKG,BKG,BKG,BKG,BKG,BKG,MGA,VLT,BKG,BKG,BKG,BKG,
		BKG,BKG,BKG,MGA,MGA,MGA,MGA,VLT,BKG,BKG,BKG,BKG,
		BKG,BKG,BKG,JAD,JAD,MGA,VLT,VLT,BKG,BKG,BKG,BKG,
		BKG,BKG,BKG,JAD,JAD,VLT,VLT,VLT,BKG,BKG,BKG,BKG,
		BKG,BKG,JAD,WHT,WHT,JAD,VLT,JAD,JAD,BKG,BKG,BKG,
		BKG,BKG,BKG,BLU,WHT,JAD,VLT,FOR,FOR,BKG,BKG,BKG,
		BKG,BKG,JAD,FOR,JAD,JAD,VLT,FOR,BKG,BKG,BKG,BKG,
		BKG,FOR,FOR,FOR,FOR,JAD,VLT,OLV,OLV,BKG,BKG,BKG,
		JAD,FOR,FOR,FOR,JAD,JAD,VLT,OLV,JAD,OLV,BKG,BKG,
		BKG,JAD,JAD,JAD,JAD,OLV,OLV,JAD,JAD,OLV,BKG,BKG,
		BKG,BKG,JAD,JAD,OLV,OLV,OLV,JAD,FOR,OLV,BKG,BKG,
		BKG,BKG,BKG,VLT,OLV,OLV,JAD,FOR,OLV,OLV,OLV,BKG,
		BKG,BKG,BKG,BKG,FOR,JAD,JAD,OLV,OLV,OLV,OLV,BKG,
		BKG,BKG,BKG,BKG,FOR,JAD,JAD,OLV,MRN,MRN,MRN,BKG,
		BKG,BKG,BKG,BKG,BKG,JAD,JAD,OLV,OLV,OLV,OLV,OLV,
		BKG,BKG,BKG,BKG,BKG,JAD,JAD,OLV,OLV,OLV,OLV,BKG,
		BKG,BKG,BKG,BKG,BKG,JAD,JAD,BKG,FOR,FOR,BKG,BKG,
		BKG,BKG,BKG,BKG,BKG,BKG,JAD,JAD,JAD,FOR,BKG,BKG,
		BKG,BKG,BKG,BKG,BKG,FOR,FOR,FOR,BKG,JAD,BKG,BKG,
		BKG,BKG,BKG,BKG,BKG,BKG,FOR,JAD,JAD,JAD,BKG,BKG,
		BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,JAD,JAD,BKG,BKG,
	};


	static char crawler4[]
	{
		BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,MGA,BKG,BKG,BKG,
		BKG,BKG,BKG,BKG,BKG,BKG,BKG,MGA,VLT,BKG,BKG,BKG,
		BKG,BKG,BKG,BKG,MGA,MGA,MGA,MGA,VLT,BKG,BKG,BKG,
		BKG,BKG,BKG,BKG,JAD,JAD,MGA,VLT,VLT,BKG,BKG,BKG,
		BKG,BKG,BKG,BKG,JAD,JAD,JAD,VLT,VLT,BKG,BKG,BKG,
		BKG,BKG,BKG,JAD,WHT,WHT,JAD,VLT,JAD,JAD,BKG,BKG,
		BKG,BKG,BKG,BKG,BLU,WHT,JAD,VLT,FOR,FOR,BKG,BKG,
		BKG,BKG,BKG,JAD,FOR,JAD,JAD,VLT,FOR,BKG,BKG,BKG,
		BKG,BKG,FOR,FOR,FOR,FOR,JAD,VLT,BKG,BKG,BKG,BKG,
		BKG,JAD,FOR,FOR,FOR,JAD,JAD,VLT,OLV,BKG,BKG,BKG,
		BKG,BKG,JAD,JAD,JAD,JAD,VLT,OLV,JAD,OLV,BKG,BKG,
		BKG,BKG,BKG,JAD,JAD,OLV,OLV,OLV,JAD,OLV,BKG,BKG,
		BKG,BKG,BKG,BKG,BKG,OLV,OLV,OLV,JAD,OLV,OLV,BKG,
		BKG,BKG,BKG,BKG,OLV,OLV,OLV,OLV,JAD,OLV,OLV,BKG,
		BKG,BKG,BKG,FOR,FOR,OLV,OLV,OLV,JAD,MRN,MRN,BKG,
		BKG,BKG,BKG,FOR,FOR,FOR,MRN,MRN,JAD,OLV,OLV,OLV,
		BKG,BKG,BKG,FOR,BKG,BKG,OLV,OLV,JAD,OLV,OLV,BKG,
		BKG,BKG,BKG,BKG,FOR,FOR,FOR,FOR,JAD,FOR,FOR,BKG,
		BKG,BKG,BKG,BKG,BKG,FOR,FOR,JAD,JAD,FOR,FOR,BKG,
		BKG,BKG,BKG,BKG,FOR,FOR,BKG,JAD,JAD,FOR,FOR,BKG,
		BKG,BKG,BKG,BKG,BKG,BKG,BKG,JAD,JAD,FOR,BKG,BKG,
		BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,JAD,JAD,FOR,BKG,
	};*/

static char Walk1[]{ 0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,1,14,1,14,1,0,0,0,0,0,0,
0,0,0,0,0,0,0,14,1,14,1,14,1,0,0,0,0,0,0,
0,0,0,0,0,0,14,1,14,1,1,1,1,0,0,0,0,0,0,
0,0,0,0,0,0,14,1,1,17,17,17,14,0,0,0,0,0,0,
0,0,0,0,0,0,1,14,17,13,13,13,17,0,0,0,0,0,0,
0,0,0,0,0,0,14,17,17,17,1,17,17,0,0,0,0,0,0,
0,0,0,0,0,0,14,17,17,17,17,13,13,0,0,0,0,0,0,
0,0,0,0,0,0,14,1,17,17,13,13,17,0,0,0,0,0,0,
0,0,0,0,0,0,14,14,1,17,17,17,17,0,0,0,0,0,0,
0,0,0,0,0,0,1,14,14,1,1,1,1,0,0,0,0,0,0,
0,0,0,0,0,1,14,1,14,14,14,14,14,0,0,0,0,0,0,
0,0,0,0,1,14,14,14,1,14,14,14,14,14,0,0,0,0,0,
0,0,0,1,14,1,14,1,14,14,14,14,14,14,14,0,0,0,0,
0,0,0,14,14,14,1,1,14,14,14,1,14,14,1,0,0,0,0,
0,0,0,14,14,14,1,14,1,1,1,14,1,1,14,0,0,0,0,
0,0,0,1,14,14,17,14,14,14,14,14,14,14,14,0,0,0,0,
0,0,0,0,1,17,17,17,14,14,14,14,14,14,1,17,0,0,0,
0,0,0,0,0,17,17,1,1,14,14,1,14,14,17,0,0,0,0,
0,0,0,0,0,1,14,14,14,1,1,14,1,1,1,0,0,0,0,
0,0,0,0,0,1,14,1,1,14,14,14,14,1,14,1,0,0,0,
0,0,0,0,0,0,1,14,14,14,0,0,14,14,1,0,0,0,0,
0,0,0,0,0,0,1,1,1,1,0,1,1,14,1,0,0,0,0,
0,0,0,0,0,0,1,14,14,1,0,1,14,1,0,0,0,0,0,
0,0,0,0,0,0,1,14,14,14,1,1,14,14,1,0,0,0,0,
0,0,0,0,0,0,1,1,14,14,14,1,14,14,14,1,0,0,0,
};

static char Walk2[]{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,1,14,1,14,1,0,0,0,0,0,
0,0,0,0,0,0,0,0,14,1,14,1,14,1,0,0,0,0,0,
0,0,0,0,0,0,0,14,1,14,1,1,1,1,0,0,0,0,0,
0,0,0,0,0,0,0,14,1,1,17,17,17,14,0,0,0,0,0,
0,0,0,0,0,0,0,1,14,17,13,13,13,17,0,0,0,0,0,
0,0,0,0,0,0,0,14,17,17,17,1,17,17,0,0,0,0,0,
0,0,0,0,0,0,0,14,17,17,17,17,13,13,0,0,0,0,0,
0,0,0,0,0,0,0,14,1,17,17,13,13,17,0,0,0,0,0,
0,0,0,0,0,0,1,1,14,1,17,17,17,17,0,0,0,0,0,
0,0,0,0,0,1,14,14,1,14,1,1,1,1,17,17,0,0,0,
0,0,0,0,0,1,14,14,14,1,1,1,1,14,17,17,17,0,0,
0,0,0,0,0,0,1,14,1,14,14,14,14,14,14,17,0,0,0,
0,0,0,0,0,0,14,1,1,14,14,14,14,1,1,0,0,0,0,
0,0,0,0,0,0,14,14,14,1,1,1,1,14,14,0,0,0,0,
0,0,0,0,0,0,1,1,14,14,14,14,14,14,1,0,0,0,0,
0,0,0,0,0,1,14,14,1,14,14,1,14,1,0,0,0,0,0,
0,0,0,0,0,1,1,14,14,1,1,14,1,1,1,0,0,0,0,
0,0,0,1,14,14,14,1,1,14,14,0,14,14,1,1,0,14,0,
0,0,1,14,14,14,14,14,14,0,0,0,1,14,14,14,14,14,0,
0,0,1,14,14,1,1,1,0,0,0,0,0,1,14,14,14,1,0,
0,0,1,14,14,0,0,0,0,0,0,0,0,0,0,14,1,0,0,
0,0,0,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,


};
static char Walk3[]{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,1,14,1,14,1,0,0,0,0,0,0,
0,0,0,0,0,0,0,14,1,14,1,14,1,0,0,0,0,0,0,
0,0,0,0,0,0,14,1,14,1,1,1,1,0,0,0,0,0,0,
0,0,0,0,0,0,14,1,1,17,17,17,14,0,0,0,0,0,0,
0,0,0,0,0,0,1,14,17,13,13,13,17,0,0,0,0,0,0,
0,0,0,0,0,0,14,17,17,17,1,17,17,0,0,0,0,0,0,
0,0,0,0,0,0,14,17,17,17,17,13,13,0,0,0,0,17,17,
0,0,0,0,0,0,14,1,17,17,13,13,17,0,0,0,17,17,17,
0,0,0,0,0,1,14,14,1,17,17,17,17,0,0,0,14,14,14,
0,0,0,1,1,14,1,1,14,1,1,1,1,1,14,14,14,14,1,
0,0,1,1,14,14,14,14,1,14,14,14,14,14,1,14,14,1,0,
0,1,14,14,1,14,14,1,14,14,14,14,14,14,14,1,1,0,0,
1,14,14,14,14,1,1,14,14,14,14,1,14,14,14,0,0,0,0,
1,14,14,14,0,14,14,14,1,1,1,14,1,1,1,0,0,0,0,
1,14,17,17,0,14,14,14,14,14,14,14,14,14,14,0,0,0,0,
0,17,17,17,0,1,14,14,14,14,14,14,14,14,14,0,0,0,0,
0,0,17,0,0,1,1,14,14,14,14,1,14,14,0,0,0,0,0,
0,0,0,0,1,14,14,1,1,1,1,14,1,1,0,0,0,0,0,
0,0,0,0,0,1,14,14,1,14,14,14,14,1,1,0,0,0,0,
0,0,0,0,0,0,1,1,14,14,1,1,14,1,0,0,0,0,0,
0,0,0,0,0,0,1,14,1,1,14,14,1,1,0,0,0,0,0,
0,0,0,0,0,1,14,14,14,14,1,14,1,0,0,0,0,0,0,
0,0,0,0,0,0,1,14,14,1,14,14,14,0,0,0,0,0,0,
0,0,0,0,0,0,0,1,14,14,1,14,1,1,0,0,0,0,0,

};

	walkAnim->AddSprite(Walk2, 19, 26, 0.1f);
	walkAnim->AddSprite(Walk3, 19, 26, 0.1f);
	walkAnim->AddSprite(Walk1, 19, 26, 0.05f);

	//this->transform.scale->x = 16;
	//this->transform.scale.y = 0.5f;

	speed = 80.0f;
	this->AddComponent<Animation>();
	this->AddComponent<Collider>()->SetUpSquare(0.0f, 0.0f, 15.0f,15.0f);
}

void Player::update(float deltaTime)
{
	oldpos.x = transform.position.x;
	oldpos.y = transform.position.y;
	if (GetInput()->KeyDown(KeyCode::Left))
	{
		walkAnim->hasPriority = true;
		this->GetComponent<Animation>()->PlayAnimation(walkAnim, true);
		this->transform.rotation.y = -180;
		this->transform.position.x -= speed * deltaTime;
	}
	else if (GetInput()->KeyDown(KeyCode::Right))
	{
		walkAnim->hasPriority = true;
		this->GetComponent<Animation>()->PlayAnimation(walkAnim, true);
		this->transform.rotation.y = 0;
		this->transform.position.x += speed * deltaTime;
	}
	else if (GetInput()->KeyDown(KeyCode::Up))
	{
		walkAnim->hasPriority = true;
		this->GetComponent<Animation>()->PlayAnimation(walkAnim, true);
		this->transform.position.y += speed * deltaTime;
	}
	else if (GetInput()->KeyDown(KeyCode::Down))
	{
		walkAnim->hasPriority = true;
		this->GetComponent<Animation>()->PlayAnimation(walkAnim, true);
		this->transform.position.y -= speed * deltaTime;
	}
	else
	{
		this->GetComponent<Animation>()->PlayAnimation(walkAnim, true,2,2);
	}
}