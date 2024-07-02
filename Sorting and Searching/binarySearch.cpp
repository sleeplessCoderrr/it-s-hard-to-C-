#include<stdio.h>

int binarySearch(int arr[], int left, int right, int x){
    if(right >= left){
        int mid = left + (right - left) / 2;

        if(arr[mid] == x) return mid;
        else if(arr[mid] > x) return binarySearch(arr, left, mid-1, x);
        return binarySearch(arr, mid+1, right, x);
    }

    return -1;
}


int main(){

    int arr[] = {1,2,3,4,5,6,7};
    int arrLen = sizeof(arr)/sizeof(arr[0]);

    int temp = binarySearch(arr, 0, arrLen-1, 6);

    if(temp != -1){
        printf("Number found at index: %d", temp);
    } else printf("Number not found!");

    return 0;
}