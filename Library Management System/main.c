//include needed files to run the program
#include <stdio.h>
#include "Book.h"
#include "User.h"
#include "Borrow.h"
#include "Hash.h"
#include "RootCauseAnalysis.h"

int main() {
    // Initialize components
    HashTable bookHashTable;
    initializeHashTable(&bookHashTable);

    BorrowList borrowList;
    initializeBorrowList(&borrowList);

    ErrorLog errorLog;
    initializeErrorLog(&errorLog);

    // Example books and users
    Book book1, book2;
    initializeBook(&book1, "1234567890123", "Book One", "Author One", 2020);
    initializeBook(&book2, "9876543210987", "Book Two", "Author Two", 2015);

    User user1, user2;
    initializeUser(&user1, 1, "User One", "123-456-7890");
    initializeUser(&user2, 2, "User Two", "987-654-3210");

    // Example usage of components
    insertBook(&bookHashTable, &book1);
    insertBook(&bookHashTable, &book2);

    displayBook(findBook(&bookHashTable, "1234567890123"));

    borrowBook(&borrowList, &book1, &user1);
    borrowBook(&borrowList, &book2, &user2);

    displayBorrowList(&borrowList);

    returnBook(&borrowList, "1234567890123");

    displayBorrowList(&borrowList);

    // Log an error for demonstration purposes
    logError(&errorLog, "Unexpected behavior occurred in the library system.");

    // Display error log
    displayErrorLog(&errorLog);

    return 0;
}