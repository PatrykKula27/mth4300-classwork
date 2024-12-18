#include <string>
#include <queue>
#include <iostream>
#include "ticketCounter.h"

void TicketCounter::addCustomer(std::queue<Customer>& ticketQueue, int& ticketCounter)
{
    std::string name;

    std::cout<<"Enter the name of the customer: ";
    std::cin>>name;
    std::cout<<std::endl;

    ticketCounter++;
    ticketQueue.push(Customer(name, ticketCounter));

    std::cout<<"Customer "<<name<<", Ticket Number #"<<ticketCounter<<" has been added to the list of customers."<<std::endl;
}

void TicketCounter::serveCustomer(std::queue<Customer>& ticketQueue)
{
    if (ticketQueue.empty())
    {
        std::cout<<"There are no customers currently in the list."<<std::endl;
        return;
    }

    Customer next = ticketQueue.front();

    std::cout<<"Currently serving customer: "<<next.name<<", Ticket Number #"<<next.ticketNumber<<"."<<std::endl;
    ticketQueue.pop();
}

void TicketCounter::displayCustomers(const std::queue<Customer>& ticketQueue)
{
    if (ticketQueue.empty())
    {
        std::cout<<"There are currently no customers in the list."<<std::endl;
        return;
    }

    std::cout<<"Customers that are currently in the list:"<<std::endl;
    std::queue<Customer> displayCustomerQueue = ticketQueue;

    while (!displayCustomerQueue.empty())
    {
        Customer current = displayCustomerQueue.front();
        std::cout<<"Customer "<<current.name<<", Ticket Number #"<<current.ticketNumber<<"."<<std::endl;
        displayCustomerQueue.pop();
    }
}