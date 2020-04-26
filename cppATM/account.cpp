#include "account.h"
#include<ostream>
using namespace std;
void account::add(long a)
{
	balance += a;//잔액 증가
}

void account::sub(long a)
{
	if ((balance - a) < 0) throw "잔액부족";//잔액 부족시 throw 함
	balance -= a;//잔액 감소
}

long account::SetBal()
{
	string tmpbal;//계좌 내용
	size_t beginnum;//여는 괄호index
	size_t endnum;//닫는 괄호index
	string path(this->_ID.Getaccpath());//계좌 파일 path
	ifstream balpath(path);//계좌 파일 열기
	if (balpath.is_open())//정상적으로 열었다면
	{
		getline(balpath, tmpbal);//내용 긁어오기
		beginnum = tmpbal.find_first_of("(");//여는 괄호 위치 찾기
		endnum = tmpbal.find_first_of(")");//닫는 괄호 위치 찾기
		balpath.close();//파일 닫기
		return stol(tmpbal.substr(beginnum + 1, endnum - beginnum - 1));//괄호 사이의 잔액 읽어오기
	}
	return 0;
}

void account::saveData()
{
	string tmpbal;//계좌 내용
	size_t beginnum;//여는 괄호 위치
	size_t endnum;//닫는 괄호 위치
	string path(this->_ID.Getaccpath());//계좌 파일 path
	ifstream balpath(path);//계좌 파일 열기
	ofstream savepath;//저장용 stream 선언
	if (balpath.is_open())// 정상적으로 열었다면
	{
		getline(balpath, tmpbal);//내용 긁어오기
		beginnum = tmpbal.find_first_of("(");//여는 괄호 찾기
		endnum = tmpbal.find_first_of(")");//닫는 괄호 찾기
		tmpbal.replace(tmpbal.begin()+beginnum+1,tmpbal.begin()+endnum,to_string(this->balance));//긁어온 내용에서 괄호 사이의 값을 새로운 값으로 대치하기
	}
	balpath.close();//파일 닫기
	savepath.open(path);//쓰기용으로 파일 열기
	if (savepath.is_open())//정상적으로 열었다면
	{
		savepath << tmpbal;//파일에 저장
	}
	savepath.close();//파일 닫기
}
