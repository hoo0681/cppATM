#pragma once
#include "account.h"
class handler
{
private:
	//사용자 계좌
	account user_acc;
public:
	handler() {}
	//잘못되면 throw함
	handler(int* id, std::string pw);
	//입금
	void deposit(long money);
	//출금
	void withdraw(long money);
	//이체
	void transfar(account _id, long money);
	//조회
	std::string checkAccount();
};

