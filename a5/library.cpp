#include "library.hpp"


Library::Library() :
    books() {}
  
Library::Library(vector<Book> new_books){
    for (int i = 0; i < new_books.size(); i++) {      //runs for loop to put each book object from the other vector into this new library object
        books.push_back(new_books[i]);
    }
}

void Library::print() {
    for (int i = 0; i < books.size(); i++) {    //runs for loop and print method to print out all of the book info in the library along with the index of the book
        cout << i << endl;
        books[i].print();
    }   
}

bool Library::insert_book(Book new_book) {
    for (int i = 0; i < books.size(); i++) {
        if (books[i].get_bookTitle() == new_book.get_bookTitle() && books[i].get_author() == new_book.get_author() && books[i].get_date() == new_book.get_date()) {
            cout << "book is already in library, please input another book" << endl;
            return false;      //insert book checks each of the books in the library and the new book to see if theyre the exact same, if so then fn will return false and wont add it to the library
        }
    }

    books.push_back(new_book);
    cout << "book has been added to the library" << endl; //if check is not true, then it will add book object to library
    return true;
}

bool Library::insert_book(string bookTitle, string author, string date) {
    for (int i = 0; i < books.size(); i++) {
        if (books[i].get_bookTitle() == bookTitle && books[i].get_author() == author && books[i].get_date() == date) {
            cout << "book is already in library, please input another book" << endl; 
            return false;  //same thing as the fn above but takes in book info and not an actual instance
        }
    }
    Book new_book(bookTitle, author, date);
    books.push_back(new_book);
    cout << "book has been added to the library"<< endl;
    return true;
}


bool Library::remove_book(Book new_book) {
    for (int i = 0; i < books.size(); i++) {
        if (books[i].get_bookTitle() == new_book.get_bookTitle() && books[i].get_author() == new_book.get_author() && books[i].get_date() == new_book.get_date()) {
            books.erase(books.begin()+i);
            cout << "book has been erased"<< endl;
            return true;        //Checks if the book that is being requested to be removed is in the library, if so, it is deleted, returns true
        }
    }

    cout << "book has is not in the library"<< endl; //if book is not in library, it will return false
    return false;
}

bool Library::remove_book(string bookTitle, string author, string date) {
    for (int i = 0; i < books.size(); i++) {
        if (books[i].get_bookTitle() == bookTitle && books[i].get_author() == author && books[i].get_date() == date) {
            books.erase(books.begin() + i);
            cout << "book has been erased"<< endl;
            return true;   //same thing as fn above but instead it compares the values passed with the values of the book objects in the library
        }
    }
    cout << "book not in library"<< endl;
    return false;
} 