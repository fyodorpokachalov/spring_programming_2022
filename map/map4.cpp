#include <iostream>
#include <map>
using namespace std;
template <class T1, class T2>
map<T1, T2> sum(map<T1,T2> m1, map<T1,T2> m2)
{
    map<T1,T2> res;
    for (auto x : m1)
        res.insert(pair<T1,T2>(x.first, m1[x.first] + m2[x.first]));
    return res;
}

int main()
{
    map<int,int> m1, m2, m;
  cout << "the first number of the first map: "; cin >> m1[1];
  cout << "the second number of the first map: "; cin >> m1[2];
  cout << "the first number of the second map: "; cin >> m2[1];
  cout << "the second number of the second map: "; cin >> m2[2];

    m = sum(m1, m2);

    for (auto x : m)
        cout << x.first << " is paired with " << x.second << endl;

    return EXIT_SUCCESS;
}
