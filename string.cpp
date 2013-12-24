#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char** argv)
{
	string s1("the dog is the dog"); 
	string buf;
	stringstream ss(s1);
	vector<string> s;

	while(ss>>buf){
		s.push_back(buf);
	}
	
	vector<string>::iterator it;	
	vector<string>::iterator it2;		
  for( it = s.begin(); it != s.end(); it++ ){
		for(it2=it+1; it2!=s.end(); it2++){
			cout << *it << endl;
		}
	}
	return 0;
}