#pragma once
#include "id.h"
class id_pw :
	public id
	//id�� ��ӹ޴µ� id�� public ������� id_pw�� ���� ȣ���� �� �ֵ��� ��ӹ޴´�.
{
private: 
	//��й�ȣ�� ���� �������� 0000���� ��� ��ȣ�� ���� �� ������ string Ÿ������ ����
	std::string PW;
public:
	//�⺻ ������
	id_pw() :id() {
		
	}
	//id�� password�� �޴� ������
	id_pw(int* id, std::string pw) :id(id)
	{
		PW = pw;
	}
	//���� ������
	id_pw( id_pw& other):id(other)//�θ�Ŭ������ ��������ڵ� ȣ���Ѵ�.
	{
		PW = other.PW;
	}
	//���� ���°ų�, �߸��� ����ΰ�� false, ��й�ȣ�� �˻��ϵ��� �������̵�
	bool ck_id() override;
};

