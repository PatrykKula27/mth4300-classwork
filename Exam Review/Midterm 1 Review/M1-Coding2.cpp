#include <iostream>
using namespace std;

int main()
{
    int x;
    int y;

    cout << "Enter a value for x: " << endl;
    cin >> x;

    cout << "Enter a value for y: " << endl;
    cin >> y;

    cout<<endl;

    int** userArr = new int* [5]; // Creates the 2d array
    for (int i = 0; i < 5; i++)
    {
        userArr[i] = new int[5];
    }

    for (int j = 0; j < 5; j++) // Assigns random values to the 2d array
    {
        for (int k = 0; k < 5; k++)
        {
            if (j != x)
            {
                userArr[j][k] = 0;
            }
            else
            {
                userArr[x][k] = (y + k);
            }
        }
    }

    for (int a = 0; a < 5; a++) // Prints out the array.
    {
        for (int b = 0; b < 5; b++)
        {
            cout<<userArr[a][b]<<" ";
        }
        cout<<endl;
    }

    for (int c = 0; c < 5; c++) // Deletes pointers within the 2d array
    {
        delete[] userArr[c]; // Deletes pointer
        userArr[c] = nullptr; // Avoids dangling pointer
    }
    delete[] userArr; // Deletes the 2d array
    userArr = nullptr; // Avoids dangling pointer

    return 0;
}