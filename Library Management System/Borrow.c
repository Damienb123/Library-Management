// creation of Borrow.c
#include <stdio.h>
#include <string.h>
#include "Borrow.h"

void initializeBorrowList(BorrowList* borrowList) {
    borrowList->count = 0;
}
//getting a count of borrowed books until limit is reached
//if borrowing isn't successful, return 0
int borrowBook(BorrowList* borrowList, Book* book, User* user) {
    if (borrowList->count >= MAX_BORROWED_BOOKS) {
        printf("User has reached the maximum limit of borrowed books.\n");
        return 0;  // Borrowing failed
    }

    // Check if the book is available
    if (book->isBorrowed) {
        printf("Book not found or already borrowed.\n");
        return 0;  // Borrowing failed
    }

    // Add the book to the borrow list
    BorrowEntry* entry = &borrowList->entries[borrowList->count];
    entry->book = book;
    entry->user = user;
    // Set due date (you may implement this based on your requirements)
    strncpy(entry->dueDate, "2024-03-15", sizeof(entry->dueDate));

    // Mark the book as borrowed
    book->isBorrowed = 1;

    borrowList->count++;
    return 1;  // Borrowing successful
}

int returnBook(BorrowList* borrowList, const char* isbn) {
    for (int i = 0; i < borrowList->count; ++i) {
        if (strcmp(borrowList->entries[i].book->isbn, isbn) == 0) {
            // Mark the book as returned
            borrowList->entries[i].book->isBorrowed = 0;

            // Remove the entry from the borrow list
            for (int j = i; j < borrowList->count - 1; ++j) {
                borrowList->entries[j] = borrowList->entries[j + 1];
            }
            borrowList->count--;

            return 1;  // Returning successful
        }
    }

    printf("Book not found in the borrow list.\n");
    return 0;  // Returning failed
}

void displayBorrowList(const BorrowList* borrowList) {
    printf("Borrowed Books:\n");
    for (int i = 0; i < borrowList->count; ++i) {
        printf("Book ISBN: %s, User ID: %d, Due Date: %s\n",
               borrowList->entries[i].book->isbn,
               borrowList->entries[i].user->id,
               borrowList->entries[i].dueDate);
    }
}
