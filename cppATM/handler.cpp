#include "handler.h"

handler::handler(int* id, long pw)
{
	this->user = id_pw(id, pw);
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
	}
	
}

void handler::transfar(int* id, long money)//송금 //이름까지 확인 되고 들어옴
{
	try
	{
		account target(id);
		user_acc.sub(money);
		target.add(money);
		user_acc.saveData();
		target.saveData();
	}
	catch (const char* err)
	{
		puts(err);
	}
}

void handler::checkAccount()//조회
{

}
