#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* Say(void* blah){
  printf("Hello! I am a thread!\n");
  return 0;
}


int main(){
  int threads = 4;
  pthread_t* handlers = malloc(threads * sizeof(pthread_t));
  int i = 0;
  for (i = 0; i<threads; i++){
    pthread_create(&handlers[i], NULL, Say, NULL);
  }
  //waiting!
  for (i =0; i<threads; i++){
    pthread_join(handlers[i], NULL);
  }
  free(handlers);
}
