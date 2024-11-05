#include <iostream>

using namespace std;

int recursive_sum(int arr[], int size);
bool check_rotation(int arr1[],int arr2[], int sizeArr1, int sizeArr2);

int main()
{
    // Question 1
    int m = 0; // Rows
    int n = 0; // Columns
    int count = 1; // Variable for random numerical values

    cout<<"Rows: "; // Sets the variable for rows. Disallows any number that is less than or equal to 0.
    while (m <= 0)
    {
        cin>>m;
        if (m > 0)
        {
            break;
        }
        cout<<"Enter a valid input: ";
    }
    cout<<endl;

    cout<<"Columns: "; // Sets the variable for columns. Disallows any number that is less than or equal to 0.
    while (n <= 0)
    {
        cin>>n;
        if (n > 0)
        {
            break;
        }
        cout<<"Enter a valid input: ";
    }
    cout<<endl;

    int** userArray = new int* [m]; // Creates pointer for the 2d array
    for (int i = 0; i < m; i++)
    {
        userArray[i] = new int[n]; // Creates arrays within the array using pointers.
    }

    for (int i = 0; i < m; i++) // Fills the 2d array with numerical values.
    {
        for (int j = 0; j < n; j++)
        {
            userArray[i][j] = count;
            count++;
            cout<<userArray[i][j] << " ";
        }
        cout<<endl;
    }

    for (int i = 0; i < m; i++) // Deletes pointers within the 2d array
    {
        delete[] userArray[i]; // Deletes pointer
        userArray[i] = nullptr; // Avoids dangling pointer
    }
    delete[] userArray; // Deletes the 2d array
    userArray = nullptr; // Avoids dangling pointer

    cout<<endl;

    // Question 2
    int arr1[5] = {1,2,3,4,5}; // Array 1
    int size1 = sizeof(arr1) / sizeof(arr1[0]); // Calculates the size of array 1
    int sum1 = recursive_sum(arr1, size1); // Calls the recursive sum function and assigns it to a variable.

    cout<<"Sum of Array 1: "<< sum1 <<endl; // Prints out the sum

    int arr2[5] = {10,12,35,41,-51}; // Array 2
    int size2 = sizeof(arr2) / sizeof(arr2[0]); // Calculates the size of array 2
    int sum2 = recursive_sum(arr2, size2); // Calls the recursive sum function and assigns it to a variable.

    cout<<"Sum of Array 2: "<< sum2 <<endl; // Prints out the sum
    // Prints out the sum of both arrays.
    cout<<endl;

    // Question 3
    int arr3[4] = {10,20,30,40}; // Array 3
    int size3 = sizeof(arr3) / sizeof(arr3[0]); // Calculates the size of array 3

    int arr4[4] = {30,40,10,20}; // Array 4
    int size4 = sizeof(arr4) / sizeof(arr4[0]); // Calculates the size of array 4

    cout<< "0 = False." <<endl;
    cout<< "1 = True." <<endl;
    cout<< "Rotation: " << check_rotation(arr3, arr4, size3, size4) <<endl; // Calls the check rotation function and prints out true or false.

    return 0;
}

int recursive_sum(int arr[], int size)
{
    if (size == 0) // Ends the recursion when variable size is 0, which is when recursion access the final element in the array.
    {
        return 0; // Returns the sum.
    }
    return arr[size-1] + recursive_sum(arr, size-1); // Since the size variable will always start off 1 more than the final element's index, we do size-1 so we don't get a potential error.
}

bool check_rotation(int arr1[], int arr2[], int sizeArr1, int sizeArr2)
{
    //FILL IN CODE HERE
    if (sizeArr1 != sizeArr2) // Returns false if arrays aren't the same size.
    {
        return false;
    }
    
    for (int i = 0; i < sizeArr1; i++)
    {
        bool rotation = true;
        for (int j = 0; j < sizeArr2; j++)
        {
                if (arr1[(i + j) % sizeArr1] != arr2[j])
                {
                    rotation = false;
                    break;
                }
        }
        if (rotation)
        {
            return true;
        }
    }
    return false;
}