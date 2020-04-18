#pragma once
#include<fstream>
#include<io.h>
#include<string>
using namespace std;
class id// 계좌 불러올시 id& pw 및 이체 시 상대 계좌 불러오기용
{
private:
	char* accpath;
protected: 
	int ID[3];	//계좌번호 PW1:은행번호,PW2,3 : 계좌번호	
	char* name;//이름
	
public:
	id() {//기본생성자
		for (int i = 0; i < 3; i++) {
			ID[i] = 0;
		}
		accpath = nullptr;
		name = nullptr;
	}
	id(int* id) //
	{ 
		for (int i = 0; i < 3; i++) {
			ID[i] = id[i];
		}
		if (ck_id()) {
			setName();
		}
		else {
			name = nullptr;
		}
	}//
	id(id& other)
	{
		for (int i = 0; i < 3; i++) {
			ID[i] = other.ID[i];
		}
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.GetName());

	}
	~id() {
		if(name!=nullptr) delete[] name;
		
	}
	void setpath();
	virtual bool ck_id();//있는 id인지확인.계좌 이체 시 사용
	void setName();//저장된 이름 불러와저장.
	const char* GetName() { return name; }//이름 내보내기
};

