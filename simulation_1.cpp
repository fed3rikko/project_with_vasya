#include<bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;
const int MAXN = 1e3 + 5;
const int DAY_COST = 3;


const int CHILD_COST = 10;

const int HUNT_REWARD = 5;


//double ans = 0;
//const int lower_bound_to_get_child = 10;
int64_t hashik = 0;




enum class is_alive{
	dead,
	alive
};



class Person {
//private:
public:
	int energy;
	
    double prob_hunt;
	double prob_child;
	double prob_help;

public:
	Person() :
		energy(0),

		prob_hunt(0),
		prob_child(0),
		prob_help(0)
	{}

	explicit Person(int _energy, double _prob_hunt, double _prob_child, double _prob_help) :
		energy(_energy),

		prob_hunt(_prob_hunt),
		prob_child(_prob_child),
		prob_help(_prob_help)

	{}

	Person(const Person& other) {
		prob_hunt = other.prob_hunt;
		prob_child = other.prob_child;
		prob_help = other.prob_help;

		energy = other.energy;
    }




	Person& operator=(const Person& other) {
		prob_hunt = other.prob_hunt;
		prob_child = other.prob_child;
		prob_help = other.prob_help;

		energy = other.energy;

		return *this;
	}
	


	is_alive end_day () {
		energy -= DAY_COST;
		if (energy <= 0) {
			return is_alive::dead;
		}

		return is_alive::alive;
	}


	int want_to_hunt() {
		return rand()/(float)RAND_MAX < prob_hunt;
	}

	int want_child() {
		if (energy >= CHILD_COST) {
			return rand()/(float)RAND_MAX < prob_child;
		}
	}

	std::vector<double> give_child_gens() {
		// самая простенькая реализация пускай пока тут будет
		double pr_ht = (rand()/(float)RAND_MAX - 0.5) / 1000 + this->prob_hunt;
		double pr_ch = (rand()/(float)RAND_MAX - 0.5) / 1000 + this->prob_child;
		double pr_hp = (rand()/(float)RAND_MAX - 0.5) / 1000 + this->prob_help;
		
		return {pr_ht, pr_ch, pr_hp};
	}


	int want_to_help() {
		return rand()/(float)RAND_MAX < prob_help;
	}


};


//  операции для работы со структуркой
//////////////////////////////////

/*
void end_day() {
		el_energy -= DAY_COST;
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



//about all elemetns
void new_element_added(int64_t code, int64_t chg) {
	//len_all_el++;
	love_deg[code] = chg;
	love_sum += chg;
}


void this_element_poped(map<int64_t, Person> &mp) {
	mp.erase(my_hash);

	for (auto& [x, y] : mp) {
		y.other_element_poped(my_hash);
	}
}


void other_element_poped(int64_t hashik) {
	love_sum -=love_deg[hashik];
	love_deg.erase(hashik);
}

*/


void add_new_element(map<int64_t, Person> &mp) {// нужна для создания начального состояния - далее для рождения ее использовать не следует
	//for (auto& [x, y] : mp) {
	//	y.new_element_added(hashik, 1);
	//}

	Person addic(5, 0.5, 0.5, 0.5);

	mp[hashik] = addic;

	hashik++;

}

void person_birth_new_person (Person& parent, map<int64_t, Person> &mp) { // функция для рождения детей
	auto vars = parent.give_child_gens();
	Person addic(5, vars[0], vars[1], vars[2]);// 5 - стартовое значение енергии

	mp[hashik] = addic;
	hashik++;
}





void delete_element (int pos, std::map<int64_t, Person> &mp) { // для удаления чела из структуры при его смерти

	mp.erase(pos);
}





////////////////////////////////////////////////



map<int64_t, Person> build(int N) {//N - количество челов
	map<int64_t, Person> mapchik;

	for (int i = 0; i < N; i++) {
		add_new_element(mapchik);
	}

	return mapchik;
}



void live_one_fakking_day (std::map<int64_t, Person> &mp) {
	vector<int> qu_del;
	vector<Person> qu_birth;

	for (auto &[x, y] : mp) {
		if (y.want_to_hunt() ) {
			y.energy += HUNT_REWARD;
		}
		
		if (y.want_child()) {
			//person_birth_new_person(y, mp);
			qu_birth.push_back(y);
		}

		if (y.end_day() == is_alive::dead) {
			//delete_element(x, mp);
			qu_del.push_back(x);
		}

	}


	for (auto x : qu_del) {
		delete_element(x, mp);
	}

	for (auto y : qu_birth) {
		person_birth_new_person(y, mp);
	}

}



int main() {
	//setprecision(12);
	//double t = 1;
	//cout << 1;

	map<int64_t, Person> elements_now = build(100);//100 - количество micro-челов



	for (int i = 0; i < 10; i++) {
		live_one_fakking_day(elements_now);
	}

	cout << elements_now.size();

	return 0;
}
