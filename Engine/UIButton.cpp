#include "pch.h"
#include "UIButton.h"
#include "Transform2D.h"

#include <raylib.h>

UIButton::UIButton(Entity* pEntity) : UIElement(pEntity)
{
}

UIButton::~UIButton()
{
}

void UIButton::Update()
{
	if (IsMouseInside())
	{ 
		OnHover();
		SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			OnClick();

		return;
	}
	SetMouseCursor(MOUSE_CURSOR_DEFAULT);
}

bool UIButton::IsMouseInside()
{
	int mouseX = GetMouseX();
	int mouseY = GetMouseY();
	Vec2f position = m_pTransform->GetPosition();
	Vec2f size = m_pTransform->GetSize();

	return	mouseX > position.x &&
		mouseX < position.x + size.x &&
		mouseY > position.y &&
		mouseY < position.y + size.y;

}
