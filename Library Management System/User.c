//Creation of User.c
#include <stdio.h>
#include <string.h>
#include "User.h"

void initializeUser(User* user, int id, const char* name, const char* contact) {
    user->id = id;
    strncpy(user->name, name, sizeof(user->name));
    strncpy(user->contact, contact, sizeof(user->contact));
}
//getting information to display user needed contents
void displayUser(const User* user) {
    printf("ID: %d\nName: %s\nContact: %s\n", user->id, user->name, user->contact);
}
