#pragma once
#include <iostream>
#include<sstream>
#include "handler.h"

class ATM
{
private:
	//�����
	handler user;
	//handler�� �α��� �߸��Ǹ� ���� throw
	void login();
	//�ش� ���� �ҷ�����.
	account tagetid();
	//�Է¹��� �ݾ� �ѱ�
	long moneyIN();
	//start~end ������ ���� �Է¹޾� ��ȯ
	template<typename T>
	T onlyNUM(T start,T end);
	//�Ա�
	void deposit();
	//���
	void withdraw();
	//��ü
	void transfar();
	//��ȸ
	void checkAccount();
public:
	//�⺻ ������
	ATM() {};
	//�޴�â
	void menu();
	
};

