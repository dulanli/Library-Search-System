/*
    librarySystem.cpp
    Author: M00723060
    Created: 20/03/2021
    Updated: 29/04/2021
*/

#include <fstream>
#include "book.h"
#include <sstream> 
#include <limits>   // to get numeric limits

int main(int argc, char *argv[]) {

    Book hashMap = Book();
    std::string title = "";
    std::string author = "";
    std::string isbn = "";
    std::string qty = "";
   
    system("clear");    // clear the screen

    std::cout << "==================================" << std::endl;
    std::cout << " == ||Library Search System|| ==" << std::endl;
    std::cout << "==================================" << std::endl << std::endl;

    if (argc != 2) {

        std::cout << "[ERROR] Invalid file" << std::endl;
        std::cout << ">> Please check your file input" << std::endl;
        exit(1);

    } else {
        
        // Read file from command line
        std::ifstream file(argv[1]);

        if (!file.good()) {

            std::cout << "[ERROR] Invalid file" << std::endl;
            std::cout << ">> File does not exist" << std::endl;
            exit(1);

        } else {

            std::string text;

            std::cout << "   [DATABASE] " << argv[1];

            while (getline(file, text)) {    // read the file line by line

                std::istringstream iss(text);
                getline(iss, title, '\t');
                getline(iss, author, '\t');
                getline(iss, isbn, '\t');
                getline(iss, qty, '\t');

                hashMap.addBook(title, author, isbn, qty);
            }
            file.close();

        }

    }

    int selection = 0;

    do {
        std::string searchTitle = "";
        std::string deleteTitle = "";

        std::cout << std::endl;
        std::cout << "\n-----------------------" << std::endl;
        std::cout << "----- [BOOK MENU] -----" << std::endl;
        std::cout << "-----------------------" << std::endl;
        std::cout << " [1] Search" << std::endl;
        std::cout << " [2] Add book" << std::endl;
        std::cout << " [3] Delete book"<< std::endl;
        std::cout << " [4] Exit" << std::endl;

        std::cout << "> ";
        std::cin >> selection;
        std::cout << "\n==================================" << std::endl;

        if (std::cin.fail()) {
            
            std::cout << "\n[ERROR] Invalid input" << std::endl;
            exit(1);
        }

        switch (selection) {

            case 1:                
                std::cout << "\n----------" << std::endl;
                std::cout << "  Search" << std::endl;
                std::cout << "----------" << std::endl;
                std::cout << "\nEnter Book Title: ";

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                getline(std::cin, searchTitle);
                std::cout << std::endl;

                hashMap.searchBook(searchTitle);

                break;

            case 2:
                std::cout << "\n------------" << std::endl;
                std::cout << "  Add Book" << std::endl;
                std::cout << "------------" << std::endl;

                std::cout << "\nEnter Book Title: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                getline(std::cin, title);

                std::cout << "Enter Author(s)\n";
                std::cout << "[Separate by a ',' if there are multiple authors]: ";
                getline(std::cin, author);

                std::cout << "Enter ISBN: ";
                getline(std::cin, isbn);

                std::cout << "Enter qty: ";
                getline(std::cin, qty);

                std::cout << std::endl;

                hashMap.addBook(title, author, isbn, qty);

                std::cout << ">> ";
                std::cout << title << " successfully added!";

                break;

            case 3:
                std::cout << "\n---------------" << std::endl;
                std::cout << "  Delete Book" << std::endl;
                std::cout << "---------------" << std::endl;
                std::cout << "\nEnter Book Title: ";

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                getline(std::cin, deleteTitle);
                std::cout << std::endl;

                hashMap.deleteBook(deleteTitle);

                break;  
            
            case 4:
                exit(1);

            default:
                std::cout << "\n[ERROR] Invalid input" << std::endl;
        }

    }   while (selection != 4);
    
    return 0;

}

