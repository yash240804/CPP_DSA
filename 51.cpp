#include<iostream>
using namespace std;
int sum(int a, int b){
    int ans = a + b;
    return ans;
}
float sum(float a, float b){
    float ans = a + b;
    return ans;
}
int main(){
    int n, m;
    cin>>n>>m;
    cout<<sum(n, m)<<endl;
    float x, y;
    x = 1.5f, y = 6.8f;
    cout<<sum(x, y);
    return 0;
}