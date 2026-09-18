#ifndef WINDOW_H_
#define WINDOW_H_

#include <Vec2.h>
#include <string>

class Window
{
public:
	Window(int width, int height, std::string name);
	~Window();

	void SetTargetFPS(int target);

	void Open();
	bool IsOpen();
	void Close();

private:
	Vec2i m_size;
	std::string m_name;
};

#endif
