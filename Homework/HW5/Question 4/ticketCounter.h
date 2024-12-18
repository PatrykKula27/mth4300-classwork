#ifndef TICKETCOUNTER_H
#define TICKETCOUNTER_H

#include <string>
#include <queue>

struct Customer
{
    std::string name;
    int ticketNumber;

    Customer(std::string personName, int ticketNum)
    {
        name = personName;
        ticketNumber = ticketNum;
    }
};

class TicketCounter
{
    public:
        TicketCounter() {}

        void addCustomer(std::queue<Customer>& ticketQueue, int& ticketCounter);
        void serveCustomer(std::queue<Customer>& ticketQueue);
        void displayCustomers(const std::queue<Customer>& ticketQueue);
};

#endif