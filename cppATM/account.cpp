#include "account.h"

void account::add(long a)
{
	balance += a;
}

void account::sub(long a)
{
	if ((balance - a) < 0) throw "ÀÜ¾×ºÎÁ·";
	balance -= a;
}

long account::SetBal()
{
	string tmpbal;
	size_t beginnum;
	size_t endnum;
	string path(this->_ID.Getaccpath());
	ifstream balpath(path);
	if (balpath.is_open())
	{
		getline(balpath, tmpbal);
		beginnum = tmpbal.find_first_of("{");
		endnum = tmpbal.find_first_of("}");
		return stol(tmpbal.substr(beginnum + 1, endnum - beginnum - 1));
	}
	return 0;
}

void account::saveData()
{
	string tmpbal;
	size_t beginnum;
	size_t endnum;
	string path(this->_ID.Getaccpath());
	ifstream balpath(path);
	if (balpath.is_open())
	{
		getline(balpath, tmpbal);
		beginnum = tmpbal.find_first_of("(");
		endnum = tmpbal.find_first_of(")");
		tmpbal.replace(tmpbal.begin()+beginnum,tmpbal.begin+endnum,to_string(this->balance));
	}
}
