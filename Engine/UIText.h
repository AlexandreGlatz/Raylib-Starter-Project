#ifndef UI_TEXT_H_
#define UI_TEXT_H_

#include "UIElement.h"

#include <filesystem>
#include <string>
#include <raylib.h>

struct TextAttributes
{
	Font const* pFont;
	Color color;
	float fontSize;
	float spacing;
};

class UIText : public UIElement
{
public:
	UIText(Entity* pEntity);
	~UIText();

	void Update() override;

	void SetText(std::string text);
	void SetTextAttibutes(TextAttributes const& attibutes);

private:
	std::string m_text;
	TextAttributes m_attributes;

};

#endif
