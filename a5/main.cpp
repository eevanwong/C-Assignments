#include <iostream>   
using namespace std;
#include "book.hpp"
#include "library.hpp"
#include<vector>


/*
We tested each function to ensure everything worked, as in we created a
book vector, added books to it, and utilized the print method, as well as the remove/add methods, also 
checked the different parametric constructors and such

Note: We did run into an error, something about unable to allocate memory, like 
the program wouldnt run, but for some reasonw hen we compiled it again it worked

Limitations might include memory(?) 
*/

void test_book_insertion(Library &new_library, Book random_book);
//purpose: to insert a book into a library

//input: library object and book object

//output: none
void test_book_removal(Library &new_library, Book random_book);
//purpose: remove a book from a library

//input: Library and book object

//output: none


int main() {     //testing that they work
    
    vector<Book> book_delivery;
    book_delivery.push_back(Book("life", "me"));
    book_delivery.push_back(Book("Lifewithoutcoop", "me", "November18"));
    Book random_book = Book("Hallejijah", "m,e", "222");
    book_delivery.push_back(random_book);
    Library new_library(book_delivery);

    new_library.print();
    test_book_insertion(new_library, random_book);
    test_book_removal(new_library, random_book);
    
}


void test_book_insertion(Library &new_library,Book random_book) {
    new_library.insert_book(random_book); //inserts book object into the library object
}


void test_book_removal(Library &new_library, Book random_book) {
    new_library.remove_book(random_book); //removes book object from library object

}

