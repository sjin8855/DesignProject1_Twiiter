#include "Twit.h"

Twit::Twit()
{
	index = 0;
	user_index = 0;
	first_user_index = 0;
	time = 0;
}

int Twit::get_index()	// 글 인덱스 리턴
{
	return index;
}

int Twit::get_user_index()	// 유저 인덱스 리턴
{
	return user_index;
}
	
string Twit::get_str()	// 글 내용 리턴
{
	return str;
}

void Twit::set_index(int _index)	//글 인덱스 입력
{
	index = _index;
}

void Twit::set_user_index(int _user_index)	// 유저 인덱스 입력
{
	user_index = _user_index;
}

void Twit::set_str(string _str)	// 글 내용 입력
{
	str = _str;
}

int Twit::get_first_user_index()
{
	return first_user_index;
}

void Twit::set_first_user_index(int _index)
{
	first_user_index = _index;
}

int Twit::get_post_time()
{
	return time;
}

void Twit::set_post_time(int _time)
{
	time = _time;
}