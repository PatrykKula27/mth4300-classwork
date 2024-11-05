#include <iostream>
#include <iomanip>

class Book
{
    private:
        std::string title;
        std::string author;
        int yearPublished;
        double price;
    
    public:
        Book(std::string& bookTitle, std::string& bookAuthor, int publishedYear = 1900, double bookPrice = 0.0): title(bookTitle), author(bookAuthor), yearPublished(publishedYear), price(bookPrice) {}
        
        void applyDiscount(double& discount)
        {
            price -= (price*(discount/100));
        }

        void const getBookInfo()
        {
            std::cout<<"Book Title: "<<title<<std::endl;
            std::cout<<"Book Author: "<<author<<std::endl;
            std::cout<<"Year Published: "<<yearPublished<<std::endl;
            std::cout<<"Price: "<<std::fixed<<std::setprecision(2)<<price<<std::endl;
        }
};

int main()
{
    std::string bookName = "The Great Gatsby";
    std::string author = "F. Scott Fitzgerald";
    Book myBook(bookName, author, 1925, 15.99);
    double discount = 10.0; // 10% Discount
    myBook.applyDiscount(discount);
    myBook.getBookInfo();
    return 0;
}