#pragma once
#include<fstream>
#include<io.h>
#include<string>

class id// ���� �ҷ��ý� id& pw �� ��ü �� ��� ���� �ҷ������
{
protected: 
	int ID[3];	//���¹�ȣ PW1:�����ȣ,PW2,3 : ���¹�ȣ	
	std::string name;//�̸�
	std::string accpath;
public:
	id() {//�⺻������
		for (int i = 0; i < 3; i++) {
			ID[i] = 0;
		}
		
	}
	id(int* id) //
	{ 
		for (int i = 0; i < 3; i++) {
			ID[i] = id[i];
		}
		setpath();
		if (ck_id()) {
			setName();
			
		}
	}//
	id(id& other)
	{
		for (int i = 0; i < 3; i++) {
			ID[i] = other.ID[i];
		}
		name = other.name;
		setpath();
	}
	~id() {
			
	}
	void setpath();
	std::string Getaccpath(){
		return accpath;
	}
	virtual bool ck_id();//�ִ� id����Ȯ��.���� ��ü �� ���
	void setName();//����� �̸� �ҷ�������.
	std::string_view GetName(){ 
		return name;
	}//�̸� ��������
};

