#pragma once
#include "id.h"
class id_pw :
	protected id
{
private: 
	long PW;//��й�ȣ
public:
	id_pw() :id() {
		PW = 0;
	}
	id_pw(int* id, long pw) :id(id)
	{
		PW = pw;
	}
	id_pw( id_pw& other):id(other)
	{
		PW = other.PW;
	}
	bool ck_id() override;//���� ���°ų�, �߸��� ����ΰ�� false
};
