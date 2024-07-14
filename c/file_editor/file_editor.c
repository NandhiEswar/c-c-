#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 100
#define MAX_TEXT 1000

void displayMenu() {
    printf("Simple Text Editor\n");
    printf("1. Open File\n");
    printf("2. Save File\n");
    printf("3. Edit Text\n");
    printf("4. Display Text\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void openFile(char *filename, char *text) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fread(text, sizeof(char), MAX_TEXT, file);
    fclose(file);
    printf("File opened successfully.\n");
}

void saveFile(char *filename, char *text) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error saving file.\n");
        return;
    }

    fwrite(text, sizeof(char), strlen(text), file);
    fclose(file);
    printf("File saved successfully.\n");
}

void editText(char *text) {
    printf("Enter text (end with a single line containing only 'END'):\n");
    char buffer[MAX_TEXT];
    text[0] = '\0'; // Clear the text

    while (1) {
        fgets(buffer, MAX_TEXT, stdin);
        if (strncmp(buffer, "END", 3) == 0 && buffer[3] == '\n') {
            break;
        }
        strcat(text, buffer);
    }
}

void displayText(char *text) {
    printf("Current Text:\n%s\n", text);
}

int main() {
    char filename[MAX_FILENAME];
    char text[MAX_TEXT] = {0};
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume the newline character left in the buffer

        switch (choice) {
            case 1:
                printf("Enter filename to open: ");
                fgets(filename, MAX_FILENAME, stdin);
                filename[strcspn(filename, "\n")] = '\0'; // Remove newline character
                openFile(filename, text);
                break;
            case 2:
                printf("Enter filename to save: ");
                fgets(filename, MAX_FILENAME, stdin);
                filename[strcspn(filename, "\n")] = '\0'; // Remove newline character
                saveFile(filename, text);
                break;
            case 3:
                editText(text);
                break;
            case 4:
                displayText(text);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
