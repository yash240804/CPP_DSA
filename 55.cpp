#include<iostream>
using namespace std;
int reverse(int n){
    int rem, ans = 0;
    while (n)
    {
        rem = n % 10;
        n = n / 10;
        if (ans > 500 - rem || ans < -500 - rem)
        {
            return 0;
        }
        ans = ans*10 + rem;
    }
    return ans;
    
}
int main(){
    int n;
    cin>>n;
    cout<<reverse(n);
    return 0;
}