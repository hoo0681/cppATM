#include "ATM.h"
using namespace std;
void ATM::login()
{
	int ID[3];
	string pw;
	cin.ignore(100, '\n');
	cout << "���¹�ȣ�� �Է��ϼ���" << endl;
	for (int i = 0; i < 3; i++) {
		cin >> ID[i];
		if (cin.fail() || ID[i] < 0) {
			cout << "����� �Է����ּ���" << endl;
			cin.clear();
			cin.ignore(100, '\n');
			i = -1;
		}
	}
	cin.ignore(100, '\n');
	cout << "���� ��й�ȣ�� ��������" << endl;
	cin >> pw;
	user = handler(ID, pw);//�߸� �Ѿ�� throw��
}
//account�� ���������� �����ѱ� ����!
account ATM::tagetid()//�������������� �����߻� ���ɼ� ���� 
{
	int ID[3];
	cout << "�Ա��Ͻ� ���¹�ȣ�� �Է��ϼ���" << endl;
	for (int i = 0; i < 3; i++) {
		cin >> ID[i];
		if (cin.fail() || ID[i] < 0) {
			cout << "����� �Է����ּ���" << endl;
			cin.clear();
			cin.ignore(100, '\n');
			i = -1;
		}
	}
	return account(ID);
}

long ATM::moneyIN()
{
	long tmpMoney;
	cout << "�ݾ��� �Է��ϼ���" << endl;
	tmpMoney = onlyNUM(1l, LONG_MAX);
	return tmpMoney;
}

template<typename T>
 T ATM::onlyNUM(T start, T end)
{
	 T input;
	 //cin.ignore(100, '\n');
	 while (true) {
		cout << "�Է�:" << endl;
		cin >> input;
		if (cin.fail() || ((input > end) || (input < start))) {
			cout << "����� �Է����ּ���" << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
		else {
			break;
		}
	 }
	 return input;
}

void ATM::menu()
{
	int idx = 0;
	bool err = true;
	do
	{
		try
		{
			cout << "Menu" << endl;
			cout << "[1]���� ��ȸ" << endl;
			cout << "[2]�Ա�" << endl;
			cout << "[3]���" << endl;
			cout << "[4]��ü" << endl;
			idx = onlyNUM((int)1, (int)5);
			login();
			switch (idx)
			{
			case 1:
				checkAccount();
				break;
			case 2:
				deposit();//�Ա�
				break;
			case 3:
				withdraw();//���
				break;
			case 4:
				transfar();//������ü
				break;
			default:
				exit(0);
				break;
			}
		}
		catch (const char* msg)
		{
			puts(msg);
			puts("�޴��� ���ư��ϴ�.");
		}
	} while (true);
}

void ATM::deposit()//�Ա�
{
	long money;
	money=moneyIN();
	user.deposit(money);
	checkAccount();
}

void ATM::withdraw()
{
	long money;
	checkAccount();
	cout << "��ݱݾ��� �Է��ϼ���." << endl;
	money=moneyIN();
	user.withdraw(money);
	checkAccount();
}

void ATM::transfar()
{
	long money;
	account traget=tagetid();
	char ans;
	cout << "�޴»��: " << traget.GetID().GetName() << "�� �½��ϱ�?" << endl;
	cout << "N�� ���� �޴��� ���ư��� �ֽ��ϴ�." << endl;
	cin >> ans;
	if (ans == 'N' || ans == 'n')throw "��ҵǾ����ϴ�.";
	cout << "������ ���� ��Ȳ�� ������ �����ϴ�." << endl;
	checkAccount();
	cout << "��ü�Ͻ� �ݾ��� �Է��ϼ���" << endl;
	money = moneyIN();
	cout << money << "���� ��ü�մϴ�." << endl;
	cout << "N�� ���� �޴��� ���ư��� �ֽ��ϴ�." << endl;
	cin >> ans;
	if (ans == 'N' || ans == 'n')throw "��ҵǾ����ϴ�.";
	user.transfar(traget, money);
	cout << "�Ϸ�" << endl;

}

void ATM::checkAccount()
{
	cout << "���� ��Ȳ" << endl;
	string infos;
	string tmp;
	stringstream spilts;
	infos=user.checkAccount();
	spilts << infos;
	spilts >> tmp;
	cout << "�̸�: " << tmp << endl;
	spilts >> tmp;
	cout << "�ܾ�: " << tmp << endl;
	
}
