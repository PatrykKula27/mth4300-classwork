#include <iostream>

void selectionSort(int arr[], int len)
{
    for (int i = len-1; i >= 0; i--)
    {
        int maxIndex = i;
        for (int j = 0; j <= i; j++)
        {
            if (arr[j] > arr[maxIndex])
            {
                maxIndex = j;
            }
        }
        std::swap(arr[maxIndex], arr[i]);
    }
}

void display(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

int main()
{
    int arr[] = {10, 25, 43, 21, 56, 2, 7, 91, 23};
    int len = sizeof(arr)/sizeof(arr[0]);

    std::cout<<"Original Array: ";
    display(arr, len);
    std::cout<<std::endl;

    std::cout<<"Sorted Array: ";
    selectionSort(arr, len);
    display(arr, len);
    std::cout<<std::endl;

    return 0;
}