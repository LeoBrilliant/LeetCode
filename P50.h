/*
 * P50.h
 *
 *  Created on: 2016年10月20日
 *      Author: user
 */

#ifndef P50_H_
#define P50_H_

#include "Common.h"

double myPow(double x, int n) {

	if(n == 0)
		return 1.0;

	double ret;

	if(n > 0)
	{
		ret = (double)myPow(x, n / 2);

		ret *= ret;
		if(n % 2)
			ret *= x;
	}
	else
	{
		if(n == -2147483648)
		{
			ret = (double)myPow(x, n / 2);
			ret =  (ret * ret);
		}

		else{
		n = -n;

		ret = (double)myPow(x, n / 2);
		ret *= ret;
		if(n%2)
			ret *= x;

		ret = 1.0 / ret;
		}
	}

	return ret;
}


void MyPowTest()
{
	double x;
	int n;

	x = 1.0;
	n = 0;

	x = 2;
	n = 4;

	x = -2;
	n = -1;

	x = -5;
	n = 2;

	x = 1.01;
	n = 10;


	x = 0.0;
	n = -1;

	x = 2;
	n = -2147483648;
	double ret = myPow(x, n);

	cout << ret << endl;

	cout << pow(0, -1) << endl;

//	cout << 1.0 / 0 << endl;
}


#endif /* P50_H_ */
