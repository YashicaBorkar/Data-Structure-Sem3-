#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;

typedef struct LL {
    node *start;
} LL;

void insertbegin(LL *l, int x) {
    node *newrec = (node *)malloc(sizeof(node));
    newrec->data = x;
    newrec->next = l->start;
    newrec->prev = NULL;

    if (l->start != NULL) {
        l->start->prev = newrec;
    }
    l->start = newrec;
}

void insertend(LL *l, int x) {
    node *newrec = (node *)malloc(sizeof(node));
    newrec->data = x;
    newrec->next = NULL;
    newrec->prev = NULL;

    if (l->start == NULL) {
        l->start = newrec;
    } else {
        node *p = l->start;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = newrec;
        newrec->prev = p;
    }
}

void insert(LL *l, int x, int pos) {
    int i;
    node *newrec, *p;
    newrec = (node *)malloc(sizeof(node));
    newrec->data = x;
    newrec->next = NULL;
    newrec->prev = NULL;

    if (pos > count(l) + 1) {
        printf("\nInvalid Position...");
    } else if (pos == 1) {
        newrec->next = l->start;
        if (l->start != NULL) {
            l->start->prev = newrec;
        }
        l->start = newrec;
    } else {
        p = l->start;
        for (i = 1; i < pos - 1; i++) {
            p = p->next;
        }
        newrec->next = p->next;
        newrec->prev = p;
        if (p->next != NULL) {
            p->next->prev = newrec;
        }
        p->next = newrec;
    }

    printf("\nList after insertion: ");
    // display(l);
}

void deletebegin(LL *l) {
    node *p;
    if (l->start == NULL) {
        printf("\nDeletion not possible...");
    } else {
        p = l->start;
        l->start = l->start->next;
        if (l->start != NULL) {
            l->start->prev = NULL;
        }
        free(p);
    }
}

void deleteend(LL *l) {
    node *p;
    if (l->start == NULL) {
        printf("\nDeletion not possible...");
    } else if (l->start->next == NULL) {
        p = l->start;
        l->start = NULL;
        free(p);
    } else {
        p = l->start;
        while (p->next != NULL) {
            p = p->next;
        }
        p->prev->next = NULL;
        free(p);
    }
}

void delete(LL *l, int pos) {
    int i;
    node *p;
    if (pos > count(l)) {
        printf("\nInvalid position...");
    } else if (pos == 1) {
        deletebegin(l);
    } else {
        p = l->start;
        for (i = 1; i < pos; i++) {
            p = p->next;
        }
        if (p->next != NULL) {
            p->next->prev = p->prev;
        }
        p->prev->next = p->next;
        free(p);
    }

    printf("\nList after deletion: ");
    // display(l);
}

int count(LL *l) {
    int cnt = 0;
    node *p = l->start;
    while (p != NULL) {
        cnt++;
        p = p->next;
    }
    return cnt;
}

void display(LL *l) {
    node *p = l->start;
    if (p == NULL) {
        printf("\nList is empty...");
    } else {
        printf("\nList: ");
        while (p != NULL) {
            printf("\t%d ", p->data);
            p = p->next;
        }
        // printf("NULL\n");
    }
}

int main() {
    LL l;
    l.start = NULL;
    int ch, x;

    do {
        printf("\n\nMenu:");
        printf("\n1. Insert at beginning");
        printf("\n2. Insert at end");
        printf("\n3. Delete from beginning");
        printf("\n4. Delete from end");
        printf("\n5. Insert at a specific position");
        printf("\n6. Delete from a specific position");
        printf("\n7. Display list");
        printf("\n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter element to be inserted: ");
                scanf("%d", &x);
                insertbegin(&l, x);
                display(&l);
                break;
            case 2:
                printf("\nEnter element to be inserted: ");
                scanf("%d", &x);
                insertend(&l, x);
                display(&l);
                break;
            case 3:
                deletebegin(&l);
                display(&l);
                break;
            case 4:
                deleteend(&l);
                display(&l);
                break;
            case 5: {
                int pos;
                printf("\nEnter element to be inserted and position: ");
                scanf("%d%d", &x, &pos);
                insert(&l, x, pos);
                display(&l);
                break;
            }
            case 6: {
                int pos;
                printf("\nEnter position of element to be deleted: ");
                scanf("%d", &pos);
                delete(&l, pos);
                display(&l);
                break;
            }
            case 7:
                display(&l);
                break;
            case 8:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid Choice...");
        }
    } while (ch != 8);

    return 0;
}
