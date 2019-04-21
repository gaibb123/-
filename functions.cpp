//===========================================================
//functions.cpp
#include"head.h"

BigNumber operator%(BigNumber &bn1, BigNumber &bn2)               //重载%
{
	BigNumber bn3, bn4;
	string num;
	if (bn1.sNumber[0] != '-'&&bn2.sNumber[0] != '-')
	{
		return modBigNumber(bn1, bn2);
	}
	if (bn1.sNumber[0] == '-'&&bn2.sNumber[0] != '-')
	{
		num = string(bn1.sNumber.begin() + 1, bn1.sNumber.end());
		bn3.set(num);
		bn4 = modBigNumber(bn3, bn2);
		num = string(bn4.sNumber.begin(), bn4.sNumber.end());
		addMinus(num);
		bn4.set(num);
		return bn4;
	}
	if (bn1.sNumber[0] != '-'&&bn2.sNumber[0] == '-')
	{
		num = string(bn2.sNumber.begin() + 1, bn2.sNumber.end());
		bn3.set(num);
		bn4 = modBigNumber(bn1, bn3);
		return bn4;
	}
	if (bn1.sNumber[0] == '-'&&bn2.sNumber[0] == '-')
	{
		num = string(bn1.sNumber.begin() + 1, bn1.sNumber.end());
		bn3.set(num);
		num = string(bn2.sNumber.begin() + 1, bn2.sNumber.end());
		bn4.set(num);
		bn3 = modBigNumber(bn3, bn4);
		num = string(bn3.sNumber.begin(), bn3.sNumber.end());
		addMinus(num);
		bn4.set(num);
		return bn4;
	}
}

BigNumber modBigNumber(BigNumber &bn1, BigNumber &bn2)               //把两个正数做取余
{
	BigNumber bn3 = bn1 / bn2;
	bn3 = bn3 * bn2;
	return bn1 - bn3;
}

bool operator>=(BigNumber &bn1, BigNumber &bn2)                     //重载>=
{
	if (bn1.sNumber == bn2.sNumber)
		return 1;
	if (bn1.sNumber[0] != '-'&&bn2.sNumber[0] == '-')
		return 1;
	if (bn1.sNumber[0] == '-'&&bn2.sNumber[0] != '-')
		return 0;
	if (bn1.sNumber.size() > bn2.sNumber.size())
		return 1;
	else if (bn1.sNumber.size() == bn2.sNumber.size())
		for (int i = 0; i < bn1.sNumber.size(); i++)
			if (bn1.sNumber[i] > bn2.sNumber[i])
				return 1;
			else if (bn1.sNumber[i] < bn2.sNumber[i])
				return 0;
	return 0;
}

BigNumber operator/(BigNumber &bn1, BigNumber &bn2)               //重载/
{
	if (bn2.sNumber[0] == '0')
	{
		printf("cannot divide 0\n");
		exit(0);
	}
	string num;
	BigNumber bn3;
	if (bn1.sNumber[0] != '-'&&bn2.sNumber[0] != '-')
	{
		return divideBigNumber(bn1, bn2);
	}
	if (bn1.sNumber[0] == '-'&&bn2.sNumber[0] != '-')
	{
		num = string(bn1.sNumber.begin() + 1, bn1.sNumber.end());
		bn3.set(num);
		return divideBigNumber(bn3, bn2);
	}
	if (bn1.sNumber[0] != '-'&&bn2.sNumber[0] == '-')
	{
		num = string(bn2.sNumber.begin() + 1, bn2.sNumber.end());
		bn3.set(num);
		return divideBigNumber(bn1, bn3);
	}
	if (bn1.sNumber[0] == '-'&&bn2.sNumber[0] == '-')
	{
		num = string(bn1.sNumber.begin() + 1, bn1.sNumber.end());
		bn3.set(num);
		num = string(bn2.sNumber.begin() + 1, bn2.sNumber.end());
		BigNumber bn4;
		bn4.set(num);
		return divideBigNumber(bn3, bn4);
	}
}

BigNumber divideBigNumber(BigNumber &bn1, BigNumber &bn2)         //把两个正数相除
{
	string num;
	BigNumber bn3, bn4, bn5, bn6, bnOne, bnZero, bnTen;
	int len1 = bn1.sNumber.size(), len2 = bn2.sNumber.size();
	if (!(bn1 >= bn2))
	{
		bn3.set("0");
		return bn3;
	}
	else if (bn1.sNumber == bn2.sNumber)
	{
		bn3.set("1");
		return bn3;
	}
	bnOne.set("1");
	bnZero.set("0");
	bnTen.set("10");
	bn6.set("0");
	for (int i = len2 - 1; i < len1; i++)
	{
		num = string(bn1.sNumber.begin(), bn1.sNumber.begin() + i + 1);
		bn3.set(num);
		bn5 = bn6 * bnTen;
		bn5 = bn5 * bn2;
		bn3 = bn3 - bn5;
		if (bn2 >= bn3 && bn2.sNumber != bn3.sNumber)
		{
			bn4.set("0");
		}
		else
		{
			for (bn4.set("1"); 1; bn4 = bn4 + bnOne)
			{
				bn5 = bn2 * bn4;
				bn5 = bn3 - bn5;
				if (!(bn5 >= bnZero))
				{
					bn4 = bn4 - bnOne;
					break;
				}
				else if (bn5.sNumber == bnZero.sNumber)
					break;
				else if (bn4 >= bnTen)
				{
					bn4.set("9");
					break;
				}
			}
		}
		bn6 = bn6 * bnTen;
		bn6 = bn6 + bn4;
	}
	return bn6;
}

BigNumber operator*(BigNumber &bn1, BigNumber &bn2)           //重载*
{
	string num;
	BigNumber bn3, bn4;
	if (bn1.sNumber[0] != '-'&&bn2.sNumber[0] != '-')
		return multiplyBigNumber(bn1, bn2);
	if (bn1.sNumber[0] == '-'&&bn2.sNumber[0] != '-')
	{
		num = string(bn1.sNumber.begin() + 1, bn1.sNumber.end());
		bn3.set(num);
		bn4 = multiplyBigNumber(bn2, bn3);
		num = string(bn4.sNumber.begin(), bn4.sNumber.end());
		addMinus(num);
		bn4.set(num);
		return bn4;
	}
	if (bn1.sNumber[0] != '-'&&bn2.sNumber[0] == '-')
	{
		num = string(bn2.sNumber.begin() + 1, bn2.sNumber.end());
		bn3.set(num);
		bn4 = multiplyBigNumber(bn1, bn3);
		num = string(bn4.sNumber.begin(), bn4.sNumber.end());
		addMinus(num);
		bn4.set(num);
		return bn4;
	}
	if (bn1.sNumber[0] == '-'&&bn2.sNumber[0] == '-')
	{
		num = string(bn1.sNumber.begin() + 1, bn1.sNumber.end());
		bn3.set(num);
		num = string(bn2.sNumber.begin() + 1, bn2.sNumber.end());
		bn4.set(num);
		return multiplyBigNumber(bn3, bn4);
	}
}

BigNumber multiplyBigNumber(BigNumber &bn1, BigNumber &bn2)           //把两个正数相乘
{
	int cnt = 0, len1 = bn1.sNumber.size(), len2 = bn2.sNumber.size();
	BigNumber bn3, bn4;
	bn4.set("0");
	for (int i = len2 - 1; i >= 0; i--)
	{
		int digit = bn2.sNumber[i] - '0';
		string num;
		num.resize(len1 + 1 + cnt, '0');
		for (int j = len1 - 1; j >= 0; j--)
		{
			num[j + 1] += (bn1.sNumber[j] - '0')*digit % 10;
			if (num[j + 1] > '9')
			{
				num[j + 1] -= 10;
				num[j]++;
			}
			num[j] += (bn1.sNumber[j] - '0')*digit / 10;
		}
		bn3.set(num);
		if (bn3.sNumber[0] == '0')
		{
			num = string(bn3.sNumber.begin() + 1, bn3.sNumber.end());
			bn3.set(num);
		}
		cnt++;
		bn4 = bn3 + bn4;
	}
	return bn4;
}

BigNumber operator-(BigNumber &bn1, BigNumber &bn2)             //重载-
{
	BigNumber bn3, bn4;
	string num;
	if (bn1.sNumber[0] != '-'&&bn2.sNumber[0] != '-')
		if (bn1 >= bn2)
			return minusBigNumber(bn1, bn2);
		else
		{
			bn3 = minusBigNumber(bn2, bn1);
			num = bn3.sNumber;
			addMinus(num);
			bn3.set(num);
			return bn3;
		}
	if (bn1.sNumber[0] == '-'&&bn2.sNumber[0] != '-')
	{
		num = string(bn1.sNumber.begin() + 1, bn1.sNumber.end());
		bn3.set(num);
		bn4 = addBigNumber(bn2, bn3);
		num = bn4.sNumber;
		addMinus(num);
		bn4.set(num);
		return bn4;
	}
	if (bn1.sNumber[0] != '-'&&bn2.sNumber[0] == '-')
	{
		num = string(bn2.sNumber.begin() + 1, bn2.sNumber.end());
		bn3.set(num);
		bn4 = addBigNumber(bn1, bn3);
		return bn4;
	}
	if (bn1.sNumber[0] == '-'&&bn2.sNumber[0] == '-')
	{
		num = string(bn2.sNumber.begin() + 1, bn2.sNumber.end());
		bn3.set(num);
		return bn3 + bn1;
	}
}

void addMinus(string& num)                                 //在字符串num前面添加负号
{
	string result;
	result.resize(num.size() + 1);
	result[0] = '-';
	for (int i = 0; i < num.size(); i++)
		result[i + 1] = num[i];
	num = result;
}

BigNumber operator+(BigNumber &bn1, BigNumber &bn2)       //重载+
{
	BigNumber bn3, bn4;
	string num;
	if (bn1.sNumber[0] != '-'&&bn2.sNumber[0] != '-')
		return addBigNumber(bn1, bn2);
	if (bn1.sNumber[0] != '-'&&bn2.sNumber[0] == '-')
	{
		num = string(bn2.sNumber.begin() + 1, bn2.sNumber.end());
		bn3.set(num);
		if (bn1 >= bn3)
		{
			return minusBigNumber(bn1, bn3);
		}
		else
		{
			bn4 = minusBigNumber(bn3, bn1);
			num = bn4.sNumber;
			addMinus(num);
			bn4.set(num);
			return bn4;
		}
	}
	if (bn1.sNumber[0] == '-'&&bn2.sNumber[0] != '-')
	{
		num = string(bn1.sNumber.begin() + 1, bn1.sNumber.end());
		bn3.set(num);
		if (bn2 >= bn3)
			return minusBigNumber(bn2, bn3);
		else
		{
			bn4 = minusBigNumber(bn3, bn2);
			num = bn4.sNumber;
			addMinus(num);
			bn4.set(num);
			return bn4;
		}
	}
	if (bn1.sNumber[0] == '-'&&bn2.sNumber[0] == '-')
	{
		string num1(bn1.sNumber.begin() + 1, bn1.sNumber.end());
		string num2(bn2.sNumber.begin() + 1, bn2.sNumber.end());
		bn3.set(num1); 
		bn4.set(num2);
		BigNumber bn5 = addBigNumber(bn3, bn4);
		num = bn5.sNumber;
		addMinus(num);
		bn5.set(num);
		return bn5;
	}
}

BigNumber minusBigNumber(BigNumber &bn1, BigNumber &bn2)      //把两个正数相见
{
	BigNumber result;
	if (bn1.sNumber == bn2.sNumber)
	{
		string num("0");
		result.set(num);
		return result;
	}
	int len1 = bn1.sNumber.size(), len2 = bn2.sNumber.size();
	reverse(bn1.sNumber.begin(), bn1.sNumber.end());
	reverse(bn2.sNumber.begin(), bn2.sNumber.end());
	result.sNumber.resize(len1, '0');
	for (int i = 0; i < len1; i++)
		result.sNumber[i] = bn1.sNumber[i];
	for (int i = 0; i < len2; i++)
		result.sNumber[i] -= bn2.sNumber[i] - '0';
	for (int i = 0; i < len1 - 1; i++)
		if (result.sNumber[i] < '0')
		{
			result.sNumber[i] += 10;
			result.sNumber[i + 1]--;
		}
	reverse(bn1.sNumber.begin(), bn1.sNumber.end());
	reverse(bn2.sNumber.begin(), bn2.sNumber.end());
	reverse(result.sNumber.begin(), result.sNumber.end());
	for(int i=0;i<len1;i++)
		if (result.sNumber[i] != '0')
		{
			string num(result.sNumber.begin() + i, result.sNumber.end());
			result.set(num);
			return result;
		}
}

BigNumber addBigNumber(BigNumber &bn1, BigNumber &bn2)        //把两个正数相加
{
	BigNumber result;
	reverse(bn1.sNumber.begin(), bn1.sNumber.end());
	reverse(bn2.sNumber.begin(), bn2.sNumber.end());
	if (bn1.sNumber.size() > bn2.sNumber.size())
	{
		int len1 = bn1.sNumber.size(), len2 = bn2.sNumber.size();
		result.sNumber.resize(len1, '0');
		for (int i = 0; i < len1; i++)
			result.sNumber[i] = bn1.sNumber[i];
		for (int i = 0; i < len2; i++)
		{
			result.sNumber[i] += bn2.sNumber[i] - '0';
			if (result.sNumber[i] > '9')
			{
				result.sNumber[i] -= 10;
				result.sNumber[i + 1]++;
			}
		}
	}
	else
	{
		int len1 = bn2.sNumber.size(), len2 = bn1.sNumber.size();
		result.sNumber.resize(len1 + 1, '0');
		for (int i = 0; i < len1; i++)
			result.sNumber[i] = bn2.sNumber[i];
		for (int i = 0; i < len2; i++)
		{
			result.sNumber[i] += bn1.sNumber[i] - '0';
			if (result.sNumber[i] > '9')
			{
				result.sNumber[i] -= 10;
				result.sNumber[i + 1]++;
			}
		}
	}
	reverse(bn1.sNumber.begin(), bn1.sNumber.end());
	reverse(bn2.sNumber.begin(), bn2.sNumber.end());
	reverse(result.sNumber.begin(), result.sNumber.end());
	if (result.sNumber[0] == '0')
	{
		string number(result.sNumber.begin() + 1, result.sNumber.end());
		result.set(number);
	}
	return result;
}

ostream& operator<<(ostream &out, const BigNumber &bn)      //重载<<
{
	int iFlag = 0;
	for (int i = 0; i < bn.sNumber.size(); i++)
		if (bn.sNumber[i] >= '1'&&bn.sNumber[i] <= '9')
			iFlag = 1;
	if (iFlag == 0)
		out << "0";
	else 
		out << bn.sNumber;
	return out;
}
