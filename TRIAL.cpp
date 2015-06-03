#include<iostream>
#include<cstdio>
#include<cmath>
#include<map>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
#define gi(a) scanf("%d",&a);
#define ll long long
#define PAIR pair<int,int>
#define MP(a,b)	make_pair(a,b)
int main(){
	int T;
	gi(T);
	while(T--){
		int m,n,tmp=0,i,j;
		vector<PAIR> entries;
		gi(m);gi(n);
		char graph[25][25];
		string s;
		bool flag=0;
		for(i=0;i<m;i++){
			cin>>s;
			for(j=0;j<n;j++){
				if((i==0 || i==m-1 || j==0 || j==n-1) && s[j]=='.'){
					entries.push_back(MP(i,j));
					tmp++;
				}
				graph[i][j]=s[j];
			}
		}
		if(tmp!=2){
			cout<<"invalid\n";
		}
		else{
			flag=0;
			stack <PAIR> dfss;
			PAIR temp,dest;
			bool visited[25][25]={{0}};
			dest=MP(entries.at(1).first,entries.at(1).second);
			dfss.push(MP(entries.at(0).first,entries.at(0).second));
			while(!dfss.empty()){
				temp=dfss.top();
				dfss.pop();
				if(visited[temp.first][temp.second] || temp.first>=m || temp.first<0 || temp.second>=n || temp.second<0){
					continue;
				}
				if(temp.first==dest.first && temp.second==dest.second){
					flag=1;
					break;
				}
				visited[temp.first][temp.second]=1;
				if(graph[temp.first][temp.second]=='#'){
				 	continue;
				}
				dfss.push(MP(temp.first+1,temp.second));
				dfss.push(MP(temp.first-1,temp.second));
				dfss.push(MP(temp.first,temp.second+1));
				dfss.push(MP(temp.first,temp.second-1));
			}
			if(flag)	cout<<"valid\n";
			else		cout<<"invalid\n";
		}
	}
	return 0;
}
