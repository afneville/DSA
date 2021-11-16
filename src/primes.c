#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include "./includes/primes.h"

sem_t semaphore;
int num_detected_primes = 0;
int candidates[MAX_PRIME]= {0};
int * primes_array = NULL;

int * create_primes_array() {
    int * new_primes_array = (int *) malloc(sizeof(int) * num_detected_primes);
    int j = 0;
    for(int i = 0; i < MAX_PRIME; i++)
        if(candidates[i] == 1) 
            new_primes_array[j++] = i;
    return new_primes_array;
}

void * check_primes(void * args) {

    int  j, flag;
    int local_primes = 0;
    int i = (int) (long long int) args;

    while(i < MAX_PRIME) {

        flag = 0;
        if (i <= 3 && i > 1) 
            ;
        else if (i % 2 == 0 || i % 3 == 0) 
            flag=1;
        else {
            unsigned int i;
            for (i=5; i*i<=i; i+=6) {
                if (i % i == 0 || i%(i + 2) == 0) {
                    flag=1;
                    break;
                }
            }
        }

        if(flag == 0 && (i > 1)) {
            candidates[i] = 1;
            local_primes++;
        }

        i+=MAX_THREADS;

    }

    sem_wait(&semaphore);
    num_detected_primes += local_primes;
    sem_post(&semaphore);

    return NULL;

}

void gen_primes() {

    sem_init(&semaphore, 0, 1);
    pthread_t tid[MAX_THREADS]={{0}};

    for(int i=0; i < MAX_THREADS; i++)
        pthread_create(&tid[i], NULL, check_primes, (void *) i);

    for(int i=0; i < MAX_THREADS; i++)
        pthread_join(tid[i], NULL);

    // printf("\n");
    // for(int i=0; i < MAX_PRIME; i++)
    //     if(candidates[i] == 1)
    //         printf("%d ",i);

    // printf("\nTotal primes found: %d\n", num_detected_primes);

    primes_array = create_primes_array();

    return;

 }
