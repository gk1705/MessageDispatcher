#pragma once
#include <string>

enum class EventType
{
	FooEvent,
	BarEvent,
};

class Event
{
protected:
	EventType type;

public:
	explicit Event(EventType type) : type(type) {}
	virtual ~Event() = default;

	EventType GetType() const { return type; }
	virtual std::string ToString() const { return EventToString(type); }

private:
	static std::string EventToString(EventType type);
};