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
