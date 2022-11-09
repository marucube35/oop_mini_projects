#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define CSV "log.csv"
#define TXT "log.txt"
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Time {
public:
	static string toString(string del = " ") {
		time_t now = time(0);
		tm* ltm = localtime(&now);
		stringstream builder;

		builder << 1900 + ltm->tm_year << del;
		builder << ltm->tm_mon << del;
		builder << ltm->tm_mday << del;
		builder << ltm->tm_hour << del;
		builder << ltm->tm_min << del;
		builder << ltm->tm_sec;

		return builder.str();
	}
};

class MySimpleLogger {
public:
	virtual MySimpleLogger* createInstance() {
		MySimpleLogger* result = nullptr;
		return result;
	};
	virtual void write(string) {};
};

class MySimpleConsoleLogger : public MySimpleLogger {
private:
	inline static MySimpleConsoleLogger* _instance = nullptr;
	string _time;

	MySimpleConsoleLogger() {
	}

public:
	static MySimpleConsoleLogger* createInstance()
	{
		if (nullptr == _instance)
		{
			_instance = new MySimpleConsoleLogger();
		}
		return _instance;
	}

	void write(string msg)
	{
		_time = Time::toString();
		cout << _time << " " << msg << endl;
	}
};
