#include<stdio.h>
#include<stdlib.h>

int arr[100];
int idx = 0;

int getParent(int idx){
    return (idx)/2;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int number){
    idx++;
    arr[idx] = number;
    
    int currIndex = idx;
    while(arr[currIndex] > arr[getParent(currIndex)] && currIndex > 1){
    	swap(&arr[currIndex], &arr[getParent(currIndex)]);
    	currIndex = getParent(currIndex);
	}
}


void heapify(int pos){
	int largest = pos;
    int left = 2*pos;
    int right = 2*pos + 1;

    if(left <= idx && arr[left] > arr[largest]){
        largest = left;
    }
    
    if(right <= idx && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != pos){
        swap(&arr[pos], &arr[largest]);
        heapify(largest);
    }
}


void pop(){
	int max = arr[1];
	arr[1] = arr[idx];
	idx--;

    heapify(1);
}


void viewData(){
    for(int i=1; i<=idx; i++){
        printf("%d ", arr[i]);
    }
}


int main(){
    insert(10);
    insert(20);
    insert(40);
    insert(50);
    
    pop();
    pop();

    viewData();

    return 0;
}
