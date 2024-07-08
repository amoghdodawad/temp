#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long query(vector<long long>& bit, int i){
    long long sum = 0;
    while(i){
        sum += bit[i];
        i -= (i&-i);
    }
    return sum;
}

int main(){
    int n,q;
    cin >> n >> q;
    vector<long long> v(n+1),bit(n+1,0);
    for(int i=1;i<=n;++i) cin >> v[i];
    for(int i=1;i<=n;++i){
        int x = i;
        while(x <= n){
            bit[x] += v[i];
            x += (x&-x);
        }
    }
    while (q--){
        int o,k,u;
        cin >> o >> k >> u;
        if(o == 1){
            int temp = k;
            while(k <= n){
                bit[k] -= v[temp];
                bit[k] += u;
                k += (k&-k);
            }
            v[temp] = u;
        } else if(o == 2){
            cout << query(bit,u)-query(bit,k-1) << endl;
        }
    }
    
    return 0;
}