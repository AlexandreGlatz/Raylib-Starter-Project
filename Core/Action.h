#ifndef ACTION_H_
#define ACTION_H_

#include <vector>
#include <queue>

template <class R, class ... Args>
class Action
{
public:
	Action();
	~Action();

	void Subscribe(R(*func)(Args ...));
	void SubscribeOnce(R(*func)(Args ...));
	void Execute(Args ...);

private:
	std::vector<R(*func)(Args)> m_subscribedFunctions;
	std::queue<R(*func)(Args)> m_subscribedOnceFunctions;
};


template<class R, class ...Args>
inline Action<R, Args...>::Action()
{
}

template<class R, class ...Args>
inline Action<R, Args...>::~Action()
{
}

template<class R, class ...Args>
inline void Action<R, Args...>::Subscribe(R(*func)(Args ...))
{
	m_subscribedFunctions.push(func);
}

template<class R, class ...Args>
inline void Action<R, Args...>::SubscribeOnce(R(*func)(Args...))
{
	m_subscribedOnceFunctions.push(func);
}

template<class R, class ...Args>
inline void Action<R, Args...>::Execute(Args ...)
{
	while (m_subscribedOnceFunctions.empty() == false)
	{
		m_subscribedOnceFunctions.front()(Args ...);
		m_subscribedOnceFunctions.pop();
	}

	std::vector<R(*func)(Args ...)>::iterator i;
	for (i = m_subscribedFunctions.begin(); i < m_subscribedFunctions.end(); i++)
	{
		*i(Args ...);
	}
}

#endif



