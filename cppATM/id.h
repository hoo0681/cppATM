#pragma once
#include<fstream>
#include<io.h>
#include<string>

class id// 계좌 불러올시 id& pw 및 이체 시 상대 계좌 불러오기용
{
protected: //상속받는 클래스에서도 사용할 멤버 변수들
	int ID[3];	//계좌번호 PW1:은행번호,PW2,3 : 계좌번호	
	std::string name;//이름
	std::string accpath;
public:
	id() {//기본생성자
		for (int i = 0; i < 3; i++) {
			ID[i] = 0;
		}		
	}
	//id 를 인수로 받는 생성자
	id(int* id) 
	{ 
		for (int i = 0; i < 3; i++) {
			ID[i] = id[i];//멤버변수에 복사
		}
		setpath();//계좌 번호로 파일 경로 만들기
		if (ck_id()) {//계좌의 유무확인
			setName();//이름 불러오기			
		}
	}
	//복사 생성자
	id(id& other)
	{
		for (int i = 0; i < 3; i++) {
			ID[i] = other.ID[i];//멤버변수 복사
		}
		name = other.name;//이름 복사
		setpath();//경로 만들기
	}
	~id() {}
	//계좌 번호로 파일 경로 만들기
	void setpath();
	//파일경로 반환
	std::string Getaccpath(){
		return accpath;//
	}
	//있는 id인지확인.계좌 이체 시 사용, 다형성을 위해 virtual함수로 선언
	virtual bool ck_id();
	//계좌 파일에 저장된 이름 불러오기
	void setName();
	//계좌의 주인 이름 반환
	std::string_view GetName(){ 
		return name;
	}//이름 내보내기
};

