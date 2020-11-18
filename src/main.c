#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Allocation function
float* allocate(int size) {
    float* arr = malloc(size * sizeof(float));
    return arr;
}

// Copy input vector into dynamically alocated field
int copyInputToField(float* arr, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%f", &arr[i]);
    }
    return 0;
}
  
float sum_exponentials(float* arr, const int len) {  
    float sum = 0; 
    for (int i = 0; i < len; i++)  {
         sum += exp(arr[i]);
    }  
    return sum;  
} 

float* softmax(float* arr, const int len) {
    float softmax_denominator = sum_exponentials(arr, len);

    for (int i = 0; i < len; i++) {
        float computed_value = exp(arr[i]) / softmax_denominator;
        arr[i] = computed_value;
    }

    return arr;
}

int argmax(float* arr, const int len) {
    int index_max = 0;
    float max = arr[0];

    for(int i = 0; i < len; ++i){
        if(arr[i] > max){
            max = arr[i];
            index_max = i;
        }
    }
    return index_max;
}

int print_result(int current_argmax, float* current_softmax, const int len) {
    printf("%d", current_argmax);

    for (int i = 0; i < len; i++) {
        printf(" %.4f", current_softmax[i]);
    }

    printf("\n");

    return 0;
}

int main() {
    // Input vector size is given
    const int INPUT_VECTOR_SIZE = 10;

    int input_vectors_count = 1;
    scanf("%d\n", &input_vectors_count);

    float** pointers_array = (float**) malloc(input_vectors_count * sizeof(float*));

    for (int i = 0; i < input_vectors_count; i++) {
        pointers_array[i] = allocate(INPUT_VECTOR_SIZE);
        copyInputToField(pointers_array[i], INPUT_VECTOR_SIZE);

        float* current_softmax = softmax(pointers_array[i], INPUT_VECTOR_SIZE);
        int current_argmax = argmax(pointers_array[i], INPUT_VECTOR_SIZE);

        print_result(current_argmax, current_softmax, INPUT_VECTOR_SIZE);
        free(pointers_array[i]);
    }

    free(pointers_array);

    return 0;
}
