#pragma once
#include "account.h"
class handler
{
private:
	//id_pw user;
	account user_acc;
public:
	handler() {}
	handler(int* id, std::string pw);//�߸��Ǹ� throw��
	void deposit(long money);//�Ա�
	void withdraw(long money);//���
	void transfar(account _id, long money);//��ü
	std::string checkAccount();//��ȸ
};

