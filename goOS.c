// ==============
//     Kernel
// ==============

#include <stdio.h>
#include <string.h>

// ==============
//   Functions
// ==============

void greet() {
    printf("Hello!\n");
}

void echo(char *msg) {
    printf("%s\n", msg);
}

void clear() {
    printf("\033[H\033[J");
}

void help() {
    printf("GoOS Commands:\n==========\n");
    printf("greet - Shows a greet message\necho [msg] - Echos a message\nclear - Clears the screen\nhelp - Shows this help message\nshutdown - Shutdowns the OS\n");
    printf("==========\n");
}

// ==============
//      Main
// ==============

int main() {
    printf("Welcome to\n");
    printf("============\n");
    printf("    GoOS        \n");
    printf("============\n");
    char option[100];
    while (1) {
        printf(">>> ");
        fgets(option, sizeof(option), stdin);
        option[strcspn(option, "\n")] = 0;
        if (strcmp(option, "greet") == 0) {
            greet();
        } else if (strncmp(option, "echo ", 5) == 0) {
            echo(option + 5);
        } else if (strcmp(option, "clear") == 0) {
            clear();
        } else if (strcmp(option, "help") == 0) {
            help();
        } else if (strcmp(option, "shutdown") == 0) {
            break;
        } else if (strcmp(option, "") == 0) {
            // Do nothing.
        } else {
            printf("The command %s does not exist!\n", option);
        }
    }
    return 0;
}
