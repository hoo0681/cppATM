#include "id.h"
void id::setpath()
{
	accpath = to_string(ID[0]);
	accpath.append(to_string(ID[1]));
	accpath.append(to_string(ID[2]));
	accpath.append(".txt");
}

bool id::ck_id()
{//path ex)ID.txt
	
	std::ifstream file(accpath);
	if (file.is_open()) {
		file.close();
		return true;
	}
	else
	{
		file.close();
		return false;
	}
}

void id::setName()
{//계좌 파일 내의 구조 [이름] {pw} (잔액);
	std::ifstream acc(this->accpath);
	std::string tmpname;
	size_t beginnum;
	size_t endnum;
	if (acc.is_open()){//다시한번확인
		acc.seekg(0);
		getline(acc,tmpname);
		beginnum = tmpname.find_first_of("[");
		endnum = tmpname.find_first_of("]");
		this->name = tmpname.substr(beginnum + 1, endnum - beginnum - 1);
	}
}
