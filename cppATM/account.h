#pragma once
#include "id_pw.h"
class account//���� ������ �ҷ�����& ����
{
private: 
	id _ID;
	long balance;
public:
	account(id& checked ) //id �� pw�� Ȯ�εȰ��� �Ѿ�´�.
	{
		if (checked.ck_id())
		{
			_ID = checked;
		}
		/*�ܾ� �ҷ�����*/
	}
	account(account& other) {
		_ID = other._ID;
		balance = other.balance;
	}
	void add(long a);//�ܾ�����
	void sub(long a);//�ܾװ���//�ܾ׺��� ����
	long GetBal() { return balance; }
	id GetID() { return _ID; }
};

