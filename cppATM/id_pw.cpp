#include "id_pw.h"
using namespace std;
bool id_pw::ck_id()
{
	std::string tmpw;//���� ����
	size_t beginnum;//���� �߰�ȣ ��ġ
	size_t endnum;//�ݴ� �߰�ȣ ��ġ
	std::ifstream file(accpath);//���� ����
	if (file.is_open()) {//����� ��������
		getline(file, tmpw);//���� �о����
		beginnum = tmpw.find_first_of("{");//���� �߰�ȣ ��ġ
		endnum = tmpw.find_first_of("}");//�ݴ� �߰�ȣ ��ġ
		//�߰�ȣ ������ ��й�ȣ�� �Է� ���� ��й�ȣ�� ��ġ�ϴ��� Ȯ��
		if (this->PW == tmpw.substr(beginnum + 1, endnum - beginnum - 1))
		{
			file.close();//���� �ݱ�
			return true;//�� ��ȯ
		}
		else {
			file.close();//���� �ݱ�
			return false;//���� ��ȯ
		}
	}
	else
	{
		file.close();//���� �ݱ�
		return false;//���� ��ȯ
	}
	
}
