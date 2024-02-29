// Borrow.h
#ifndef BORROW_H
#define BORROW_H

#define MAX_BORROWED_BOOKS 3

#include "Book.h"
#include "User.h"

typedef struct {
    Book* book;
    User* user;
    char dueDate[11];  // Assuming date format YYYY-MM-DD
} BorrowEntry;

typedef struct {
    BorrowEntry entries[MAX_BORROWED_BOOKS];
    int count;
} BorrowList;

void initializeBorrowList(BorrowList* borrowList);
int borrowBook(BorrowList* borrowList, Book* book, User* user);
int returnBook(BorrowList* borrowList, const char* isbn);
void displayBorrowList(const BorrowList* borrowList);

#endif // BORROW_H
