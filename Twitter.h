#pragma once
#include "SocialGraph.h"
#include <Windows.h>
#include <string>
#include <istream>

class Twitter
{
public:
	Twitter();

// <11가지 기능 구현>
public: 
	void login(int _user_id, string _pass_word);	//로그인
	void logout();	// 로그아웃
	void add_user(int _user_id, string _pass_word, string _name);	// 사용자 추가
	void write_tweet();	// 트윗 입력
	void remove_twit();	// 트윗 삭제
	void visit_timeline(int id);	// 아이디로 타임라인을 볼 수 있다
	void request_follow();	// Following 신청
	void sort_follower();	// Follow_Count 기준으로 내림차순
	void block_follow();	// 상대방이 사용자의 타임라인을 볼 수 없다
	void re_tweet();

public:
	void print_user_relation();	//	current_user 관계도 출력
	void print_user_timeline(); //	current_user 타임라인 출력시 Class Twit::index 오름차순으로 출력
	void print_Twitter_menu();	//	Twitter메뉴 출력
	void print_Tweeter_menu();	//	Tweeter메뉴 출력
	void print_interface();		//	interface메뉴 출력

private:
	SocialGraph graph;
	User* current_user;	// 현재 사용자
	

};

