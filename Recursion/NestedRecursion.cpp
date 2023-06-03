

// Recursion will pass parameter as a recursive

#include <iostream>

using namespace std;
int Func(int n)
{
    if (n > 100)
        return n - 10;
    else
        return Func(Func(n + 11));
}
int main()
{
    Func(95);
    return 0;
}