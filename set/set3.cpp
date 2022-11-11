#include <iostream>
#include <set>
using namespace std;
int main()
{
    set<int> s;
    set<int> recurring;
    set<int> recurring2;
    int add;
    cin >> add;
    while (cin.good())
    {
        if (s.count(add))
        {
            if(recurring2.count(add))
               recurring2.erase(add);
            if(!recurring.count(add))
               recurring2.insert(add);
            recurring.insert(add);
        }
        s.insert(add);
        cin >> add;
    }
    for (int x : recurring2)
        cout << x << "  ";
    cout << endl;
    return EXIT_SUCCESS;
}
