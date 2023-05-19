#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;
int main(){
   //creation
   unordered_map<string,int>m;
   //insetion
   pair<string,int>p=make_pair("babbar",3);
   m.insert(p);

   pair<string,int>pair2("love",2);
   m.insert(pair2);

  

  
   cout<<m.at("babbar")<<endl;
   cout<<m.size()<<endl;
   cout<<m.count("babbar")<<endl;
   //iterator
   unordered_map<string,int>::iterator it=m.begin();
   while(it!=m.end()){
    cout<<it->first<<" "<<it->second<<endl;it++;
   }
  
  for(auto i:m){
    cout<<i.first<<" "<<i.second<<endl;
  }



    return 0;
}