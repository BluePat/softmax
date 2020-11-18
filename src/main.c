#include <stdio.h>
#include <stdlib.h>

// Input vector size is given
int INPUT_VECTOR_SIZE = 10;

// Allocation function
int* allocate(int size) {
    int* input_arr = malloc(size * sizeof(int));
    return input_arr;
}

// Copy input vector into dynamically alocated field
int copyInputToField(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    return 0;
}

int main() {
    int input_vectors_count = 0;
    scanf("d", &input_vectors_count);

    int** pointers_array = (int*) malloc(input_vectors_count * sizeof(int*));

    for (int i = 0; i < input_vectors_count; i++) {
        pointers_array[i] = allocate(INPUT_VECTOR_SIZE);
        copyInputToField(pointers_array[i], INPUT_VECTOR_SIZE);
    }

    return 0;
}