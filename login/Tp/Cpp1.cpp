#include <iostream>
#include <vector>
#include <fstream>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int maxSize = 0;
int minSize = 0;
vector<string> inStrings;
vector<int> strPosi;

fstream write;
string outStrings;


void filling(int starPosi, int endPosi)
{
	for(int i=0; i<10; i++)
	{
		if(starPosi < endPosi)
		{
			outStrings[starPosi] = static_cast<char>(i+'0');
			filling(starPosi+1, endPosi);
			
		}
		else
		{
			write << outStrings << endl;
			return;
		}
	}
	return;
}


void bitDecied()
{
	int oldSize = outStrings.length();
	
	for (int i=minSize; i<=maxSize; i++)
	{
		if(oldSize > i)
			continue;
		else if(oldSize < i)
		{
			outStrings.append(i-oldSize,'\0');
			filling(oldSize,i);
		}
		else
		{
			write << outStrings << endl;
		}
	}
}

int wordsGroup(int posi,int wordsNum)
{
//		cout << posi<<" "<<wordsNum <<  endl;
//		system("pause");	 
	if(wordsNum != 0)
	{
		wordsNum--;
		for(int i=0; i<inStrings.size(); i++)
		{
			strPosi[posi] = i;
			wordsGroup(posi+1,wordsNum);
		}
	}
	else
	{
		outStrings.clear();
		for(int j=0; j<posi; j++)
			outStrings.append(inStrings[strPosi[j]]);		
		bitDecied();
	}

	return 0;
}


int main(int argc, char** argv) {
	
	write.open("./data/code.txt", ios::out);
	if(!write)
	{
		printf("data writ error"); 
	}
		
	write << "hello "<< endl;
	
//	cout << "请输入字符串以@结束"<<endl;
//	string s;
//	
//	do 
//	{
//		cin >> s;
//		inStrings.push_back(s);
//	}
//	while(s != "@");
//	inStrings.pop_back();
//	
//	cout << "请输入最短和最长位数" << endl;
//	cin >> minSize >> maxSize ;
//	 
//	for(int i=1; i<=inStrings.size(); i++)
//	{
//		strPosi.push_back(0);
//		wordsGroup(0,i);
//	}
//	
//	cout <<"hello" <<  endl;
//	system("pause");	 
	write.close();
	return 0;
}