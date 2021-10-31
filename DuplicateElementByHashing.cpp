#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of array";
    cin>>n;
    int a[n];

    int min=10000000;
    int max=-9999999;

    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>max){
            max=a[i];
        }
        if(a[i]<min){
            min=a[i];
        }
    }

    int hash[max+1]={0};

    for(int i=0;i<n;i++){
        hash[a[i]]++;
    }
    for(int i=min;i<max+1;i++){
        if(hash[i]>1){
            cout<<i<<" Occurs time is "<<hash[i]<<endl;
        }
    }


    return 0;
}