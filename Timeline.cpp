#include "Timeline.h"

Timeline::Timeline()
{

}

vector<Twit>Timeline:: get_twit()	// user_twit 飘拉 府畔
{
	return user_twit;
}	

void Timeline::write_twit(Twit& twit)	// twit 飘拉 涝仿
{
	user_twit.push_back(twit);
}

void Timeline::remove_twit(int &index)	// index 飘拉 力芭
{
	for(int i=0; i<user_twit.size(); i++)
		if(user_twit[i].get_index() == index)
			user_twit.erase(user_twit.begin() + i);
}


