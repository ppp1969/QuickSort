# include <stdio.h>
# define MAX 9
//�� ������ �ٸ� ���Ŀ� ���� �ӵ��� ������ ������ �߰����� �޸� ������ �ʿ�� ���� �ʴ´�.
//��, ���ĵ� ����Ʈ�� ���ؼ��� �ұ��� ���ҿ� ���� �ð��� ���� �ɸ���. 
void QuickSort(int A[], int start, int end){
	int index;

	if(start<end){				//����Լ��� ���� list�� ū list ������ QuickSort����.
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
	int pivot = A[end];				//���� ������ ���� pivot���� ��´�.(������ ������ �ֵ� ���x)
	int i;
	int index = start;

	int temp;

	for(i=start; i<end; i++){		//pivot�� �������� ũ�� �ε��� ���� �����Եǰ� ������ i���� ����. �� ���� �ٰŷ� ��ȯ.
		if( A[i] <= pivot ){		//�� �ݺ����� ������ pivot���� ���� ���� ����,pivot,pivot���� ū ���� �������� �κ����� ��.
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
