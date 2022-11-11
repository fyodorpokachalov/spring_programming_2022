#include <iostream>
#include <map>
using namespace std;
void print1(){
    map<int,int> m1;
    int n1;
    int n2;
    int n3;
    int n4;
    cout<<"enter the number of pairs: ";
    cin >> n1;
    for(int i = 0; i<n1; i++){
      cout<<"enter the number: ";
      cin >> n2;
      cout<<"enter the pair: ";
      cin >> n3;
      m1[n2]=n3;
    }
    cout << "enter the sequence: ";
    while(true){
      cin >> n4;
      if(cin.good()){
        if(m1.count(n4)){
          cout<<"the image of the number is: ";
          cout<<m1[n4]<<endl;}
        if(!m1.count(n4)){
          cout<<"the very same number is: ";
          cout<<n4<<endl;}
      }
      else
        break;
    }
}
int main(){
  print1();
  return EXIT_SUCCESS;
}
