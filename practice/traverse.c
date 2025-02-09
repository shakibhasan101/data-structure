#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

void Traverse (int A[], int s) {
    for (int i = 0; i < s; i++)
        printf ("%d ", A[i]);
    printf ("\n");
}

int main () {
    int A[SIZE];

    A[2] = 10;
    printf ("%d \n", A[2] + 5);
    printf("%d\n",sizeof(A));

    Traverse (A, sizeof (A) / sizeof (int));

    return 0;
}

