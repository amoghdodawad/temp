#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void maxHeapify(vector<int>& arr, int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest]) largest = left;
    if(right < n && arr[right] > arr[largest]) largest = right;
    if(i != largest) swap(arr[i],arr[largest]);
    if(i != largest) maxHeapify(arr,n,largest);
};

void minHeapify(vector<int>& arr, int n, int i){
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] < arr[smallest]) smallest = left;
    if(right < n && arr[right] < arr[smallest]) smallest = right;
    if(i != smallest) swap(arr[i],arr[smallest]);
    if(i != smallest) minHeapify(arr,n,smallest);
}

void heapSort(vector<int>& arr, int choice){
    int n = arr.size();
    if(choice == 0){
        for(int i = (n)/2 - 1; i >= 0; i--){
            maxHeapify(arr,n,i);
        }
        for(int i=n-1; i > 0; --i){
            swap(arr[0],arr[i]);
            maxHeapify(arr,i,0);
        }
    } else {
        for(int i = (n)/2 - 1; i >= 0; i--){
            minHeapify(arr,n,i);
        }
        for(int i=n-1; i > 1; --i){
            swap(arr[0],arr[i]);
            minHeapify(arr,i,0);
        }
    }
}

int main(){
    int n, choice;
    cin >> n >> choice;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    heapSort(arr,choice);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}