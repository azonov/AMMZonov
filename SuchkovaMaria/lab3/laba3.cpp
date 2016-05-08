#include "stdafx.h"
#include "fstream"
#include "iostream"
using namespace std;
#include "string"
int CalculationParenthesis(string, int);
int Factorial(int);
int Calclulation(string s){
	char op;
	int num1=0, num2=0, i=s.length()-1, k=1,c, result=0;
	while (i>=0){
		if (s[i]>='0'&&s[i]<='9'){
			k=1,num1=0;
			while (i>=0&&s[i]>='0'&&s[i]<='9'){
				c=s[i]-'0';
				num1+=k*c;
				k*=10;
				i--;
			}
			if (i>=0) op=s[i]; i--; k=1;
			if (i>=0&&s[i]>='0'&&s[i]<='9'){
				k=1;num2=0;
				while (i>=0&&s[i]>='0'&&s[i]<='9'){
					c=s[i]-'0';
					num2+=k*c;
					k*=10;
					i--;
				}
			}
			else
				if (i>=0&&s[i]==')'){
					num2=0;
					i--;
					num2=CalculationParenthesis(s,i);
					do
						i--;
					while (i>=0&&s[i]!='(');
				}
				else
					if (i>0&&s[i]=='!'){
						num2=0;i--;
						if (i>=0&&s[i-1]==')'){
							i--;
							num2=Factorial(CalculationParenthesis(s,i));
							do
								i--;
							while (i>=0&&s[i]!='(');
						}
						else{
							k=1;num2=0;
							while (i>=0&&s[i]>='0'&&s[i]<='9'){
								c=s[i]-'0';
								num2+=k*c;
								k*=10;
								i--;
							}
						num2=Factorial(num2);
					}
				}				
		}
		if (op='+') result+=num1+num2;
		else result+=num2-num1;
	}
	return result;
}
int CalculationParenthesis(string s, int i){
	int k=1,c,res=0,num1=0, num2=0;
	char op;
	while (i>=0&&s[i]!='('){
		if (i>=0&&s[i]==')'){
			i--;
			res+=CalculationParenthesis(s, i);
		}
		else
		{
			if (s[i]>='0'&&s[i]<='9'){
			k=1,num1=0;
			while (i>=0&&s[i]>='0'&&s[i]<='9'){
				c=s[i]-'0';
				num1+=k*c;
				k*=10;
				i--;
			}
			if (i>=0){
				op=s[i]; i--; k=1;
				if (i>=0&&s[i]>='0'&&s[i]<='9'){
					k=1;num2=0;
					while (i>=0&&s[i]>='0'&&s[i]<='9'){
						c=s[i]-'0';
						num2+=k*c;
						k*=10;
						i--;
					}
				}
				else
					if (i>=0&&s[i]==')'){
						num2=0;
						i--;
						num2=CalculationParenthesis(s,i);
						do
							i--;
						while (i>=0&&s[i]!='(');
					}
					else
						if (i>0&&s[i]=='!'){
							num2=0;i--;
							if (i>=0&&s[i-1]==')'){
								i--;
								num2=CalculationParenthesis(s,i);
								do
									i--;
								while (i>=0&&s[i]!='(');
							}
							else{
								k=1;num2=0;
								while (i>=0&&s[i]>='0'&&s[i]<='9'){
									c=s[i]-'0';
									num2+=k*c;
									k*=10;
									i--;
								}								
							}
							num2=Factorial(num2);
						}				
				}
		}
	}
}
return res;
}
int Factorial(int n){
	int f=1;
	for (int i=2;i<=n;i++)
		f*=i;
	return f;
}
int main()
{
	cout<<"Enter the name of the file"<<"\n";
	string filename;
	cin>>filename;
	ifstream fin;
	fin.open("filename");
	if (fin.is_open())
	{
		string str;
		fin>>str;
		
		int i=0,k=1,p_open=0,p_close=0,j=0;
		while (str[j]!='\0')/*for(int j=0;j<=str.length();j++)*/
		{
			if ((str[j]>='0'&&str[j]<='9')||str[j]=='('||str[j]==')'||str[j]=='+'||str[j]=='-'||str[j]=='!')
			{
				if (str[j]=='(') p_open++;
				if (str[j]==')') p_close++;
			}
			else k=0;
			j++;
		}
		if (k==0||p_open!=p_close)
			cout<<"\n"<<"Wrong information";
		else
			cout<<"\n"<<Calclulation(str);
	}	
	else cout<<"\n" <<"File not found"<<"\n";
	fin.close();
	system("pause");
}