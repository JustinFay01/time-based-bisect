#define SIZE 131072
#include <stdlib.h>
#include <time.h>

int values[SIZE];

int cmp(const void* a, const void* b) {
    const int* A = a;
    const int* B = b;

    return (*A > *B) - (*A < *B);
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        values[i] = rand();
    }

    qsort(values, SIZE, sizeof(int), cmp);
}
