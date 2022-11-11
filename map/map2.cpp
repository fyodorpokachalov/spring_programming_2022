#include <iostream>
#include <map>
using namespace std;
map<int,int> print1(){
    map<int,int> m1;
    int n1;
    int n2;
    int n3;
    cout<<"enter the number of pairs: ";
    cin >> n1;
    for(int i = 0; i<n1; i++){
      cout<<"enter the number: ";
      cin >> n2;
      cout<<"enter the pair: ";
      cin >> n3;
      m1[n2]=n3;
    }
    return(m1);
}
void print(map<int,int> m){
  for (auto x:m)
  cout<<x.first << " is paired with " <<x.second << endl;
}
int main(){
  print(print1());
  return EXIT_SUCCESS;
}
