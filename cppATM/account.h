#pragma once
#include "id_pw.h"
class account//���� ������ �ҷ�����& ����
{
private: 
	id _ID;
	long balance;
public:
	account() {
		balance = 0;
	}
	account(int* _id) {//�߸��Ǹ� �����ѱ�
		_ID = id(_id);
		if (_ID.ck_id() == false)throw "wrong id";
		balance = SetBal();
	}
	account(id& checked ) //id �� pw�� Ȯ�εȰ��� �Ѿ�´�.
	{
		if (checked.ck_id())
		{
			_ID = checked;
		}
		else throw "wrong id";
		balance=SetBal();
	}
	account(account& other) {
		_ID = other._ID;
		balance = other.balance;
	}
	void add(long a);//�ܾ�����
	void sub(long a);//�ܾװ���//�ܾ׺��� ����
	long SetBal();
	long GetBal() { return balance; }
	id GetID() { return _ID; }
	void saveData();//������� ����
};

