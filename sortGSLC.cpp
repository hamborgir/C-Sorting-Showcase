#include <stdio.h>
#include <stdlib.h>

// prototyping
void printArr(int n, int arr[]);
void swap(int *a, int *b);
void selectionSort(int n, int arr[]);
void insertionSort(int n, int arr[]);
void bubbleSort(int n, int arr[]);
int menu();


// main
int main(){
	int arr[] = {32, 22, 12, 37, 42, 16, 31};
	int len = sizeof(arr)/sizeof(arr[0]);
	
	int choice = menu();
	
	if(choice == 0) exit(1);
	
	printf("Original array:\n");
	for(int i = 0; i<len; i++) printf("%d ", arr[i]);
	printf("\n\n");
	
	switch(choice){
		case 1:
			selectionSort(len, arr);
			break;
		case 2:
			insertionSort(len, arr);
			break;
		case 3:
			bubbleSort(len, arr);
			break;
	}
	
	printf("\nSorted array:\n");
	for(int i = 0; i<len; i++) printf("%d ", arr[i]);
	puts("");
}

// Utility Func.
void printArr(int n, int arr[]){
	printf("Sorting... : ");
	for(int i = 0; i<n; i++) printf("%d ", arr[i]);
	puts("");
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int menu(){
	puts("-------------Sorting Algorithm Showcase-----------\n");
	puts("1. Selection Sort");
	puts("2. Insertion Sort");
	puts("3. Bubble Sort");
	puts("0. Exit");
	puts("");
	
	int choice = 4;
	
	while(!(choice <= 3 && choice >= 0)){
		printf("Choose: ");
		scanf("%d", &choice);
	}
	puts("");
	return choice;
}

// Functions
void selectionSort(int n, int arr[]){
	for(int i=0; i<n-1; i++){
		int min = i;
		
		for(int j = i+1; j<n; j++){
			if(arr[j] > arr[min])
			min = j;
		}
		swap(&arr[i], &arr[min]);
		printArr(n, arr);
	}
}

void insertionSort(int n, int arr[]){
	for(int i=1; i<n; i++){
		int key = arr[i];
		int j = i-1;
		
		while(j>=0 && arr[j] < key){
			arr[j+1] = arr[j];
			j--;
		}			
		arr[j+1] = key;
		printArr(n, arr);
	}
}

void bubbleSort(int n, int arr[]){
	for(int i = 0; i<n-1; i++){
		int swapped = 0;
		
		for(int j = 0; j<n-i-1; j++){
			if(arr[j] < arr[j+1]){
				swap(&arr[j], &arr[j+1]);
				swapped = 1;
			}
		}
		
		if(swapped == 0) break;
		printArr(n, arr);
	}
}
