#include "MessageDispatcher.h"

void MessageDispatcher::subscribe(EventType type, IListener* listener, int priority)
{
	listenersMap[type].push({ listener, priority });
}

void MessageDispatcher::unsubscribe(EventType type, const IListener* listener)
{
	auto& queue = listenersMap[type];
	std::priority_queue<ListenerInfo> updatedQueue;
	while (!queue.empty())
	{
		auto info = queue.top();
		queue.pop();
		if (info.listener != listener)
		{
			updatedQueue.push(info);
		}
	}
	listenersMap[type] = updatedQueue;
}

void MessageDispatcher::queueEvent(Event* event)
{
	eventQueue.push(event);
}

void MessageDispatcher::processQueue()
{
	while (!eventQueue.empty())
	{
		const auto event = eventQueue.front();
		auto listenersQueue = listenersMap[event->GetType()];

		while (!listenersQueue.empty())
		{
			const auto listenerInfo = listenersQueue.top();
			listenersQueue.pop();
			listenerInfo.listener->onEvent(*event);
		}

		eventQueue.pop();
	}
}