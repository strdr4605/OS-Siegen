#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *funct_printMessage(void *threadIndex);
const int threadsAmount = 2;
const int messagesPerThread = 10;

int main() {
    pthread_t threads[threadsAmount];

    for(int i = 0; i < threadsAmount; ++i) {
        int *threadIndex = malloc(sizeof(int));
        if(threadIndex == NULL) {
            fprintf(stderr, "Couldn't allocate memory for thread arg.\n");
            return 1;
        }
        *threadIndex = i;
        if(pthread_create(threads + i, NULL, funct_printMessage, (void *)(threadIndex))) {
            fprintf(stderr, "Error creating thread %d.\n", i);
            return 2;
        }
    }

    for(int i = 0; i < threadsAmount; ++i) {
        if(pthread_join(threads[i], NULL)) {
            fprintf(stderr, "Error joining thread %d.\n", i);
            return 3;
        }
    }
    
    return 0;
}

void *funct_printMessage(void *threadIndex) {
    const char *message = "This is thread %d.\n";
    for(int i = 0; i < messagesPerThread; ++i) {
        fprintf(stdout, message,*(int *)threadIndex);
    }
    free(threadIndex);
    return NULL;
}
