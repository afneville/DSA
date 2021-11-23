#ifndef primes_H
#define primes_H

// macros
// #define N 2147483647
#define MAX_PRIME 1000
#define MAX_THREADS 4

// globals
extern int num_detected_primes;
extern int * primes_array;
extern int candidates[MAX_PRIME];

// funcs
void * check_primes(void * args);
void gen_primes();
int * create_primes_array();

#endif // primes_H
