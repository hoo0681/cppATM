#pragma once
#include "account.h"
class handler
{
private:
	id_pw user;
	account user_acc;
public:
	handler(int* id, long pw);
	void deposit(long money);//�Ա�
	void withdraw(long money);//���
	void transfar(int* id, long money);//��ü
	void checkAccount();//��ȸ
};

