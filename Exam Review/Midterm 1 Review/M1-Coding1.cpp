#include <iostream>
using namespace std;

class toaster
{
    private:
        int size;
        int time;
        int heat;
        string name;
    
    public:
        toaster(int s, int t, int h, string n)
        {
            size = s;
            time = t;
            heat = h;
            name = n;
        }

        void getInfo()
        {
            cout << "Toaster: "<< name << "." << endl;
            cout <<"The toaster has a capacity of "<< size << "." <<endl;
            cout << "The toaster currently has a timer of " << time << "." << endl;
            cout << "The toaster has it's temperature set to " << heat << " degrees." << endl;
        }

        void countdownTimer()
        {
            while (time > 0)
            {
                cout << time << " minutes left." << endl;
                time--;
                cout << "One minute passes by." << endl;
            }
            cout << "Time is up! Your toast is ready!" << endl;
        }

        void setTime(int newTime)
        {
            cout << "Time is currently set to " << time << "." << endl;
            time = newTime;
            cout << "Time is now at " << time << "." << endl;
        }

        void setSize(int newSize)
        {
            cout << "Size is currently set to " << size << "." << endl;
            size = newSize;
            cout << "Size is now at " << size << "." << endl;
        }

        void setHeat(int newHeat)
        {
            cout << "Temperature is currently set to " << heat << " degrees." << endl;
            heat = newHeat;
            cout << "Temperature is now at " << heat << " degrees." << endl;
        }

        void setName(string newName)
        {
            cout << "Name is currently set to " << name << "." << endl;
            name = newName;
            cout << "Name is now " << name << "." << endl;
        }
};

int main()
{
    toaster one(2, 15, 250, "Shiny Silver");
    toaster two(4, 12, 325, "Gold Standard");

    one.getInfo();
    cout<<endl;
    one.countdownTimer();

    cout<<endl;
    
    two.getInfo();
    cout<<endl;
    two.countdownTimer();
    return 0;
}