#include <stdio.h>

void show(int *arr, int len);
void double_arr(int *arr, int len);
void print_2d_arr(int a[2][3]);

int main() {
  /* Easy Example */
  float f[4]; // declare an array of 4 floats

  f[0] = 1.1;
  f[1] = 2.2;
  f[2] = 3.3;
  f[3] = 4.4;

  for (int i = 0; i < 4; i++) {
    printf("%f\n", f[i]);
  }

  /* Getting the Length of an Array */
  int x[12];
  int len = sizeof x / sizeof(int);
  
  printf("Size of x array: %d\n", len);

  /* Array Initializers */
  int a[5] = {1, 2, 3, 4, 5}; // Initialize array with these values
  int a_len = sizeof a / sizeof(int);

  for (int i = 0; i < a_len; i++) {
    printf("%d\n", a[i]);
  }

  int z[100] = {0}; // Initialize array with 100 zeroes
  
  // Specifying an index for the value
  int wtf[10] = {1, 1, [5]=1, 0, 1}; // 1 1 0 0 0 1 0 1 0 0

  // Compute the size of the array from the initializer
  int _a[3] = {1, 2, 3};
  
  // same:

  int __a[] = {1, 2, 3};

  /* Multidimensional Arrays */
  int two_d[2][2];

  // or
 
  int dd[2][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8}
  };

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++) {
      printf("(%d, %d) = %d\n", i, j, dd[i][j]);
    }
  }
  
  // Make a 3x3 matrix
  int matrix[3][3] = {[0][0]=1, [1][1]=1, [2][2]=1};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  /* Arrays and Pointers */
  int ar[5] = {11, 22, 33, 44, 55}; 
  int *p;

  p = &ar[0]; // pointer for the first elem 

  printf("%d\n", *p); // 11

  /* 
  p = &ar[0];

  --same--

  p = ar;
  */

  // Passing Single Dimensional Arrays to Functions
  int try_[5] = {11, 22, 33, 44, 55};
  show(try_, 5);

  // Changing Arrays in Functions 
  int try_double[5] = {1, 2, 3, 4, 5};

  double_arr(try_double, 5);
  
  for (int i = 0; i < 5; i++) {
    printf("%d\n", try_double[i]);
  }

  // Passing Multidimensional Arrays to Functions
  int mm [2][3] = {
    {1, 2, 3},
    {4, 5, 6}
  };

  print_2d_arr(mm);
  
  return 0;
}

void show(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    printf("%d\n", arr[i]);
  }
}

void double_arr(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    arr[i] *= 2;
  }
}

void print_2d_arr(int a[2][3]) { // or int[][3]
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", a[i][j]);
    }
  }
}

