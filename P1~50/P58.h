/*
 * P58.h
 *
 *  Created on: 2016年10月4日
 *      Author: LeoBrilliant
 */

#ifndef P58_H_
#define P58_H_

#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string s)
{
	int length = 0;
	size_t index = 0;
	int size = s.find_last_not_of(' ');
	if(size != string::npos) {
	index = s.rfind(' ', size);
	//未找到空格
	if(index == string::npos)
	{
		length = size + 1;
	}
	else
	{
		length = size - index;
	}
	}
	return length;
}

void LengthOfLastWordTest()
{
	string s = "Hello World";
	//s = "HelloWorld";
	//s = "";
	//s = " ";
	//string s;
	//string s = "a ";

	int length = 0;
	length = lengthOfLastWord(s);

	cout << length << endl;
}



#endif /* P58_H_ */
