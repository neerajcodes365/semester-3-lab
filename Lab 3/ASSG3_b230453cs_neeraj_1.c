#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[50];
    char rollno[10];
    int age;
    struct node *next;
};

struct node *arr[4] = {NULL};

int hash(char name[], int age) {
    int i = 0;
    int sum = 0;
    while (name[i] != '\0') {
        sum += name[i];
        i++;
    }
    sum += age;
    return sum % 4;
}

void insert(struct node *a) {
    int index = hash(a->name, a->age);
    a->next = arr[index];
    arr[index] = a;
}

void insert_target(struct node *a, int target) {
    a->next = arr[target];
    arr[target] = a;
}

void countandlist(struct node** arr, int group) {
    struct node* temp = arr[group];
    int count = 0;

    while (temp != NULL) {
        temp = temp->next;
        count++;
    }

    // Print '0' if there are no elements in the group
    if (count == 0) {
        printf("0\n");
        return;
    }

    printf("%d ", count);

    char* students[count];
    temp = arr[group];
    for (int i = 0; i < count; i++) {
        students[i] = temp->name;
        temp = temp->next;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(students[i], students[j]) > 0) {
                char* temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%s ", students[i]);
    }
    printf("\n");
}


void toLowerCaseUsingASCII(char* str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;  
        }
    }
}

void grouplistbranch(struct node **arr, int group, char *branch) {
    struct node* temp = arr[group];
    int found = 0;

    toLowerCaseUsingASCII(branch);

    while (temp != NULL) {
        char studentBranch[3];
        studentBranch[0] = temp->rollno[7];
        studentBranch[1] = temp->rollno[8];
        studentBranch[2] = '\0';
        toLowerCaseUsingASCII(studentBranch);

        if (strcmp(studentBranch, branch) == 0) {
            printf("%s ", temp->name);
            found = 1;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("-1");
    }
    printf("\n");
}

void print(char *rollno) {
    for (int i = 0; i < 4; i++) {
        struct node *temp = arr[i];
        while (temp != NULL) {
            if (strcmp(temp->rollno, rollno) == 0) {
                printf("%s %d %c%c\n", temp->name, temp->age, temp->rollno[7], temp->rollno[8]);
                return;
            }
            temp = temp->next;
        }
    }
    printf("-1\n");
}

void grouptransfer(struct node **arr, int source, int target, char *branch) {
    int transfers = 0;
    struct node *temp = arr[source];
    struct node *prev = NULL;

    toLowerCaseUsingASCII(branch);

    while (temp != NULL) {
        char studentBranch[3];
        studentBranch[0] = temp->rollno[7];
        studentBranch[1] = temp->rollno[8];
        studentBranch[2] = '\0';
        toLowerCaseUsingASCII(studentBranch);

        if (strcmp(studentBranch, branch) == 0) {
            struct node *nextTemp = temp->next;
            if (prev == NULL) {
                arr[source] = temp->next;
            } else {
                prev->next = temp->next;
            }
            insert_target(temp, target);
            transfers++;
            temp = nextTemp;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
    printf("%d\n", transfers);
}

int GroupIndexAndSplit(struct node** arr, char* name) {
    for (int i = 0; i < 4; i++) {
        struct node* temp = arr[i];
        while (temp != NULL) {
            if (strcmp(temp->name, name) == 0) {
                printf("%d\n", i);
                return i;
            }
            temp = temp->next;
        }
    }
    printf("-1\n");
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        struct node *a = (struct node *)malloc(sizeof(struct node));
        scanf("%s %s %d", a->name, a->rollno, &a->age);
        a->next = NULL;
        insert(a);
    }

    char choice;
    char name[50];
    int group;
    char branch[3];
    char rollno[10];
    int source, target;

    do {
        scanf(" %c", &choice);
        switch (choice) {
            case 'a':
                scanf("%s", name);
                GroupIndexAndSplit(arr, name);
                break;

            case 'b':
                scanf("%d", &group);
                countandlist(arr, group);
                break;

            case 'c':
                scanf("%d %s", &group, branch);
                grouplistbranch(arr, group, branch);
                break;

            case 'd':
                scanf("%s", rollno);
                print(rollno);
                break;

            case 'e':
                scanf("%d %d %s", &source, &target, branch);
                grouptransfer(arr, source, target, branch);
                break;

            case 'f':
                break;
        }
    } while (choice != 'f');
    return 0;
}
