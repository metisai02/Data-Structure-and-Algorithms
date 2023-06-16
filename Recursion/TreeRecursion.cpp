#include <iostream>

using namespace std;
// O(n^n)
// recur(3) with 15 calls
void recur(int n)
{

    if (n > 0)
    {
        cout << n;
        recur(n - 1);
        recur(n - 1);
    }
}
int main()
{
    recur(3);
    return 0;
}