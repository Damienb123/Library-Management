// creation of Book.h
#ifndef BOOK_H
#define BOOK_H

//initializing length and needed quantity
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_BOOKS 100

typedef struct {
    char isbn[14];  // Assuming ISBN-13 format
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int publicationYear;
    int isBorrowed;  // New field
} Book;

void initializeBook(Book* book, const char* isbn, const char* title, const char* author, int publicationYear);
void displayBook(const Book* book);

#endif // BOOK_H
