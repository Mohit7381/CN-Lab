#include<iostream>
using namespace std;

string xor2(string a,string b){
	string res="";
	for(int i=1;i<b.length();i++){
		if(a[i]==b[i]){
			res+="0";
		}else{
			res+="1";
		}
	}
	return res;
}
string divide(string input,string crc){
	//number bits to be divided
	int pick=crc.length();
	string temp=input.substr(0,pick);
	int n=input.length();
	while(pick<n){
		if(temp[0]=='1'){
			temp=xor2(crc,temp)+input[pick];
		}else{
			temp=xor2(string(pick,'0'),temp)+input[pick];
		}
		pick+=1;
	}
	if(temp[0]=='1'){
		temp=xor2(crc,temp);
	}else{
		temp=xor2(string(pick,'0'),temp);
	}
return temp;
}
string sender(string input,string crc){
	int lenC=crc.length();
	string app_in=input+string(lenC-1,'0');
	string rem=divide(app_in,crc);
        cout<<"Remainder :"<<rem<<endl;	
		cout<<"Input : "<<input<<endl;
	return input+rem;
}
void reciver(string input,string crc){
	string curr=divide(input.substr(0,crc.length()),crc);
	int pos=crc.length();
	while(pos!=input.length()){
		if(curr.length()!=crc.length()){
			curr.push_back(input[pos++]);
		}else{
			curr=divide(curr,crc);
		}
	}
	if(curr.length()==crc.length()){
		curr=divide(curr,crc);
	}
	if(curr.find('1')!= string::npos){
		cout<<"Message is not correct\n";
	}else{
		cout<<"Message is correct";
	}
}
int main(){
	string input;
	cout<<"Enter Message to be Sent in binary\n";
	cin>>input;
	string crc="10011";
	string sent=sender(input,crc);
	cout<<"Message Sent : "<<sent<<endl;
	reciver(sent,crc);
return 0;
}
