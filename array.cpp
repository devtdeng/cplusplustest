#include <iostream>
using namespace std;


// 5. search 
// 10. reverse words
// 12. 1+2+…+n without loop
// 11. find max distance between 2 nodes, add 2 more fields to the node.
// 18. remove m th from n array, retur last one
// 20. change "345" to 345;
// 21. 输入两个整数 n 和 m，从数列1，2，3.......n 中 随意取几个数, 使其和等于 m ,要求将其中所有的可能组合列出来.
// 25. 在字符串中找出连续最长的数字串，并把这个串的长度返回，
// 26. 左旋转字符串
// 30. 在从1到n的正数中1出现的次数


// Array templated
template<class T>
class Array {
	enum { size = 100 };
	T A[size];
public:
	T& operator[](int index);
};

template<class T>
   T& Array<T>::operator[](int index) {
     assert(index >= 0 && index < size);
     return A[index];
   }

// suppose it is ASCII string
bool isuniquestr(char* str)
{	
	if(str==NULL) return true;
	
	int i=0;
	
	// can also use bit vector here to save space
	bool charset[256]={0}; 
	
	while(str[i]){
		if(charset[str[i]]) return false;
		charset[str[i]] = true;
		i++;
	}
	return true;
}


// string length unknown
void reverse(char* str)
{
	if(str){
		char* end=str;
		char tmp;
		
		while(*end){
			end++;
		}
		--end;
		
		while(str<end){
			tmp=*str;
			*str++=*end;
			*end--=tmp;
		}
	}
}

void removedups(char* str)
{
	if(str){
		// check length
		int i=0, length=0;
		while(str[i++])	length++;
		if(length<2) return;
		
		int tail=0;
		for(i=1; i<length; i++){
			int j;
			for(j=0; j<tail; j++){
				if(str[i]==str[j]) break; // duplicate char, skip
			}
			
			// no duplicate
			if(j==tail)	{
				str[tail]=str[i];
				tail++;
			}
		}
		str[tail]=0;
	}
}

// replace 'a' with '%20'
void replacblank(char* str)
{
	if(str==NULL) return;

	int count=0;
	int space=0;
	while(str[count]){
		if(str[count]=='a') space++;
		count++;
	}	

	int newcount=count+space*2;
	
	for(int i=count-1; i>=0; i--)
	{
		if(str[i]=='a'){
			str[newcount-1]='0';
			str[newcount-2]='2';
			str[newcount-3]='%';
			newcount-=3;								
		} else {
			str[newcount-1]=str[i];
			newcount-=1;
		}
	}	

	cout << str << endl;
}

void rotatematrix()
{
	int i,j,length=4;
	int matrix[][4] = {{1,2,3,0},{5,6,7,8},{9,0,1,2},{3,1,5,0}};
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}	
	
	for(int layer=0; layer<length/2; layer++){
		int first=layer, last=length-layer-1;
		for(i=first; i<last; i++){
			int offset = i-first;
			int tmp= matrix[first][i];
			matrix[first][i]=matrix[last-offset][first];
			matrix[last-offset][first]=matrix[last][last-offset];
			matrix[last][last - offset] = matrix[i][last];
			matrix[i][last] = tmp;
		}
	}
	
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}		
}

// Write an algorithm such that if an element in an MxN matrix is 0, 
// its entire row and column is set to 0
void setZeros(){
	int matrix[][4] = {{1,2,3,0},{5,6,7,8},{9,0,1,2},{3,1,5,0}};
	int column[4]={0};
	int row[4]={0};
	int i,j;

	for(i=0; i<4; i++){
		for(j=0; j<4;j++){
			if(matrix[i][j]==0){
				column[i]=1;
				row[j]=1;
			}
		}
	}
	
	for(i=0; i<4; i++){
		for(j=0; j<4;j++){
			if(column[i]==1 || row[j]==1){
				matrix[i][j]=0;
			}
		}
	}
	
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}			
}

/* find continus elements which have biggest sum */
int maxSum(int* arr)
{
	int i=0, length=0;	
	int maxSum=0;
	int sum=0;
	
	while(arr[i++]){
		length++;
	}
	
	for(i=0; i<length; i++){
		if(sum<=0)
			sum=arr[i];
		else
			sum+=arr[i];
		
		if(maxSum<sum)
			maxSum=sum;
	}
	return maxSum;	
}

/* find sum of 2 in the array == sum */
void sumoftwo()
{
	const int sum=1000;
  	int a[10]={1,5,6,8,11,18,19,23,24,29};
	
	int begin=0;
	int end=10-1;
	
	while(begin<end){
		if(a[begin]+a[end]==sum)
			break;
		if(a[begin]+a[end]<sum)
			begin++;
		else 
			end--;			
	}
	
	if(begin<end)	//found
		cout<<a[begin]<<"+"<<a[end]<<"="<<sum<<endl;
	else
		cout<<"not found"<<endl;
}

/* find first not repeating char */
/* suppose it is ASCII code */
/* use hash table */
char firstnotrepeatingchar(char* str)
{
	if(str==NULL) return 0;
	
	int hashtable[256]={0};	// ASCII
	char* hashKey=str;
	
	/* count for each character from 0-255*/
	while(*hashKey){
		hashtable[*hashKey]++;
		hashKey++;
	}
	
	while(*str){
		if(hashtable[*str]==1)
			return *str;
		str++;
	}
		
	return 0;
}


/* 1, 1, 2, 3, 5, 8, 13, ....*/
int fibonacci(int n)
{
	/* recursive */
	/*
	if(n==0)
		return 0;
	else if(n==1 || n==2)
		return 1;
	else
		return fibonacci(n-1)+fibonacci(n-2);
	*/

	/* xxxxxxxx */	
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	else{
		int fibminus1=1;
		int fibminus2=0;
		int fibN=0;
		for(int i=2; i<=n; i++){
			fibN=fibminus1+fibminus2;
			fibminus2=fibminus1;
			fibminus1=fibN;
		}
		return fibN;
	}
}

/* how many 1 in the 2jinzhi */
int numberof1(int i)
{
	int count=0;
	unsigned int flag=1;
	
	while(flag){
		if(flag & i)
			count++;
		flag=flag<<1;
	}
	return count;
}


int main(int argc, char** argv)
{
  //int a[10]={1,-8,6,3,-1,5,7,-2,0,1};	
	//cout << "maxSum(a)=" << maxSum(a) <<endl;
	
	//sumoftwo();
	//char str[]="aaaageeagearejghahgeaklehsh";
	//cout<<"first not repeating char:"<<firstnotrepeatingchar(str)<<endl;
	
	//cout<<fibonacci(5)<<endl;
	cout<<numberof1(-5)<<endl;
	
	//char str[256];
	//cout << "please input string: ";
	//cin >> str;
	//cout << isuniquestr(str) << endl;
	//reverse(str);
	//removedups(str);
	//cout << str << endl;
	
	//replacblank();
	//rotatematrix();
	//setZeros();
	return 0;
}