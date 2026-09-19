#ifndef UI_BUTTON_H
#define UI_BUTTON_H

#include "UIElement.h"

#include <Action.h>

class UIButton : public UIElement
{
public:
	UIButton(Entity* pEntity);
	~UIButton();

	void Update() override;

	Action<void()> OnHover;
	Action<void()> OnClick;

private:
	bool IsMouseInside();
};

#endif
