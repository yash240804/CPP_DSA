#include<iostream>
using namespace std;
int main(){
    int arr[] = {1, 2, 3, 4, 5};
    cout<<sizeof(arr)<<"  ";  // to get size or array or any variable or datatype use size of
    cout<<sizeof(arr)/sizeof(arr[0]); // to find the lenght of array
    return 0;
}