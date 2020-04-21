#pragma once
#include "id_pw.h"
class account//계좌 데이터 불러오기& 수정
{
private: 
	id _ID;
	long balance;
public:
	account() {
		balance = 0;
	}
	account(int* _id) {//잘못되면 오류넘김
		_ID = id(_id);
		if (_ID.ck_id() == false)throw "wrong id";
		balance = SetBal();
	}
	account(id& checked ) //id 와 pw는 확인된것이 넘어온다.
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
	void add(long a);//잔액증가
	void sub(long a);//잔액감소//잔액부족 던짐
	long SetBal();
	long GetBal() { return balance; }
	id GetID() { return _ID; }
	void saveData();//변경사항 저장
};

