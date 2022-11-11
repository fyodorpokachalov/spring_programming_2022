#include <iostream>
#include <set>
using namespace std;
void first(set<int> s)
{
    for (int x : s)
        cout << x << "  ";
    cout << endl;
}
int main()
{
    set<int> s;
    int add;
    cin >> add;
    while (cin.good())
    {
        s.insert(add);
        cin >> add;
    }
    first(s);

    return EXIT_SUCCESS;
}
