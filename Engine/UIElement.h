#ifndef UI_ELEMENT_H_
#define UI_ELEMENT_H_

#include "Component.h"

#include <Vec2.h>

class Transform2D;
class UIElement : public Component
{
public:
	UIElement(Entity* pEntity);
	~UIElement();

	virtual void Update() override;
	void SetOrigin(Vec2f const& origin);

protected:
	std::shared_ptr<Transform2D> m_pTransform;
	Vec2f m_origin;

};

#endif
