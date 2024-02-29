#pragma once
#include <queue>
#include <unordered_map>

#include "Event.h"
#include "ListenerInfo.h"

class MessageDispatcher
{
	std::unordered_map<EventType, std::priority_queue<ListenerInfo>> listenersMap;
	std::queue<Event*> eventQueue;

public:
	void subscribe(EventType type, IListener* listener, int priority = 0);
	void unsubscribe(EventType type, const IListener* listener);
	void queueEvent(Event* event);
	void processQueue();
};