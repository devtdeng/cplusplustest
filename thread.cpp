#include <iostream>
#include <pthread.h>
using namespace std;

#define NUM_THREAD	5

struct thread_data{
	long threadid;
	char* message;
};

void *printHello(void* threadarg)
{
	struct thread_data *mydata = (struct thread_data*)threadarg;
	cout<<"threadid="<<mydata->threadid<<endl;
	pthread_exit(NULL);
}

int main(int argc, char** argv)
{
	pthread_t	threads[NUM_THREAD];
	struct thread_data	td[NUM_THREAD];
	int rc;
	
	for(int i=0; i<NUM_THREAD; i++){
		td[i].threadid = i;
		rc=pthread_create(&threads[i], NULL, printHello, &td[i]);
		if(rc){
			cout<<"failed to create thread!"<<endl;
		}
	}
	pthread_exit(NULL);
}