#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#pragma warining(disable:4996)
int a[101];
int n=0;
void rBuildHeap(int i);
void buildHeap();
void downHeap(int i);
void print(int a[]); //인쇄
int main(){
    scanf("%d",&n);
    for (int i=1;i<n+1;i++){
        scanf("%d",&a[i]);
    }
    //rBuildHeap(1);
    buildHeap();
    print(a);
    return 0;
}
void rBuildHeap(int i){
    if (i>n)
        return;
    rBuildHeap(2*i);
    rBuildHeap(2*i+1);
    downHeap(i);
    return rBuildHeap(2*i);
}
void buildHeap(){
    for (int i=n/2;i==1;i--){
        downHeap(i);
    }
    return;
}
void downHeap(int i){
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
        downHeap(larger);  // 재귀적으로 호출
    }
}
void print(int a[]) //인쇄
{
	for (int i = 1; i <= n; i++)
		printf(" %d", a[i]);
	printf("\n");
}