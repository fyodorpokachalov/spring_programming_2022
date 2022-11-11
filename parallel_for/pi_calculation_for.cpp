#include <iostream>
#include <cstdlib>
#include <cmath>
#include <omp.h>
using namespace std;
double function(double x)
{
    return (1 / (1 + x * x));
}

double pi_successively(int n)
{
    double time = omp_get_wtime();
    double sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum += function((2.0 * i - 1) / (2 * n));
    }
    cout << "omp_get_wtime: "  << omp_get_wtime() - time<< endl;

    return 4 * sum / n;
}

double pi_parallel(int n)
{
	double sum = 0;
	double time = omp_get_wtime();
/*#pragma omp parallel for schedule(static, 5) reduction(+: sum)
	for (int i = 1; i <= n; ++i)
	{
		sum += function((2.0 * i - 1) / (2 * n));
	}
	cout << "time static: " << omp_get_wtime() - time << endl;*/

	double time1 = omp_get_wtime();
#pragma omp parallel for schedule(dynamic, 5) reduction(+: sum)
	for (int i = 1; i <= n; ++i)
	{
		sum += function((2.0 * i - 1) / (2 * n));
	}
	cout << "time dynamic: " << omp_get_wtime() - time1 << endl;

/*	double time2 = omp_get_wtime();
  #pragma omp parallel for schedule(guided, 5) reduction(+: sum)
	for (int i = 1; i <= n; ++i)
	{
		sum += function((2.0 * i - 1) / (2 * n));
	}
	cout << "time guided: " << omp_get_wtime() - time2 << endl;
*/
	return 4 * sum / n;
}
int main()
{
    int n;
    cin >> n;
    cout << pi_successively(n) << endl;
    cout << pi_parallel(n) << endl;
    return 0;
}
