//双指针
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 200005;
long long a[N];

int main(){
    int n;
    long long c;
    cin >> n >> c;

    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    long long ans = 0;
    int l = 0, r = 0;

    while(r < n){
        if(a[r] - a[l] < c){
            r++;
        }
        else if(a[r] - a[l] > c){
            l++;
        }
        else{
            long long cnt1 = 1, cnt2 = 1;

            while(l + 1 < n && a[l] == a[l + 1]){
                cnt1++;
                l++;
            }
            while(r + 1 < n && a[r] == a[r + 1]){
                cnt2++;
                r++;
            }

            ans += cnt1 * cnt2;
            l++;
            r++;
        }

        if(l == r) r++;
    }

    cout << ans << endl;
}
