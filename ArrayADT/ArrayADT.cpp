#include <iostream>
using namespace std;
class ArrayADT
{
private:
    int *A;
    int length;
    int size;

public:
    ArrayADT(int size, int length)
    {
        this->size = size;
        this->length = length;
        A = new int[this->size];
    }
    ~ArrayADT()
    {
        delete[] A;
    }
    int GetLenght()
    {
        return length;
    }
    int GetValue(int index)
    {
        return A[index];
    }
    void Emplements(void);
    void Display(void);
    void Appen(int value);
    void Insert(int index, int value);
    void Delete(int index);
    int Search(int value);
    int SearchLinear(int value);
    int SearchBinary(int value);
    int Get(int index);
    void Set(int index, int value);
    int Max();
    int Min();
    int SumRecursion(int length);
    void Reverse();
};
void Merge(ArrayADT *A, ArrayADT *B, ArrayADT *C)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < A->GetLenght() - 1 && j < B->GetLenght() - 1)
    {
        if (A->GetValue(i) < B->GetValue(j))
            C->Set(k++, A->GetValue(i++));
        else
            C->Set(k++, B->GetValue(j++));
    }
    for (; i < A->GetLenght() - 1; i++)
    {
        C->Set(k++, A->GetValue(i));
    }
    for (; j < B->GetLenght() - 1; j++)
    {
        C->Set(k++, B->GetValue(j));
    }
}
void ArrayADT::Display(void)
{
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << endl;
    }
}
void ArrayADT::Emplements(void)
{
    for (int i = 0; i < length; i++)
    {
        cout << "array[" << i << "]: ";
        cin >> A[i];
    }
}
void ArrayADT::Appen(int value)
{
    A[length] = value;
    length++;
}
void ArrayADT::Insert(int index, int value)
{
    for (int i = length; i > index; i--)
    {
        A[i] = A[i - 1];
    }
    A[index] = value;
    length++;
}
void ArrayADT::Delete(int index)
{
    for (int i = index; i < length - index; i++)
    {
        A[i] = A[i + 1];
    }
    length--;
}
int ArrayADT::Search(int value)
{
    for (int i = 0; i < length; i++)
    {
        if (value == A[i])
            return 0;
    }
    return -1;
}
int ArrayADT::SearchLinear(int value)
{
    for (int i = 0; i < length; i++)
    {
        if (value == A[i])
        {
            swap(A[i - 1], A[i]);
            return 0;
        }
    }
    return -1;
}
int ArrayADT::SearchBinary(int value)
{
    int l = 0, h = length;
    int mid;
    while (l <= h)
    {
        mid = (h + l) / 2;
        if (A[mid] == value)
            return 0;
        else if (A[mid] < value)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return -1;
}
int ArrayADT::Max()
{
    int max = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}
int ArrayADT::Min()
{
    int min = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] < min)
            min = A[i];
    }
    return min;
}
void ArrayADT::Set(int index, int value)
{
    if (index < length)
        A[index] = value;
}
int ArrayADT::SumRecursion(int lenght)
{
    if (lenght < 0)
        return 0;
    else
        return SumRecursion(lenght - 1) + A[lenght];
}
void ArrayADT::Reverse()
{
    for (int i = 0, j = length - 1; i < j; i++, j--)
    {
        swap(A[i], A[j]);
    }
}
int main(void)
{
    ArrayADT arr(10, 5);
    arr.Emplements();
    // arr.Display();
    // arr.Appen(10);
    // arr.Display();
    // arr.Insert(2, 99);
    // arr.Delete(2);
    arr.Display();
    if (arr.SearchBinary(1) == 0)
        cout << "got that!!" << endl;
    cout << arr.SumRecursion(4);
    arr.Reverse();
    arr.Display();
}
