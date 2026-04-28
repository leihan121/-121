//哈希
#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    long long c;
    cin >> n >> c;
    
    unordered_map<long long,long long> cnt;
    long long x;

    for(int i = 0; i < n; i++){
        cin >> x;
        cnt[x]++;
    }

    long long ans = 0;

    for(auto &p : cnt){
        long long val = p.first;
        if(cnt.count(val + c)){
            ans += p.second * cnt[val + c];
        }
    }

    cout << ans << endl;
    return 0;
}
