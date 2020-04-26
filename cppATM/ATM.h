#pragma once
#include <iostream>
#include<sstream>
#include "handler.h"

class ATM
{
private:
	//사용자
	handler user;
	//handler에 로그인 잘못되면 오류 throw
	void login();
	//해당 계좌 불러오기.
	account tagetid();
	//입력받은 금액 넘김
	long moneyIN();
	//start~end 사이의 수를 입력받아 반환
	template<typename T>
	T onlyNUM(T start,T end);
	//입금
	void deposit();
	//출금
	void withdraw();
	//이체
	void transfar();
	//조회
	void checkAccount();
public:
	//기본 생성자
	ATM() {};
	//메뉴창
	void menu();
	
};

