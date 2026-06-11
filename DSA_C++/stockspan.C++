#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};
    vector<int> span(price.size());
    stack<int> s;

    span[0] = 1;
    s.push(0);

    for(int i = 1; i < price.size(); i++){
        while(!s.empty() && price[s.top()] <= price[i]){
            s.pop();
        }
        span[i] = s.empty() ? i + 1 : i - s.top();
        s.push(i);
    }

    for(int i = 0; i < span.size(); i++){
        cout << span[i] << " ";
    }
    return 0;
}
