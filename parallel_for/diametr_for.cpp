#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <omp.h>
using namespace std;
struct Point
{
    float x, y, z;
    Point(float x, float y, float z) : x(x), y(y), z(z) {};
    double operator +(const Point& other) {
        return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y) + (z - other.z) * (z-other.z));
    }
};
float successively(vector<Point> vect)
{
    double time = omp_get_wtime();
    float max = 0;
    for (int i = 0; i <  vect.size() - 1; ++i)
    {
        for (int j = i + 1; j < vect.size(); ++j)
        {
            if (vect[i] + vect[j] > max)
                max = vect[i] + vect[j];
        }
    }
    //cout << "time succ: " << omp_get_wtime() - time << endl;
    return max;
}

float parallel(vector<Point> vect)
{
    double time = omp_get_wtime();
    float max1 = 0;
    float maxtemp = 0;
#pragma omp parallel for schedule(static, 5) reduction(max:max1)
    for (int i = 0; i <  vect.size() - 1; ++i)
    {
        for (int j = i + 1; j < vect.size(); ++j)
        {
          maxtemp = vect[i] + vect[j];
          if (maxtemp > max1)
              max1 = maxtemp;
        }
    }
    //cout << "time parallel: " << omp_get_wtime() - time << endl;
    return max1;
}
int main()
{
    Point p1(1.2, 2.3, 3.4);
    Point p2(2.2, 5.3, 4.4);
    Point p3(1.2, 3.3, 5.4);
    Point p4(5.2, 2.3, 3.4);
    Point p5(9.1, 7.3, 9.4);
    Point p6(2.2, 11.3, 12.1);
    Point p7(1.2, 14.2, 10.4);
    Point p8(15.2, 22.3, 3.9);
    vector<Point> vect {p1, p2, p3, p4, p5, p6, p7, p8};
    cout << successively(vect) << endl;
    cout << parallel(vect) << endl;
    return 0;
}
