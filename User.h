#pragma once
#include "Timeline.h"

class User
{
public:
	User();

public:
	int get_user_id();	// ID 리턴
	string get_user_password();	// PW 리턴
	int get_user_index();	// 인덱스 리턴
	string get_user_name();	// 이름 리턴
	int get_following_count();	// Following count 리턴
	int get_follower_count();	// Follower count 리턴
	void set_user_id(int _id);	// ID 입력
	void set_user_password(string _password);	// PW 입력
	void set_user_name(string _name);	// 이름 입력
	void set_user_index(int _index);	//인덱스 입력
	void set_following_count(int count);	// Following count 입력
	void set_follower_count(int count);	// Follower count 입력
	

	void write_twit(Twit &twit);	// user_line에 twit 추가
	void remove_twit(int &index); // user_line에 index제거
	vector<Twit> get_twit();	// Twit 리턴

private:
	Timeline ti;	// 타임라인
	int user_index;	// 유저 인덱스
	int user_id;	// 아이디
	string user_password;	//비번
	string user_name;	//이름
	int following_count;	//Following 숫자
	int follower_count;	//Follower 숫자 
};

