#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Merg(int a[],int low,int mid,int high) {
	int* help = (int*)malloc(sizeof(int) * (high - low + 1) );
	int i=low,j=mid+1,k=0;
	while(i <= mid && j <= high ) {
		if (a[i] < a[j]) {
			help[k++] = a[i++];
		}
		if ( a[j] < a[i]) {
			help[k++] = a[i++];
		}
	}
	while(i <= mid) {
		help[k++] = a[i++];
	}
	while(j <= high) {
		help[k++] = a[j++];
	}
	for(i=low,k=0;i<=high;i++) {
		a[i] = help[k];
	}
	free(help);
}

void MergeSort(int a[],int left,int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		MergeSort(a,left,mid);
		MergeSort(a,mid+1,right);
		Merg(a,left,mid,right);
	}	
	
}

int main()
{
	int a[10],i;
	for(i=0;i<10;i++) {
		scanf("%d",&a[i]);
	}
	MergeSort(a,0,9);
	
	
	return 0;
}
