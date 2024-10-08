#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#pragma warining(disable:4996)
void inPlaceInsertionSort(int *a,int n);
int main(){
	int n;
	scanf("%d",&n);
	int *a = malloc(sizeof(int)*n);
	for (int i =0 ;i<n;i++){
		scanf("%d",&a[i]);
	}
	inPlaceInsertionSort(a,n);
	for (int i =0 ;i<n;i++){
		printf(" %d",a[i]);
	}
	free(a);
	return 0;
}
void inPlaceInsertionSort(int *a,int n){
	int save,j;
	for (int i=1;i<n;i++){
		save=a[i];
		j=i-1;
		while((j>=0)&&(a[j]>save)){
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=save;
	}
}