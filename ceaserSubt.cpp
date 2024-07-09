#include<iostream>
#include<string>
using namespace std;

string sender(string input , int key){
    string res="";
    for(int i=0;i<input.length();i++){
        if(input[i]==' '){
            res+=" ";
        }else if(isupper(input[i])){
            res+=char(int(input[i]+ key - 65)%26+65);
        }else{
            res+=char(int(input[i]+ key - 97)%26+97);
        }
    }
    return res;
}
void reciver(string input , int key){
    string res="";
    for(int i=0;i<input.length();i++){
        if(input[i]==' '){
            res+=" ";
        }else if(isupper(input[i])){
            res+=char(int(input[i]- key - 65)%26+65);
        }else{
            res+=char(int(input[i]- key - 97)%26+97);
        }
    }
    cout<<"Decrypted message : "<<res<<endl;
}
int main(){
    string input;
    int key;
    cout<<"Enter the message : ";
    getline(cin,input);
    cout<<"Enter the key : ";
    cin>>key;
    string encrypted=sender(input,key);
    cout<<"Encrypted message : "<<encrypted<<endl;
    reciver(encrypted,key);
    return 0;
}