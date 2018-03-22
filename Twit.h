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
	int get_index();	// �� �ε��� ����
	int get_user_index();	// ���� �ε��� ����
	string get_str();	// �� ���� ����
	int get_first_user_index();
	int get_post_time();
	void set_index(int _index);	//�� �ε��� �Է�
	void set_user_index(int _user_index);	// ���� �ε��� �Է�
	void set_str(string _str);	// �� ���� �Է�
	void set_first_user_index(int _index);
	void set_post_time(int _time);

private:
	int index;	// �� �ε���
	int user_index;	// ���� �ε���
	string str;	// �۳���
	int first_user_index;
	int time;
};

