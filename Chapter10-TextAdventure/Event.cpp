#include "Event.h"
#include "Eventhandler.h"

#include <cassert>

Event::Event(EventID eventId)
	:m_id{ eventId }
{
	
}

void Event::Send()
{
	for (auto& listner : m_listeners)
	{
		if (listner != nullptr)
		{
			listner->HandleEvent(this);
		}
	}
}

void Event::SendToHandler(EventHandler& eventHandler)
{
	auto found = std::find(m_listeners.begin(), m_listeners.end(), &eventHandler);
	if (found != m_listeners.end())
	{
		(*found)->HandleEvent(this);
	}
}

void Event::AttachListener(EventHandler& eventHandler)
{
	m_listeners.push_back(&eventHandler);
}

void Event::DetachListner(EventHandler& eventHandler)
{
	for (EventHandlerIterator iter = m_listeners.begin();
		iter != m_listeners.end();
		++iter)
	{
		if (&eventHandler == *iter)
		{
			m_listeners.erase(iter);
			break;
		}
	}
}