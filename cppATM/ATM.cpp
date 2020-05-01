#include "ATM.h"
using namespace std;
void ATM::login()
{
	int ID[3];//���� ��ȣ�� 3���� ������
	string pw;//��й�ȣ�� ���ڿ��� �޴´�
	cin.ignore(100, '\n');//���� �Էµ� ���ڵ��� �����Ѵ�
	cout << "���¹�ȣ�� �Է��ϼ���" << endl;
	for (int i = 0; i < 3; i++) {
		cin >> ID[i];//������ �޴´�
		if (cin.fail() || ID[i] < 0) {//������ �ƴϰų� ������ ������
			cout << "����� �Է����ּ���" << endl;
			cin.clear();//���� �÷��׸� ���� 
			cin.ignore(100, '\n');//������ �����Ѵ�
			i = -1;//�ε����� �ʱ�ȭ�Ѵ�.
		}
	}
	cin.ignore(100, '\n');//3ȸ�� ����� �Է��� �����Ѵ�.
	cout << "���� ��й�ȣ�� ��������" << endl;
	cin >> pw;//��й�ȣ �Է�
	user = handler(ID, pw);//�߸� �Ѿ�� throw��
}
//account�� ���������� ����� �ѱ� ����!
account ATM::tagetid()//�������������� �����߻� ���ɼ� ���� 
{
	int ID[3];//�Է� ���� ���¹�ȣ ����
	cout << "�Ա��Ͻ� ���¹�ȣ�� �Է��ϼ���" << endl;
	for (int i = 0; i < 3; i++) {
		cin >> ID[i];//���¹�ȣ�� �Է�
		if (cin.fail() || ID[i] < 0) {//������ �ƴϰų� �������
			cout << "����� �Է����ּ���" << endl;
			cin.clear();//���� �÷��׸� ����
			cin.ignore(100, '\n');//������ ����
			i = -1;//�ε��� �ʱ�ȭ
		}
	}
	return account(ID);//���¹�ȣ�� accout����� ��ȯ
}
//�� �Է� �޴� �Լ�
long ATM::moneyIN()
{
	long tmpMoney;//����
	cout << "�ݾ��� �Է��ϼ���" << endl;
	tmpMoney = onlyNUM<long>(1l, LONG_MAX);//1~long�� �ִ밪 ������ ���� �Է¹޾� ����
	return tmpMoney;//��ȯ
}

template<typename T>//���ø��� �̿��� Ÿ�� ������� ���� ���� ���ڸ� �Է� �޴� �Լ�
 T ATM::onlyNUM(T start, T end)
{
	 T input;//����
	 while (true) {
		cout << "�Է�:" << endl;
		cin >> input;//�Է� �ޱ�
		if (cin.fail() || ((input > end) || (input < start))) {//Ÿ���� �ȸ°ų� ������ �Ѿ��
			cout << "����� �Է����ּ���" << endl;
			cin.clear();//���� �÷��� ����
			cin.ignore(100, '\n');//���빫��
		}
		else {
			break;//����� �Է� �޾����� �ݺ��� Ż��
		}
	 }
	 return input;//�Է� ���� �� ��ȯ
}

void ATM::menu()//�޴�â
{
	int idx = 0;
	do
	{
		try//���� ���� throw�� �޴´�
		{
			cout << "Menu" << endl;
			cout << "[1]���� ��ȸ" << endl;
			cout << "[2]�Ա�" << endl;
			cout << "[3]���" << endl;
			cout << "[4]��ü" << endl;
			idx = onlyNUM<int>(1,5); //��ɼ���
			login();//���� �α���
			switch (idx)//���
			{
			case 1:
				checkAccount();//��ȸ
				break;
			case 2:
				deposit();//�Ա�
				break;
			case 3:
				withdraw();//���
				break;
			case 4:
				transfer();//������ü
				break;
			default:
				exit(0);//ATM����
				break;
			}
		}
		catch (const char* msg)//throw������
		{
			puts(msg);//���� �޼��� ���
			puts("�޴��� ���ư��ϴ�.");//�޴��� ���ư���
		}
	} while (true);
}

void ATM::deposit()//�Ա�
{
	long money;//
	money=moneyIN();//�ݾ��� �Է� �޴´�
	user.deposit(money);//�Է� ���� �ݾ��� handler�� ���� �Ա�
	checkAccount();//���� ��Ȳ ���
}

void ATM::withdraw()//���
{
	long money;//
	checkAccount();//����� �ܾ� ��ȸ
	cout << "��ݱݾ��� �Է��ϼ���." << endl;
	money=moneyIN();//�ݾ��� �Է� �޴´�
	user.withdraw(money);//���, �ܾ��� �����ϸ� ���� �޼����� throw �Ѵ�. 
	checkAccount();//����� �ܾ� ��ȸ
}

void ATM::transfer()//��ü
{
	long money;
	account traget=tagetid();//��ü ����� ���¸� �ҷ��´�, ���� ���¸� �޼��� throw
	char ans;//��ҿ� 
	cout << "�޴»��: " << traget.GetID().GetName() << "�� �½��ϱ�?" << endl;//�����ָ� Ȯ��
	cout << "N�� ���� �޴��� ���ư��� �ֽ��ϴ�." << endl;
	cin >> ans;//���
	if (ans == 'N' || ans == 'n')throw "��ҵǾ����ϴ�.";//����ϸ� �޼��� throw
	cout << "������ ���� ��Ȳ�� ������ �����ϴ�." << endl;
	checkAccount();//���� ��Ȳ
	cout << "��ü�Ͻ� �ݾ��� �Է��ϼ���" << endl;
	money = moneyIN();//�ݾ� �Է�
	cout << money << "���� ��ü�մϴ�." << endl;
	cout << "N�� ���� �޴��� ���ư��� �ֽ��ϴ�." << endl;
	cin >> ans;//���
	if (ans == 'N' || ans == 'n')throw "��ҵǾ����ϴ�.";//����ϸ� �޼��� throw
	user.transfar(traget, money);//���� ��ü, �ܾ� ������ �޼��� throw
	cout << "�Ϸ�" << endl;

}

void ATM::checkAccount()
{
	cout << "���� ��Ȳ" << endl;
	string infos;//�̸��� �ܾ��� ������ �����ڷ� ���´�
	string tmp;//��¿� �ӽ� ����
	stringstream spilts;//string�� streamó�� ����ϱ�����
	infos=user.checkAccount();//infos ����)�̸� �ܾ�
	spilts << infos;//spilts�� infos�� ������ �Է�
	spilts >> tmp;//>>�����ڸ� �̿��Ͽ� ������ �����ڷ� �̸��� �о��
	cout << "�̸�: " << tmp << endl;
	spilts >> tmp;//>>�����ڸ� �̿��Ͽ� ������ �����ڷ� �ܾ��� �о��
	cout << "�ܾ�: " << tmp << endl;
	
}
