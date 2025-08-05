#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	// 1. 打开文件
	ifstream fin("number.in"); // fstream class OOP面向对象的class类 -> object对象 Person类 Richard对象
	ofstream fout("number.out"); // fstream class OOP面向对象的class类 -> object对象 Person类 Richard对象
	// 2.接收字符串 
	string str; // 定义一个字符串str a,b  int a,b;
	fin>>str;
	// 3.for if else result += 1
	int result = 0; // 保存1有多少个
	for(int i = 0;i < str.length();i++){ // 10100110
		if(str[i] == '1'){ // str[0],str[1],...,str[7]
			result += 1;
		}
	}
	fout<<result;
	fin.close();
	fout.close();
	return 0;
}
