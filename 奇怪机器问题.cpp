#include<iostream>
#include<string>
#include<vector>
using namespace std;
 
// 计算经过一圈的效果
void one_cycle(long long& x, const string& ji, int n, long long& cntA_in_cycle) {
    cntA_in_cycle = 0;
    for(int i = 0; i < n && x > 0; i++) {
        if(ji[i] == 'A') {
            x--;
            cntA_in_cycle++;
        } else {
            x /= 2;
        }
    }
}
 
long long calc(long long x, long long steps, const string& ji, int n) {
    if(steps == 0 || x == 0) return x;
    
    long long full_cycles = steps / n;
    int remainder = steps % n;
    long long cntA;
    
    // 关键优化：如果x很大，先快速跳过前面的圈
    while(full_cycles > 0 && x > 0) {
        long long old_x = x;
        one_cycle(x, ji, n, cntA);
        full_cycles--;
        
        // 如果这一圈全是A
        if(cntA == n) {
            // 剩下的全A圈可以直接计算
            // 每圈减n，需要 ceil(x/n) 圈变成0
            if(x > full_cycles * n) {
                x -= full_cycles * n;
                full_cycles = 0;
            } else {
                return 0; // 在full_cycles圈内就会变成0
            }
            break;
        }
        
        // 如果值不再变化，跳出
        if(x == old_x) break;
        
        // 如果x变得很小，继续循环也不会太多次
        if(x < n * 100) break; // 小数字直接交给后面的循环处理
    }
    
    // 处理剩余的完整圈（此时x已经很小，直接模拟）
    for(long long i = 0; i < full_cycles && x > 0; i++) {
        one_cycle(x, ji, n, cntA);
    }
    
    // 处理剩余步数
    for(int i = 0; i < remainder && x > 0; i++) {
        if(ji[i] == 'A') x--;
        else x /= 2;
    }
    
    return x;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        string ji;
        cin >> ji;
        
        // 统计A的数量
        int cntA = 0;
        for(char c : ji) cntA += (c == 'A');
        
        vector<long long> num(q);
        for(int i = 0; i < q; i++) {
            cin >> num[i];
        }
        
        for(int i = 0; i < q; i++) {
            long long x = num[i];
            
            // 全A直接输出
            if(cntA == n) {
                cout << x << '\n';
                continue;
            }
            
            long long l = 0, r = 1e12;
            while(l < r) {
                long long mid = (l + r) / 2;
                if(calc(x, mid, ji, n) == 0) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            cout << l << '\n';
        }
    }
    return 0;
}
