#pragma once
#include "id_pw.h"
class account//계좌 데이터 불러오기& 수정
{
private: 
	id _ID;
	long balance;
public:
	account(id& checked ) //id 와 pw는 확인된것이 넘어온다.
	{
		if (checked.ck_id())
		{
			_ID = checked;
		}
		/*잔액 불러오기*/
	}
	account(account& other) {
		_ID = other._ID;
		balance = other.balance;
	}
	void add(long a);//잔액증가
	void sub(long a);//잔액감소//잔액부족 던짐
	long GetBal() { return balance; }
	id GetID() { return _ID; }
};

