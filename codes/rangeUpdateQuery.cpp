#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N = 2 * 1e5;
vector<long long> tree(4*N,0);

void buildTree(vector<long long>& arr, long long start, long long end, long long index){
    if(start == end){
        // cout << index << " " << start << " " << arr[start] << endl;
        tree[index] = arr[start];
        return;
    }
    int mid = (start + end)/2;
    buildTree(arr,start,mid,2*index);
    buildTree(arr,mid+1,end,2*index+1);
}


// start, end, 0, n-1
void update(long long start, long long end, long long left, long long right, long long val, long long index){
    if(right < start || left > end) return;
    if(right <= end && left >= start){
        tree[index] += val;
        return;
    }
    long long mid = (left + right)/2;
    update(start, end, left, mid,val, 2*index);
    update(start, end, mid+1,right,val, 2*index+1);
}

long long query(long long start, long long end, long long index, long long k){
    if(start == end && end == k) return tree[index];
    long long mid = (start + end)/2;
    if(tree[index]){
        if(2*index < tree.size()) tree[2*index] += tree[index];
        if(2*index + 1 < tree.size()) tree[2*index + 1] += tree[index];
        tree[index] = 0;
    }
    if(k <= mid){
        return query(start,mid,2*index,k);
    }
    return query(mid+1,end,2*index+1,k);
}

int main(){
    long long n,q;
    cin >> n >> q;
    vector<long long> arr(n+1);
    for(int i=0;i<n;++i){
        cin >> arr[i];
    }
    buildTree(arr,0,n-1,1);
    for(long long i=0;i<q;++i){
        long long opt;
        cin >> opt;
        if(opt == 1){
            long long l,r,v;
            cin >> l >> r >> v;
            update(l-1,r-1,0,n-1,v,1);
        } else if (opt == 2){
            long long k;
            cin >> k;
            cout << query(0,n-1,1,k-1) << endl;
        }
    }
}
