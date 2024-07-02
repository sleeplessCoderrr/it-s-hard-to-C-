#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void merge(int arr[], int left, int mid, int right){
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int leftArr[leftSize];
    int rightArr[rightSize];

    // Copy elements from arr to leftArr and rightArr
    for(int i = 0; i < leftSize; i++){
        leftArr[i] = arr[left + i];
    }

    for(int i = 0; i < rightSize; i++){
        rightArr[i] = arr[mid + 1 + i];
    }

    int leftCount = 0, rightCount = 0;
    int arrCount = left;

    while(leftCount < leftSize || rightCount < rightSize){
        if(leftCount < leftSize && (rightCount >= rightSize || leftArr[leftCount] <= rightArr[rightCount])){
            arr[arrCount] = leftArr[leftCount];
            leftCount++;
        }else {
            arr[arrCount] = rightArr[rightCount];
            rightCount++;
        }
        arrCount++;
    }

    while(leftCount < leftSize){
        arr[arrCount] = leftArr[leftCount];
        leftCount++;
        arrCount++;
    }

    while(rightCount < rightSize){
        arr[arrCount] = rightArr[rightCount];
        rightCount++;
        arrCount++;
    }

}

void mergeSort (int arr[], int left, int right){
    if(left < right){
        int mid = left + (right-left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        merge(arr, left, mid, right);
    }
}


void printArray(int arr[], int len){
    for(int i=0; i<len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main(){

    int arr[] = {1, 6, 7, 3, 9, 10, 56, 6, 8, 5, 3};
    int arrLen = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sorting: ");
    printArray(arr, arrLen);

    mergeSort(arr, 0, arrLen - 1);
    printf("After Sorting: ");
    printArray(arr, arrLen);

    return 0;
}