// name: Yao Chen
// email: chen.yao2@northeastern.edu


// please start with a copy of your hw7.c, rename it to hw.8
// and then complete the assignment

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_STRING 200
#define HASH_SIZE 400

// finite state machine states
#define START_STATE 0
#define STATE_1 1
#define STATE_2 2
#define STATE_3 3
#define STATE_4 4
#define STATE_5 5
#define STATE_6 6
#define ACCEPT_STATE 10
#define ERROR_STATE 11

// check if a character c is a digit
bool isDigit(char c) {
  return (c >= '0' && c <= '9');
}

// append a character c to a string s
void appendChar(char* s, char c) {
  s[strlen(s)] = c;
  s[strlen(s) + 1] = '\0';
}

// finite state machine
int stateMachine(int inState, int nextChar, char* temp, char* inputLine, int* lineNum_p, int* popInt_p, char* cityStr) {
  int state = inState;

  switch (state) {
    case START_STATE:
      if (isDigit(inputLine[nextChar])) {
        state = STATE_1;
        appendChar(temp, inputLine[nextChar]);
      } else {
        state = ERROR_STATE;
      }  
      break;

    case STATE_1:
      if (isDigit(inputLine[nextChar])) {
        state = STATE_1;
        appendChar(temp, inputLine[nextChar]);
      } else if (inputLine[nextChar] == ',') {
        state = STATE_2;
        sscanf(temp, "%d", lineNum_p);
        temp[0] = '\0';
      } else {
        state = ERROR_STATE;
      } 
      break;
         
    case STATE_2:
      if (inputLine[nextChar] == '\"') {
        state = STATE_3;
      } else {
        state = ERROR_STATE;
      }
      break;
         
    case STATE_3:
      if (inputLine[nextChar] == '\"') {
        state = STATE_4;
        strcpy(cityStr, temp);
        temp[0] = '\0';
      } else {
        state = STATE_3;
        appendChar(temp, inputLine[nextChar]);
      }
      break;
         
    case STATE_4:
      if (inputLine[nextChar] == ',') {
        state = STATE_5;
      } else {
        state = ERROR_STATE;
      }
      break;
         
    case STATE_5:
      if (inputLine[nextChar] == '\"') {
        state = STATE_6;
      } else {
        state = ERROR_STATE;
      }
      break;
         
    case STATE_6:
      if (isDigit(inputLine[nextChar])) {
        state = STATE_6;
        appendChar(temp, inputLine[nextChar]);
      } else if (inputLine[nextChar] == ',') {
        state = STATE_6;
      } else if (inputLine[nextChar] == '\"') {
        state = ACCEPT_STATE;
        sscanf(temp, "%d", popInt_p);
      } else {
        state = ERROR_STATE;
      }
      break;
         
    case ACCEPT_STATE:
      break;
         
    default:
      state = ERROR_STATE;
      break;
  }
  return state;
}

// key-value pairs
typedef struct kv {
  char key[MAX_STRING];
  int value;
  struct kv* next;
} keyvalue_t;

keyvalue_t* newKeyValue(char* s, int i) {
  keyvalue_t* t = (keyvalue_t*) malloc(sizeof(keyvalue_t));
t->key = (char*) malloc(strlen(s) + 1);
strcpy(t->key, s);
t->value = i;
t->next = NULL;
return t;
}

// Function to add a new key-value pair to the hash table
void addKeyValue(hash_table_t* table, char* key, int value) {
int index = hashFunction(key, table->size);
keyvalue_t* curr = table->list[index];
keyvalue_t* prev = NULL;
while (curr != NULL && strcmp(curr->key, key) != 0) {
prev = curr;
curr = curr->next;
}
if (curr == NULL) {
keyvalue_t* t = newKeyValue(key, value);
if (prev == NULL) {
// Insert as first element in the linked list
table->list[index] = t;
} else {
prev->next = t;
}
} else {
// Update value of existing key
curr->value = value;
}
}

// Function to get the value associated with a given key
int getValue(hash_table_t* table, char* key) {
int index = hashFunction(key, table->size);
keyvalue_t* curr = table->list[index];
while (curr != NULL) {
if (strcmp(curr->key, key) == 0) {
return curr->value;
}
curr = curr->next;
}
// Key not found in hash table
return -1;
}

// Function to delete a key-value pair from the hash table
void deleteKeyValue(hash_table_t* table, char* key) {
int index = hashFunction(key, table->size);
keyvalue_t* curr = table->list[index];
keyvalue_t* prev = NULL;
while (curr != NULL && strcmp(curr->key, key) != 0) {
prev = curr;
curr = curr->next;
}
if (curr != NULL) {
if (prev == NULL) {
// Delete first element in the linked list
table->list[index] = curr->next;
} else {
prev->next = curr->next;
}
free(curr->key);
free(curr);
}
}