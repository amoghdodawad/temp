#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, windowSize;
    int start = 0, end = 0;
    int maxStart = 0, maxEnd = 0;
    int sum = 0, maxSum = 0;

    cin >> n >> windowSize;
    if(windowSize > n) windowSize = n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i=0;i<windowSize;++i){
        sum += arr[i];
    }
    maxSum = sum;
    end = windowSize;
    maxEnd = end-1;
    while(end < n){
        sum -= arr[start++];
        sum += arr[end++];
        if(sum > maxSum){
            maxSum = sum;
            maxStart = start;
            maxEnd = end-1;
        }
    }

    cout << maxSum << " " << maxStart << " " << maxEnd;

}