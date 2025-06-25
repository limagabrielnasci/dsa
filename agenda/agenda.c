#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE     20
#define AGE_SIZE      3
#define EMAIL_SIZE    31
#define RECORD_SIZE   (NAME_SIZE + AGE_SIZE + EMAIL_SIZE)
#define TEMP_SIZE     NAME_SIZE

void showMenu(void *pBuffer) {
    printf("\n1 - Add Person (Name, Age, Email)\n");
    printf("2 - Remove Person\n");
    printf("3 - Search Person\n");
    printf("4 - List All\n");
    printf("5 - Exit\n");
    printf("Choice: ");
    scanf("%d", (int *)pBuffer);
    getchar();
}

void addPerson(void **pBuffer) {
    *((int *)(*pBuffer) + 1) += 1;

    *pBuffer = realloc(*pBuffer, sizeof(int) * 2 + TEMP_SIZE + (*((int *)(*pBuffer) + 1)) * RECORD_SIZE);
    if (!*pBuffer) exit(1);

    char *newRecord = ((char *)((int *)(*pBuffer) + 2)) + TEMP_SIZE + ((*((int *)(*pBuffer) + 1) - 1) * RECORD_SIZE);

    printf("Name: ");
    scanf("%19[^\n]%*c", newRecord);
    printf("Age: ");
    scanf("%2s%*c", newRecord + NAME_SIZE);
    printf("Email: ");
    scanf("%30s%*c", newRecord + NAME_SIZE + AGE_SIZE);
}

void removePerson(void **pBuffer) {
    printf("Enter name to remove: ");
    scanf("%19[^\n]%*c", (char *)((int *)(*pBuffer) + 2));

    char *dataStart = ((char *)((int *)(*pBuffer) + 2)) + TEMP_SIZE;
    int total = *((int *)(*pBuffer) + 1);
    char *ptr = dataStart;
    char *end = dataStart + total * RECORD_SIZE;

    while (ptr < end) {
        if (strcmp(ptr, (char *)((int *)(*pBuffer) + 2)) == 0) {
            if (ptr != end - RECORD_SIZE) {
                memcpy(ptr, end - RECORD_SIZE, RECORD_SIZE);
            }
            *((int *)(*pBuffer) + 1) -= 1;

            *pBuffer = realloc(*pBuffer, sizeof(int) * 2 + TEMP_SIZE + (*((int *)(*pBuffer) + 1)) * RECORD_SIZE);
            if (!*pBuffer) exit(1);

            printf("Person removed.\n");
            return;
        }
        ptr += RECORD_SIZE;
    }

    printf("Person not found.\n");
}

void searchPerson(void *pBuffer) {
    printf("Enter name to search: ");
    scanf("%19[^\n]%*c", (char *)((int *)pBuffer + 2));

    char *dataStart = ((char *)((int *)pBuffer + 2)) + TEMP_SIZE;
    int total = *((int *)pBuffer + 1);
    char *ptr = dataStart;
    char *end = dataStart + total * RECORD_SIZE;

    while (ptr < end) {
        if (strcmp(ptr, (char *)((int *)pBuffer + 2)) == 0) {
            printf("\nName: %s\nAge: %s\nEmail: %s\n", ptr, ptr + NAME_SIZE, ptr + NAME_SIZE + AGE_SIZE);
            return;
        }
        ptr += RECORD_SIZE;
    }

    printf("Person not found.\n");
}

void listPeople(void *pBuffer) {
    int total = *((int *)pBuffer + 1);
    if (total == 0) {
        printf("No people in list.\n");
        return;
    }

    char *dataStart = ((char *)((int *)pBuffer + 2)) + TEMP_SIZE;
    char *ptr = dataStart;
    char *end = dataStart + total * RECORD_SIZE;

    while (ptr < end) {
        printf("\nName: %s\nAge: %s\nEmail: %s\n", ptr, ptr + NAME_SIZE, ptr + NAME_SIZE + AGE_SIZE);
        ptr += RECORD_SIZE;
    }
}

int main() {
    void *pBuffer = calloc(1, sizeof(int) * 2 + TEMP_SIZE);
    if (!pBuffer) return 1;

    *((int *)pBuffer + 1) = 0;

    while (1) {
        showMenu(pBuffer);
        int option = *((int *)pBuffer);
        if (option == 1) {
            addPerson(&pBuffer);
        } else if (option == 2) {
            removePerson(&pBuffer);
        } else if (option == 3) {
            searchPerson(pBuffer);
        } else if (option == 4) {
            listPeople(pBuffer);
        } else if (option == 5) {
            break;
        }
    }

    free(pBuffer);
    return 0;
}