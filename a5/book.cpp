//for actual initialization
#include "book.hpp"

Book::Book(string new_bookTitle, string new_authors, string new_date) : 
    bookTitle(new_bookTitle),
    authors(new_authors),
    date(new_date) {}
    
Book::Book(string new_bookTitle, string new_authors) : 
    bookTitle(new_bookTitle),
    authors(new_authors),
    date("n/a") {}

Book::Book(string new_bookTitle) : 
    bookTitle(new_bookTitle),
    authors("n/a"),
    date("n/a") {}

Book::Book() : 
    bookTitle("n/a"),
    authors("n/a"),
    date("n/a") {}

void Book::print() { //prints info
    cout << "Title: " << bookTitle << endl
    << "Authors: " << authors << endl 
    << "Date of Publication: " << date << endl;
}

string Book::get_bookTitle(){  //returns the values of the objects
    return(bookTitle);
}
string Book::get_author(){
    return(authors);
}

string Book::get_date(){
    return(date);
}





