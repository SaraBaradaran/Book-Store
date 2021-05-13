#include "customer.h"

Customer::Customer(int no,QString name):no(no),name(name)
{
    shoppingbag = new Stack;
}

Customer::Customer(Customer &customer)
{
    this->name = customer.name;
    this->no = customer.no;
    this->shoppingbag = customer.shoppingbag;
}

void Customer::AddBookToShopphingBag(Book* book)
{
    shoppingbag->Push(book);
}

void Customer::PrintShoppingBag(QListWidget* list)
{
    shoppingbag->Print(list);
}
