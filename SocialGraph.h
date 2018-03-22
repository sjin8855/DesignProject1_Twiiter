#pragma once
#include "User.h"
#include <fstream>
class SocialGraph
{
public:
	SocialGraph();

public:
	void load_user();	// ����� �ε�
	void save_user();	// ����� ����
	void load_relation();	//	���赵 �ε�
	void save_relation();	// ���赵 ����
	void load_timeline(); // Ÿ�Ӷ��� �ε�
	void save_timeline();	// Ÿ�Ӷ��� ����
	void load_time();	// �ð� �ε�
	void save_time();	// �ð� ����

public:
	User* login(int _user_id, string _pass_word);	// �α���
	User* add_user(int _user_id, string _pass_word, string _name);	// ȸ�� �߰�
	void request_follow(int _index, int target_index);	// Following ��û
	void block_follow(int _index, int target_index);	// Follower ����
	int get_twit_count();	// Ʈ�� �� ���� ����
	void add_twit_count();	// Ʈ�� ��ȣ 1����
	bool re_tweet(int _index, int target_index,int value);		//��Ʈ��

public:
	void print_user_relation(int index);	// ������� Follower, Following
	void print_user_timeline(int index);	// ������� Timeline ���
	void print_visit_timeline(int id);	// �Է��� ID�� Timeline ���
	void print_sort_follow();	// ������� Follower_count �������� �������� ����
	void print_me_timeline(int index);
	void print_else_timeline(int index, int &value);

private:
	vector<User*> array_user;	// �ε�� �����
	int** array_relation;	// �������
	int twit_count;	// Ʈ�� �� ����, �� ��ȣ(Class Twit::index)
	int** time_relation;	// �ð� �������
};

