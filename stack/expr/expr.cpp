<<<<<<< HEAD
#include<bits/stdc++.h>
=======
#include <iostream>
#include <fstream>
#include <
>>>>>>> 088ce7671c6ffa406bb7c91f8b0a29b5745ec605

using namespace std;

int main(){
	ifstream fin("expr.in");
	ofstream fout("expr.out");

	char s[20];
	fin>>s;
	int l = strlen(s);
	s[l] = ')';
<<<<<<< HEAD
	stack<node> n;
	stack<char> q;
	q.push('(');

	for(int i = 0;i <= l;i++){
		if(s[i] == '('){
			q.push(s[i]);
		}else if(s[i] == '1' || s[i] == '0'){
			node temp;
			temp.v = s[i] - '0';
			temp.y = 0;
			temp.h = 0;
			n.push(temp);
		}else{
			bool fff = false;
			if(s[i] == ')'){
				fff = true;
				if(q.top() = '('){
					q.pop();
				}
			}
			if(){}
			if(fff = false){
				q.pop();
			}
		}
	}
	fout<<n.top().v<<endl;
	fout<<n.top().y<<" "<<n.top().h<<endl;
=======

	// 0&(1|0)|(1|1|1&0)
	for(int i = 0; i<=l;i++){
		fout<<s;
	}


	fin.close();
	fout.close();

>>>>>>> 088ce7671c6ffa406bb7c91f8b0a29b5745ec605
	return 0;
}
