#pragma once
#include "Timeline.h"

class User
{
public:
	User();

public:
	int get_user_id();	// ID ����
	string get_user_password();	// PW ����
	int get_user_index();	// �ε��� ����
	string get_user_name();	// �̸� ����
	int get_following_count();	// Following count ����
	int get_follower_count();	// Follower count ����
	void set_user_id(int _id);	// ID �Է�
	void set_user_password(string _password);	// PW �Է�
	void set_user_name(string _name);	// �̸� �Է�
	void set_user_index(int _index);	//�ε��� �Է�
	void set_following_count(int count);	// Following count �Է�
	void set_follower_count(int count);	// Follower count �Է�
	

	void write_twit(Twit &twit);	// user_line�� twit �߰�
	void remove_twit(int &index); // user_line�� index����
	vector<Twit> get_twit();	// Twit ����

private:
	Timeline ti;	// Ÿ�Ӷ���
	int user_index;	// ���� �ε���
	int user_id;	// ���̵�
	string user_password;	//���
	string user_name;	//�̸�
	int following_count;	//Following ����
	int follower_count;	//Follower ���� 
};

