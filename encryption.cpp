#include<bits/stdc++.h>
using namespace std;
int main()
{
	cout<<"Enter password."<<endl<<"-> ";
	string pass;
	cin>>pass;
	if(pass=="14437")
	{
		cout<<"Enter option numbers"<<endl<<endl;
		srand(time(0));
		while(1)
		{
			int key;
			cout<<"\t1-> Encrypt."<<endl<<"\t2-> Decrypt."<<endl<<"\t3-> Exit."<<endl<<"-> ";
			cin>>key;
			switch (key)
			{
				case (1):
				{
					string temp="qaMwzL0PeNxKdO2BfJrtgIVvH3UCbujGh5nXFTZ7mkRSiEoA8WpQ";
					string numbers="9s4cy6YD1l";
					int k = (rand()-1)%1000+1;
					if(k&1)
						reverse(temp.begin(),temp.end());
					for(int i=0; i<=51; i++)
						for(int j=0; j<k; j++)
							next_permutation(temp.begin(),temp.begin()+i);
					for(int i=0; i<k*1000;i++)
						next_permutation(numbers.begin(),numbers.end());
					if(k&1)
						reverse(numbers.begin(),numbers.end());
					unordered_map<char, char> mp;
					for(int i=0; i<=25; i++)
						mp[(char)(i+65)]=temp[i];
					for(int i=26; i<=51; i++)
						mp[(char)(i-26+97)]=temp[i];
					for(int i=0;i<=9; i++)
						mp[(char)(48+i)]=numbers[i];
					string code="", input, word;
					ifstream file("text.txt");
					getline(file,input);
					file.close();
					istringstream stream(input);
					int cnt = 0;
					int dup=k;
					string knum;
					while(dup)
					{
						knum+=(char)(48+dup%10);
						dup/=10;
						cnt++;
					}
					reverse(knum.begin(),knum.end());
					code+=(char)(48+cnt);
					code+=knum;
					int jump=0;
					while(stream>>word)
					{
						for(char c : word)
							if(mp[c])
								code+=mp[c];
							else
								code+=c;
						code+=(char)(35+jump);
						jump=(jump+1)%3;
					}
					cout<<endl<<"ENCRYPTED!!!"<<endl<<endl;
					ofstream file2("text.txt");
					file2<<code<<endl;
					file2.close();
					break;
				}
				case (2):
				{
					string temp="qaMwzL0PeNxKdO2BfJrtgIVvH3UCbujGh5nXFTZ7mkRSiEoA8WpQ";
					string numbers="9s4cy6YD1l";
					string input;
					ifstream file("text.txt");
					getline(file,input);
					file.close();
					int cnt=input[0]-48;
					int k=0;
					for(int i=1; i<=cnt; i++)
						k=k*10+input[i]-48;
					if(k&1)
						reverse(temp.begin(),temp.end());
					for(int i=0; i<=51; i++)
						for(int j=0; j<k; j++)
							next_permutation(temp.begin(),temp.begin()+i);
					for(int i=0; i<k*1000;i++)
						next_permutation(numbers.begin(),numbers.end());
					if(k&1)
						reverse(numbers.begin(),numbers.end());
					unordered_map<char, char> mp;
					for(int i=0;i<=25;i++)
						mp[temp[i]]=(char)(i+65);
					for(int i=26; i<=51; i++)
						mp[temp[i]]=(char)(i+97-26);
					for(int i=0; i<=9; i++)
						mp[numbers[i]]=(char)(i+48);
					mp['#']=mp['$']=mp['%']=' ';
					int n=input.size();
					string code="";
					for(int i=cnt+1; i<=n-1; i++)
					{
						if(mp[input[i]])
							code+=mp[input[i]];
						else
							code+=input[i];
					}
					cout<<endl<<"Decrypted!!!"<<endl<<endl;
					ofstream file2("text.txt");
					file2<<code<<endl;
					file2.close();
					break;
				}
				case (3): exit(0);
				default:
					{
						cout<<"Invalid option."<<endl;
						break;
					}
			}
		}
	}
	else
	{
		cout<<"GET LOST!!!"<<endl;
	}
	getchar();
}
