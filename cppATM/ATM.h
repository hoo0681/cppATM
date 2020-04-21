#pragma once
#include <iostream>
#include<sstream>
#include "handler.h"

class ATM
{
private:
	handler user;
	
	void login();//잘못되면 오류넘김
	account tagetid();//해당 계좌 불러오기.
	long moneyIN();//입력받은 금액 넘김
	template<typename T>
	T onlyNUM(T start,T end);//start~end 사이의 수를 입력받아 반환
public:
	ATM() {};
	void menu();
	void deposit();//입금
	void withdraw();//출금
	void transfar();//이체
	void checkAccount();//조회
};

