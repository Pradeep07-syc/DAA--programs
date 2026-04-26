#include <iostream>
using namespace std;
int main (){
    int n;
    cout <<"Enter number of elements:";
    cin>>n;
    int a[n];
    cout<<"Enter elements:\n";
    for(inti=0;i<n;i++)
    cin >>a[i];
    for(int i=0;i<n-1;i++){
        int minlndex=i;
        for(intj=i+1;j<n;j++){
            if(a[j]<a[minlndex])
            minlndex=j;
        }
        int temp=a[i];
        a[i]=a[minlndex];
        a[minlndex]=temp;
    }
    cout<<"Sorted array:\n";
    for(inti=0;i<n;i++)
    cout<<a[i]<<"";
    return 0;
 
}
