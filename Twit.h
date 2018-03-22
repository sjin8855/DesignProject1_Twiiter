#pragma once
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Twit
{
public:
	Twit();

public:
	int get_index();	// 글 인덱스 리턴
	int get_user_index();	// 유저 인덱스 리턴
	string get_str();	// 글 내용 리턴
	int get_first_user_index();
	int get_post_time();
	void set_index(int _index);	//글 인덱스 입력
	void set_user_index(int _user_index);	// 유저 인덱스 입력
	void set_str(string _str);	// 글 내용 입력
	void set_first_user_index(int _index);
	void set_post_time(int _time);

private:
	int index;	// 글 인덱스
	int user_index;	// 유저 인덱스
	string str;	// 글내용
	int first_user_index;
	int time;
};

