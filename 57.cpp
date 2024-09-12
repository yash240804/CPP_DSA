#include<bits/stdc++.h>

using namespace std;
int countdigit(int n){
    int count = 0;
    while (n){
        count++;
        n = n / 10;
    }
    return count;
}
void armstrong(int n, int digit){
    int rem, ans = 0;
    int num = n;
    while (n)
    {
        rem = n % 10;
        n = n / 10;
        ans = ans + (double)(pow(rem, digit));
    }
    if (num == ans)
    cout<<"Yes";
    else 
    cout<<"No";
    
}
int main(){
    int n;
    cin>>n;
    int digit = countdigit(n);
    armstrong(n, digit);
    return 0;
}