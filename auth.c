#include <stdio.h>
#include <string.h>
#include "auth.h"

int authenticate_user() {
    char uname[50], pwd[50];
    printf("Enter username: ");
    scanf("%s", uname);
    printf("Enter password: ");
    scanf("%s", pwd);
    if (strcmp(uname, "anany") == 0 && strcmp(pwd, "me123") == 0) {
        printf("Authentication successful!\n");
        return 1;
    } else {
        printf("Authentication failed! Invalid username or password.\n");
        return 0;
    }
}
