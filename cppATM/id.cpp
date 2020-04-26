#include "id.h"
using namespace std;
void id::setpath()//계좌번호.txt가 파일 이름
{
	accpath = to_string(ID[0]);
	accpath.append(to_string(ID[1]));
	accpath.append(to_string(ID[2]));
	accpath.append(".txt");
}

bool id::ck_id()
{//path ex)ID.txt
	
	std::ifstream file(accpath);//파일을 찾아서 열어본다
	if (file.is_open()) {//제대로 열었으면 
		file.close();//다시 닫는다
		return true;//참을 반환
	}
	else
	{
		file.close();//제대로 열지 못했으면
		return false;//거짓을 반환
	}
}

void id::setName()
{//계좌 파일 내의 구조 [이름] {pw} (잔액);
	std::ifstream acc(this->accpath);//파일을 연다
	std::string tmpname;//파일 내용을 임시 저장할 변수
	size_t beginnum;//여는 대괄호 위치
	size_t endnum;//닫는 대괄호 위치
	if (acc.is_open()){//다시한번확인
		acc.seekg(0);//파일의 처음으로 이동
		getline(acc,tmpname);//내용읽어오기
		beginnum = tmpname.find_first_of("[");//여는 대괄호 위치 찾기
		endnum = tmpname.find_first_of("]");//닫는 대괄호 위치 찾기
		this->name = tmpname.substr(beginnum + 1, endnum - beginnum - 1);//이름을 읽어오기
	}
}
