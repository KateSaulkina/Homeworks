#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#define N 1000000

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;

}

void countingSort(int *arr, size_t k) {
    unsigned int* value;
    value = (unsigned int*)malloc(N * sizeof(unsigned int));
    if (value == NULL) {
        printf("ERROR");
        exit(1);
    }
    for (size_t i = 0; i < N; i++)
    {
        value[i] = 0;
    }
    for (size_t i = 0; i < k; i++) {
        value[arr[i]] += 1;
    }
    int index = 0;
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < value[i]; j++) {
            arr[index] = i;
            index++;
        }
    }
    free(value);
}

void bubbleSort(int *arr, size_t k) {
    for (size_t i = 0; i < (k - 1); i++) {
        for (size_t j = 0; j < (k - 1 - i); j++) {
            if (arr[j + 1] < arr[j]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void quickSortL(int *arr, size_t l, size_t r){
    if (l == r || l == (r - 1))
		return;
	size_t med = (r - l) / 2 + l;
	swap(&arr[l], &arr[med]);
	size_t k = l + 1, t = 0;
	while (k < (r - t)) {
		if (arr[k] > arr[k - 1]) {
            t++;
			swap (&arr[k], &arr[r - t]);
		} else {
			swap (&arr[k], &arr[k - 1]);
			k++;
		}
	}
	quickSortL(arr, l, k - 1);
	quickSortL(arr, k, r);

}

void quickSort(int *arr, size_t k) {
    quickSortL(arr, 0, k);
}

void random(int *arr, size_t k) {
	srand(5000);
	for (size_t i = 0; i < k; i++){
		arr[i] = rand() % N;
	}
}

void times(int *arr, size_t k, void (*f)(int*, size_t)) {
    clock_t begin, end;
    begin = clock();
    f(arr, k);
    end = clock();
    printf("Size: %d\n Time: %f\n", k, (float)(end - begin) / CLOCKS_PER_SEC);
}

int main()
{
    size_t number[] = {5, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
    int *el = (int*)malloc(100000000 * sizeof(int));
        if (el == 0) {
            printf("ERROR");
            exit(1);
        }
    void (*sorts[])(int *, size_t) = {&countingSort, &quickSort, &bubbleSort};
	char *name[]= {"countingSort", "quickSort", "bubbleSort"};
	clock_t begin;
	clock_t end;
	size_t kSorts = sizeof(sorts) / sizeof(sorts[0]);
	size_t kNum = sizeof(number) / sizeof(number[0]);
	for (size_t i = 0; i < kSorts; i++) {
        printf("%s\n", name[i]);
        for (size_t j = 0; j < kNum; j++) {
            random(el, number[j]);
            begin = clock();
            sorts[i](el, number[j]);
            end = clock();
            printf("Size: %d\nTime: %f\n", number[j], (float)(end - begin) / CLOCKS_PER_SEC);
        }
	}


    return 0;
}
