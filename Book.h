#ifndef _BOOK_H_
#define _BOOK_H_

/*
    Book.h
    Author: M00723060
    Created: 20/03/2021
    Updated: 29/04/2021
*/

#include <iostream>
#include <string>

class Book {

    private:
        static const int tableSize = 50;
        
        struct book {
            std::string title;
            std::string author;
            std::string isbn;
            std::string qty;
            book* next;        
        };
        
        book* HashTable[tableSize];

    public:
        Book (std::string title, std::string author, std::string isbn, std::string qty);
        Book();
        ~Book();
        int Hash(std::string key);
        void addBook(std::string title, std::string author, std::string isbn, std::string qty);
        void searchBook(std::string title);
        void deleteBook(std::string title);
		
};

#endif 

