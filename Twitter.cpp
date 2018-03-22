#include "Twitter.h"

Twitter::Twitter()
{

}

// <11가지 기능 구현>
void Twitter::login(int _user_id, string _pass_word)	//로그인
{
	current_user = graph.login(_user_id, _pass_word);
	if(current_user == NULL)
	{	
		cout<<"로그인 실패했습니다."<<endl;
		system("pause");
		system("cls");
	}

	else 
	{
		cout<<"login되었습니다."<<endl;
		system("pause");
		system("cls");
		print_Tweeter_menu();
	}
}

void Twitter::logout()	// 로그아웃
{
	if(current_user!=NULL)
	{
		current_user = NULL;
		cout<<"로그아웃 되었습니다."<<endl;
	}
	else
		cout<<"로그인 상태가 아닙니다."<<endl;
}

void Twitter::add_user(int _user_id, string _pass_word, string _name)	// 사용자 추가
{
	current_user = graph.add_user(_user_id,_pass_word,_name);
	if(current_user == NULL)
	{
		cout<<"이미 사용중인 아이디입니다."<<endl;
		print_interface();
	}
	else
	{
		cout<<"회원가입 되었습니다. 가입한 아이디로 로그인합니다."<<endl;
		print_Tweeter_menu();
	}



}

void Twitter::write_tweet()	// 트윗 입력
{
	Twit twit;
	time_t ti;
	char content[300];
	graph.add_twit_count();
	cout<<"트위터 : "<<graph.get_twit_count()<<endl;
	cout<<"          < 트윗을 작성해 주세요 >"<<endl;
	cout<<"          ";
	cin.ignore();
	cin.getline(content, 120);
	ti = time(0);
	twit.set_post_time(ti);
	twit.set_user_index(current_user->get_user_index());
	twit.set_index(graph.get_twit_count());
	twit.set_str(content);
	current_user->write_twit(twit);
	graph.save_timeline();
	print_user_timeline();
}

void Twitter::remove_twit()	// 트윗 삭제
{
	int index;
	graph.print_me_timeline(current_user->get_user_index());
	cout<<"< 삭제할 트윗의 번호를 입력하세요 >"<<endl<<endl;
	cin>>index;
	current_user->remove_twit(index);
	graph.save_timeline();
	print_user_timeline();
}

void Twitter::visit_timeline(int id)	// 아이디로 타임라인을 볼 수 있다
{
	graph.print_visit_timeline(id);
}

void Twitter::request_follow()	// Following 신청
{
	int id;
	cout<<"<<Request Follow>>"<<endl<<endl;
	cout<<"Following ID를 입력하세요"<<endl;
	cin >> id;
	graph.request_follow(current_user->get_user_index(), id);
	graph.save_relation();
	graph.save_time();
	print_user_timeline();
}

void Twitter::sort_follower()	// Follow_Count 기준으로 내림차순
{
	graph.print_sort_follow();
}

void Twitter::block_follow()	// 상대방이 사용자의 타임라인을 볼 수 없다
{
	int id;
	cout<<"<<Block Follow>>"<<endl<<endl;
	cout<<"Block 시킬 ID를 입력하세요"<<endl;
	cin >> id;
	graph.block_follow(current_user->get_user_index(), id);
	print_user_timeline();
}

void Twitter::print_user_relation()	//	current_user 관계도 출력
{
	graph.print_user_relation(current_user->get_user_index());
}

void Twitter::print_user_timeline()  //	current_user 타임라인 출력시 Class Twit::index 오름차순으로 출력
{
	graph.print_user_timeline(current_user->get_user_index());
}

void Twitter::print_Twitter_menu()
{
	int sellect=1;
	int id;
	string password;
	string name;
	while(sellect)
	{
		cout<<"			Twitter"<<endl;
		cout<<"┌─────────────────────┐"<<endl;
		cout<<"│       메뉴                               │"<<endl;
		cout<<"│                                          │"<<endl;
		cout<<"│1. 회원가입                               │"<<endl;
		cout<<"│2. 로그인                                 │"<<endl;
		cout<<"│3. 로그아웃                               │"<<endl;
		cout<<"│0. 종료                                   │"<<endl;
		cout<<"└─────────────────────┘"<<endl<<endl;
		cout<<"메뉴 선택 : ";
		cin >> sellect;
		switch(sellect)
		{
		case 1:
			cout<<"id를 입력해주세요 : ";
			cin>> id;
			cout<<"password를 입력해주세요 : ";
			cin >> password;
			cout<<"이름을 입력해주세요 : ";
			cin >> name;
			add_user(id,password,name);
			system("pause");
			system("cls");
			break;

		case 2:
			cout<<"id를 입력해주세요 : ";
			cin >> id;
			cout<<"password를 입력해주세요 : ";
			cin >> password;
			login(id, password);
			break;

		case 3:
			logout();
			system("pause");
			system("cls");

		case 0:
			exit(100);

		default:
			cout<<"잘못된 값을 입력하셨습니다. 다시입력해주세요."<<endl;
			system("pause");
			system("cls");
		}
	}
}

void Twitter::print_Tweeter_menu()
{
	int sellect=1;
	while(sellect)
	{
		cout<<"Tweeter"<<endl<<endl;
		cout<<"┌─────────────────────┐"<<endl;
		cout<<"│       메뉴                               │"<<endl;
		cout<<"│                                          │"<<endl;
		cout<<"│1. Relation print                         │"<<endl;
		cout<<"│2. Timeline print                         │"<<endl;
		cout<<"│3. Tweet write                            │"<<endl;
		cout<<"│4. Request following                      │"<<endl;
		cout<<"│5. Tweet delete                           │"<<endl;
		cout<<"│6. Visit Tweet                            │"<<endl;
		cout<<"│7. Sort Follower                          │"<<endl;
		cout<<"│8. Block Follow                           │"<<endl;
		cout<<"│9. Re tweet                               │"<<endl;
		cout<<"│0. 종료                                   │"<<endl;
		cout<<"└─────────────────────┘"<<endl<<endl;
		cout<<"메뉴 선택 : ";
		cin >> sellect;

		switch(sellect)
		{
		case 1:
			print_user_relation();
			system("pause");
			system("cls");
			break;

		case 2:
			print_user_timeline();
			system("pause");
			system("cls");
			break;

		case 3:
			write_tweet();
			system("pause");
			system("cls");
			break;

		case 4:
			request_follow();
			system("pause");
			system("cls");
			break;

		case 5:
			remove_twit();
			system("pause");
			system("cls");
			break;

		case 6:
			int id;
			cout<<"<<Visit Tweet>>"<<endl<<endl;
			cout<<"< 방문하고 싶은 아이디를 입력하세요 >"<<endl;
			cin >> id;
			visit_timeline(id);
			system("pause");
			system("cls");
			break;

		case 7:
			sort_follower();
			system("pause");
			system("cls");
			break;

		case 8:
			block_follow();
			system("pause");
			system("cls");
			break;

		case 9 :
			re_tweet();
			system("pause");
			system("cls");
			break;

		case 0:
			graph.save_relation();
			graph.save_timeline();
			exit(100);

		

		default:
			cout<<"잘못 입력하셨습니다.";
			system("pause");
			system("cls");
			break;
		}
	}
}

void Twitter::print_interface()
{
	print_Twitter_menu();
}

void Twitter::re_tweet()
{
	int index, target_index;
	int value = 0;
	index = current_user->get_user_index();
	cout<<"<<Re Tweet>>"<<endl<<endl;
	graph.print_else_timeline(index, value);
	cout<<"리트윗 할 글 인덱스를 선택해주세요"<<endl;
	cin >> target_index;
	if(graph.re_tweet(index, target_index, value)==NULL)
	{
		cout<<"잘못된 인덱스를 선택하셨습니다."<<endl;
		print_Tweeter_menu();
	}
	else
	{
		cout<<"리트윗했습니다. 타임라인을 출력합니다."<<endl;
		print_user_timeline();
	}

}