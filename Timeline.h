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
	vector<Twit> get_twit();	// user_twit 飘拉 府畔
	void write_twit(Twit& twit);	// twit 飘拉 涝仿
	void remove_twit(int &index);	// index 飘拉 力芭
	
private:
	vector<Twit> user_twit;	// 荤侩磊 飘拉
};

