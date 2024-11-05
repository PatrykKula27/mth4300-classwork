#include <iostream>
using namespace std;

class car
{
    private:
        int serial;
        string make;
        int mileage;
        string colour;
        int year;
        string name;
    
    public:
        car(int s, string ma, int mi, string c, int y, string n)
        {
            serial = s;
            make = ma;
            mileage = mi;
            colour = c;
            year = y;
            name = n;
        }

        void getInfo()
        {
            cout<<"Car: "<<name<<"."<<endl;
            cout<<year<<" "<<make<<" "<<colour<<", Seriail #"<<serial<<". "<<mileage<<" mile(s) logged."<<endl;
        }

        void addMileage()
        {
            int moreMiles;
            while (true)
            {
                cout<<"Add mileage to car "<<name<<": ";
                cin>>moreMiles;
                if (moreMiles > 0)
                {
                    mileage += moreMiles;
                    break;
                }
                else
                {
                    cout<<"Please enter a valid input."<<endl;
                }
            }
            cout<<"Mileage has been updated to "<<mileage<<"."<<endl;
        }
};

int main()
{
    int row = 5;
    int col = 5;
    int count = 0;

    int** arr = new int*[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }

    for (int x = 0; x < row; x++)
    {
        for (int y = 0; y < col; y++)
        {
            arr[x][y] = count;
            count++;
            cout<<arr[x][y]<<" ";
        }
        cout<<endl;
    }

    for (int a = 0; a < row; a++)
    {
        delete[] arr[a];
        arr[a] = nullptr;
    }
    delete[] arr;
    arr = nullptr;

    cout<<endl;

    car one(2145, "Honda Civic", 35000, "Black", 2012, "Beast");
    one.getInfo();

    cout<<endl;

    car two(4414, "Hyundai Palisade", 21000, "Silver", 2020, "Family Wagon");
    two.getInfo();

    one.addMileage();
    cout<<endl;
    one.getInfo();

    return 0;
}