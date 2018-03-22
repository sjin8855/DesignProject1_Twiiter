#include "User.h"

User::User()
{
	user_index = 0;
	user_id = 0;
	following_count = 0;
	follower_count = 0;
}


int User::get_user_id()	// ID 리턴
{
	return user_id;
}

string User::get_user_password()	// PW 리턴
{
	return user_password;
}

int User::get_user_index()	// 인덱스 리턴
{
	return user_index;
}

string User::get_user_name()	// 이름 리턴
{
	return user_name;
}

int User::get_following_count()	// Following count 리턴
{
	return following_count;
}

int User::get_follower_count()	// Follower count 리턴
{
	return follower_count;
}

void User::set_user_id(int _id)	// ID 입력
{
	user_id = _id;
}

void User::set_user_password(string _password)	// PW 입력
{
	user_password = _password;
}

void User::set_user_name(string _name)	// 이름 입력
{
	user_name = _name;
}

void User::set_user_index(int _index)	//인덱스 입력
{
	user_index = _index;
}

void User::set_following_count(int count)	// Following count 입력
{
	following_count = count;
}

void User::set_follower_count(int count)	// Follower count 입력
{
	follower_count = count;
}

void User::write_twit(Twit &twit)	// user_line에 twit 추가
{
	ti.write_twit(twit);
}

void User::remove_twit(int &index) // user_line에 index제거
{
	ti.remove_twit(index);
}

vector<Twit> User::get_twit()	// Twit 리턴
{
	return ti.get_twit();
}

