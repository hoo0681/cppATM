#include "id.h"
void id::setpath()
{
	int idlen=5;//.txt(4) + null(1)
	for (int a = 0; a < 3; a++) {
		idlen += log10(ID[a]);
	}
	accpath = new char[idlen](); //�Ҵ��� �ʱ�ȭ
	char tmp[10] = {0};//�ʱ�ȭ
	for (int a = 0; a < 3; a++)
	{
		strcat(accpath, _itoa(ID[a],tmp , 10));
	}
	strcat(accpath, ".txt");
}

bool id::ck_id()
{//path ex)ID.txt
	
	std::ifstream file(accpath);
	if (file.is_open()) {
		return true;
	}
	else return false;
}

void id::setName()
{//���� ���� ���� ���� [�̸�] {pw} (�ܾ�);
	std::ifstream acc(this->accpath);
	std::string tmpname;
	if (acc.is_open()){//�ٽ��ѹ�Ȯ��
		acc.seekg(0);
		getline(acc,tmpname);
	}
}
