#include <iostream>

using namespace std;
// no handle any call back
void recur(int n)
{
    cout << n;
    if (n > 0) // base condition
        recur(n - 1);
}
int main()
{
    recur(5);
    return 0;
}