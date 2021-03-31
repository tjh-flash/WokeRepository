#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Log
{
public:
	~Log();
	static Log*  getInstance()
	{
		if (ptr == nullptr)
			ptr = new Log();
		return  ptr;
	}
	template<class T>
	static void debug( const vector<T> &data) {
		for (auto it : data)
			cout << it << " ";
		cout << endl;
	}

	template<class T>
	static void debug(const char* tille, const vector<T> &data) {
		cout << "#Debug :" << tille<<" " ;
		debug(data);

		//for (auto it : data)
		//	cout << it << " ";
		//cout << endl;
	}

	template<class T>
	static void Erron(const vector<T> &data) {
		for (auto it : data)
			cerr << it << " ";
		cerr << endl;
	}

private:
	Log();

private:
	static Log* ptr;
};
