#include <iostream> 

using namespace std;
// handle call back to print inf
void recur(int n)
{
    
    if (n > 0) // base condition
        recur(n - 1);
    cout << n;
}
int main()
{
    recur(5);
    return 0;
}