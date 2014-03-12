#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5

int x;

void *mah_thread(void *args) {
  ++x;
  printf("x is %i now\n", x);
  return NULL;
}

main() {
  pthread_t threads[NUM_THREADS];
  int i;

  // create all threads one by one
  for (i = 0; i < NUM_THREADS; ++i) {
    pthread_create(&threads[i], NULL, mah_thread, NULL);
  }

  // wait for each thread to complete
  for (i = 0; i < NUM_THREADS; ++i) {
    // block until thread i completes
    pthread_join(threads[i], NULL);
  }

  printf("final x is %i\n", x);
  exit(EXIT_SUCCESS);
}
