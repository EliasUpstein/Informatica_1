/*
 * threads_mutex_v1.c - compile with:
 *           gcc -o threads_m1 threads_mutex_v1.c -lpthread
 */

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[2];
int counter;

void *doSomeThing(void *arg) {
    unsigned long i = 0;
    counter += 1;
    printf("\n Job %d started\n", counter);

    for(i=0; i<1000; i++) {
        usleep(1000);
    };

    printf("\n Job %d finished\n", counter);

    return NULL;
}

int main(void) {
    int i = 0;
    int err;

    while(i < 2) {
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        i++;
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    return 0;
}