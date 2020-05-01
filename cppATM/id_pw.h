#pragma once
#include "id.h"
class id_pw :
	public id
	//id를 상속받는데 id의 public 멤버들을 id_pw를
	//통해 호출할 수 있도록 상속받는다.
{
private: 
	//비밀번호는 전부 숫자지만 0000같은 
	//비밀 번호도 있을 수 있으니 string 타입으로 선언
	std::string PW;
public:
	//기본 생성자
	id_pw() :id() {}
	//id와 password를 받는 생성자
	id_pw(int* id, std::string pw) :id(id)
	{	PW = pw;	}
	//복사 생성자
	//부모클래스의 복사생성자도 호출한다.
	id_pw( id_pw& other):id(other)
	{
		PW = other.PW;
	}
	//없는 계좌거나, 잘못된 비번인경우 false, 
	//비밀번호도 검사하도록 오버라이드
	bool ck_id() override;
};

