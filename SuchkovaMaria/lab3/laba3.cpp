#include "stdafx.h"
#include "fstream"
using namespace std;
#include "iostream"
using namespace std;
#include "string"
int CalculationParenthesis(string, int);
int Factorial(int);
int Calclulation(string s){
	int result=0, i=s.length(), k=1, number=0,c;
	while (i>=0){
		if (s[i]>='0'&&s[i]<='9'){
			while (s[i]>='0'&&s[i]<='9'){
				c=s[i];
				number+=k*c;
				k*=10;
				i--;
			}
			if (s[i]=='+') 
				result+=number;
			else 
				result-=number;	
		}
		else
			if (s[i]==')'){
				i--;
				result+=CalculationParenthesis(s,i);
				do
					i--;
				while (s[i]!='(');
			}
			else
				if (s[i]=='!')
					if (s[i-1]==')'){
						i--;
						result+=Factorial(CalculationParenthesis(s,i));
						do
							i--;
						while (s[i]!='(');
					}
					else{
						number=0;k=1;
						while (s[i]>='0'&&s[i]<='9'){
							c=s[i];
							number+=k*c;
							k*=10;
							i--;
						}
						result+=Factorial(number);
					}
	i--;
	}
	return result;
}
int CalculationParenthesis(string s, int i){
	int number=0,k=1,c,res=0;
	while (s[i]!='('){
		if (s[i]==')'){
			i--;
			res+=CalculationParenthesis(s, i);
		}
		else
		{
			number=0;k=1;
			while (s[i]>='0'&&s[i]<='9'){
				c=s[i];
				number+=k*c;
				k*=10;
				i--;
			}
			if (s[i]=='+') 
				res+=number;
			else 
				res-=number;
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
	//cout<<"Enter the name of the file"<<"\n";
	//string filename;
	//cin>>filename;
	//ifstream fin;
	//fin.open("filename");
	//if (fin.is_open())
	//{
		string str;
		//fin>>str;
		cin>>str;
		int i=0,k=1,p_open=0,p_close=0;
		while (str[i]!='\0'&&k)
		{
			if ((str[i]>='0'&&str[i]<='9')||str[i]=='('||str[i]==')'||str[i]=='+'||str[i]=='-'||str[i]=='!')
			{
				if (str[i]=='(') p_open++;
				if (str[i]==')') p_close++;
			}
			else k=0;
			i++;
		}
		if (k==0||p_open!=p_close)
			cout<<"\n"<<"Wrong information";
		else
			cout<<"\n"<<Calclulation(str);
	//}	
	//else cout<<"\n" <<"File not found"<<"\n";
	//fin.close();
	system("pause");
}