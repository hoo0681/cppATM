#include "handler.h"

handler::handler(int* id, std::string pw)
{
	id_pw user= id_pw(id, pw);//���¹�ȣ�� ��й�ȣ�� id_pw ���� 
	if (user.ck_id()) {//����Ȯ��
		user_acc = account(user);//Ȯ�ε� id,pw�� user_acc �ʱ�ȭ ( ��������ڸ� �̿��Ͽ� ������ ����)
	}
	else {
		throw "wrong account";//���� ���� �̰ų� ��� ��ȣ�� �ٸ��� �޼��� throw
	}
}

void handler::deposit(long money)//�Ա�
{
	user_acc.add(money);//�ݾ� �߰�
	user_acc.saveData();//������� ����
}

void handler::withdraw(long money)//���
{
	try
	{
		user_acc.sub(money);//��ݽõ� 
		user_acc.saveData();//������ ����
	}
	catch (const char* err)//throw�� �޼��� �ִٸ�
	{
		puts(err);//�����
		throw err;//�ٽ� ������
	}
	
}
//�̸����� Ȯ�� �ǰ� ������
void handler::transfar(account _id, long money)//�۱� 
{
	try
	{
		account target(_id);//���� ���̵�� throw ��
		user_acc.sub(money);//�ܾ� �����̸� throw ��
		target.add(money);//�����¿� �Ա�
		user_acc.saveData();//������� ����
		target.saveData();//������� ����
	}
	catch (const char* err)//throw�� �޼��� �ִٸ�
	{
		puts(err);//�����
		throw err;//�ٽ� ������
	}
}
//�̸��� �ܾ��� �������� ������ ���ڿ� ��ȯ
std::string handler::checkAccount()//��ȸ
{
	std::string info;//���ڿ� 
	info.append(user_acc.GetID().GetName());//�̸�
	info.append(" ");//����
	info.append(std::to_string(user_acc.GetBal()));//�ܾ�
	return info;//�̸� �ܾ� ��ȯ
}
