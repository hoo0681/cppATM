#pragma once
#include<fstream>
#include<io.h>
#include<string>

class id// ���� �ҷ��ý� id& pw �� ��ü �� ��� ���� �ҷ������
{
protected: //��ӹ޴� Ŭ���������� ����� ��� ������
	int ID[3];	//���¹�ȣ PW1:�����ȣ,PW2,3 : ���¹�ȣ	
	std::string name;//�̸�
	std::string accpath;
public:
	id() {//�⺻������
		for (int i = 0; i < 3; i++) {
			ID[i] = 0;
		}		
	}
	//id �� �μ��� �޴� ������
	id(int* id) 
	{ 
		for (int i = 0; i < 3; i++) {
			ID[i] = id[i];//��������� ����
		}
		setpath();//���� ��ȣ�� ���� ��� �����
		if (ck_id()) {//������ ����Ȯ��
			setName();//�̸� �ҷ�����			
		}
	}
	//���� ������
	id(id& other)
	{
		for (int i = 0; i < 3; i++) {
			ID[i] = other.ID[i];//������� ����
		}
		name = other.name;//�̸� ����
		setpath();//��� �����
	}
	~id() {}
	//���� ��ȣ�� ���� ��� �����
	void setpath();
	//���ϰ�� ��ȯ
	std::string Getaccpath(){
		return accpath;//
	}
	//�ִ� id����Ȯ��.���� ��ü �� ���, �������� ���� virtual�Լ��� ����
	virtual bool ck_id();
	//���� ���Ͽ� ����� �̸� �ҷ�����
	void setName();
	//������ ���� �̸� ��ȯ
	std::string_view GetName(){ 
		return name;
	}//�̸� ��������
};

