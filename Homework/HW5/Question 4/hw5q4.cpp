#include <iostream>
#include <string>
#include <queue>
#include "ticketCounter.h"

int main()
{

    std::queue<Customer> ticketCounterQueue;
    int ticketCounterNum = 0;
    int choice = 0;

    TicketCounter ticketCounter;

    while (choice != 4)
    {
        std::cout<<"Ticker Counter System Program."<<std::endl;
        std::cout<<"Functions: "<<std::endl;

        std::cout<<"1. Add a customer to the current queue."<<std::endl;
        std::cout<<"2. Serve the next customer in the queue."<<std::endl;
        std::cout<<"3. Display the current customer queue."<<std::endl;
        std::cout<<"4. Terminate the program."<<std::endl;

        std::cout<<"Enter a number to choose one of the following: ";
        std::cin>>choice;
        std::cout<<std::endl;

        if (choice == 1)
        {
            ticketCounter.addCustomer(ticketCounterQueue, ticketCounterNum);
        }
        else if (choice == 2)
        {
            ticketCounter.serveCustomer(ticketCounterQueue);
        }
        else if (choice == 3)
        {
            ticketCounter.displayCustomers(ticketCounterQueue);
        }
        else if (choice == 4)
        {
            std::cout<<"Terminating the program..."<<std::endl;
        }
        else
        {
            std::cout<<"Invalid Input."<<std::endl;
            std::cout<<std::endl;
        }
    }

    return 0;
}