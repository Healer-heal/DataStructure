#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Merge(int num[],int low,int high) {
	int  i = low, mid = (low + high) / 2, j = mid+1, k = 0;
	int* help = (int*)malloc(sizeof(int) * (high - low + 1));
	while(i <= mid && j <= high) {
		if ( num[i] < num[j] ) {
			help[k++] = num[i++];
		}
		if (num[j] < num[i]) {
			help[k++] = num[j++];
		}
	}
	while(i <= mid) {
		help[k++] = num[i++];
	}
	while(j <= high) {
		help[k++] = num[j++];
	}
	for(i = low,k=0; i <= high; i++) {
		num[i] = help[k++];
	}
	free(help);
}

void MergeSort(int num[],int left,int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		MergeSort(num,left,mid);
		MergeSort(num,mid+1,right);
		Merge(num,left,right);
	}	
}

int main()
{
	int num[10],i=0;
	//memset(num,0,10);
	for(i=0;i<10;i++) {
		scanf("%d",&num[i]);
	}
	MergeSort(num,0,9);
	for(i=0;i<10;i++) {
		printf("%6d",num[i]);
	}
	
	return 0;
}
