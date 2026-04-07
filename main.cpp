#include <bits/stdc++.h>
using namespace std;

static unsigned long long sum_proper_divisors(unsigned long long n){
    if(n <= 1) return 0ULL;
    unsigned long long sum = 1; // 1 is a proper divisor for n>1
    unsigned long long temp = n;

    // factor 2
    if((temp & 1ULL) == 0ULL){
        unsigned long long term_sum = 1;
        unsigned long long curr = 1;
        while((temp & 1ULL) == 0ULL){
            temp >>= 1ULL;
            curr <<= 1ULL;
            term_sum += curr;
        }
        sum *= term_sum;
    }

    for(unsigned long long f = 3; f*f <= temp; f += 2){
        if(temp % f == 0){
            unsigned long long term_sum = 1;
            unsigned long long curr = 1;
            do{
                temp /= f;
                curr *= f;
                term_sum += curr;
            } while(temp % f == 0);
            sum *= term_sum;
        }
    }

    if(temp > 1){
        sum *= (1 + temp);
    }

    // sum of proper divisors
    return sum - n;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    if(!(cin >> m)) return 0;
    for(int i = 0; i < m; ++i){
        unsigned long long n; cin >> n;
        unsigned long long s = sum_proper_divisors(n);
        cout << (s == n ? 1 : 0);
        if(i + 1 < m) cout << '\n';
    }
    return 0;
}
