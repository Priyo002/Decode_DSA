#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter your number : ";
    cin >> n;


    for(int i=1;i<=n;i++){
        for(int s=1;s<=n-i;s++){
            cout << " ";
        }
        for(int j=1;j<=i;j++){
        cout << "*";
        }
        cout << endl;
    }
    for(int i=n+1;i<2*n;i++){
        for(int s=1;s<=i-n;s++){
            cout << " ";
        }
        for(int j=1;j<=2*n-i;j++){
        cout << "*";
        }
        cout << endl;
    }


    return 0;
}