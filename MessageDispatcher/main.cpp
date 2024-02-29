#include <iostream>

#include "MessageDispatcher.h"

class FooEvent : public Event
{
public: FooEvent() : Event(EventType::FooEvent) {}
};
class BarEvent : public Event
{
public: BarEvent() : Event(EventType::BarEvent) {}
};

class FooListener : public IListener
{
public:
	void onEvent(const Event& event) override
	{
		if (event.GetType() == EventType::FooEvent)
			std::cout << "FooListener: " << event.ToString() << std::endl;
		if (event.GetType() == EventType::BarEvent)
			std::cout << "FooListener: " << event.ToString() << std::endl;
	}
};
class BarListener : public IListener
{
public:
	void onEvent(const Event& event) override
	{
		if (event.GetType() == EventType::FooEvent)
			std::cout << "BarListener: " << event.ToString() << std::endl;
		if (event.GetType() == EventType::BarEvent)
			std::cout << "BarListener: " << event.ToString() << std::endl;
	}
};

int main()
{
	MessageDispatcher dispatcher;
	FooListener fooListener;
	BarListener barListener;
	dispatcher.subscribe(EventType::FooEvent, &fooListener, 1);
	dispatcher.subscribe(EventType::BarEvent, &fooListener, 1);
	dispatcher.subscribe(EventType::FooEvent, &barListener, 2);
	dispatcher.subscribe(EventType::BarEvent, &barListener, 2);

	FooEvent fooEvent;
	BarEvent barEvent;

	dispatcher.queueEvent(&fooEvent);
	dispatcher.queueEvent(&barEvent);

	dispatcher.processQueue();

	for (int i = 0; i < 10; ++i)
	{
		std::cout << "-";
	}

	std::cout << std::endl;

	dispatcher.unsubscribe(EventType::FooEvent, &fooListener);

	dispatcher.queueEvent(&fooEvent);
	dispatcher.queueEvent(&barEvent);
	dispatcher.processQueue();
	dispatcher.processQueue();

	return 0;
}