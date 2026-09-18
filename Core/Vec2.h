#ifndef VEC2_H_
#define VEC2_H_

template <typename T>
struct Vec2
{
	Vec2();
	Vec2(T _x, T _y) { x = _x, y = _y; }
	T x;
	T y;
};


typedef Vec2<float> Vec2f;
typedef Vec2<int> Vec2i;

template<>
inline Vec2<float>::Vec2()
{
	x = 0.0f, y = 0.0f;
}

template<>
inline Vec2<int>::Vec2()
{
	x = 0, y = 0;
}

#endif


