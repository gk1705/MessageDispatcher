#include "Event.h"

std::string Event::EventToString(EventType type)
{
	switch (type)
	{
	case EventType::FooEvent:
		return "FooEvent";
	case EventType::BarEvent:
		return "BarEvent";
	default:
		return "Unknown";
	}
}