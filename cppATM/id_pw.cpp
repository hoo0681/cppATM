#include "id_pw.h"

bool id_pw::ck_id()
{
	std::string tmpw;
	size_t beginnum;
	size_t endnum;
	std::ifstream file(accpath);
	if (file.is_open()) {
		getline(file, tmpw);
		beginnum = tmpw.find_first_of("{");
		endnum = tmpw.find_first_of("}");
		if (this->PW == tmpw.substr(beginnum + 1, endnum - beginnum - 1))
		{
			file.close();
			return true;
		}
		else {
			return false;
		}
	}
	else
	{
		file.close();
		return false;
	}
	
}
