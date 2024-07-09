#include<iostream>
using namespace std;
int main(){
   double n,p,q,phi,e,d;
    cout<<"Enter the value of p and q : ";
    cin>>p>>q;
    n=p*q;
    phi=(p-1)*(q-1);
    cout<<"Enter the value of e :";
    cin>>e;
    d=(2*phi+1)/e;
    cout<<d<<endl;
    // d=1;
    // while(1){
    //     if((d*e)%phi==1){
    //         break;
    //     }
    //     d++;
    // }
    cout<<"Public key : ("<<n<<","<<e<<")\n";
    cout<<"Private key : ("<<n<<","<<d<<")\n";
    cout<<"Enter Message to be encrypted :";
    double msg;
    cin>>msg;
    cout<<msg<<endl;
    cout<< (pow(msg,e)) << "\n";
    int c=int(pow(msg,e)) % int(n);
    cout<<"Encrypted message : "<<c<<endl;

    // cout<<"Decrypted message : "<<int(pow(c,d))%int(n)<<endl;
    cout<<int(pow(c,d)) % int(n)<<endl;
    return 0;    
}
