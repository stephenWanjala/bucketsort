#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char* string;
    struct node* next;
} node;

typedef struct bucket {
    char* min_word;
    node* head;
} bucket;

node* createNode(char* str) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->string = strdup(str);
    newNode->next = NULL;
    return newNode;
}

void insertNode(node** head, char* str) {
    node* newNode = createNode(str);
    node* temp = *head;
    if(*head == NULL || strcasecmp((*head)->string, str) > 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        while(temp->next != NULL && strcasecmp(temp->next->string, str) < 0) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void printBucket(bucket* buckets, int size) {
    for(int i = 0; i < size; i++) {
        printf("bucket %d: ", i);
        node* head = buckets[i].head;
        while(head != NULL) {
            printf("%s ", head->string);
            head = head->next;
        }
        printf("\n");
    }
}
char* removePunctuation(char* word) {
    int len = strlen(word);
    if (ispunct(word[len - 1])) {
        word[len - 1] = '\0';
    }
    return word;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Fatal error! There must be at-least one CLA.\n");
        return 1;
    }

    bucket* buckets = (bucket*)malloc(sizeof(bucket) * argc);
    for(int i = 0; i < argc; i++) {
        buckets[i].min_word = argv[i];
        buckets[i].head = NULL;
    }

    char word[100];
    while(scanf("%s", word) != EOF) {
        for(int i = 0; i < argc; i++) {
            if(i == argc - 1 || strcasecmp(word, buckets[i+1].min_word) < 0) {
               insertNode(&(buckets[i].head), removePunctuation(word));
                break;
            }
        }
    }

    printBucket(buckets, argc);

    return 0;
}