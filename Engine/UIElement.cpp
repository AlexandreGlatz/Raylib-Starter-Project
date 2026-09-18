#include "pch.h"
#include "UIElement.h"
#include "Entity.h"
#include "Transform2D.h"

UIElement::UIElement(Entity* pEntity) : Component(pEntity)
{
	m_pEntity->CheckDependencies<0, Transform2D>(GetTypeStr(GetType()));

	m_pTransform = m_pEntity->GetComponent<Transform2D>();
}

UIElement::~UIElement()
{
}

void UIElement::Update()
{
}

void UIElement::SetOrigin(Vec2f const& origin)
{
	m_origin = origin;
}


