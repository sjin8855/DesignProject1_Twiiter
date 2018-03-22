#include "User.h"

User::User()
{
	user_index = 0;
	user_id = 0;
	following_count = 0;
	follower_count = 0;
}


int User::get_user_id()	// ID ����
{
	return user_id;
}

string User::get_user_password()	// PW ����
{
	return user_password;
}

int User::get_user_index()	// �ε��� ����
{
	return user_index;
}

string User::get_user_name()	// �̸� ����
{
	return user_name;
}

int User::get_following_count()	// Following count ����
{
	return following_count;
}

int User::get_follower_count()	// Follower count ����
{
	return follower_count;
}

void User::set_user_id(int _id)	// ID �Է�
{
	user_id = _id;
}

void User::set_user_password(string _password)	// PW �Է�
{
	user_password = _password;
}

void User::set_user_name(string _name)	// �̸� �Է�
{
	user_name = _name;
}

void User::set_user_index(int _index)	//�ε��� �Է�
{
	user_index = _index;
}

void User::set_following_count(int count)	// Following count �Է�
{
	following_count = count;
}

void User::set_follower_count(int count)	// Follower count �Է�
{
	follower_count = count;
}

void User::write_twit(Twit &twit)	// user_line�� twit �߰�
{
	ti.write_twit(twit);
}

void User::remove_twit(int &index) // user_line�� index����
{
	ti.remove_twit(index);
}

vector<Twit> User::get_twit()	// Twit ����
{
	return ti.get_twit();
}

