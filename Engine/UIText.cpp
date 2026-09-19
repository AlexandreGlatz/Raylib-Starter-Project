#include "pch.h"
#include "UIText.h"
#include "Transform2D.h"

UIText::UIText(Entity* pEntity) : UIElement(pEntity), m_attributes()
{
}

UIText::~UIText()
{
		
}

void UIText::Update()
{
	Vec2f position = m_pTransform->GetPosition();
	float rotation = m_pTransform->GetRotation();
	DrawTextPro(*m_attributes.pFont, m_text.c_str(), Vector2(position.x, position.y), Vector2(m_origin.x, m_origin.y), 
		rotation, m_attributes.fontSize, m_attributes.spacing, m_attributes.color);
}

void UIText::SetText(std::string text)
{
	m_text = text;
}

void UIText::SetTextAttibutes(TextAttributes const& attibutes)
{
	m_attributes = attibutes;
}

