//======================================================================
//main.cpp
#include"head.h"

int main()
{
	BigNumber bn1, bn2;
	string num1, num2;
	char signal;

	while (1)
	{
		cin >> signal; 
		if (signal == '@')
			return 0;
		cin >> num1 >> num2;
		bn1.set(num1);
		bn2.set(num2);
		switch (signal)
		{
		case '+':
			cout << bn1 + bn2 << endl;
			break;
		case '-':
			cout << bn1 - bn2 << endl;
			break;
		case '*':
			cout << bn1 * bn2 << endl;
			break;
		case '/':
			cout << bn1 / bn2 << endl;
			break;
		case '%':
			cout << bn1 % bn2 << endl;
			break;
		}
	}

	return 0;
}
