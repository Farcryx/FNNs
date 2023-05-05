#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber(int max) {
//    srand(time(NULL));
    return (rand() % max) + 1;
}


int gen_num_if(int max) {
    int number = (rand() % max) + 1; // generate a random number between 1 and max
    if (number == 1) {
        return -1;
    }
    else {
        return 1;
    }
}


// Arrays multiply function
void matrix_multiply(int weights_array[2][3], int inputs_array[3], int result[2]) {
    result[0] = weights_array[0][0] * inputs_array[0] + weights_array[0][1] * inputs_array[1] + weights_array[0][2] * inputs_array[2];
    result[1] = weights_array[1][0] * inputs_array[0] + weights_array[1][1] * inputs_array[1] + weights_array[1][2] * inputs_array[2];
}


void multiply(int array_hid[3], int hid_weights[3], int result_out[1]) {
    result_out[0] = array_hid[0] * hid_weights[0] + array_hid[1] * hid_weights[1] + array_hid[2] * hid_weights[2];
}


int from_input_to_hidden(){
    int input_1 = generateRandomNumber(10000);
    int input_2 = generateRandomNumber(10000);
    int weight_11 = gen_num_if(2);
    int weight_21 = gen_num_if(2);
    int weight_12 = gen_num_if(2);
    int weight_22 = gen_num_if(2);
    int weight_h1 = gen_num_if(2);
    int weight_h2 = gen_num_if(2);
    int bias_1 = 1;
    int bias_w1 = gen_num_if(2);
    int bias_w2 = gen_num_if(2);
    int bias_w3 = gen_num_if(2);
    printf("Liczby pseudolosowe: \t %d \t %s \t %d \t %s \t %d \t %s \t %d \n %s \t %d \t %s \t %d", weight_11, " oraz ", weight_12, " oraz ", weight_21, " oraz ", weight_22, " Wejścia: ", input_1, " i ", input_2);
    int weights_array[2][3] = {{weight_11, weight_12, bias_w1}, {weight_21, weight_22, bias_w2}};
    int inputs_array[3] = {input_1, input_2, bias_1};
    int result[2];
    matrix_multiply(weights_array, inputs_array, result);
    printf("\n Result: [%d, %d]\n", result[0], result[1]);
    if (result[0] >= 0) {
        result[0] = 1;
    }
    else {
        result[0] = 0;
    }

    if (result[1] >= 0) {
        result[1] = 1;
    }
    else {
        result[1] = 0;
    }
    int array_hid[3] = {result[0], result[1], bias_1};
    int hid_weights[3] = {weight_h1, weight_h2, bias_w3};
    int result_out[1];
    multiply(array_hid, hid_weights, result_out);
    printf("\n Result out: [%d] \n", result_out[0]);
    return result_out[0];
}


//int max(
//        double d,
//        int result
//)


// Zrobić funkcję max:

int output(int result) {
    if (result % 2 == 0) {
        printf("Final number is even \n");
        int r = max(0.0, result);
        return r;
    }
    else {
        printf("Final number is odd \n");
        return 0;
    }
}


int main(){
    srand(time(NULL));  // seed the random number generator with current time
    int result = from_input_to_hidden();
    output(result);
}