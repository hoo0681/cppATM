#include "handler.h"

handler::handler(int* id, std::string pw)
{
	id_pw user= id_pw(id, pw); 
	if (user.ck_id()) {
		user_acc = account(user);
	}
	else {
		throw "wrong account";
	}
}

void handler::deposit(long money)//입금
{
	user_acc.add(money);
	user_acc.saveData();
}

void handler::withdraw(long money)//출금
{
	try
	{
		user_acc.sub(money);
		user_acc.saveData();
	}
	catch (const char* err)
	{
		puts(err);
		throw err;
	}
	
}
//이름까지 확인 되고 들어오셈
void handler::transfar(account _id, long money)//송금 
{
	try
	{
		account target(_id);//없는 아이디면 throw 함
		user_acc.sub(money);//잔액 부족이면 throw 함
		target.add(money);
		user_acc.saveData();
		target.saveData();
	}
	catch (const char* err)
	{
		puts(err);
		throw err;
	}
}
//이름과 잔액을 공백으로 구분한 문자열 반환
std::string handler::checkAccount()//조회
{
	std::string info;
	info.append(user_acc.GetID().GetName());
	info.append(" ");
	info.append(std::to_string(user_acc.GetBal()));
	return info;
}
