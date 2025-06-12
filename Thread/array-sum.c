
//sum of an array using two thread with dynamically allocated size
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
typedef struct {
    int *arr;
    int start;
    int end;
} ThreadData;
void *sum_array(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int *sum = (int *)malloc(sizeof(int));
    *sum = 0;
    for (int i = data->start; i < data->end; i++) {
        *sum += data->arr[i];
    }
    pthread_exit((void *)sum);
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

    // Divide the array into two parts
    ThreadData td1 = {arr, 0, n / 2};
    ThreadData td2 = {arr, n / 2, n};

    pthread_t t1, t2;
    void *res1, *res2;

    pthread_create(&t1, NULL, sum_array, &td1);
    pthread_create(&t2, NULL, sum_array, &td2);

    pthread_join(t1, &res1);
    pthread_join(t2, &res2);

    int total_sum = *((int *)res1) + *((int *)res2);
    printf("Total Sum = %d\n", total_sum);

    
    free(arr);
    free(res1);
    free(res2);

    return 0;
}
