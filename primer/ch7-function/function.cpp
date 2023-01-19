#include <iostream>

int sum_arr(int arr[],int n);
int sum_arr(int arr[],int n){
    arr[0] = 2;
    return n;
}
int main(){
    using namespace std;
    int arr[3] = {1,2,3};
    sum_arr(arr,1);
    cout<<arr[0]<<endl;
}