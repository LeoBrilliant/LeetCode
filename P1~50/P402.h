/*
 * P402.h
 *
 *  Created on: 2016年10月5日
 *      Author: LeoBrilliant
 */

#ifndef P402_H_
#define P402_H_

#include "Common.h"

string removeKdigits(string num, int k) {
	for(int i = 0; i < k; ++i)
	{
		char max = '0';
		int index = -1;
		if(num.size() && num[0] != '0'){
			for(int j = 0; j < num.size(); ++j)
			{
				if(num[j] >= max)
				{
					max = num[j];
					index = j;
				}
				else
					break;
			}
			num.erase(index, 1);

			while(num.size() && num[0] == '0')
				num.erase(0, 1);
		}
		else
		{
			//num.erase(0, 1);
		}
		if(!num.size())
			break;
	}
	while(num.size() && num[0] == '0')
		num.erase(0, 1);

	if(num.size() == 0)
		num = "0";

	return num;
}

void RemoveKDigitsTest()
{
	string num = "1432219";
	int k = 3;
	num = "10200";
	k = 1;
	num = "10";
	k = 2;
	string s = removeKdigits(num, k);

	//string s;
	cout << s << endl;
/*
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.empty() << endl;

	s = "";
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.empty() << endl;

	s = "1";
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.empty() << endl;
*/
}


#endif /* P402_H_ */
