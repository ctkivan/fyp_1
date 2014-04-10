#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>


unsigned NUM_THREADS = 1;
unsigned global_count = 0;
void *thread(void *);

int main(int argc, char *argv[]) {
  long i;
  pthread_t pthread_id[200];
  NUM_THREADS = atoi(argv[1]);

  for(i = 0; i < NUM_THREADS; i++)
    pthread_create(&pthread_id[i], NULL, thread, (void *) i);
  for(i = 0; i < NUM_THREADS; i++)
    pthread_join(pthread_id[i], NULL);

  assert(global_count==NUM_THREADS);
  return 0;
}

void *thread(void * num) {
  unsigned temp = global_count;
  temp++;
  global_count = temp;
  return NULL;
}
