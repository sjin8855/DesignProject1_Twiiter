#include "Twit.h"

Twit::Twit()
{
	index = 0;
	user_index = 0;
	first_user_index = 0;
	time = 0;
}

int Twit::get_index()	// �� �ε��� ����
{
	return index;
}

int Twit::get_user_index()	// ���� �ε��� ����
{
	return user_index;
}
	
string Twit::get_str()	// �� ���� ����
{
	return str;
}

void Twit::set_index(int _index)	//�� �ε��� �Է�
{
	index = _index;
}

void Twit::set_user_index(int _user_index)	// ���� �ε��� �Է�
{
	user_index = _user_index;
}

void Twit::set_str(string _str)	// �� ���� �Է�
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