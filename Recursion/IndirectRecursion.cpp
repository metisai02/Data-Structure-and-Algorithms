#include <iostream>

using namespace std;
void FuncB(int n);
void FuncA(int n)
{
    if (n > 0)
    {
        cout << n << endl;
        FuncB(n - 1);
    }
}
void FuncB(int n)
{
    if (n > 1)
    {
        cout << n << endl;
        FuncA(n / 2);
    }
}
int main()
{
    FuncA(10);
    return 0;
}