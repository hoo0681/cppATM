#include "ATM.h"
using namespace std;
void ATM::login()
{
	int ID[3];//계좌 번호는 3개의 정수들
	string pw;//비밀번호는 문자열로 받는다
	cin.ignore(100, '\n');//전에 입력된 문자들을 무시한다
	cout << "계좌번호를 입력하세요" << endl;
	for (int i = 0; i < 3; i++) {
		cin >> ID[i];//정수를 받는다
		if (cin.fail() || ID[i] < 0) {//정수가 아니거나 음수가 들어오면
			cout << "제대로 입력해주세요" << endl;
			cin.clear();//오류 플래그를 끄고 
			cin.ignore(100, '\n');//내용을 무시한다
			i = -1;//인덱스를 초기화한다.
		}
	}
	cin.ignore(100, '\n');//3회를 벗어나는 입력을 무시한다.
	cout << "계좌 비밀번호를 넣으세요" << endl;
	cin >> pw;//비밀번호 입력
	user = handler(ID, pw);//잘못 넘어가면 throw함
}
//account를 지역변수로 만들어 넘김 주의!
account ATM::tagetid()//지역변수에의한 오류발생 가능성 있음 
{
	int ID[3];//입력 받은 계좌번호 변수
	cout << "입금하실 계좌번호를 입력하세요" << endl;
	for (int i = 0; i < 3; i++) {
		cin >> ID[i];//계좌번호를 입력
		if (cin.fail() || ID[i] < 0) {//정수가 아니거나 음수라면
			cout << "제대로 입력해주세요" << endl;
			cin.clear();//오류 플래그를 끄고
			cin.ignore(100, '\n');//내용을 무시
			i = -1;//인덱스 초기화
		}
	}
	return account(ID);//계좌번호로 accout만들어 반환
}
//돈 입력 받는 함수
long ATM::moneyIN()
{
	long tmpMoney;//변수
	cout << "금액을 입력하세요" << endl;
	tmpMoney = onlyNUM<long>(1l, LONG_MAX);//1~long의 최대값 사이의 값을 입력받아 저장
	return tmpMoney;//반환
}

template<typename T>//템플릿을 이용한 타입 상관없이 범위 내의 숫자를 입력 받는 함수
 T ATM::onlyNUM(T start, T end)
{
	 T input;//변수
	 while (true) {
		cout << "입력:" << endl;
		cin >> input;//입력 받기
		if (cin.fail() || ((input > end) || (input < start))) {//타입이 안맞거나 범위를 넘어가면
			cout << "제대로 입력해주세요" << endl;
			cin.clear();//오류 플래그 끄고
			cin.ignore(100, '\n');//내용무시
		}
		else {
			break;//제대로 입력 받았으면 반복문 탈출
		}
	 }
	 return input;//입력 받은 값 반환
}

void ATM::menu()//메뉴창
{
	int idx = 0;
	do
	{
		try//실행 중의 throw를 받는다
		{
			cout << "Menu" << endl;
			cout << "[1]계좌 조회" << endl;
			cout << "[2]입금" << endl;
			cout << "[3]출금" << endl;
			cout << "[4]이체" << endl;
			idx = onlyNUM<int>(1,5); //기능선택
			login();//계좌 로그인
			switch (idx)//기능
			{
			case 1:
				checkAccount();//조회
				break;
			case 2:
				deposit();//입금
				break;
			case 3:
				withdraw();//출금
				break;
			case 4:
				transfer();//계좌이체
				break;
			default:
				exit(0);//ATM종료
				break;
			}
		}
		catch (const char* msg)//throw있으면
		{
			puts(msg);//받은 메세지 출력
			puts("메뉴로 돌아갑니다.");//메뉴로 돌아간다
		}
	} while (true);
}

void ATM::deposit()//입금
{
	long money;//
	money=moneyIN();//금액을 입력 받는다
	user.deposit(money);//입력 받은 금액을 handler를 통해 입금
	checkAccount();//계좌 현황 출력
}

void ATM::withdraw()//출금
{
	long money;//
	checkAccount();//출금전 잔액 조회
	cout << "출금금액을 입력하세요." << endl;
	money=moneyIN();//금액을 입력 받는다
	user.withdraw(money);//출금, 잔액이 부족하면 오류 메세지를 throw 한다. 
	checkAccount();//출금후 잔액 조회
}

void ATM::transfer()//이체
{
	long money;
	account traget=tagetid();//이체 대상의 계좌를 불러온다, 없는 계좌면 메세지 throw
	char ans;//취소용 
	cout << "받는사람: " << traget.GetID().GetName() << "님 맞습니까?" << endl;//예금주명 확인
	cout << "N을 눌러 메뉴로 돌아갈수 있습니다." << endl;
	cin >> ans;//대답
	if (ans == 'N' || ans == 'n')throw "취소되었습니다.";//취소하면 메세지 throw
	cout << "고객님의 계좌 현황은 다음과 같습니다." << endl;
	checkAccount();//계좌 현황
	cout << "이체하실 금액을 입력하세요" << endl;
	money = moneyIN();//금액 입력
	cout << money << "원을 이체합니다." << endl;
	cout << "N을 눌러 메뉴로 돌아갈수 있습니다." << endl;
	cin >> ans;//대답
	if (ans == 'N' || ans == 'n')throw "취소되었습니다.";//취소하면 메세지 throw
	user.transfar(traget, money);//계좌 이체, 잔액 부족시 메세지 throw
	cout << "완료" << endl;

}

void ATM::checkAccount()
{
	cout << "계좌 현황" << endl;
	string infos;//이름과 잔액이 공백을 구분자로 들어온다
	string tmp;//출력용 임시 변수
	stringstream spilts;//string을 stream처럼 사용하기위함
	infos=user.checkAccount();//infos 예시)이름 잔액
	spilts << infos;//spilts에 infos의 내용을 입력
	spilts >> tmp;//>>연산자를 이용하여 공백을 구분자로 이름을 읽어옴
	cout << "이름: " << tmp << endl;
	spilts >> tmp;//>>연산자를 이용하여 공백을 구분자로 잔액을 읽어옴
	cout << "잔액: " << tmp << endl;
	
}
