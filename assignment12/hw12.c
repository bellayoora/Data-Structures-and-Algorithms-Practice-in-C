// name: Yao Chen
// email: chen.yao2@northeastern.edu
// Compile with:
//
// gcc -lpthread hw12.c -o hw12
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 100

// shared variable
int count = 0;
pthread_mutex_t lock;

// thread to be executed - unspecified variable arguments
void* thread1 (void* vargp) {
  // add 1 to count
    pthread_mutex_lock(&lock);
    count = count + 1;
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* thread2 (void* vargp) {
  // add 5 to count
    pthread_mutex_lock(&lock);
    count = count + 5;
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* thread3 (void* vargp) {
  // subtract 2 from count
    pthread_mutex_lock(&lock);
    count = count - 2;
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* thread4 (void* vargp) {
  // subtract 10 from count
    pthread_mutex_lock(&lock);
    count = count - 10;
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
  // array to keep Pthread IDs of created threads
  pthread_t tid[NTHREADS*4];
  int i;
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("failed operations\n");
        return 1;
    }

  printf("Count starts at %d\n", count);

  for (i = 0; i < NTHREADS; ++i){
    pthread_create(&(tid[i]), NULL, thread1, NULL);
      pthread_create(&(tid[i]), NULL, thread2, NULL);
      pthread_create(&(tid[i]), NULL, thread3, NULL);
      pthread_create(&(tid[i]), NULL, thread4, NULL);

  }

  for (i = 0; i < NTHREADS*4; ++i){
    pthread_join(tid[i], NULL);
  }

  pthread_mutex_destroy(&lock);
  printf("Count ends at %d\n", count);

  return 0;
}
