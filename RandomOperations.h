#ifndef RANDOMOPERATIONS_H
#define RANDOMOPERATIONS_H

#include <cstdlib>
#include <ctime>
#include <vector>
#include <queue>
using std::rand;
using std::srand;
using std::clock;
using std::vector;
using std::queue;

void seedRefresh(){
	srand(clock());
}

template<class T>
T rangeSelect(T from = 0, T to = 100){
	seedRefresh();
	if(from==to) return from;
	return rand()%to+from;
}

double randDouble(int from = 0, int to = 100){
	return (static_cast<double>(rangeSelect<int>(from, to))/rangeSelect<int>(from, to));
}

template<class T>
T& vecSelector(vector<T> vec){
	return vec[rangeSelect<T>(0, vec.size())];
}

template<class T>
void vecShuffle(vector<T>& vec){
	vector<T> shuffled;
	while(vec.size() > 0){
		int random = rangeSelect<int>(0, vec.size());
		shuffled.push_back(vec[random]);
		vec.erase(vec.begin()+random);
	}
	while(shuffled.size() > 0){
		vec.push_back(shuffled.back());
		shuffled.pop_back();
	}
}

template <class T>
void randomQueue(queue<T>& que){
	int rand = rangeSelect<int>(0, que.size());
	for(int i = 0; i < rand; ++i) que.pop();
	rand = rangeSelect<int>();
	for(int i = 0; i < rand; ++i) que.push(rangeSelect<T>());
}
#endif
