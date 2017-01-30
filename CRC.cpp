#include<bits/stdc++.h>
using namespace std;

//Declaring the variables for the data and generator
string initial1,initial2,main1,main2,final1,final2,generator,rem1="",rem2="",temp1,temp2="";
long long len1,len2,s1,s2,len3,i,remval,diff;
int val = 0;

//Function for computing the CRC code
void compute_CRC(string str){
    s1=0;
	temp1 = str.substr(s1,len3).c_str();

	s1 += len3;
	while(true){
		temp2 = "";
		val = 0;
		for(i=0;i<len3;i++){
			if(val==0){
				if(temp1[i]!=generator[i]){
					temp2 += '1';
					val = 1;
				}
			}
			else if(val==1){
				if(temp1[i]==generator[i]){
					temp2 += '0';
				}
				else{
					temp2 += '1';
				}
			}
		}
		len2 = strlen(temp2.c_str());
		remval = len3-len2;
        if(remval==len3){
            while(str[s1]=='0'){
                s1++;
            }
        }
		for(i=s1;i<s1+remval;i++){
			temp2 += str[i];
		}
		len2 = strlen(temp2.c_str());

		s1 += remval;
		temp1 = temp2;
		if(len2<len3){
			return;
		}
	}
}


int main(){

	cout<<"Enter the initial string of data:";
	cin>>initial1;
	main1 = initial1;

	cout<<"Enter the generator:";
	cin>>generator;
    len3 = strlen(generator.c_str());

	for(i=0;i<len3-1;i++){
		initial1 += '0';
	}
	len1 = strlen(initial1.c_str());

	//Computing the CRC code for the first string
	compute_CRC(initial1);
    rem1 = temp2;
	if(strlen(rem1.c_str())<len3-1){
        diff = len3-1-strlen(rem1.c_str());
        for(i=0;i<diff;i++){
            main1 += '0';
        }
	}
	//Concatenating the string and the check code
	final1 = main1 + rem1;

	cout<<"The check code for the given string: "<<rem1<<endl;
	cout<<"The given string along with the check code: "<<final1<<endl;
    cout<<endl;

	cout<<"Enter modified string of data:";
	cin>>initial2;
    main2 = initial2;

	for(i=0;i<len3-1;i++){
		initial2 += '0';
	}
	len1 = strlen(initial2.c_str());

	compute_CRC(initial2);
    rem2 = temp2;
	if(strlen(rem2.c_str())<len3-1){
        diff = len3-1-strlen(rem2.c_str());
        for(i=0;i<diff;i++){
            main2 += '0';
        }
	}
	//Concatenating the string and the check code
	final2 = main2 + rem2;

	cout<<"The check code for the modified string: "<<rem2<<endl;
	cout<<"The modified string along with the check code: "<<final2<<endl;
	cout<<endl;

	//Comparing both the strings
	if(strcmp(final1.c_str(),final2.c_str())==0){
        cout<<"No error found";
	}
	else{
        cout<<"Error detected";
	}

return 0;
}
