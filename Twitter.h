#pragma once
#include "SocialGraph.h"
#include <Windows.h>
#include <string>
#include <istream>

class Twitter
{
public:
	Twitter();

// <11���� ��� ����>
public: 
	void login(int _user_id, string _pass_word);	//�α���
	void logout();	// �α׾ƿ�
	void add_user(int _user_id, string _pass_word, string _name);	// ����� �߰�
	void write_tweet();	// Ʈ�� �Է�
	void remove_twit();	// Ʈ�� ����
	void visit_timeline(int id);	// ���̵�� Ÿ�Ӷ����� �� �� �ִ�
	void request_follow();	// Following ��û
	void sort_follower();	// Follow_Count �������� ��������
	void block_follow();	// ������ ������� Ÿ�Ӷ����� �� �� ����
	void re_tweet();

public:
	void print_user_relation();	//	current_user ���赵 ���
	void print_user_timeline(); //	current_user Ÿ�Ӷ��� ��½� Class Twit::index ������������ ���
	void print_Twitter_menu();	//	Twitter�޴� ���
	void print_Tweeter_menu();	//	Tweeter�޴� ���
	void print_interface();		//	interface�޴� ���

private:
	SocialGraph graph;
	User* current_user;	// ���� �����
	

};

