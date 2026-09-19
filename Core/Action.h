#ifndef ACTION_H_
#define ACTION_H_

#include <vector>
#include <iterator>
#include <queue>
#include <utility>

template <typename R, typename ... Args>
class Action
{
};

template<typename R, typename ... Args>
class Action<R(Args ...)>
{
public:
	Action();
	~Action();

	void Subscribe(R (*func)(Args ...));
	void SubscribeOnce(R (*func)(Args ...));
	void Invoke(Args ...);

	void operator()(Args ...);

private:
	std::vector<R (*)(Args ...)> m_subscribedFunctions;
	std::queue<R (*)(Args ...)> m_subscribedOnceFunctions;

};

template<class R, class ...Args>
inline Action<R(Args...)>::Action()
{
}

template<class R, class ...Args>
inline Action<R(Args...)>::~Action()
{
}

template<class R, class ...Args>
inline void Action<R(Args...)>::Subscribe(R (*func)(Args ...))
{
	m_subscribedFunctions.push_back(func);
}

template<class R, class ...Args>
inline void Action<R(Args...)>::SubscribeOnce(R (*func)(Args...))
{
	m_subscribedOnceFunctions.push(func);
}

template<class R, class ...Args>
inline void Action<R(Args...)>::Invoke(Args ... args)
{
	while (m_subscribedOnceFunctions.empty() == false)
	{
		m_subscribedOnceFunctions.front()(args ...);
		m_subscribedOnceFunctions.pop();
	}

	for (int i = 0; i<m_subscribedFunctions.size(); ++i)
	{
		m_subscribedFunctions[i](args ...);
	}
}

template<typename R, typename ...Args>
inline void Action<R(Args...)>::operator()(Args ... args)
{
	Invoke(args ...);
}

#endif



