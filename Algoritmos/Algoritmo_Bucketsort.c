#include <stdio.h>
#include <stdlib.h>

#define NVETOR 20
#define NBUCKET 7
#define INTERVAL 10

struct Bucket{
    int data;
    struct Bucket *next;
};

void BucketSort(int arr[]);
struct Bucket *BubbleSort(struct Bucket *list);
void print(int arr[]);
void printBuckets(struct Bucket *list);
int getBucketIndex(int value);

void BucketSort(int arr[]){
    int i, j;
    struct Bucket **buckets;

    buckets = (struct Bucket **)malloc(sizeof(struct Bucket *)* NBUCKET);

    for (i = 0; i < NBUCKET; ++i){
        buckets[i] = NULL;
    }

    for (i = 0; i < NVETOR; ++i){
        struct Bucket *current;
        int pos = getBucketIndex(arr[i]);

        current = (struct Bucket *)malloc(sizeof(struct Bucket));
        current->data = arr[i];
        current->next = buckets[pos];
        buckets[pos] = current;
    }

    printf("Baldes antes da ordenação\n");
    for (i = 0; i < NBUCKET; ++i){
        printf("Balde[%d]: ", i);
        printBuckets(buckets[i]);
        printf("\n");
    }

    for (i = 0; i < NBUCKET; ++i){
        buckets[i] = BubbleSort(buckets[i]);
    }

    printf("-------------\n");
    printf("Baldes após a ordenação\n");
    for (i = 0; i < NBUCKET; ++i){
        printf("Balde[%d]: ", i);
        printBuckets(buckets[i]);
        printf("\n");
    }

    for (j = 0, i = 0; i < NBUCKET; ++i){
        struct Bucket *bucket;
        bucket = buckets[i];
        while (bucket != NULL){
            arr[j++] = bucket->data;
            bucket = bucket->next;
        }
    }

    return;
}

struct Bucket *BubbleSort(struct Bucket *list){
    struct Bucket *k, *bucketList;
    int swapped;
    if (list == NULL || list->next == NULL){
        return list;
    }
    bucketList = list;
    
    do{
        swapped = 0;
        k = list;
        while (k->next != NULL){
            if (k->data > k->next->data){
                int temp = k->data;
                k->data = k->next->data;
                k->next->data = temp;
                swapped = 1;
            }
            k = k->next;
        }
    } while (swapped);
    return bucketList;
}

int getBucketIndex(int value){
    return value / INTERVAL;
}

void print(int ar[]){
    int i;
    for (i = 0; i < NVETOR; ++i){
        printf("%d ", ar[i]);
    }
    printf("\n");
}

void printBuckets(struct Bucket *list){
    struct Bucket *cur = list;
    while (cur){
        printf("%d ", cur->data);
        cur = cur->next;
    }
}

int main(){
    int vetor[NVETOR] = {29, 25, 3, 49, 9, 37, 21, 43, 35, 1, 15, 12, 19, 20, 55, 52, 67, 60, 50, 62};

    printf("Vetor antes da ordenação: \n");
    print(vetor);
    printf("-------------\n");
    BucketSort(vetor);
    printf("-------------\n");
    printf("Vetor após a ordenação: \n");
    print(vetor);
    return 0;
}
