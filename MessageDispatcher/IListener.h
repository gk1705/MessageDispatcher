#pragma once

#include "Event.h"

class IListener
{
public:
	virtual ~IListener() = default;
	virtual void onEvent(const Event& event) = 0;
};