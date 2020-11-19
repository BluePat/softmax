#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/** Allocation function */
float* allocate(int size) {
    float* arr = malloc(size * sizeof(float));
    return arr;
}

/** Copy input vector into dynamically alocated field */
int copyInputToField(float* arr, int size) {

    for (int i = 0; i < size; i++) {
        scanf("%f", &arr[i]);
    }

    return 0;
}

/** Softmax function transforms input vector into a vector of probability distribution.
 * 
 * Generalization of logistic function to multiple dimensions.
 * For given input vector of given length `len`, calculates probability distribution
 * of `len` possible outcomes.
 * 
 * @param arr   A pointer to an input vector (array of floats).
 * @param len   A length of input vector
 */
float* softmax(float* arr, const int len) {
    float softmax_denominator = 0;

    for (int i = 0; i < len; i++)  {
         softmax_denominator += exp(arr[i]);
    }  

    for (int i = 0; i < len; i++) {
        float computed_value = exp(arr[i]) / softmax_denominator;
        arr[i] = computed_value;
    }

    return 0;
}

/** Argmax function returns and index of an element with the largest likelihood,
 * according to probability distribution vector calculated by softmax.
 * 
 * @param arr   A pointer to a probability distribution vector (array of floats).
 * @param len   A length of a probability distribution vector.
 * 
 * @returns Index of the element with the largest likelihood.
 */
int argmax(float* arr, const int len) {
    int index_max = 0;
    float max = arr[0];

    for(int i = 0; i < len; ++i){
        if (arr[i] > max) {
            max = arr[i];
            index_max = i;
        }
    }

    return index_max;
}

/** Prints output into STDOUT in defined format */
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

    float* arr_pointer = allocate(INPUT_VECTOR_SIZE);

    for (int i = 0; i < input_vectors_count; i++) {
        copyInputToField(arr_pointer, INPUT_VECTOR_SIZE);

        softmax(arr_pointer, INPUT_VECTOR_SIZE);
        int current_argmax = argmax(arr_pointer, INPUT_VECTOR_SIZE);

        print_result(current_argmax, arr_pointer, INPUT_VECTOR_SIZE);
    }

    free(arr_pointer);
    return 0;
}
