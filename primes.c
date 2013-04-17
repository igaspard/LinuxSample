#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void* compute_prime(void* arg)
{
    int num = *(int*) arg;
    int *prime = (int*) calloc(num, sizeof(int));
    int candidate = 4, i = 0;
    int factor, upper;
    bool bPrime;

    prime[i++] = 2; prime[i++] = 3;
    
    do {
        upper = sqrt(candidate);
        bPrime = true;
        for (factor = 2; factor <= upper; factor++) {
            if (candidate % factor == 0) {
                bPrime = false;
                break;            
            }
        }
        if (bPrime) {
            prime[i++] = candidate;
        }
        candidate++;
    } while (i < num);

    /*for (i = 0; i < num; i++) {
        printf("%d, ", prime[i]);
    }
    printf("\n");*/

    return (void*) prime[num-1];
}

int main(int argc, const char *argv[])
{
    pthread_t thread;
    int num_of_prime = 4000;
    int prime;

    pthread_create(&thread, NULL, &compute_prime, &num_of_prime);

    pthread_join(thread, (void*) &prime);

    printf("The %dth prime was %d\n", num_of_prime, prime);
    return 0;
}
