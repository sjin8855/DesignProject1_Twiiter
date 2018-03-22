#pragma once
#include "Twit.h"
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Timeline
{
public:
	Timeline();
	
public:
	vector<Twit> get_twit();	// user_twit Ʈ�� ����
	void write_twit(Twit& twit);	// twit Ʈ�� �Է�
	void remove_twit(int &index);	// index Ʈ�� ����
	
private:
	vector<Twit> user_twit;	// ����� Ʈ��
};

