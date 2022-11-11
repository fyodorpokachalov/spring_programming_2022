#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;
    set<int> recurring;
    int add;
    cin >> add;
    while (cin.good())
    {
        if (s.count(add))
            recurring.insert(add);
        s.insert(add);
        cin >> add;
    }

    for (int x : recurring)
        cout << x << "  ";
    cout << endl;
    return EXIT_SUCCESS;
}
