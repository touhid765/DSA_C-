#include<iostream>
using namespace std;
int main(){
    int a, b;
    
    cout<< "enter a:";
    cin>> a;

    cout<< "enter b:";
    cin>> b;

    int sum = a + b;
    int devide = a / b;
    int mul = a * b;
    int sub = a - b;

    cout << "deevide = " << devide<< endl;
    cout << "sum = " << sum << endl;
    cout << "mul = " << mul << endl;
    cout << "sub = " << sub << endl;
     return 0;
}