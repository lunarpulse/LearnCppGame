#include "QuitOption.h"
#include "SDBMHash.h"
#include "EventManager.h"

namespace
{
	constexpr char*const QuitEventString = "QuitEvent";
	constexpr int QuitEventStringLength =
#ifndef constexpr
		constexpr_strlen(QuitEventString);
#else
		9;
#endif // !constexpr
	constexpr int QuitEvent = SDBMCalculator<QuitEventStringLength>::CalculateValue(QuitEventString);
}
void QuitOption::Evaluate(Player& player) 
{
	Notify<&QuitObserver::OnQuit>();
}