//15. Создать вектор из целых чисел. Упорядочить его по следующему
//критерию : вначале – по максимальному количеству одинаковых цифр,
//а затем – по убыванию.
//(*как я поняла - сначала где больше одинаковых цифр, а есть есть числа 
// с одинаковым таким количеством, то среди них - по убыванию)

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#include "Sorting.h"

int main()
{
	ifstream fin("in.txt");
	ofstream fout("out.txt");

	if (!fin.is_open())
		fout << "Error! Cannot open file!\n";
	else if (fin.peek() == EOF)
		fout << "File is empty!\n";
	else
	{
		string str;

		vector<int> v;
		//vector<int> v{ 112, 232, 35, 43333, 54456, 666666, 7355, 85, 99, 10 };

		while (getline(fin, str))
		{
			unsigned int length = str.length();
			int a;

			a = atoi(str.c_str());

			v.push_back(a);
		}

		for (int i = 0; i < 10; i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		Sorting a;

		a(v);

		for (int i = 0; i < 10; i++)
		{
			cout << v[i] << " ";
			fout << to_string(v[i]);
			fout << endl;
		}
		cout << endl;

		fin.close();
		fout.close();

	}

	return 0;
}