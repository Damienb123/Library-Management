// User.h
#ifndef USER_H
#define USER_H

#define MAX_NAME_LENGTH 50
#define MAX_CONTACT_LENGTH 20
#define MAX_USERS 100

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char contact[MAX_CONTACT_LENGTH];
} User;

void initializeUser(User* user, int id, const char* name, const char* contact);
void displayUser(const User* user);

#endif // USER_H
