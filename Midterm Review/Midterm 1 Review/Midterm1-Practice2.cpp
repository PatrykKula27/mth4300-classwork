#include <iostream>
using namespace std;

int recursiveSum(int arr[], int size);

int main()
{
    int row;

    cout<<"Enter number of rows: ";
    cin>>row;
    cout<<endl;

    int* userArr = new int[row];
    for (int i = 0; i < row; i++)
    {
        userArr[i] = i + 1;
    }

    cout<<"Recursive sum of Array (only odd indexes): "<<recursiveSum(userArr, row)<<"."<<endl;
    delete[] userArr;
    return 0;
}

int recursiveSum(int arr[], int size)
{
    if (size <= 1)
    {
        return 0;
    }
    if ((size - 1) % 2 != 0)
    {
        return arr[size - 1] + recursiveSum(arr, size - 1);
    }
    else
    {
        return recursiveSum(arr, size - 1);
    }
}