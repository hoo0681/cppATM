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
	void deposit();//�Ա�
	void withdraw();//���
	void transfar();//��ü
	void checkAccount();//��ȸ
};

