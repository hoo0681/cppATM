#pragma once
#include <iostream>
#include<sstream>
#include "handler.h"

class ATM
{
private:
	handler user;
	
	void login();//�߸��Ǹ� �����ѱ�
	account tagetid();//�ش� ���� �ҷ�����.
	long moneyIN();//�Է¹��� �ݾ� �ѱ�
	template<typename T>
	T onlyNUM(T start,T end);//start~end ������ ���� �Է¹޾� ��ȯ
public:
	ATM() {};
	void menu();
	void deposit();//�Ա�
	void withdraw();//���
	void transfar();//��ü
	void checkAccount();//��ȸ
};

