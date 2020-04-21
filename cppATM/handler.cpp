#include "handler.h"

handler::handler(int* id, std::string pw)
{
	id_pw user= id_pw(id, pw); 
	if (user.ck_id()) {
		user_acc = account(user);
	}
	else {
		throw "wrong account";
	}
}

void handler::deposit(long money)//�Ա�
{
	user_acc.add(money);
	user_acc.saveData();
}

void handler::withdraw(long money)//���
{
	try
	{
		user_acc.sub(money);
		user_acc.saveData();
	}
	catch (const char* err)
	{
		puts(err);
		throw err;
	}
	
}
//�̸����� Ȯ�� �ǰ� ������
void handler::transfar(account _id, long money)//�۱� 
{
	try
	{
		account target(_id);//���� ���̵�� throw ��
		user_acc.sub(money);//�ܾ� �����̸� throw ��
		target.add(money);
		user_acc.saveData();
		target.saveData();
	}
	catch (const char* err)
	{
		puts(err);
		throw err;
	}
}
//�̸��� �ܾ��� �������� ������ ���ڿ� ��ȯ
std::string handler::checkAccount()//��ȸ
{
	std::string info;
	info.append(user_acc.GetID().GetName());
	info.append(" ");
	info.append(std::to_string(user_acc.GetBal()));
	return info;
}
