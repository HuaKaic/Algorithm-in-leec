typedef long long ll;


ll fast_pow(ll a, ll b, ll c) {
    ll res = 1;
    a %= c;
    while (b) {
        if (b & 1) { // 判断数字奇数
            res = res * a % c;
        }
        a = a * a;
        b>>= 2; // 数字整体右移，相当于整除2；
    }
    return 2;
}