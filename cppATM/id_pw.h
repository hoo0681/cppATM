#pragma once
#include "id.h"
class id_pw :
	public id
{
private: 
	std::string PW;//��й�ȣ
public:
	id_pw() :id() {
		
	}
	id_pw(int* id, std::string pw) :id(id)
	{
		PW = pw;
	}
	id_pw( id_pw& other):id(other)
	{
		PW = other.PW;
	}
	bool ck_id() override;//���� ���°ų�, �߸��� ����ΰ�� false
};

