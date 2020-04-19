#pragma once
#include "handler.h"

class ATM
{
private:
	handler user;
	long money;
	
	void login();
	void tagetid();
	void moneyIN();
public:
	void menu();
	void deposit();//입금
	void withdraw();//출금
	void transfar();//이체
	void checkAccount();//조회
};

