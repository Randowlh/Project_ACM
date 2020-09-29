class mint{
    public:
    int powmod(int a,int b) {int res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
    inline int niyuan(int x, int mod) { return powmod(x, mod - 2); }
    int  n;
    mint() : n(0) { ; }
    mint(ll m) : n(m)
    {
        if (n >= mod)
            n %= mod;
        else if (n < 0)
            n = (n % mod + mod) % mod;
    }
    operator int() { return n; }
    inline mint operator=(mint a){n=a.n;return n;}
    inline bool operator==(mint a){return n==a.n;}
    inline bool operator!=(mint a){return n!=a.n;}
    inline bool operator<(mint a){return n<a.n;}
    inline bool operator>(mint a){return n>a.n;}
    inline bool operator<=(mint a){return n<=a.n;}
    inline bool operator>=(mint a){return n>=a.n;}
    inline mint operator+(mint a){int res=n+a.n;if(res>=mod)res-=mod; return res;}
    inline mint operator-(mint a){int res=n-a.n;if(res<0)res+=mod;return res;}
    inline mint operator*(mint a){int res=n*a.n%mod;return res;}
    inline mint operator/(mint a){int res=n*niyuan(a.n,mod)%mod;return res;}
    inline mint operator+=(mint a){*this=*this+a;return *this;}
    inline mint operator-=(mint a){*this=*this-a;return *this;}
    inline mint operator*=(mint a){*this=*this*a;return *this;}
    inline mint operator/=(mint a){*this=*this/a;return *this;}
    inline mint operator++(){n++;n%=mod;return n;}
};