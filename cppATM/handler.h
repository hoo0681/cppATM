#pragma once
#include "account.h"
class handler
{
private:
	//id_pw user;
	account user_acc;
public:
	handler() {}
	handler(int* id, std::string pw);//잘못되면 throw함
	void deposit(long money);//입금
	void withdraw(long money);//출금
	void transfar(account _id, long money);//이체
	std::string checkAccount();//조회
};

