/*
Create a class `Book` that stores information about the book's title (dynamically allocated array of characters), 
ISBN of the book (dynamically allocated array of 5 integers), and the number of pages (integer). 
Provide set and get methods for the class, and overload the following operators:

- `==` operator to compare two books based on their ISBNs
- `<<` operator to print information about the book in the format Title: title ISBN:[x y z k l]

Write a class `BorrowABook` for a library for renting books,
which stores information about the library's name (an array of 100 characters), 
an array of books (dynamically allocated array of objects of the `Book` class), 
and the number of books it has (integer). In the `BorrowABook` class,
write a constructor with one argument to initialize the library's name. 
Increase the capacity of the dynamically allocated array by 1 element each time
a new book is added to the library. Overload the following operators in this class:

- `+=` for adding a new book to the library
- `-=` for removing a given book from the library (the one with the existing ISBN matching the ISBN of another book)

On exit, print the name of the library and the list of books it rents,
whose number of pages is greater than 150. Finally, 
implement a function `printNumberOfPages(int max)` in the `BorrowABook` class.

Explanation of the main function: Information about the books is read from the
keyboard using the `+=` operator. In the last line of the input, 
information is provided for a book that is entered incorrectly because 
it has the same ISBN as another book. It needs to be deleted.
!!! DO NOT MAKE CHANGES TO THE MAIN() FUNCTION !!!
*/

#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;

class Book{
private:
    char *title;
    int pages;
    int *isbn;
public:
Book()
{
title=new char[0];
isbn=new int[5];
pages=0;
}
    Book(char *title,int *isbn,int pages)
    {
        this->title=new char [strlen(title)+1];
        strcpy(this->title,title);
        this->pages=pages;
        this->isbn=new int [5];
        for(int i=0;i<5;i++)
            this->isbn[i]=isbn[i];
    }
    Book(const Book &a)
    {
        this->title=new char [strlen(a.title)+1];
        strcpy(this->title,a.title);
        this->pages=a.pages;
        this->isbn=new int [5];
        for(int i=0;i<5;i++)
            this->isbn[i]=a.isbn[i];
    }
    Book & operator=(const Book &a)
    {
        if(this!=&a)
        {
             
        delete [] title;
            this->title=new char [strlen(a.title)+1];
        strcpy(this->title,a.title);
        this->pages=a.pages;
        delete [] isbn;
        this->isbn=new int [5];
        for(int i=0;i<5;i++)
            this->isbn[i]=a.isbn[i];
        }
        return *this;
    }
     ~Book()
    {
        delete [] isbn;
        delete [] title;
    }
   
    bool operator==(const Book &a)
    {
        int br=0;
        for(int i=0;i<5;i++)
        {
            if(this->isbn[i]==a.isbn[i])
            br++;

        }
        if(br==5)
            return true;
       
            return false;

    }
    friend ostream&operator<<(ostream &out,const Book &a)

    {
        out<<"Title: "<<a.title<<" ISBN: [ ";
        for(int i=0;i<5;i++)
            out<<a.isbn[i]<<" ";
        out<<"]"<<endl;
        return out;
    }
    int getPages()
    {
        return pages;
    }

};
class BorrowABook
{
private:
    char ime[100];
    Book *niza;
    int n;
public:
    BorrowABook(char *ime)
    {
        strcpy(this->ime,ime);
        this->niza=new Book[0];
        this->n=0;
    }
    ~BorrowABook()
    {
        delete [] niza;
    }
    BorrowABook(const BorrowABook &rc)
    {
    strcpy(this->ime,rc.ime);
    this->n=rc.n;
    this->niza=new Book [rc.n];
    for(int i=0;i<rc.n;i++)
    this->niza[i]=rc.niza[i];
    }
    BorrowABook &operator=(const BorrowABook &rc)
    {
    if(this!=&rc)
    {
    strcpy(this->ime,rc.ime);
    this->n=rc.n;
    this->niza=new Book [rc.n];
    delete [] niza;
    for(int i=0;i<rc.n;i++)
    this->niza[i]=rc.niza[i];
    }
    return *this;
    }
    BorrowABook &operator+=(const Book &nov)
    {
        Book *temp=new Book [n+1];
        for(int i=0;i<n;i++)
            temp[i]=niza[i];
        temp[n++]=nov;
        delete [] niza;
        niza=temp;
        return *this;
    }
    BorrowABook &operator-=(const Book &nov)
    {
         Book *temp=new Book [n-1];
         int br=0;
         for(int i=0;i<n;i++)
         {
             if(niza[i]==nov)
                continue;
             else
             {
                 temp[br]=niza[i];
                 br++;
             }
         }
         delete []niza;
         niza=temp;
         n=br;
         return *this;
    }
    void  printNumberOfPages(int max)
    {
        cout<<ime<<endl;
        for(int i=0;i<n;i++)
        {
            if(niza[i].getPages()>max)
                cout<<niza[i]<<endl;
        }
    }

};
/// Do NOT edit the main() function
int main()
{
   BorrowABook library("FINKI-Library");
   int n;
   cin>>n;
    
   for (int i=0;i<n;i++)
   {
    	char title[100];
    	int isbn[5];
    	int pages;
    
       	cin>>title;
    
       	for (int j=0;j<5;j++)
    		cin>>isbn[j];
    
    	cin>>pages;
    
       	Book nov=Book(title,isbn,pages);
       
    	//adding a new book
       	library+=nov;   
       
   }
    //the book which has the same isbn as some previous one
    char title[100];
    int isbn[5];
    int pages;
    cin>>title;
    for (int i=0;i<5;i++)
    cin>>isbn[i];
    cin>>pages;
    
    Book greshka=Book(title,isbn,pages);
    
    //deleting a book
    library-=greshka;
    
    library.printNumberOfPages(150);
    
    return 0;
}
