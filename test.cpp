#include<iostream>
#include<set>

using namespace std;

int main(){
    
    set<int> table;
    table.insert(table.begin(), 10);
    table.insert(table.begin(), 20);
    // cout<<table[0]<<endl;
    // cout<<table[1]<<endl;
    // cout<<*(table.begin())<<endl;
    // cout<<*(table.begin()+1)<<endl;

    for (auto iter: table){
        cout<<iter<<endl;
    }
    
}