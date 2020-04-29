#define ll long long
#define mod 1000000007  

struct matrix{

    ll a,b,c,d;

    matrix(ll w=0, ll x=0, ll y=0, ll z=0){ a=w; b=x; c=y; d=z; }

    matrix operator * (const matrix &mat) const{

        ll new_a = (a*mat.a+b*mat.c)%mod;
        ll new_b = (a*mat.b+b*mat.d)%mod;    
        ll new_c = (c*mat.a+d*mat.c)%mod;
        ll new_d = (c*mat.b+d*mat.d)%mod;

        return matrix(new_a, new_b, new_c ,new_d);
    }
};

ll Fib(ll n)
{
    ll temp=n; 

    n=abs(n);   

    matrix rslt(1,0,0,1); 
    matrix base(1,1,1,0);  

    while(n>0)
    {
        if(n&1)
            rslt=rslt*base;
        base=base*base;
        n>>=1;
    }
    return rslt.c;  
}