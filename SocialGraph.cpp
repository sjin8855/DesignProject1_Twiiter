#include "SocialGraph.h"

SocialGraph::SocialGraph()
{                        
	load_user();
	load_relation();
	load_time();
	load_timeline();
}

void SocialGraph::load_user()	// 사용자 로드
{
	int index, id, following_count, follower_count;
	string password, name;
	ifstream inf("user.txt");
	string record;
	while(getline(inf, record))
	{
		User* user = new User();
		stringstream spacing(record);
		spacing >>index >> id >> password >> name >>
			following_count >> follower_count ;
		user->set_user_index(index);
		user->set_user_id(id);
		user->set_user_password(password);
		user->set_user_name(name);
		user->set_following_count(following_count);
		user->set_follower_count(follower_count);
		array_user.push_back(user);
	}
	inf.close();

}

void SocialGraph::save_user()	// 사용자 저장
{
	ofstream ofs;
	ofs.open("user.txt");
	for(int i=0; i<array_user.size(); i++)
	{
		ofs << endl <<array_user[i]->get_user_index()<<' '<<array_user[i]->get_user_id()<<' '
			<<array_user[i]->get_user_password()<<' '<<array_user[i]->get_user_name()<<' '
			<<array_user[i]->get_following_count()<<' '<<array_user[i]->get_follower_count();
	}
	ofs.close();
}

void SocialGraph::load_relation()	//	관계도 로드
{
	int temp = array_user.size();
	array_relation = new int*[temp];

	for(int i=0; i<temp; i++)
		array_relation[i] = new int[temp];

	ifstream inf("relation.txt");

	for ( int i = 0 ; i < temp; i++ )
	{
		for ( int j = 0 ; j < temp; j++ )
		{	
			if (!inf.eof ())
				inf >> array_relation[i][j];
			else
				cout << endl;
		}
	}
	inf.close();
}

void SocialGraph::save_relation()	// 관계도 저장
{
	int temp = array_user.size();
	ofstream ofs("relation.txt");
	for(int i=0; i<temp; i++)
	{
		ofs<<endl;
		for(int j=0; j<temp; j++)
			ofs << ' '<<array_relation[i][j];
	}
	ofs.close();
}

void SocialGraph::load_timeline() // 타임라인 로드
{
	ifstream ifs("timeline.txt");
	Twit t_line;
	int index, user_index, first_index, time;
	string str;
	twit_count=0;

	while(!ifs.eof()){
		ifs>>index>>user_index>>first_index>>time;
		for(int i=0; i<array_user.size(); i++)
		{
			if(user_index == array_user.at(i)->get_user_index())
			{
				t_line.set_index(index);
				t_line.set_user_index(user_index);
				t_line.set_first_user_index(first_index);
				t_line.set_post_time(time);
				getline(ifs,str);
				t_line.set_str(str);
				array_user.at(i)->write_twit(t_line);
				twit_count++;
			}
		}
	}
	ifs.close();
}

void SocialGraph::save_timeline()	// 타임라인 저장
{
	ofstream outf("timeline.txt");
	vector<Twit> twit;
	for(int i=0; i<array_user.size(); i++) 
	{
		twit = array_user.at(i)->get_twit();
		for(int j=0; j<twit.size(); j++)
		{
			outf<< endl 
				<<twit.at(j).get_index() << ' ' 
				<< twit.at(j).get_user_index() << ' ' 
				<< twit.at(j).get_first_user_index()<<' '
				<< twit.at(j).get_post_time()<<' '
				<< twit.at(j).get_str();
		}
	}
}

void SocialGraph::load_time()	// 시간 로드
{
	int temp = array_user.size();
	time_relation = new int*[temp];

	for(int i=0; i<temp; i++)
		time_relation[i] = new int[temp];

	ifstream inf("time.txt");

	for ( int i = 0 ; i < temp; i++ )
	{
		for ( int j = 0 ; j < temp; j++ )
		{	
			if (!inf.eof ())
				inf >> time_relation[i][j];
			else
				cout << endl;
		}
	}
	inf.close();
}

void SocialGraph::save_time()	// 시간 저장
{
	int temp = array_user.size();
	ofstream ofs("time.txt");
	for(int i=0; i<temp; i++)
	{
		ofs<<endl;
		for(int j=0; j<temp; j++)
			ofs << ' '<<time_relation[i][j];
	}
	ofs.close();
}

User* SocialGraph::login(int _user_id, string _pass_word)	// 로그인
{
	for(int i=0; i<array_user.size(); i++)
	{
		if(array_user[i]->get_user_id() == _user_id)
		{
			if(array_user[i]->get_user_password() == _pass_word)
				return array_user[i];
		}
	}
	return NULL;
}	

User* SocialGraph::add_user(int _user_id, string _pass_word, string _name)	// 회원 추가
{
	User* user = new User();
	int size = array_user.size();
	for(int i=0; i<array_user.size(); i++)
		if(_user_id == array_user[i]->get_user_id())
			return NULL;

	user->set_user_index(size);
	user->set_user_id(_user_id);
	user->set_user_password(_pass_word);
	user->set_user_name(_name);
	user->set_following_count(0);
	user->set_follower_count(0);
	array_user.push_back(user);


	int temp = array_user.size();
	int** _arr;

	_arr = new int*[temp-1]; 
	for(int i=0; i<temp-1; i++)
		_arr[i] = new int[temp-1];

	for(int i=0; i<temp-1; i++)
		for(int j=0; j<temp-1; j++)
			_arr[i][j] = array_relation[i][j];

	array_relation = new int*[temp];
	for(int i=0; i<temp; i++)
		array_relation[i] = new int[temp];

	for(int i=0; i<temp; i++)
		for(int j=0; j<temp; j++)
			array_relation[i][j] = 0;

	for(int i=0; i<temp-1; i++)
		for(int j=0; j<temp-1; j++)
			array_relation[i][j] = _arr[i][j];

	save_user();  
	save_relation();
	return user;
}

void SocialGraph::request_follow(int _index, int target_index)	// Following 신청//target_index= id입력받음
{
	for(int i=0; i<array_user.size(); i++)
	{
		if(array_user[i]->get_user_id() == target_index)
		{
			time_t _time;
			if(array_relation[_index][i] == 2)
				cout<<"차단한 상태입니다. 신청할 수 없습니다."<<endl;

			if(array_relation[i][_index] == 2)
				cout<<"차단당한 상태입니다. 신청할 수 없습니다."<<endl;

			else
			{

				int wercount = array_user[i]->get_follower_count();
				int wingcount = array_user[_index]->get_following_count();
				array_user[i]->set_follower_count(++wercount);
				array_user[_index]->set_following_count(++wingcount);
				array_relation[_index][i] = 1;
				_time = time(NULL);
				time_relation[_index][i] = _time;

			}
		}
	}
}	

void SocialGraph::block_follow(int _index, int target_index)	// Follower 차단
{
	for(int i=0; i<array_user.size(); i++)
	{
		if(array_user[i]->get_user_id() == target_index)
		{
			int wer_count = array_user[i]->get_follower_count();
			int wing_count = array_user[_index]->get_following_count();
			if(array_relation[_index][i]==1)
			{
				array_user[i]->set_follower_count(--wer_count);
				array_user[_index]->set_following_count(--wing_count);
			}
			array_relation[_index][i] = 2;
		}
	}
}	

int SocialGraph::get_twit_count()	// 트윗 총 개수 리턴
{
	return twit_count;
}

void SocialGraph::add_twit_count()	// 트윗 번호 1증가
{
	twit_count++;
}

void SocialGraph::print_user_relation(int index)	// 사용자의 Follower, Following
{
	cout<<"<<Relation print>>"<<endl<<endl;
	cout<<"현재 사용자의 Follow 관계 "<<endl<<endl;

	cout<<"Following : ";
	for(int i=0; i<array_user.size(); i++)
	{
		if(array_relation[index][i]==1)
			cout<<array_user[i]->get_user_id()<<" ";
	}
	cout<<endl<<endl;

	cout<<"Follow : ";
	for(int i=0; i<array_user.size(); i++)
	{
		if(array_relation[i][index]==1)
			cout<<array_user[i]->get_user_id()<<" ";
	}
	cout<<endl<<endl;
}

void SocialGraph::print_user_timeline(int index)	
{
	vector<Twit> temp_twit; 
	vector<int> temp_index; 
	vector<int> _time;
	vector<int> time_index;
	temp_twit.clear();
	temp_index.clear();
	_time.clear();
	time_index.clear();
	temp_index.push_back(index); 

	for(int i=0; i<array_user.size(); i++)
	{
		if(array_relation[index][i] == 1)
			if(array_relation[i][index]!=2)
			{
				temp_index.push_back(array_user[i]->get_user_index());
				_time.push_back(time_relation[index][i]);
				time_index.push_back(array_user[i]->get_user_index());
			}
	}

	for(int i=0; i<temp_index.size(); i++)
	{ 
		int twit_size = array_user[temp_index[i]]->get_twit().size();
		for(int j=0; j<twit_size; j++)
			temp_twit.push_back(array_user[temp_index[i]]->get_twit()[j]);
	}

	for(int i=0; i<temp_twit.size(); i++)
	{
		for(int j=i+1; j<temp_twit.size(); j++)
		{
			if(temp_twit[i].get_index() < temp_twit[j].get_index())
			{
				Twit temp = temp_twit[i];
				temp_twit[i] = temp_twit[j];
				temp_twit[j] = temp;
			}
		}
	}

	print_me_timeline(index);


	for(int j=0; j<_time.size(); j++)
	{

		for(int i=0; i<temp_twit.size(); i++)
		{
			if(temp_twit[i].get_user_index() == time_index[j])
			{
				if(_time[j] < temp_twit[i].get_post_time())
				{

					cout<< "<" << temp_twit[i].get_index() << "> : ";
					if(temp_twit[i].get_first_user_index()!=0)
						cout<<"("<<temp_twit[i].get_first_user_index()<<")";

					cout<<array_user[temp_twit[i].get_user_index()]->get_user_id() 
						<< " :" << temp_twit[i].get_str() << endl;
				}
			}
		}
	}
}

void SocialGraph::print_visit_timeline(int id)	// 입력한 ID의 Timeline 출력
{
	int index;
	for(int i=0; i<array_user.size(); i++)
		if(array_user[i]->get_user_id()==id)
			index = array_user[i]->get_user_index();

	int save_index[1];
	save_index[0] = index;
	vector<Twit> temp_twit;


	cout<<"<<Timeline Print>>"<<endl<<endl;

	temp_twit = array_user[save_index[0]]->get_twit();
	for(int j=0; j<temp_twit.size(); j++)
	{
		cout<<"<"<<temp_twit[j].get_index()<<"> "
			<<array_user[temp_twit[j].get_user_index()]->get_user_id()
			<<" :     "<<temp_twit[j].get_str()<<endl;
	}
	//array_user[id]->get_twit();
}

void SocialGraph::print_sort_follow()	// 사용자의 Follower_count 기준으로 내림차순 정렬
{
	for(int i=0; i<array_user.size(); i++)
	{
		for(int j=i; j<array_user.size(); j++)
		{
			if(array_user[i]->get_follower_count() < array_user[j]->get_follower_count())
			{
				User* temp = array_user[i];
				array_user[i] = array_user[j];
				array_user[j] = temp;
			}
		}
	}

	cout<<"<<Sort Follower>>"<<endl<<endl;
	cout<<"Sort User Follower Count"<<endl<<endl;
	for(int i=0; i<array_user.size(); i++)
	{
		cout<<"ID : "<<array_user[i]->get_user_id()<<" : "
			<<"Follower Count : "<<array_user[i]->get_follower_count()<<endl;
	}
}

void SocialGraph::print_me_timeline(int index)
{
	vector<Twit> temp_twit;
	temp_twit.clear();
	int save_index[1];
	save_index[0] = index;


	for(int i=0; i<temp_twit.size(); i++)
	{
		for(int j=i+1; j<temp_twit.size(); j++)
		{
			if(temp_twit[i].get_index() < temp_twit[j].get_index())
			{
				Twit temp = temp_twit[i];
				temp_twit[i] = temp_twit[j];
				temp_twit[j] = temp;
			}
		}
	}

	cout<<"<<Timeline Print>>"<<endl<<endl;

	temp_twit = array_user[save_index[0]]->get_twit();
	for(int j=0; j<temp_twit.size(); j++)
	{
		cout<< "<" << temp_twit[j].get_index() << "> : ";
		if(temp_twit[j].get_first_user_index()!=0)
			cout<<"("<<temp_twit[j].get_first_user_index()<<")";

		cout<<array_user[temp_twit[j].get_user_index()]->get_user_id() 
			<< " :" << temp_twit[j].get_str() << endl;
	}
}

void SocialGraph::print_else_timeline(int index, int& value)
{
	vector<Twit> temp_twit; 
	vector<int> temp_index; 
	vector<int> _time;
	temp_twit.clear();
	temp_index.clear(); 

	for(int i=0; i<array_user.size(); i++)
	{
		if(array_relation[index][i] == 1)
			if(array_relation[i][index]!=2)
				temp_index.push_back(array_user[i]->get_user_index());
	}

	for(int i=0; i<temp_index.size(); i++)
	{ 
		int twit_size = array_user[temp_index[i]]->get_twit().size();
		for(int j=0; j<twit_size; j++)
		{
			temp_twit.push_back(array_user[temp_index[i]]->get_twit()[j]);
			_time.push_back(time_relation[index][i]);
		}
	}

	for(int i=0; i<temp_twit.size(); i++)
	{
		for(int j=i+1; j<temp_twit.size(); j++)
		{
			if(temp_twit[i].get_index() < temp_twit[j].get_index())
			{
				Twit temp = temp_twit[i];
				temp_twit[i] = temp_twit[j];
				temp_twit[j] = temp;
			}
		}
	}

	cout << "<< Timeline print >>" << endl << endl;

	for(int i=0; i<temp_twit.size(); i++)
	{
		if(_time[i]<temp_twit[i].get_post_time())
		{
			cout<< "<" << temp_twit[i].get_index() << "> : ";
			if(temp_twit[i].get_first_user_index()!=0)
			{
				cout<<"("<<temp_twit[i].get_first_user_index()<<")";
				value = temp_twit[i].get_first_user_index();
			}
			cout<<array_user[temp_twit[i].get_user_index()]->get_user_id() 
				<< " :" << temp_twit[i].get_str() << endl;
		}
	}
}

bool SocialGraph::re_tweet(int index, int target_index,int value)
{
	vector<Twit> temp_twit;
	Twit twit;
	time_t ti;
	int create;
	for(int i=0; i<array_user.size(); i++)
	{
		temp_twit = array_user[i]->get_twit();
		for(int j=0; j<temp_twit.size(); j++)
			if(temp_twit[j].get_index() == target_index)
			{
				create = array_user[i]->get_twit()[j].get_first_user_index();
				value = array_user[i]->get_user_id();
				ti = time(NULL);
				string str = temp_twit[j].get_str();
				add_twit_count();
				twit.set_user_index(array_user[index]->get_user_index());
				if(array_user[i]->get_twit()[j].get_first_user_index()!=0)
					twit.set_first_user_index(create);
				else
				{
					twit.set_first_user_index(value);
					create = value;
				}
				twit.set_post_time(ti);
				twit.set_index(get_twit_count());
				twit.set_str(str);
				array_user[index]->write_twit(twit);
				save_timeline();
				return true;
			}
	}

	return false;
}