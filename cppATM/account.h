#pragma once
#include "id_pw.h"
//계좌 데이터 불러오기& 수정
class account
{
private: //id와 balance에 대한 직접적인 접근을 막는다.
	//계좌이체의 경우 비밀번호없이도 잔액이 수정되야하므로 
	//계좌번호만 갖는 id를 멤버로 갖는다. 
	//또한 account생성 후는 비밀번호를 기억하고있을 필요가없다.
	id _ID;
	//잔액
	long balance;
public:
	//기본생성자
	account() {
		balance = 0;
	}
	//생성자
	//계좌 번호를 인수로 받는 경우의 생성자
	account(int* _id) {//계좌 번호를 인수로 받는다
		_ID = id(_id);//id로 만들고 저장
		if (_ID.ck_id() == false)throw "wrong id";//없는 계좌인경우 throw한다,
		balance = SetBal();//있다면 잔액을 불러온다.
	}
	//id또는 id_pw를 인수로 받는 경우의 생성자
	//레퍼런스로 받으면 id를 비롯한 id를 상속받는 객체의 다형성을 활용할 수 있다.
	account(id& checked ) 
	{
		if (checked.ck_id())//ck_id는 checked의 타입에 따라 다르게 동작한다.
		{
			//확인된경우 멤버에 복사하는데 checked가 id_pw인 경우에는 
			//자동생성된 변환 연산자에 의해 pw부분이 truncation 된다.
			_ID = checked;
		}
		else throw "wrong id";//없는 ck_id의 결과가 false이면 throw한다.
		balance=SetBal();//잔액을 불러온다.
	}
	//복사 생성자
	account(account& other) {
		_ID = other._ID;
		balance = other.balance;
	}
	//잔액증가
	void add(long a);
	//잔액감소, 잔액부족 던짐
	void sub(long a);
	//잔액을 불러온다
	long SetBal();
	//잔액을 반환한다.
	long GetBal() { return balance; }
	//멤버 id를 반환한다.
	id GetID() { return _ID; }
	//변경사항 저장
	void saveData();
};

