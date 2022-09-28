#include<bits/stdc++.h>

using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define f first	
#define s second
#define ll long long
#define db double
#define pb push_back
typedef pair<int, int> pii;

void inppp(){
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
}


const int M = 1e9 + 7;
const int MAXN = 1e3 + 5;
const int DAY_COST = 3;


//double ans = 0;
int64_t hashik = 0;


struct element_1 {
	//about this elemet
	double p_chs = -1;
	map<int, int> love_deg;
	int64_t love_sum = 0;
	int64_t el_energy = -1;
	int64_t my_hash;


	element_1(int64_t energy, double p, int64_t hashik) { //map<int64_t, element_1> &mp) {
		//len_all_el = N;
		p_chs = p;//вероятность с которой мы хотим делиться
		el_energy = energy;
		my_hash = hashik;
	}


	//about this elemet
	void end_day() {
		el_energy -= DAY_COST;
	}

	
	int choose_will() {
		return rand()/(float)RAND_MAX < p_chs;
	}

	int choose_who() {
		int64_t nb =  rand() % love_sum;

		int sum_loc = 0;
		for (auto& [x, y] : love_deg) {
			sum_loc += y;

			if (sum_loc >= love_sum) {
				return x;
			}
		}
	}

	void create_divide_new_el() {
		element_1 a;
		return;
	}


	//about all elemetns
	void new_element_added(int64_t code, int64_t chg) {
		//len_all_el++;
		love_deg[code] = chg;
		love_sum += chg;
	}


	void this_element_poped(map<int64_t, element_1> &mp) {
		mp.erase(my_hash);

		for (auto& [x, y] : mp) {
			y.other_element_poped(my_hash);
		}
	}


	void other_element_poped(int64_t hashik) {
		love_sum -=love_deg[hashik];
		love_deg.erase(hashik);
	}



};


void add_new_element(map<int64_t, element_1> &mp) {
	for (auto& [x, y] : mp) {
		y.new_element_added(hashik, 1);
	}

	element_1 addic(5, 0.4, hashik);

	mp[hashik] = addic;

	hashik++;

}



map<int64_t, element_1> build(int N) {//N - количество челов
	map<int64_t, element_1> mapchik;

	for (int i = 0; i < N; i++) {
		add_new_element(mapchik);
	}

	return mapchik;

}


int main() {
	inppp();
	//setprecision(12);
	//double t = 1;
	cout << 1;

	int64_t counter = 0;

	map<int64_t, element_1> elements_now = build(100);//количество,



	//for (a : elements_now) {

	//}

	return 0;
}