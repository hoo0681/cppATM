#pragma once
#include "account.h"
class handler
{
private:
	id_pw user;
	account user_acc;
public:
	handler(int* id, long pw);
	void deposit(long money);//입금
	void withdraw(long money);//출금
	void transfar(int* id, long money);//이체
	void checkAccount();//조회
};

