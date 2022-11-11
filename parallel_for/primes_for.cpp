#include <iostream>
#include <cstdlib>
#include <cmath>
#include <omp.h>
using namespace std;
bool prime(int n)
{
    if (n == 1) return false;
    if (n % 2 == 0 && n != 2)
        return false;

    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}
int prime_numbers_successively(int n)
{
    int count = 0;
    double time = omp_get_wtime();
    for (int i = 3; i <= n; i += 2)
    {
        count += prime(i);
    }
    cout << "omp_get_wtime: " << omp_get_wtime() - time << endl;
    return count;
}
int prime_numbers_parallel(int n)
{
    int count = 0;
	double time = omp_get_wtime();
#pragma omp parallel for schedule(static, 5) reduction(+:count)
	for (int i = 3; i <= n; i += 2)
	{
		count += prime(i);
	}
	cout << "time static: " << omp_get_wtime() - time << endl;
/*
	double time1 = omp_get_wtime();
#pragma omp parallel for schedule(dynamic, 5) reduction(+:count)
	for (int i = 1; i <= n; i+=2)
	{
		count += prime(i);
	}
	cout << "time dynamic: " << omp_get_wtime() - time1 << endl;
	double time2 = omp_get_wtime();
#pragma omp parallel for schedule(guided, 5) reduction(+:count)
	for (int i = 1; i <= n; i+=2)
	{
		count += prime(i);
	}
	cout << "time guided: " << omp_get_wtime() - time2 << endl;
*/
	return count;
}
int main()
{
    int n;
    cin >> n;
    cout << prime_numbers_successively(n) << endl;
    cout << prime_numbers_parallel(n) << endl;
    return 0;
}
