#include "id_pw.h"
using namespace std;
bool id_pw::ck_id()
{
	std::string tmpw;//계좌 내용
	size_t beginnum;//여는 중괄호 위치
	size_t endnum;//닫는 중괄호 위치
	std::ifstream file(accpath);//파일 열기
	if (file.is_open()) {//제대로 열렸으면
		getline(file, tmpw);//내용 읽어오기
		beginnum = tmpw.find_first_of("{");//여는 중괄호 위치
		endnum = tmpw.find_first_of("}");//닫는 중괄호 위치
		//중괄호 사이의 비밀번호가 입력 받은 비밀번호와 일치하는지 확인
		if (this->PW == tmpw.substr(beginnum + 1, endnum - beginnum - 1))
		{
			file.close();//파일 닫기
			return true;//참 반환
		}
		else {
			file.close();//파일 닫기
			return false;//거짓 반환
		}
	}
	else
	{
		file.close();//파일 닫기
		return false;//거짓 반환
	}
	
}
