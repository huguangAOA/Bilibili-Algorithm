#include <iostream>
using namespace std;

int main()
{
    int i, n, r = 1;
    cin >> n;
    for (i = 1; i < n; i++)
    {
        r = (r + 1) * 2;
    }
    cout << r << endl;
    return 0;
}