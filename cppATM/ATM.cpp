#include "ATM.h"
using namespace std;
void ATM::login()
{
	int ID[3];
	string pw;
	cin.ignore(100, '\n');
	cout << "계좌번호를 입력하세요" << endl;
	for (int i = 0; i < 3; i++) {
		cin >> ID[i];
		if (cin.fail() || ID[i] < 0) {
			cout << "제대로 입력해주세요" << endl;
			cin.clear();
			cin.ignore(100, '\n');
			i = -1;
		}
	}
	cin.ignore(100, '\n');
	cout << "계좌 비밀번호를 넣으세요" << endl;
	cin >> pw;
	user = handler(ID, pw);//잘못 넘어가면 throw함
}
//account를 지역변수로 만들어넘김 주의!
account ATM::tagetid()//지역변수에의한 오류발생 가능성 있음 
{
	int ID[3];
	cout << "입금하실 계좌번호를 입력하세요" << endl;
	for (int i = 0; i < 3; i++) {
		cin >> ID[i];
		if (cin.fail() || ID[i] < 0) {
			cout << "제대로 입력해주세요" << endl;
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
	cout << "금액을 입력하세요" << endl;
	tmpMoney = onlyNUM(1l, LONG_MAX);
	return tmpMoney;
}

template<typename T>
 T ATM::onlyNUM(T start, T end)
{
	 T input;
	 //cin.ignore(100, '\n');
	 while (true) {
		cout << "입력:" << endl;
		cin >> input;
		if (cin.fail() || ((input > end) || (input < start))) {
			cout << "제대로 입력해주세요" << endl;
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
			cout << "[1]계좌 조회" << endl;
			cout << "[2]입금" << endl;
			cout << "[3]출금" << endl;
			cout << "[4]이체" << endl;
			idx = onlyNUM((int)1, (int)5);
			login();
			switch (idx)
			{
			case 1:
				checkAccount();
				break;
			case 2:
				deposit();//입금
				break;
			case 3:
				withdraw();//출금
				break;
			case 4:
				transfar();//계좌이체
				break;
			default:
				exit(0);
				break;
			}
		}
		catch (const char* msg)
		{
			puts(msg);
			puts("메뉴로 돌아갑니다.");
		}
	} while (true);
}

void ATM::deposit()//입금
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
	cout << "출금금액을 입력하세요." << endl;
	money=moneyIN();
	user.withdraw(money);
	checkAccount();
}

void ATM::transfar()
{
	long money;
	account traget=tagetid();
	char ans;
	cout << "받는사람: " << traget.GetID().GetName() << "님 맞습니까?" << endl;
	cout << "N을 눌러 메뉴로 돌아갈수 있습니다." << endl;
	cin >> ans;
	if (ans == 'N' || ans == 'n')throw "취소되었습니다.";
	cout << "고객님의 계좌 현황은 다음과 같습니다." << endl;
	checkAccount();
	cout << "이체하실 금액을 입력하세요" << endl;
	money = moneyIN();
	cout << money << "원을 이체합니다." << endl;
	cout << "N을 눌러 메뉴로 돌아갈수 있습니다." << endl;
	cin >> ans;
	if (ans == 'N' || ans == 'n')throw "취소되었습니다.";
	user.transfar(traget, money);
	cout << "완료" << endl;

}

void ATM::checkAccount()
{
	cout << "계좌 현황" << endl;
	string infos;
	string tmp;
	stringstream spilts;
	infos=user.checkAccount();
	spilts << infos;
	spilts >> tmp;
	cout << "이름: " << tmp << endl;
	spilts >> tmp;
	cout << "잔액: " << tmp << endl;
	
}
