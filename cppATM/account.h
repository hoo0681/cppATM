#pragma once
#include "id_pw.h"
//���� ������ �ҷ�����& ����
class account
{
private: //id�� balance�� ���� �������� ������ ���´�.
	//������ü�� ��� ��й�ȣ���̵� �ܾ��� �����Ǿ��ϹǷ� 
	//���¹�ȣ�� ���� id�� ����� ���´�. 
	//���� account���� �Ĵ� ��й�ȣ�� ����ϰ����� �ʿ䰡����.
	id _ID;
	//�ܾ�
	long balance;
public:
	//�⺻������
	account() {
		balance = 0;
	}
	//������
	//���� ��ȣ�� �μ��� �޴� ����� ������
	account(int* _id) {//���� ��ȣ�� �μ��� �޴´�
		_ID = id(_id);//id�� ����� ����
		if (_ID.ck_id() == false)throw "wrong id";//���� �����ΰ�� throw�Ѵ�,
		balance = SetBal();//�ִٸ� �ܾ��� �ҷ��´�.
	}
	//id�Ǵ� id_pw�� �μ��� �޴� ����� ������
	//���۷����� ������ id�� ����� id�� ��ӹ޴� ��ü�� �������� Ȱ���� �� �ִ�.
	account(id& checked ) 
	{
		if (checked.ck_id())//ck_id�� checked�� Ÿ�Կ� ���� �ٸ��� �����Ѵ�.
		{
			//Ȯ�εȰ�� ����� �����ϴµ� checked�� id_pw�� ��쿡�� 
			//�ڵ������� ��ȯ �����ڿ� ���� pw�κ��� truncation �ȴ�.
			_ID = checked;
		}
		else throw "wrong id";//���� ck_id�� ����� false�̸� throw�Ѵ�.
		balance=SetBal();//�ܾ��� �ҷ��´�.
	}
	//���� ������
	account(account& other) {
		_ID = other._ID;
		balance = other.balance;
	}
	//�ܾ�����
	void add(long a);
	//�ܾװ���, �ܾ׺��� ����
	void sub(long a);
	//�ܾ��� �ҷ��´�
	long SetBal();
	//�ܾ��� ��ȯ�Ѵ�.
	long GetBal() { return balance; }
	//��� id�� ��ȯ�Ѵ�.
	id GetID() { return _ID; }
	//������� ����
	void saveData();
};

