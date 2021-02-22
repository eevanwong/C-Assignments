#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <iostream>
#include<vector>
#include "book.hpp"
using namespace std;

class Library {
    //Creates a class with vector named "books"
    vector<Book> books;

public:
    //Purpose: Create a class type with the "Library" identifier to access the 
    //         vector array filled with books
    Library(vector<Book> new_books);

    Library();

    void print();
    //Purpose: Output all the books in numeric order, including the title, author, and date
    //Inputs:  None, variables are passed by value in the vector "books"  
    //Outputs: None, table is outputted to the console
    bool insert_book(Book new_book);
    //Purpose: Insert a book instance into the "books" vector in the library of books.
    //         If the book is already present in the array, no book is inserted. 
    //Inputs:  Book new_book - The new book instance that is inserted into the library vector
    //Outputs: Returns true if the book was inserted into the library
    //         Returns  false if the book is already present in the library
    //         results of insertion are outputted to the console 
    bool insert_book(string bookTitle, string author, string date);
    //Purpose: Insert three string variables including the title, author, and date into the "books" vector in the library of books.
    //         If the book is already present in the array, no book is inserted. 
    //Inputs:  string bookTitle - Title of the book  
    //         string author - Author of the book 
    //         string date - Date of the book
    //Outputs: Returns true if the book was inserted into the library
    //         Returns  false if the book is already present in the library
    //         results of insertion are outputted to the console 
    bool remove_book(Book new_book);
    //Purpose: Removes a book instance into the "books" vector in the library of books.
    //         If the book is present in the vector, the book is removed from the library vector. 
    //         If the book is not present in the vector, no book is not removed from the library vector. 
    //Inputs:  Book new_book - The new book instance that is inserted into the library vector
    //Outputs: Returns true if the book was removed into the library
    //         Returns false if the book was not present in the library
    bool remove_book(string bookTitle, string author, string date);
    //Purpose: Remove three string variables of a book including the title, author, and date into the "books" vector in the library of books.
    //         If the book is present in the vector, the book is removed from the library vector. 
    //         If the book is not present in the vector, no book is not removed from the library vector. 
    //Inputs:  string bookTitle - Title of the book  
    //         string author - Author of the book 
    //         string date - Date of the book
    //Outputs: Returns true if the book was inserted into the library
    //         Returns false if the book is already present in the library
    //         Results of insertion are outputted to the console 
};

#endif