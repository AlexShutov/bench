/*
 * StatsData.h
 *
 * Created: 23.08.2019 2:37:34
 *  Author: Admin
 */ 


#ifndef STATSDATA_H_
#define STATSDATA_H_

/************************************************************************/
/* Содержит общий и дневной счетчики
/************************************************************************/
struct StatsData {
	// дневной счетчик	
	long dayCount;
	// общий счетчик
	long totalCount;
};




#endif /* STATSDATA_H_ */