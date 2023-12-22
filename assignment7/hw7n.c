// name: Yao Chen
// email: chen.yao2@northeastern.edu



// Hash table with doubly linked list for chaning/

#include <stdio.h>
#include <stdlib.h> 

struct bucket* hashTable = NULL; 
int BUCKET_SIZE = 10; 

// node struct
struct node {
    int key;
    int value;
    struct node* next;
    struct node* prev;
};

// bucket struct
struct bucket{
    int count;
    struct node* head;
};

// create a new node
struct node* createNode(int key, int value){
    struct node* newNode;   
    newNode = (struct node *) malloc (sizeof(struct node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

//  hash function with %
int hashFunction(int key){
    return key % BUCKET_SIZE;
}

//  insert a new key
void add(int key, int value){
    int hashIndex = hashFunction(key);
    struct node* newNode = createNode(key,value);
    struct node* temp = NULL;

    if(hashTable[hashIndex].count == 0){
        hashTable[hashIndex].count = 1;
        hashTable[hashIndex].head = newNode;
    } else {
        temp = hashTable[hashIndex].head;
        hashTable[hashIndex].head = newNode;
        newNode->next = temp;
        temp->prev = newNode;
    }
}

// remove a key
void remove_key(int key){
    int hashIndex = hashFunction(key);
    struct node* node;
    struct node* after;
    node = hashTable[hashIndex].head;

    if(node == NULL){
        printf("\ninvalid key");
        return;
    }
    while (node != NULL){
        if(node->key == key){
            if(node == hashTable[hashIndex].head){
                hashTable[hashIndex].head = node->next;
            } else {
                after = node->next;
                node->prev->next = after;
                after->prev = node->prev;
            }
            free(node);
            hashTable[hashIndex].count--;
            printf("\n removing [ %d ]  \n", key);
            return;
        }
        node = node->next;
    }
    printf("\ninvalid key");
    return;
}

// search a value using a key
void search(int key){
    int hashIndex = hashFunction(key);
    struct node* node = hashTable[hashIndex].head;

    if(node == NULL){
        printf("\ninvalid key \n");
        return;
    }
    while (node != NULL)
    {
        if (node->key == key){
            printf("\nkey = [ %d ], value = [ %d ].\n", node->key, node->value);
            return;
        }
        node = node->next;
    }
    printf("\ninvalid key \n");
    return;

}

void display(){
    struct node* iterator;

    printf("\n========= display start ========= \n");
    for (int i = 0; i<BUCKET_SIZE; i++){
        iterator = hashTable[i].head;
        printf("Bucket[%d] : ", i);
        while (iterator != NULL)
        {
            printf("(key: %d, val: %d)  <-> ", iterator->key, iterator->value);
            iterator = iterator->next;
        }
        printf("\n");
    }
    printf("\n========= display complete ========= \n");
}

int main(){
    hashTable = (struct bucket *)malloc(BUCKET_SIZE * sizeof(struct bucket));
    
    add(0, 1);
    add(1, 10);
    add(11, 12);
    add(21, 14);
    add(31, 16);
    add(5, 18);
    add(7, 19);

    display();

    remove_key(31);
    remove_key(11);

    display();

    search(11);
    search(1);
}