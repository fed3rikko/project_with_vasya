#include "constants.h"
#include "Person.h"

#include <map>
#include <vector>
#include <iostream>

int64_t hashik = 0;
int STURKT_LEN = 0;

void add_new_element(std::map<int64_t, Person> &mp) {// нужна для создания начального состояния - далее для рождения ее использовать не следует
	//for (auto& [x, y] : mp) {
	//	y.new_element_added(hashik, 1);
	//}

	Person addic(5, 0.9, 0.5, 0.5);

	mp[hashik] = addic;

	hashik++;

}

void person_birth_new_person (Person& parent, std::map<int64_t, Person> &mp) { // функция для рождения детей
	auto vars = parent.give_child_gens();
	Person addic(ENERGY_GIVE_TO_CHILD, vars[0], vars[1], vars[2]);// ENERGY_GIVE_TO_CHILD - стартовое значение енергии

	mp[hashik] = addic;
	hashik++;
}


void delete_element (int64_t pos, std::map<int64_t, Person> &mp) { // для удаления чела из структуры при его смерти
	mp.erase(pos);
}


int what_reward_get_after_hunt (int N) {
	//std::cout << 0.000000005 / N <<"kek\n";
	if (rand()/(float)RAND_MAX < (1000. / N) ) {
		//std::cout << "rwaft\n";
		return HUNT_REWARD;
	}

	return 0;
}




////////////////////////////////////////////////



std::map<int64_t, Person> build(int N) {//N - количество челов
    std::map<int64_t, Person> mapchik;

	for (int i = 0; i < N; i++) {
		add_new_element(mapchik);
	}

	return mapchik;
}



void live_one_fakking_day (std::map<int64_t, Person> &mp) {
    std::vector<int> qu_del;
    std::vector<Person> qu_birth;

	int len = mp.size();

	for (auto& [x, y] : mp) {
		if (y.want_to_hunt() ) {
			y.energy += what_reward_get_after_hunt(len);
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

    std::map<int64_t, Person> elements_now = build(10000);//10000 - количество micro-челов



	for (int i = 0; i < 1000000; i++) {
		live_one_fakking_day(elements_now);
        std::cout << elements_now.size() << '\n';
	}

	//cout << elements_now.size();

	return 0;
}
