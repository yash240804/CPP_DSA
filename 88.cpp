#include<iostream>
using namespace std;

int main(){
    int a, b;
    cin>>a>>b;
    int ans = 1;
    for(int i = 2; i <= min(a, b); i++){
        if(a % i == 0 && b % i == 0){
            ans = i;
            break;
        }
    }
    if(ans == 1){
        cout<<"Co-prime"<<endl;
    }else{
        cout<<"Not Co-prime"<<endl;
    }
    return 0;
}