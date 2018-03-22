#include "Twitter.h"

Twitter::Twitter()
{

}

// <11���� ��� ����>
void Twitter::login(int _user_id, string _pass_word)	//�α���
{
	current_user = graph.login(_user_id, _pass_word);
	if(current_user == NULL)
	{	
		cout<<"�α��� �����߽��ϴ�."<<endl;
		system("pause");
		system("cls");
	}

	else 
	{
		cout<<"login�Ǿ����ϴ�."<<endl;
		system("pause");
		system("cls");
		print_Tweeter_menu();
	}
}

void Twitter::logout()	// �α׾ƿ�
{
	if(current_user!=NULL)
	{
		current_user = NULL;
		cout<<"�α׾ƿ� �Ǿ����ϴ�."<<endl;
	}
	else
		cout<<"�α��� ���°� �ƴմϴ�."<<endl;
}

void Twitter::add_user(int _user_id, string _pass_word, string _name)	// ����� �߰�
{
	current_user = graph.add_user(_user_id,_pass_word,_name);
	if(current_user == NULL)
	{
		cout<<"�̹� ������� ���̵��Դϴ�."<<endl;
		print_interface();
	}
	else
	{
		cout<<"ȸ������ �Ǿ����ϴ�. ������ ���̵�� �α����մϴ�."<<endl;
		print_Tweeter_menu();
	}



}

void Twitter::write_tweet()	// Ʈ�� �Է�
{
	Twit twit;
	time_t ti;
	char content[300];
	graph.add_twit_count();
	cout<<"Ʈ���� : "<<graph.get_twit_count()<<endl;
	cout<<"          < Ʈ���� �ۼ��� �ּ��� >"<<endl;
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

void Twitter::remove_twit()	// Ʈ�� ����
{
	int index;
	graph.print_me_timeline(current_user->get_user_index());
	cout<<"< ������ Ʈ���� ��ȣ�� �Է��ϼ��� >"<<endl<<endl;
	cin>>index;
	current_user->remove_twit(index);
	graph.save_timeline();
	print_user_timeline();
}

void Twitter::visit_timeline(int id)	// ���̵�� Ÿ�Ӷ����� �� �� �ִ�
{
	graph.print_visit_timeline(id);
}

void Twitter::request_follow()	// Following ��û
{
	int id;
	cout<<"<<Request Follow>>"<<endl<<endl;
	cout<<"Following ID�� �Է��ϼ���"<<endl;
	cin >> id;
	graph.request_follow(current_user->get_user_index(), id);
	graph.save_relation();
	graph.save_time();
	print_user_timeline();
}

void Twitter::sort_follower()	// Follow_Count �������� ��������
{
	graph.print_sort_follow();
}

void Twitter::block_follow()	// ������ ������� Ÿ�Ӷ����� �� �� ����
{
	int id;
	cout<<"<<Block Follow>>"<<endl<<endl;
	cout<<"Block ��ų ID�� �Է��ϼ���"<<endl;
	cin >> id;
	graph.block_follow(current_user->get_user_index(), id);
	print_user_timeline();
}

void Twitter::print_user_relation()	//	current_user ���赵 ���
{
	graph.print_user_relation(current_user->get_user_index());
}

void Twitter::print_user_timeline()  //	current_user Ÿ�Ӷ��� ��½� Class Twit::index ������������ ���
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
		cout<<"����������������������������������������������"<<endl;
		cout<<"��       �޴�                               ��"<<endl;
		cout<<"��                                          ��"<<endl;
		cout<<"��1. ȸ������                               ��"<<endl;
		cout<<"��2. �α���                                 ��"<<endl;
		cout<<"��3. �α׾ƿ�                               ��"<<endl;
		cout<<"��0. ����                                   ��"<<endl;
		cout<<"����������������������������������������������"<<endl<<endl;
		cout<<"�޴� ���� : ";
		cin >> sellect;
		switch(sellect)
		{
		case 1:
			cout<<"id�� �Է����ּ��� : ";
			cin>> id;
			cout<<"password�� �Է����ּ��� : ";
			cin >> password;
			cout<<"�̸��� �Է����ּ��� : ";
			cin >> name;
			add_user(id,password,name);
			system("pause");
			system("cls");
			break;

		case 2:
			cout<<"id�� �Է����ּ��� : ";
			cin >> id;
			cout<<"password�� �Է����ּ��� : ";
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
			cout<<"�߸��� ���� �Է��ϼ̽��ϴ�. �ٽ��Է����ּ���."<<endl;
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
		cout<<"����������������������������������������������"<<endl;
		cout<<"��       �޴�                               ��"<<endl;
		cout<<"��                                          ��"<<endl;
		cout<<"��1. Relation print                         ��"<<endl;
		cout<<"��2. Timeline print                         ��"<<endl;
		cout<<"��3. Tweet write                            ��"<<endl;
		cout<<"��4. Request following                      ��"<<endl;
		cout<<"��5. Tweet delete                           ��"<<endl;
		cout<<"��6. Visit Tweet                            ��"<<endl;
		cout<<"��7. Sort Follower                          ��"<<endl;
		cout<<"��8. Block Follow                           ��"<<endl;
		cout<<"��9. Re tweet                               ��"<<endl;
		cout<<"��0. ����                                   ��"<<endl;
		cout<<"����������������������������������������������"<<endl<<endl;
		cout<<"�޴� ���� : ";
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
			cout<<"< �湮�ϰ� ���� ���̵� �Է��ϼ��� >"<<endl;
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
			cout<<"�߸� �Է��ϼ̽��ϴ�.";
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
	cout<<"��Ʈ�� �� �� �ε����� �������ּ���"<<endl;
	cin >> target_index;
	if(graph.re_tweet(index, target_index, value)==NULL)
	{
		cout<<"�߸��� �ε����� �����ϼ̽��ϴ�."<<endl;
		print_Tweeter_menu();
	}
	else
	{
		cout<<"��Ʈ���߽��ϴ�. Ÿ�Ӷ����� ����մϴ�."<<endl;
		print_user_timeline();
	}

}