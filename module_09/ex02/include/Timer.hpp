#ifndef TIMER__HPP
#define TIMER__HPP
#include <ctime>

class Timer
{

public:
	void startTimer(void);
	void stopTimer(void);
	unsigned int getTimeElapsed(void);

private:
	unsigned int start_time;
	unsigned int end_time;
};

#endif
