#include<iostream>
using namespace std;

int countOnes(string a){
	int res=0;
	for(int i=0;i<a.length();i++){
		if(a[i]=='1'){
			res++;
		}
	}
	return res;
}
string sender(string input, int type){
	//No of ones
	int cnt=countOnes(input);
	//Odd Partity
	cout<<cnt<<"\n";
	if(type==1){
		if(cnt%2==0){
			input+="1";
		}else{
			input+="0";
		}
	}else{
	//even parity
		if(cnt%2!=0){
			input+="1";
		}else{
			input+="0";
		}
	}
	return input;
}
void reciver(string input,int type){
	int cnt=countOnes(input);
	if(type==1){
		if(cnt%2!=0){
			cout<<"String Recived Correctly";
		}else{
			cout<<"String Incorrect";
		}	
	}else{
		if(cnt%2==0){
			cout<<"String Recived is correct";
		}else{
			cout<<"String Recived is incorrect";
		}
	}
}
int main(){
	int typeOfParity;
	string input;
	cout<<"Select For Type of Parity Check\n 1, Odd Parity Check \n 2.Even Parity Check\n";
	cin>>typeOfParity;
	cout<<"Enter Sender Message\n";
	cin>>input;
	cout<<"Data Entered By User:"<<input<<endl;
	string sent=sender(input,typeOfParity);   
	cout<<"Data Sent to Reciver:"<<sent<<endl;
	cout<<"Reciver Side\n";
	reciver(sent,typeOfParity);
return 0;
}
