// Fibonacci series:     0 1 1 2 3 5 8 13 21 34 55 ....
// Recurrance Relation:  Fib(i)=Fib(i-1)+Fib(i-2) where i>=2
// Base Conditions:      Fib(0)=0, Fib(1)=1;

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007  // Take mod for large values

struct matrix{

    ll a,b,c,d;

    // constructor
    matrix(ll w=0, ll x=0, ll y=0, ll z=0){ a=w; b=x; c=y; d=z; }

    // operator overloading
    matrix operator * (const matrix &mat) const{

        ll new_a = (a*mat.a+b*mat.c)%mod;
        ll new_b = (a*mat.b+b*mat.d)%mod;    // 2*2 matrix multiplication
        ll new_c = (c*mat.a+d*mat.c)%mod;
        ll new_d = (c*mat.b+d*mat.d)%mod;

        return matrix(new_a, new_b, new_c ,new_d);
    }
};


// Printing the required Matrix

void printMatrix(ll n, matrix print)
{
    int sign1=1;
    int sign2=1;

    if(n<0)
    {
        if(abs(n)&1)
            sign1=-1;
        else
            sign2=-1;
    }
    cout<<"Resultant Matrix is: \n\n";
    cout<<(sign1*print.a)<<" "<<(sign2*print.b)<<"\n"<<(sign2*print.c)<<" "<<(sign1*print.d)<<"\n\n";
}

// Using matrix exponentiation we can find nth fibonacci in log(N) time complexity

ll Fib(ll n)
{
    ll temp=n;  // For printing the resultant Matrix

    n=abs(n);   // We take absolute value for calculation

    matrix rslt(1,0,0,1);  // Resultant Matrix
    matrix base(1,1,1,0);  // Base Matrix

    while(n>0)
    {
        if(n&1)
            rslt=rslt*base;
        base=base*base;
        n>>=1;
    }

    // Uncomment below line to see Required Matrix..
    // printMatrix(temp, rslt);

    //
    // [ rslt.a   rslt.b ]     [Fib(n+1)  Fib(n)  ]
    //                    =>
    // [ rslt.c   rslt.d ]     [Fib(n)    Fib(n-1)]
    //

    return rslt.c;  // Fib(n)
}

// Driver function
int main()
{
    ll N;
    cin>>N; // Input Number

    int sign=1;

    if(N<0 && abs(N)%2==0)   // if N is negative and divisible by 2 then Nth fibonacci must be negative
        sign=-1;

    ll n=Fib(N);

    cout<<"Nth fibonacci number is: ";
    cout<<( sign * n )<<endl;

    return 0;
}
