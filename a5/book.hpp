//for declarations

//why?
#ifndef BOOK_HPP 
#define BOOK_HPP

#include <iostream>
using namespace std;

class Book {
    string bookTitle,authors,date;
  
public:
    Book(string new_bookTitle, string new_authors, string new_date);
    //purpose: parametric constructor if object is created with all 3 parameteres

    Book(string new_bookTitle, string new_authors);
    //purpose: parametric constructor if object is created with 2 book title and author name

    Book(string new_bookTitle);
    //purpose: parametric constructor if object is created with book title

    Book();
    //purpose: parametric construcor if objected is created with no parameters given


    string get_bookTitle();
    //purpose: sends back the book title of the book object
    //inputs: none
    //output: bookTitle

    string get_author();
    //purpose: sends back the author of the book object
    //inputs:none
    //output: author

    string get_date(); 
    //purpose: sends back the date of the book object
        //inputs:none
    //output: date


    void print();
    //purpose: prints the members of the book
        //inputs:none
    //output: none
};

#endif