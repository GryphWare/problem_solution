#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b);
int result(const int *arr, int size);

int main(){

  int size;
  scanf("%d", &size);

  int *num = malloc(size * sizeof(int));

  for(size_t i = 0; i < size; i++){
    scanf("%d", num + i);
  }

  qsort(num, size, sizeof(*num), compare);

  for(size_t i = 0; i < size; i++){
    printf("%d ", *(num + i));
  }

  int closest = result(num, size);
  printf("\n%d\n", num[closest]);

  free(num);
  
  return EXIT_SUCCESS;
}

int compare(const void *a, const void *b){
  int x = *(int*) a;
  int y = *(int*) b;
  return x - y;
}

//neu so  do nho hon so vua so sanh thi chon so do
// + neu so do co dang + thi nen chon

int result(const int *arr, int size){
  int index = 0;
  for(size_t i = 1; i < size; i++){
    int curr = abs(arr[i]);
    int best = abs(arr[index]);

    if(best > curr){
      index = i;
    } else if(best == curr && arr[i] > arr[index]){
      index = i;
    }
  }
  return index;
}
