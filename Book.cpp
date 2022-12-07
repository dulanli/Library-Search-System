/*
    Book.cpp
    Author: M00723060
    Created: 20/03/2021
    Updated: 29/04/2021
*/

#include "book.h"

Book::Book() {

    for (int i = 0; i < tableSize; i++) {

        HashTable[i] = new book;

        HashTable[i]->title = "empty";
        HashTable[i]->author = "empty";
        HashTable[i]->isbn = "empty";
        HashTable[i]->qty  = "empty";

        HashTable[i]->next = NULL;
    }

}

Book::~Book(){
    std::cout << "destructor: Book\n";
}

/*
    Creating and defining the Hash Table.
    @return the index of the table
*/
int Book::Hash(std::string key) {

    int hash = 0;
    int index;
    
    for (int i = 0; i < key.length(); i++) {

        hash = hash + (int)key[i];
    }
    
    index = hash % tableSize;
    
    return index;
}

/*
    Add a book to the Hash Table.
*/
void Book::addBook(std::string title, std::string author, 
                   std::string isbn, std::string qty) {

    int index = Hash(title);
    
    if (HashTable[index]->title == "empty") {
        
        HashTable[index]->title = title;
        HashTable[index]->author = author;
        HashTable[index]->isbn = isbn;
        HashTable[index]->qty = qty;

    } else {
    
        book* Ptr = HashTable[index];
        book* n = new book;

        n->title = title;
        n->author = author;
        n->isbn = isbn;
        n->qty = qty;
        n->next = NULL;
        
        while (Ptr->next != NULL) {
        
            Ptr = Ptr->next;

        }
        
        Ptr->next = n;
        
    }
}

/*
    Search a particular book in the Hash Table.
*/
void Book::searchBook(std::string title) {

    int index = Hash (title);

    bool foundName = false;
    book* Ptr = HashTable[index];
    std::string author = "";
    std::string isbn = "";
    std::string qty = "";
        
    while (Ptr != NULL) {
    
        if (Ptr->title == title) {
        
            foundName = true;

            author = Ptr->author;
            isbn = Ptr->isbn;
            qty = Ptr->qty;
        }
        
        Ptr = Ptr->next;
    }
    
    if (foundName == true) {
        
        std::cout << " Title: "<< title << std::endl;
        std::cout << " Author: " << author << std::endl;
        std::cout << " ISBN: " << isbn << std::endl;
        std::cout << " Quantity: " << qty << std::endl;
        
    } else {
        
        std::cout << ">> ";
        std::cout << title << " Not Found!" << std::endl;
    }
    
}

/*
    Delete a book in the Hash Table.
*/
void Book::deleteBook(std::string title) {

    int index = Hash(title);
    
    book* delPtr;
    book* P1;
    book* P2;

    // bucket is empty
    if (HashTable[index]->title == "empty" && HashTable[index]->author == "empty" 
       && HashTable[index]->isbn == "empty" && HashTable[index]->qty == "empty") {
    
        std::cout << ">> ";
        std::cout << title << " Not Found!" << std::endl;  

    // only one book in the bucket
    } else if (HashTable[index]->title == title && HashTable[index]->next == NULL) {
    
        HashTable[index]->title = "empty";
        HashTable[index]->author = "empty";
        HashTable[index]->isbn = "empty";
        HashTable[index]->qty = "empty";
        
        std::cout << ">> ";
        std::cout << title << " has been successfully deleted!" << std::endl; 
    
    // multiple books in the bucket and first one is a match
    } else if (HashTable[index]->title == title) {
    
        delPtr = HashTable[index];
        HashTable[index] = HashTable[index]->next;
        delete delPtr;
        
        std::cout << ">> ";
        std::cout << title << " has been successfully deleted!" << std::endl;     
    
    // multiple books but first one is not a match 
    } else {
    
        P1 = HashTable[index]->next;
        P2 = HashTable[index];
        
        while (P1 != NULL && P1->title != title) {

            P2 = P1;
            P1 = P1->next;
        }
        
        if (P1 == NULL) {
        
            std::cout << ">> ";
            std::cout << title << " Not Found!" << std::endl;         
        
        } else {
        
            delPtr = P1;
            P1 = P1->next;
            P2->next = P1;
            
            delete delPtr;

            std::cout << ">> ";
            std::cout << title << " has been successfully deleted!" << std::endl;     
   
        }
    }

}


        
        
        
