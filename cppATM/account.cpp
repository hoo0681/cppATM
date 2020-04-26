#include "account.h"
#include<ostream>
using namespace std;
void account::add(long a)
{
	balance += a;//�ܾ� ����
}

void account::sub(long a)
{
	if ((balance - a) < 0) throw "�ܾ׺���";//�ܾ� ������ throw ��
	balance -= a;//�ܾ� ����
}

long account::SetBal()
{
	string tmpbal;//���� ����
	size_t beginnum;//���� ��ȣindex
	size_t endnum;//�ݴ� ��ȣindex
	string path(this->_ID.Getaccpath());//���� ���� path
	ifstream balpath(path);//���� ���� ����
	if (balpath.is_open())//���������� �����ٸ�
	{
		getline(balpath, tmpbal);//���� �ܾ����
		beginnum = tmpbal.find_first_of("(");//���� ��ȣ ��ġ ã��
		endnum = tmpbal.find_first_of(")");//�ݴ� ��ȣ ��ġ ã��
		balpath.close();//���� �ݱ�
		return stol(tmpbal.substr(beginnum + 1, endnum - beginnum - 1));//��ȣ ������ �ܾ� �о����
	}
	return 0;
}

void account::saveData()
{
	string tmpbal;//���� ����
	size_t beginnum;//���� ��ȣ ��ġ
	size_t endnum;//�ݴ� ��ȣ ��ġ
	string path(this->_ID.Getaccpath());//���� ���� path
	ifstream balpath(path);//���� ���� ����
	ofstream savepath;//����� stream ����
	if (balpath.is_open())// ���������� �����ٸ�
	{
		getline(balpath, tmpbal);//���� �ܾ����
		beginnum = tmpbal.find_first_of("(");//���� ��ȣ ã��
		endnum = tmpbal.find_first_of(")");//�ݴ� ��ȣ ã��
		tmpbal.replace(tmpbal.begin()+beginnum+1,tmpbal.begin()+endnum,to_string(this->balance));//�ܾ�� ���뿡�� ��ȣ ������ ���� ���ο� ������ ��ġ�ϱ�
	}
	balpath.close();//���� �ݱ�
	savepath.open(path);//��������� ���� ����
	if (savepath.is_open())//���������� �����ٸ�
	{
		savepath << tmpbal;//���Ͽ� ����
	}
	savepath.close();//���� �ݱ�
}
