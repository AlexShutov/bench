/*
 * SchnackData.h
 *
 * Created: 14.08.2019 1:41:44
 *  Author: Admin
 */ 


#ifndef SCHNACKDATA_H_
#define SCHNACKDATA_H_

// ������, ����������� � �������� �����, ����������� ����� ���������
struct Data {
	// ������� �� ������ ������ �������� ����� S1
	bool mBeginON;
	// ������� �� ������ ��������� �������� ����� S2
	bool mEndON;
	
	bool operator==(Data &op2) {
		return mBeginON == op2.mBeginON &&
				mEndON == op2.mEndON;
	}
	bool operator!=(Data &op2) {
		return !this->operator ==(op2);
	}
};

#endif /* SCHNACKDATA_H_ */