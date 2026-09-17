#ifndef ACTION_H_
#define ACTION_H_

#include <queue>
#include <functional>

template <class R, class ... Args>
class Action
{
public:
	Action();
	~Action();

	void Subscribe(std::function<R(Args)>);
	void Execute(Args);

private:
	std::queue<std::function<R(Args)> m_functions;

};

#endif

