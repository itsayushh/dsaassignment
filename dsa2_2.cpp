#include<bits/stdc++.h>
using ll = long long;
using lld = long double;
using ull = unsigned long long;
using namespace std;
/*---------------------------------------------------------------------------------------------------------------------------*/
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ppb pop_back
#define all(x) (x).begin(), (x).end()
#define cmp return a > b;
#define mpr make_pair
#define ff first
#define ss second
#define MOD1 1000000007
#define MOD 998244353
/*---------------------------------------------------------------------------------------------------------------------------*/
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;}
/*---------------------------------------------------------------------------------------------------------------------------*/
int main()
{
    //binary search
    int n,target;
    cout<<"Enter size of array: \n";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array: \n";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the value to find: \n";
    cin>>target;
    int l=0,r=n-1;
    while (r>=l)
    {
        int m = (l+r)/2;
        if(arr[m]>target){
            r=m-1;
        }
        else if(arr[m]<target){
            l=m+1;
        }
        else{
            cout<<m<<" ";
            return 0;
        }
    }
    cout<<"Element not found ";
    return 0;

}