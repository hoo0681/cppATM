#pragma once
#include "account.h"
class handler
{
private:
	//����� ����
	account user_acc;
public:
	handler() {}
	//�߸��Ǹ� throw��
	handler(int* id, std::string pw);
	//�Ա�
	void deposit(long money);
	//���
	void withdraw(long money);
	//��ü
	void transfar(account _id, long money);
	//��ȸ
	std::string checkAccount();
};

