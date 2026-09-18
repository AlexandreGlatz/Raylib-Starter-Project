#include "pch.h"
#include "Window.h"

#include <raylib.h>

Window::Window(int width, int height, std::string name)
	: m_size({ width, height }),
	m_name(name)
{
}

Window::~Window()
{
}

void Window::SetTargetFPS(int target)
{
	SetTargetFPS(target);
}

void Window::Open()
{
	InitWindow(m_size.x, m_size.y, m_name.c_str());
}

bool Window::IsOpen()
{
	return WindowShouldClose() == false;
}

void Window::Close()
{
	CloseWindow();
}

