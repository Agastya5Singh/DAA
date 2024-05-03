// wap that takes three variables (a,b,c) as saparete parameters and rotates the values stored so that value a goes to b, b goes to c and c goes to a. by using swap(x,y) function.
#include <bits/stdc++.h>
using namespace std;
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    swap(a,b);
    swap(a,c);
    // swap(a,c);
    cout<<a<<" "<<b<<" "<<c;
    return 0;
}