#include "Timeline.h"

Timeline::Timeline()
{

}

vector<Twit>Timeline:: get_twit()	// user_twit Ʈ�� ����
{
	return user_twit;
}	

void Timeline::write_twit(Twit& twit)	// twit Ʈ�� �Է�
{
	user_twit.push_back(twit);
}

void Timeline::remove_twit(int &index)	// index Ʈ�� ����
{
	for(int i=0; i<user_twit.size(); i++)
		if(user_twit[i].get_index() == index)
			user_twit.erase(user_twit.begin() + i);
}


