#include "handler.h"

handler::handler(int* id, std::string pw)
{
	id_pw user= id_pw(id, pw);//계좌번호와 비밀번호로 id_pw 생성 
	if (user.ck_id()) {//진위확인
		user_acc = account(user);//확인된 id,pw로 user_acc 초기화 ( 복사생성자를 이용하여 내용을 복사)
	}
	else {
		throw "wrong account";//없는 계좌 이거나 비밀 번호가 다르면 메세지 throw
	}
}

void handler::deposit(long money)//입금
{
	user_acc.add(money);//금액 추가
	user_acc.saveData();//변경사항 저장
}

void handler::withdraw(long money)//출금
{
	try
	{
		user_acc.sub(money);//출금시도 
		user_acc.saveData();//성공시 저장
	}
	catch (const char* err)//throw된 메세지 있다면
	{
		puts(err);//출력후
		throw err;//다시 던진다
	}
	
}
//이름까지 확인 되고 들어오셈
void handler::transfar(account _id, long money)//송금 
{
	try
	{
		account target(_id);//없는 아이디면 throw 함
		user_acc.sub(money);//잔액 부족이면 throw 함
		target.add(money);//상대계좌에 입금
		user_acc.saveData();//변경사항 저장
		target.saveData();//변경사항 저장
	}
	catch (const char* err)//throw된 메세지 있다면
	{
		puts(err);//출력후
		throw err;//다시 던진다
	}
}
//이름과 잔액을 공백으로 구분한 문자열 반환
std::string handler::checkAccount()//조회
{
	std::string info;//문자열 
	info.append(user_acc.GetID().GetName());//이름
	info.append(" ");//공백
	info.append(std::to_string(user_acc.GetBal()));//잔액
	return info;//이름 잔액 반환
}
