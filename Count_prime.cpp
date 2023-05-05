#include<bits/stdc++.h>
using namespace std;
void countPrime(int n){
    bool arr[n];
    for(int i=0;i<n;i++){
        arr[i]=true;
    }
    for(int i=2;i<sqrt(n);i++){
        if(arr[i]==true){
            for(int j=i*i;j<n;j+=i){
                arr[j]=false;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]==true)cout<<i<<'\t';
    } 
}
int main(){
    cout<<"Enter a no. "<<endl;
    int n;
    cin>>n;
    countPrime(n);
}