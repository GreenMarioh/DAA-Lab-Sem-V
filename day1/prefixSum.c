#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main(){
	int n;
	printf("Enter the number of elements: \n");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the elements: \n");
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	int prefixSum[n];
	prefixSum[0] = arr[0];
	for(int i = 1; i < n; i++){
		prefixSum[i]=prefixSum[i-1]+arr[i];
	}
	printf("The output array is: \n");
	for(int i = 0; i < n; i++){
		printf("%d ", prefixSum[i]);
	}
	
	
	
return 0;
}
