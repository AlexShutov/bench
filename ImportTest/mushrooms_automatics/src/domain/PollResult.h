/*
 * PollResult.h
 *
 * Created: 18.08.2019 4:19:21
 *  Author: Admin
 */ 


#ifndef POLLRESULT_H_
#define POLLRESULT_H_

enum class PollResult {
	// ��������� ����������, ����� ���������� ������
	STATE_CHANGED,
	// �������� �� ��� �� ���������
	KEEP_STATE,
	// ��������� ������
	ERROR_STATE
};



#endif /* POLLRESULT_H_ */