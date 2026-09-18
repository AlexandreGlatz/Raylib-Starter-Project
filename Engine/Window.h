#ifndef WINDOW_H_
#define WINDOW_H_

#include <Vec2.h>
#include <string>

class Window
{
public:
	Window(float width, float height, std::string name);
	~Window();

	void SetTargetFPS(int target);

	void Open();
	bool IsOpen();

private:
	Vec2f m_size;
	std::string m_name;
};

#endif
