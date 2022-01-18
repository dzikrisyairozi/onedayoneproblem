#include <iostream>
using namespace std;
 
int main() {
	int tcase, input;
	cin>>tcase;
	for(int i=0; i<tcase; i++){
	    if(i)cout<<"\n";
	    cin>>input;
	    if(input%6)cout<<"N";
	    else cout<<"Y";
	}
	return 0;
}
 