#include "inf_int.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>

using namespace std;

int main()
{
	system("clear");
	inf_int a, e;
	inf_int b(100);
	inf_int c("32115555555555");
	inf_int d("1233455022211");
	inf_int f=d;
	inf_int g;


	g = c + d;
	a = b * c;

	b = c - d;
 
	if (f==d) {

		cout << "a : " << a << endl;
		cout << "b : " << b << endl;
		cout << "c : " << c << endl;
		cout << "d : " << d << endl;
		cout << "f : " << f << endl;
		cout << "g : " << g << endl;

	}

	return 0;
}
