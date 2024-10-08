#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#pragma warining(disable:4996)
int H[101];
int n=0;
void inPlaceHeapsort();
void printArray();
void downHeap(int end, int i);
void insertItem(int i);
void upHeap(int i);
void rBuildHeap(int i);
void buildHeap();
int main(){
    int a;
    int x;
    scanf("%d",&x);
    for (int i=1;i<=x;i++){//1기 삽입식으로 최대힙 구현
        scanf("%d",&a);
        insertItem(a);
    }
    inPlaceHeapsort();
    printArray();
    return 0;
}
void insertItem(int i){
    n++;
    int p=n;
    H[n]=i;
    upHeap(p);
}
void upHeap(int i){
    int tmp;
    if (i==1){
        return ;
    }
    if (H[i]<=H[i/2]){
        return ;
    }
    else {
        tmp=H[i/2];
        H[i/2]=H[i];
        H[i]=tmp;
    }
    upHeap(i/2);
}
void downHeap(int end, int i) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int larger = i;

    // 왼쪽 자식이 존재하고 더 큰 경우
    if (left <= end && H[left] > H[larger]) {
        larger = left;
    }
    // 오른쪽 자식이 존재하고 더 큰 경우
    if (right <= end && H[right] > H[larger]) {
        larger = right;
    }

    // 만약 더 큰 자식과 교환해야 하는 경우
    if (larger != i) {
        int tmp = H[i];
        H[i] = H[larger];
        H[larger] = tmp;
        downHeap(end, larger);  // 재귀적으로 호출
    }
}
void inPlaceHeapsort(){
    int tmp;
	for (int i = n; i >= 2; i--){
		tmp = H[1];
		H[1] = H[i];
		H[i] = tmp; //swap
		downHeap(i-1, 1);
	}
}
/*void rBuildHeap(int i){
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
}*/
void printArray() //인쇄
{
	for (int i = 1; i <= n; i++)
		printf(" %d", H[i]);
	printf("\n");
}