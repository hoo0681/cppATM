#pragma once
#include "id.h"
class id_pw :
	protected id
{
private: 
	long PW;//비밀번호
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
	bool ck_id() override;//없는 계좌거나, 잘못된 비번인경우 false
};

