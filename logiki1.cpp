#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;  
typedef pair<int,int> ii;  
typedef vector<ii> vii;  
typedef list<int> li;  
typedef map<int,int> mii;
  
#define rep(i,n) for (int i = 0; i < (n); i++)  
#define rrep(i,n) for (int i = (n)-1; i >= 0; i--)
#define rap(i,a,n) for (int i = a; i < (n); i++) 
#define rrap(i,n,a) for (int i = (n)-1; i >= a; i--) 

vi v;

inline int a1(int phi, int psi) { return v[3+3*phi+v[3+3*psi+phi]]; }
inline int a2(int phi, int chi, int psi) { return v[3+3*v[3+3*phi+v[3+3*psi+chi]]+v[3+3*v[3+3*phi+psi]+v[3+3*phi+chi]]]; }
inline int a3(int phi, int psi) { return v[3+3*v[3+3*v[psi]+v[phi]]+ v[3+3*v[3+3*v[psi]+phi]+psi]]; }

int main() {
    v.assign(12,0);
    int k;
    bool flag,flag2;
    while (1) {
        k=11;
        //rep(j,12) cout << v[j] << " ";
        //cout << endl;
        if (v[3]!=0 || v[4]==0 || v[5]==0) {
            while (k>=0) {
            if (v[k]<2) {
                if (k==11){v[k]++; break;}
                else {
                    v[k]++;
                    for (int p=k+1;p<12;p++) v[p]=0;
                }
                break;}
            else k--;
        } continue;
        }  //modus ponens
        int a,b,c;
        flag=false;
        flag2=false;
        for (int phi=0;phi<=2;phi++) {
            for (int psi=0;psi<=2;psi++) {
                //if (phi==0 && psi==1) cout << "it is " << a3(phi,psi) << endl;
                if (a1(phi,psi)!=0 || a3(phi,psi)!=0) {flag=true; break;}
                for (int chi=0;chi<=2;chi++) {
                    if (a2(phi,chi,psi)!=0) {
                        a=phi;b=chi;c=psi;
                        flag2=true; break;
                    }
                }
            }
            if (flag==true) break;
        }
        if (!flag && flag2) {
            cout << "Negation Truthtable (negation of 0, negation of 1, negation of 2):\n";
            rep(j,3) cout << v[j] << " ";
            cout << endl;
            cout << "Implication truthtable (0->0, 0->1, 0->2, ..., last is 2->2):\n";
            rap(j,3,12) cout << v[j] << " ";
            cout << endl;
            cout << "Values for Phi, Chi, Psi in A2 for result different than 0:\n";
            cout << a << " " << b << " " << c << endl;
            break;
        }
        k=11;
        flag=false;
    while (k>=0) {
            if (v[k]<2) {
                if (k==11){v[k]++; break;}
                else {
                    v[k]++;
                    for (int p=k+1;p<12;p++) v[p]=0;
                }
                break;}
            else k--;
        }
        if (k==-1) break;
    }
    ios_base::sync_with_stdio(false);
    return 0;

    //compile: g++ -std=c++14 -O2 -Wall NAME.cpp -o NAME
}
