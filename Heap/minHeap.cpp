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
    while(arr[currIndex] < arr[getParent(currIndex)] && currIndex > 1){
    	swap(&arr[currIndex], &arr[getParent(currIndex)]);
    	currIndex = getParent(currIndex);
	}
}


void heapify(int pos){
	int smallest = pos;
    int left = 2*pos;
    int right = 2*pos + 1;

    if(left <= idx && arr[left] < arr[smallest]){
        smallest = left;
    }
    
    if(right <= idx && arr[right] < arr[smallest]){
        smallest = right;
    }

    if(smallest != pos){
        swap(&arr[pos], &arr[smallest]);
        heapify(smallest);
    }
}


void pop(){
	int min = arr[1];
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
    
    viewData();
    puts("");
    pop();
    viewData();
    puts("");
    insert(5);
    insert(60);
    viewData();
    puts("");



    return 0;
}
