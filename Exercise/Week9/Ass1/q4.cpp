#include<bits/stdc++.h>
using namespace std;


int main(){
    int arr[] = {5,4,3,2,1};
    int n = 5;
    for(int i=0;i<n-1;i++){
        bool flag = false;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]<arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag = true;
            }
        }
        if(flag==false ) break;
    }
    for(int i=0;i<n;i++) cout<< arr[i] << " ";
}