#include "id.h"
using namespace std;
void id::setpath()//���¹�ȣ.txt�� ���� �̸�
{
	accpath = to_string(ID[0]);
	accpath.append(to_string(ID[1]));
	accpath.append(to_string(ID[2]));
	accpath.append(".txt");
}

bool id::ck_id()
{//path ex)ID.txt
	
	std::ifstream file(accpath);//������ ã�Ƽ� �����
	if (file.is_open()) {//����� �������� 
		file.close();//�ٽ� �ݴ´�
		return true;//���� ��ȯ
	}
	else
	{
		file.close();//����� ���� ��������
		return false;//������ ��ȯ
	}
}

void id::setName()
{//���� ���� ���� ���� [�̸�] {pw} (�ܾ�);
	std::ifstream acc(this->accpath);//������ ����
	std::string tmpname;//���� ������ �ӽ� ������ ����
	size_t beginnum;//���� ���ȣ ��ġ
	size_t endnum;//�ݴ� ���ȣ ��ġ
	if (acc.is_open()){//�ٽ��ѹ�Ȯ��
		acc.seekg(0);//������ ó������ �̵�
		getline(acc,tmpname);//�����о����
		beginnum = tmpname.find_first_of("[");//���� ���ȣ ��ġ ã��
		endnum = tmpname.find_first_of("]");//�ݴ� ���ȣ ��ġ ã��
		this->name = tmpname.substr(beginnum + 1, endnum - beginnum - 1);//�̸��� �о����
	}
}
