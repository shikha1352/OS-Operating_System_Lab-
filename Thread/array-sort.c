#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int *arr;
    int start;
    int end;
} ThreadData;

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void *sum_array(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int len = data->end - data->start;
    int *sorted =(int *)malloc(len * sizeof(int));
    if (!sorted) {
        perror("malloc failed");
        pthread_exit(NULL);
    }

    for (int i = 0; i < len; i++) {
        sorted[i] = data->arr[data->start + i];
    }

    qsort(sorted, len, sizeof(int), compare);
    pthread_exit((void *)sorted);  
}

int *merge(int *arr1, int len1, int *arr2, int len2) {
    int *sorted = (int *)malloc((len1 + len2) * sizeof(int));
    if (!sorted) {
        perror("merge failed");
        return NULL;
    }

    int i = 0, j = 0, k = 0;
    while (i < len1 && j < len2) {
        if (arr1[i] < arr2[j]) {
            sorted[k++] = arr1[i++];
        } else {
            sorted[k++] = arr2[j++];
        }
    }
    while (i < len1) {
        sorted[k++] = arr1[i++];
    }
    while (j < len2) {
        sorted[k++] = arr2[j++];
    }

    return sorted;
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        perror("malloc failed");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    ThreadData td1 = {arr, 0, n / 2};
    ThreadData td2 = {arr, n / 2, n};

    pthread_t t1, t2;
    int *sorted1 = NULL;
    int *sorted2 = NULL;

    pthread_create(&t1, NULL, sum_array, &td1);
    pthread_create(&t2, NULL, sum_array, &td2);

    pthread_join(t1, (void **)&sorted1);
    pthread_join(t2, (void **)&sorted2);

    int len1 = td1.end - td1.start;
    int len2 = td2.end - td2.start;

    int *merged = merge(sorted1, len1, sorted2, len2);
    if (!merged) {
        perror("merge failed");
        free(arr);
        free(sorted1);
        free(sorted2);
        return 1;
    }

    printf("The sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    free(arr);
    free(sorted1);
    free(sorted2);
    free(merged);

    return 0;
}
