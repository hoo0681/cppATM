#pragma once
#include<fstream>
#include<io.h>
#include<string>
using namespace std;
class id// ���� �ҷ��ý� id& pw �� ��ü �� ��� ���� �ҷ������
{
private:
	char* accpath;
protected: 
	int ID[3];	//���¹�ȣ PW1:�����ȣ,PW2,3 : ���¹�ȣ	
	char* name;//�̸�
	
public:
	id() {//�⺻������
		for (int i = 0; i < 3; i++) {
			ID[i] = 0;
		}
		accpath = nullptr;
		name = nullptr;
	}
	id(int* id) //
	{ 
		for (int i = 0; i < 3; i++) {
			ID[i] = id[i];
		}
		if (ck_id()) {
			setName();
		}
		else {
			name = nullptr;
		}
	}//
	id(id& other)
	{
		for (int i = 0; i < 3; i++) {
			ID[i] = other.ID[i];
		}
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.GetName());

	}
	~id() {
		if(name!=nullptr) delete[] name;
		
	}
	void setpath();
	virtual bool ck_id();//�ִ� id����Ȯ��.���� ��ü �� ���
	void setName();//����� �̸� �ҷ�������.
	const char* GetName() { return name; }//�̸� ��������
};

