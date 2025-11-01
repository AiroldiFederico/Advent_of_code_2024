/*
 DAY 1 OF ADVENT OF CODE 2024

 GOAL: Read from a text file the content which contains two columns of numbers, each number is 5 digits long
 	   Grab the two numbers from both columns, sort the digits within each number in ascending order, substract digit by digit, sum the result
 	   Repeat the operation for all rows and sum the final results

*/


#include <stdio.h>


// Function takes an arrays of numbers and his length, then sort it the digit in ascending order 
void sort_arr(int *arr, int arrLength){
	
	int i, y;

	for(y = 0; y < arrLength; y++ ){
		for(i = 0; i < arrLength - 1; i++ ){

			int j;

			if (i == arrLength){
				j = arrLength;
			} else {
				j = i+1;	
			}
			
			if(arr[i]<arr[j]){
				continue;
			} else {
				int var_app1 = arr[i];
				int var_app2 = arr[j];
				arr[j] = var_app1;
				arr[i] = var_app2;
			}
		}
	}
}

int main(void)
{
	int arr1[1000];  // sx column
	int arr2[1000];  // dx column
	int total = 0;

	// 1. Open and read file content
	FILE *file = fopen("input.txt", "r");
	if (file == NULL) {
		printf("Errore apertura file\n");
		return 1;
	}
	

	// Inser values inside the array
	int i = 0;
	while(fscanf(file, "%d %d", &arr1[i], &arr2[i]) == 2) {
	    i++;
	}
	fclose(file);
	
	int arrLength = i;  
	
	printf("Letti %d numeri\n", arrLength);
	
	// 2. sorting
	sort_arr(arr1, arrLength);
	sort_arr(arr2, arrLength);
	
	// 3. sum results
	for(int k = 0; k < arrLength; k++){
	    int diff = arr1[k] - arr2[k];
	    if(diff < 0) {
	        diff = -diff;  // absolute value
	    }
	    total = total + diff;
	}
    printf("total distance: %d",total);
	
	return 0;
}