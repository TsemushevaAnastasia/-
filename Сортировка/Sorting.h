#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Sorting : private vector<int>
{	
	public:
		static int calc_max(int num)
	{
		string buff = to_string(num);
		int max = 0;
		int num_amount = 1;

		for (int j = 0; j < buff.size(); j++) //проход по цифрам
		{
			for (int i = j + 1; i < buff.size(); i++)
			{
				if (buff[j] == buff[i])
				{
					num_amount++;
				}
			}
			if (num_amount > max)
			{
				max = num_amount;
			}
			num_amount = 1;
		}

		return max;
	}

	static bool comp(int num1, int num2)
	{
		if (Sorting::calc_max(num1) > Sorting::calc_max(num2))
			return true;
		else
			if (Sorting::calc_max(num1) == Sorting::calc_max(num2) && num1 > num2)
				return true;
			else
				return false;
	}

	void operator() (vector<int> &num)
	{
		sort(num.begin(), num.end(), Sorting::comp);
	}
};

