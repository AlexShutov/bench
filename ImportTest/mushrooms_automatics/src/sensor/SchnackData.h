/*
 * SchnackData.h
 *
 * Created: 14.08.2019 1:41:44
 *  Author: Admin
 */ 


#ifndef SCHNACKDATA_H_
#define SCHNACKDATA_H_

// Данные, считываемые с сенсоров шнека, забивающего мешки семечками
struct SchnackData {
	// Включен ли датчик начала движения шнека S1
	bool mBeginON;
	// Включен ли датчик окончания движения шнека S2
	bool mEndON;
	
	bool operator==(SchnackData &op2) {
		return mBeginON == op2.mBeginON &&
				mEndON == op2.mEndON;
	}
	bool operator!=(SchnackData &op2) {
		return !this->operator ==(op2);
	}
};

#endif /* SCHNACKDATA_H_ */