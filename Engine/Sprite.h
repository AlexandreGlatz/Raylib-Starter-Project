#ifndef SPRITE_H_
#define SPRITE_H_

#include "Component.h"

#include <Vec2.h>
#include <raylib.h>

class Sprite : public Component
{
public:
	Sprite();
	~Sprite();

	void Update() override;
private:
	Texture2D m_texture;
	Vec2f position;
};

#endif
