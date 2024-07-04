#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX 1000

void fillVector(int *vet) {
    for (int i = 0; i < MAX; i++)
        vet[i] = rand() % 1000 + 1;
}

void printVector(int *vet) {
    for (int i = 0; i < MAX; i++) 
        printf("%d ", vet[i]);
}

void bubbleSort(int *vet) {
    for (int i = 0; i < MAX-1; i++) {
        for (int j = i+1; j < MAX; j++) {
            if (vet[i] > vet[j]) {
                int temp = vet[j];
                vet[j] = vet[i];
                vet[i] = temp;
            }
        }
    }
}

void quickSort (int n, int *vet) {
    if (n <= 1) return;

    int x = vet[0], a = 1, b = n-1;
    do {
        while (a < n && vet[a] <= x) a++;
        while (vet[b] > x) b--;
        if (a < b) {
            int temp = vet[a];
            vet[a] = vet[b];
            vet[b] = temp;
            a++; b--;
        }
    } while (a <= b);

    vet[0] = vet[b];
    vet[b] = x;

    quickSort(b, vet);
    quickSort(n-a, &vet[a]);
}

int linearSearch(int *vet, int target) {
    for (int i = 0; i < MAX; i++) 
        if (vet[i] == target) return 1;

    return 0;
}

int binarySearch (int *vet, int target) {
    int low = vet[0], high = vet[MAX-1], mid = 0;

    while (low <= high) {
        mid = low + (high - low)/2;

        if (vet[mid] == target) return 1;
        if (vet[mid] < target) low = mid + 1;

        else high = mid - 1;
    }

    return 0;
}

int main () {
    int vet[MAX], request = -1;

    fillVector(vet);

    //bubbleSort(vet);
    quickSort(MAX, vet);

    //printVector(vet);

    if (linearSearch(vet, 0)) printf("Found\n");
    else printf("Not found\n");

    if (binarySearch(vet, 0)) printf("Found\n");
    else printf("Not found\n");


    return 0;
}