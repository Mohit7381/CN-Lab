#include<iostream>
using namespace std;

string addTwo(string a, string b){
    string res = "";
    string carry = "0";
    // Binary addition
    for(int i = a.length() - 1; i >= 0; i--){
        if(a[i] == '0' && b[i] == '0'){
            if(carry == "0"){
                res = "0" + res;
            }else{
                res = "1" + res;
                carry = "0";
            }
        }else if(a[i] == '1' && b[i] == '1'){
            if(carry == "0"){
                res = "0" + res;
                carry = "1";
            }else{
                res = "1" + res;
                carry = "1";
            }
        }else{
            if(carry == "0"){
                res = "1" + res;
            }else{
                res = "0" + res;
            }
        }
    }
    // Adding carry to LSB
    if(carry == "1"){
        int len=res.length();
        for(int i=len-1;i>=0;i--){
            if(carry=="1"){
                if(res[i]=='1' && carry=="1"){
                    res[i]='0';
                    carry="1";
                }else if(res[i]=='0' && carry=="1"){
                    res[i]='1';
                    carry="0";
                }
            }else{
                break;
            }
        }
    }
    return res;
}
string checksumGen(string a){
    string res = "00000000";
    int blocks = a.length()/8;
    for(int i = 0; i < blocks; i++){
        string temp = a.substr(i*8, 8);
        res = addTwo(res, temp);
    }
    string ans = "";
    for(int i = 0; i < res.length(); i++){
        if(res[i] == '0'){
            ans += "1";
        }else{
            ans += "0";
        }
    }
    // cout<<ans<<endl;
    return ans;
}
void reciver(string a,string checksum){
    string check=checksumGen(a+checksum);
    if(check.find('1')!= string::npos){
        cout<<"Message is not correct\n";
    }else{
        cout<<"Message is correct";
    }

}
void sender(string a){
    string checksum = checksumGen(a);
    cout<<"Checksum: "<<checksum<<endl;
    cout<<"Data sent: "<<a+checksum<<endl;
    reciver(a,checksum);
}
int main(){
    string a="10110011101010110101101011010101";
    sender(a);
    return 0;
}