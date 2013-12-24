#include <iostream>
using namespace std;

// compare pair and swap, use echange flag to avoid unnecessary scan
// O(n^2)
void bubble_sort(int arr[], int size)
{
	int exchange = size - 1;
	while(exchange){
		int bound = exchange;
		exchange = 0;
		for(int i=0; i<bound; i++){
			if(arr[i]>arr[i+1]){
				int tmp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = arr[i];
				exchange = i;
			}
		}
	}
}

// scan and find minimal value, swap it to beginning, and then scan from the next
void selection_sort(int arr[], int size)
{
	for(int i=0; i<size-1; i++){
		int min=i;
		for(int j=i; j<size; j++){
			if(arr[min]>arr[j])
				min=j;
		}
		
		if(min!=i){
			int tmp=arr[min];
			arr[min]=arr[i];
			arr[i]=tmp;
		}
	}
}

// quick sort, divide a array to sub array and do recursive sorting
void swap(int *a, int *b)
{
    int tmp;
    tmp = *a; *a = *b; *b = tmp;
}

//
void quick_sort(int a[], int left, int right)
{
    int i = left + 1, j = right;
    int  key = a[left];
 
    if (left >= right) return; 
    /* 从i++和j--两个方向搜索不满足条件的值并交换  *
     * 条件为：i++方向小于key，j--方向大于key      */
    while (1) {
       while (a[j] > key) j--;
       while (a[i] < key&&i<j) i++;
       if(i >= j) break;
       swap(&a[i],&a[j]);
       if(a[i]==key)j--;
       else  i++;
    }
 
    /* 关键数据放到‘中间’ */
    swap(&a[left],&a[j]);
 
    if(left  < i - 1)   quick_sort(a, left, i - 1);
    if(j + 1 < right)  quick_sort(a, j + 1 , right); 
}

int a[15] = { 1, 2, 8, 7, 9, 5, 6, 4, 3, 66, 77, 33, 22, 11, 2};
int main(int argc, char** argv) {
 	quick_sort(a, 0, 14); // quick_sort(array, left, right)
	return 0;
}