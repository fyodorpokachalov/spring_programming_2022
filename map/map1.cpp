#include <iostream>
#include <map>
using namespace std;
void print(map<int,int> m1){
  int n;
  while(true){
    cin>>n;
    if(cin.good()){
      m1[n]++;
    }
    else break;
  }
  for (auto x:m1)
  cout<<x.first << " was encountered " <<x.second << " times "<< endl;
};
int main(){
  map<int,int> map1;
  print(map1);
  return EXIT_SUCCESS;
}
