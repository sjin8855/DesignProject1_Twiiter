#pragma once
#include "User.h"
#include <fstream>
class SocialGraph
{
public:
	SocialGraph();

public:
	void load_user();	// 사용자 로드
	void save_user();	// 사용자 저장
	void load_relation();	//	관계도 로드
	void save_relation();	// 관계도 저장
	void load_timeline(); // 타임라인 로드
	void save_timeline();	// 타임라인 저장
	void load_time();	// 시간 로드
	void save_time();	// 시간 저장

public:
	User* login(int _user_id, string _pass_word);	// 로그인
	User* add_user(int _user_id, string _pass_word, string _name);	// 회원 추가
	void request_follow(int _index, int target_index);	// Following 신청
	void block_follow(int _index, int target_index);	// Follower 차단
	int get_twit_count();	// 트윗 총 개수 리턴
	void add_twit_count();	// 트윗 번호 1증가
	bool re_tweet(int _index, int target_index,int value);		//리트윗

public:
	void print_user_relation(int index);	// 사용자의 Follower, Following
	void print_user_timeline(int index);	// 사용자의 Timeline 출력
	void print_visit_timeline(int id);	// 입력한 ID의 Timeline 출력
	void print_sort_follow();	// 사용자의 Follower_count 기준으로 내림차순 정렬
	void print_me_timeline(int index);
	void print_else_timeline(int index, int &value);

private:
	vector<User*> array_user;	// 로드된 사용자
	int** array_relation;	// 인접행렬
	int twit_count;	// 트윗 총 개수, 글 번호(Class Twit::index)
	int** time_relation;	// 시간 인접행렬
};

