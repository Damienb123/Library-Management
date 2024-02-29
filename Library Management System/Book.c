//creation of Book.c
#include <stdio.h>
#include <string.h>
#include "Book.h"

void initializeBook(Book* book, const char* isbn, const char* title, const char* author, int publicationYear) {
    strncpy(book->isbn, isbn, sizeof(book->isbn));
    strncpy(book->title, title, sizeof(book->title));
    strncpy(book->author, author, sizeof(book->author));
    book->publicationYear = publicationYear;
}

void displayBook(const Book* book) {
    printf("ISBN: %s\nTitle: %s\nAuthor: %s\nPublication Year: %d\n",
           book->isbn, book->title, book->author, book->publicationYear);
}