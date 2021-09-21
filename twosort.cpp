////πÈ≤¢≈≈–Ú∏¥œ∞ 
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//void Merge(int num[],int low,int mid,int high) {
//		int i = low, j = mid + 1,k = 0;
//		int* help = (int*)malloc(sizeof(int) * (high - low + 1));
//		while(i <= mid && j <= high) {
//			if (num[i] < num[j]) {
//				help[k++] = num[i++];
//			}
//			if (num[j] < num[i]) {
//				help[k++] = num[j++];
//			}
//		}
//		while(i <= mid) {
//			help[k++] = num[i++];
//		}
//		while(j <= high) {
//			help[k++] = num[j++];
//		}
//		for(i=low,k=0; i <= high; i++) {
//			num[i] = help[k++];
//		}
//		free(help);
//	}
//
//void MergeSort(int num[],int left,int right) {
//	if (left < right) {
//		int mid = (left + right) / 2;
//		MergeSort(num,left,mid);
//		MergeSort(num,mid+1,right);
//		Merge(num,left,mid,right);
//	}	
//}
//
//int main()
//{
//	int num[10], i;
//	memset(num,-1,10);
//	for(i=0; i < 10; i++) {
//		scanf("%d",&num[i]);
//	}
//	MergeSort(num,0,10);
//	for(i = 0; i < 10; i++) {
//		printf("%9d",num[i]);
//	}
//	return 0;
//}

//øÏ≈≈ 
#include<stdio.h>
#include<string.h>
void swap(int &num1,int &num2) {
//	num1 = num1 ^ num2;
//	num2 = num1 ^ num2;
//	num1 = num1 ^ num2;
	int t;
	t = num1;
	num1 = num2;
	num2 = t;
}

int Partition(int num[],int low,int high) {
	int i = low,j = high,min = num[low];
	while(i < j) {
		while(i < j && num[j] > min) {
			j--;
		}
		if (i < j) {
			//swap(num[i++],num[j]);
			swap(num[j],num[i++]);
		}
		while(i < j && num[i] <= min) {
			i++;
		}
		if (i < j) {
			//swap(num[j--],num[i]);
			swap(num[i],num[j--]);
		}
	}
	return i;
}

void QuickSort(int num[],int low,int high) {
	if (low < high) {
		int mid = Partition(num,low,high);
		QuickSort(num,low,mid-1);
		QuickSort(num,mid+1,high);
	}
}

int main()
{
	int num[10],i;
	for(i = 0; i < 10; i++) {
		scanf("%d",&num[i]);
	}	
	QuickSort(num,0,9);
	for(i = 0; i < 10; i++) {
		printf("%4d",num[i]);
	}
	return 0;
}







 

