#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#pragma warining(disable:4996)
int a[101];
int n=0;
void upHeap(int a[],int i){
    int tmp;
    if (i==1){
        return ;
    }
    if (a[i]<=a[i/2]){
        return ;
    }
    else {
        tmp=a[i/2];
        a[i/2]=a[i];
        a[i]=tmp;
    }
    upHeap(a,i/2);
}
void downHeap(int a[], int i){
    int left = 2 * i;
    int right = 2 * i + 1;
    int larger = i;

    // 왼쪽 자식이 존재하고 더 큰 경우
    if (left <= n && a[left] > a[larger]) {
        larger = left;
    }
    // 오른쪽 자식이 존재하고 더 큰 경우
    if (right <= n && a[right] > a[larger]) {
        larger = right;
    }
    
    // 만약 큰 자식과 교환해야 하는 경우
    if (larger != i) {
        int tmp = a[i];
        a[i] = a[larger];
        a[larger] = tmp;
        downHeap(a, larger);  // 재귀적으로 호출
    }
}
void insertItem(int k, int a[]){
    n++;
    int p=n;
    a[n]=k;
    upHeap(a,p);
}
int removeMin(int a[]){
    int i=1;
    int k=a[1];
    a[1]=a[n];
    n--;
    downHeap(a,i);
    return k;
}
void print(int a[]) //인쇄
{
	for (int i = 1; i <= n; i++)
		printf(" %d", a[i]);
	printf("\n");
}
int main(){
    char x;
    int y;
    while (1){
        scanf("%c",&x);
        if (x=='q')
            break;
        else if (x=='i'){
            scanf("%d",&y);
            getchar();
            insertItem(y, a);
            printf("0\n");
        }
        else if (x=='d'){
            printf("%d\n",removeMin(a));
        }
        else if (x=='p'){
            print(a);
        }

    }
    return 0;
}