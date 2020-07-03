# include <stdio.h>
# define MAX 9
//퀵 정렬은 다른 정렬에 비해 속도가 빠르고 별도로 추가적인 메모리 공간을 필요로 하지 않는다.
//단, 정렬된 리스트에 한해서는 불균형 분할에 의해 시간이 많이 걸린다. 
void QuickSort(int A[], int start, int end){
	int index;

	if(start<end){				//재귀함수로 작은 list와 큰 list 각각에 QuickSort실행.
		index = Partition(A,start,end);
		for(int i=0; i<MAX; i++){
  		  	printf("%d ", A[i]);
		}
		printf("\n");
		QuickSort(A,start,index-1);
		QuickSort(A,index+1,end);
	}
	else{
		return ;				
	}
}

int Partition(int A[],int start, int end){
	int pivot = A[end];				//가장 오른쪽 값을 pivot으로 삼는다.(임의의 값으로 둬도 상관x)
	int i;
	int index = start;

	int temp;

	for(i=start; i<end; i++){		//pivot을 기준으로 크면 인덱스 값을 가지게되고 작으면 i값을 가짐. 이 값을 근거로 교환.
		if( A[i] <= pivot ){		//이 반복문이 끝나면 pivot보다 작은 값의 집합,pivot,pivot보다 큰 값의 집합으로 부분정렬 됨.
			printf("SWAP (%d)<->(%d)\n",A[index],A[i]);
			temp = A[i];
			A[i] = A[index];
			A[index] = temp;
			index++;
		}
	}
	printf("SWAP (%d)<->(%d)\n",A[index],A[end]);
	temp = A[index];
	A[index] = A[end];
	A[end] = temp;

	return index;
}


void main(){
    int i;
    int A[MAX] = {7, 3, 8, 4, 9, 1, 6, 2, 5};
	printf("Before: \n");
	for(i=0; i<MAX; i++){
    printf("%d ", A[i]);
}
	printf("\n");
    QuickSort(A, 0, MAX-1);

}
