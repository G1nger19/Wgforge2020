#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;



int fact(int n) {
	if ((n == 0) || (n == 1))
		return 1;
	else
		return n * fact(n - 1);
}
long double* unic_combination = new long double[3628800]();
int code_Lehmer(int* arr)
{
	int number = 1;
	int count = 0;
	int sum = 0;
	int i = 0;
	int len = 10;
	while (number != 11)
	{
		if (len == 1) break;
		int index = 0;

		for (int j = 0; j < len; j++)
		{
			if (arr[j] == number)
			{
				index = j;
				break;
			}
		}
		while (i != index)
		{
			if (arr[i] > number) { count++; }
			i++;
		}
		if (count != 0)
		{
			sum += count * fact(10 - number);
		}
		for (int j = index; j < len - 1; j++)
		{
			arr[j] = arr[j + 1];
		}
		len--;
		number++;
		count = 0;
		i = 0;
	}
	return sum;
}
double sortMean(int* arr)
{
	int* barr = new int[10];
	for (auto i = 0; i < 10; i++)
	{
		barr[i] = arr[i];
	}
	int unic_code = code_Lehmer(barr);
	if (unic_code == 0) return 0;
	delete[]barr;
	if (unic_combination[unic_code] != 0) return unic_combination[unic_code];
	double M_ = 0;
	double n = 0;

	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (arr[j] < arr[i])
			{
				n += 1;
				swap(arr[j], arr[i]);
				M_ += sortMean(arr);
				swap(arr[j], arr[i]);
			}
		}
	}
	/*
	int i = 0;
	int j = 1;
	while(i<10) {
		while (arr[i] - arr[j] > 0 && j<10)
			j++;
		if (arr[j] - arr[i] < 0) {
			n += 1;
			swap(arr[j], arr[i]);
			M_ += sortMean(arr);
			swap(arr[j], arr[i]);
			j++;
			continue;
		}
		i++;
		j = i;
	}*/

	if (n == 0) return 0;

	double M = 45 / n;
	M_ = M_ / n;
	//unic_combination[unic_code] = M + M_;
	unic_combination[unic_code] = M + M_;
	return M + M_;
}

int main()
{
	int n;
	cin >> n;

	int* arr = new int[10];
	double* answer = new double[n];
	int k = 0;

	while (k != n)
	{
		for (int i = 0; i < 10; i++)
		{
			cin >> arr[i];
		}
		answer[k] = sortMean(arr);
		k++;
	}
	for (int i = 0; i < n; i++)
	{
		cout << fixed << setprecision(6) << answer[i] << endl;
	}
	delete[]arr;
	delete[]answer;
	return 0;

}

