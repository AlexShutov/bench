/*
 * IncFile1.h
 *
 * Created: 13.08.2019 2:00:09
 *  Author: Admin
 */ 


#ifndef SCREEN_INFO_H_
#define SCREEN_INFO_H_

/*****************************************************/
/* Описание данных, показываемых на экране           */
/*****************************************************/
struct ScreenInfo {
	bool schnackOn;
	bool conveyerOn;
	long countTotal;
	long countDay;
};

#endif /* SCREEN_INFO_H_ */