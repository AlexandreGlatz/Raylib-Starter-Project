#ifndef VEC2_H_
#define VEC2_H_

template <typename T>
struct Vec2
{
	Vec2() {}
	Vec2(T _x, T _y) { x = _x, y = _y; }
	T x;
	T y;
};

typedef Vec2<float> Vec2f;
typedef Vec2<int> Vec2i;

#endif
