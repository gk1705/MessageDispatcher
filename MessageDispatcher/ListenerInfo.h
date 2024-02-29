#pragma once

#include "IListener.h"

class ListenerInfo
{
public:
	IListener* listener;
	int priority;

	bool operator<(const ListenerInfo& other) const
	{
		return priority < other.priority;
	}
};