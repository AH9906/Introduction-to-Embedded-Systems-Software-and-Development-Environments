/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief The implementation file of the c1m1 assignment
 *
 * This file includes all the required functions implementations in the c1m1 assignment
 *
 * @author Arshiya Hashmi
 * @date 19/11/2023
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 434, 211, 100, 354,  608, 164,  22,  506,
                              14, 288,   345, 476, 123,  587,  625,  723,
                              20, 12, 350, 190,   292,  87, 177, 244,
                              201,   6,  152,  760,   808,   62,   5,  67,
                              777,  187, 50, 30,  999,   83, 110,  190};

  /* Other Variable Declarations Go Here */
  unsigned char min = 0;
  unsigned char max = 0;
  float mean = 0;
  unsigned char median = 0;

  /* Statistics and Printing Functions Go Here */
  printf("Non sorted array: \n");
  print_array(&test, SIZE);
  median = find_median(&test, SIZE);
  mean = find_mean(&test, SIZE);
  max = find_maximum(&test, SIZE);
  min = find_minimum(&test, SIZE);
  print_statistics(min, max, mean, median);
  sort_array(&test, SIZE);
  printf("Sorted array: \n");
  print_array(&test, SIZE);
}

void print_statistics (unsigned char min, unsigned char max, float mean, unsigned char median){
  printf("The minimum is %d \n", min);
  printf("The maximum is %d \n", max);
  printf("The mean is %f \n", mean);
  printf("The median is %d \n", median);
}


void print_array (unsigned char *array, unsigned int count){
  for (int i=0; i<count; i++){
    printf("%d,", *(array + i));
  }
  printf("\n");
}

unsigned char find_median (unsigned char *array, unsigned int count){
  unsigned char median = 0;
  median = *(array + (count / 2) -1);
  return median;
}

float find_mean (unsigned char *array, unsigned int count){
  unsigned int accumulator = 0; // variable to store the accumulator value throughout the mean finding process
  float mean = 0;
  for (int i=0; i<count; i++){
    accumulator = accumulator + array[i] /* *(array + i) */;
  }
  printf("acc = %d \n", accumulator);
  mean = accumulator / ((float) count); //must type cast one of the two integers to float for accurate calculation.
  return mean;
}

unsigned char find_maximum (unsigned char *array, unsigned int count){
  unsigned char maximum = *array; // initalize the maximum variable with the value of the first array element
  for (int i=1; i<count; i++){ // start the loop from the second elemnt
    if (*(array + i) > maximum){
      maximum = *(array + i);
    }
    else {} // do nothing.
  }
  return maximum;
}

unsigned char find_minimum (unsigned char *array, unsigned int count){
  unsigned char minimum = *array; // initalize the minimum variable with the value of the first array element
  for (int i=1; i<count; i++){ // start the loop from the second elemnt
    if (*(array + i) < minimum){
      minimum = *(array + i);
    }
    else {} // do nothing.
  }
  return minimum;
}

void sort_array (unsigned char *array, unsigned int count){
  char flag = 0; //this flag is to indicate if a swap process has occurred at least once in the loop
  unsigned char temp;
  do {
    flag =0; //set flag to default at every new 'do' operation
    for (int index=0; index<count; index++){
      if (array[index] > array[index +1] || array[index] == array[index +1]) {
        continue;
      }
      else if (array[index] < array[index +1]) {
        //swap elements//
        temp = array[index];
        array[index] = array[index+1];
        array[index+1] = temp;

        flag = 1; // a swap process has occurred at least once in this loop
      }
    }
  }
  while (flag ==1); // the array is not sorted as long as a swap operation is occurred at least once
}
