#pragma once
#include<fstream>
#include<io.h>
#include<string>
using namespace std;
class id// ���� �ҷ��ý� id& pw �� ��ü �� ��� ���� �ҷ������
{
protected: 
	int ID[3];	//���¹�ȣ PW1:�����ȣ,PW2,3 : ���¹�ȣ	
	string name;//�̸�
	string accpath;
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

	}
	~id() {
			
	}
	void setpath();
	string_view Getaccpath() { return accpath; }
	virtual bool ck_id();//�ִ� id����Ȯ��.���� ��ü �� ���
	void setName();//����� �̸� �ҷ�������.
	string_view GetName() { return name; }//�̸� ��������
};

