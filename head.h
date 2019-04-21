//===================
//head.h
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class BigNumber
{
	string sNumber;
public:
	void set(const string str)                                                //设置大数
	{
		sNumber = str;
	}
	friend BigNumber addBigNumber(BigNumber &bn1, BigNumber &bn2);            //把两个正数相加
	friend BigNumber minusBigNumber(BigNumber &bn1, BigNumber &bn2);          //把两个整数相减，而且bn1>bn2
	friend BigNumber multiplyBigNumber(BigNumber &bn1, BigNumber &bn2);       //把两个正数相乘
	friend BigNumber divideBigNumber(BigNumber &bn1, BigNumber &bn2);         //把两个正数相除
	friend BigNumber modBigNumber(BigNumber &bn1, BigNumber &bn2);            //把两个正数做取余计算
	friend ostream& operator<<(ostream &out, const BigNumber &bn);            //重载<<
	friend BigNumber operator+(BigNumber &bn1, BigNumber &bn2);               //重载+
	friend BigNumber operator-(BigNumber &bn1, BigNumber &bn2);               //重载-
	friend BigNumber operator*(BigNumber &bn1, BigNumber &bn2);               //重载*
	friend BigNumber operator/(BigNumber &bn1, BigNumber &bn2);               //重载/
	friend BigNumber operator%(BigNumber &bn1, BigNumber &bn2);               //重载%
	friend bool operator>=(BigNumber &bn1, BigNumber &bn2);                   //重载>=
};
