/*
 * PollResult.h
 *
 * Created: 18.08.2019 4:19:21
 *  Author: Admin
 */ 


#ifndef POLLRESULT_H_
#define POLLRESULT_H_

enum class PollResult {
	// Состояние изменилось, нужно переходить дальше
	STATE_CHANGED,
	// остаемся на том же состоянии
	KEEP_STATE,
	// Произошла ошибка
	ERROR_STATE
};



#endif /* POLLRESULT_H_ */