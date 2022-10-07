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




/*
class Fraction {
public:
    Fraction(int numerator, int denominator)
        : numerator_(numerator)
        , denominator_(denominator) {
            int gcd= std::gcd(numerator_, denominator_);
            numerator_ /= gcd;
            denominator_ /= gcd;
    }

    Fraction(int numerator)
        : Fraction(numerator, 1) {

    }

    //Fraction(std::initializer_list<>) {

    //};

    int Numerator () const {
        return numerator_;
    }

    int Denominator() {
        return denominator_;
    }

    Fraction operator* (const Fraction& rhs) {
        return Fraction(numerator_ * rhs.numerator_, denominator_ * rhs.denominator_);
    }

    operator() (int x, int y) {

    }
private:
    int numerator_;
    int denominator_;
};

int aa_main() {
    //Fraction f;
}
*/

/*
enum class is_alive{
	dead,
	alive
};
*/



class Person {
//private:
public:
	double prob_hunt;
	double prob_child;
	double prob_help;

	int energy;


	int DAY_COST;
	int CHILD_COST;


public:
	Person() :
		energy(0),

		prob_hunt(0),
		prob_child(0),
		prob_help(0),

		DAY_COST(0),
		CHILD_COST(0)

	{}

	explicit Person(int _energy, double _prob_hunt, double _prob_child, double _prob_help, int _DAY_COST, int _CHILD_COST) :
		energy(_energy),

		prob_hunt(_prob_hunt),
		prob_child(_prob_child),
		prob_help(_prob_help),

		DAY_COST(_DAY_COST),
		CHILD_COST(_CHILD_COST)

	{}

	//Person(const Person& other)
    ///    : Person(other)
     //   {}





	Person& operator=(const Person& other) {
		prob_hunt = other.prob_hunt;
		prob_child = other.prob_child;
		prob_help = other.prob_help;

		energy = other.energy;


		DAY_COST = other.DAY_COST;
		CHILD_COST = other.CHILD_COST;

		return *this;
	}
	



	int want_to_hunt() {
		return rand()/(float)RAND_MAX < prob_hunt;
	}

	int want_child() {
		return rand()/(float)RAND_MAX < prob_child;
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
	Person a;
	return;
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


void add_new_element(map<int64_t, Person> &mp) {
	//for (auto& [x, y] : mp) {
	//	y.new_element_added(hashik, 1);
	//}

	Person addic(5, 0.5, 0.5, 0.5, 3, 10);

	mp[hashik] = addic;

	hashik++;

}




////////////////////////////////////////////////



map<int64_t, Person> build(int N) {//N - количество челов
	map<int64_t, Person> mapchik;

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

	map<int64_t, Person> elements_now = build(100);//количество,



	//for (a : elements_now) {

	//}

	return 0;
}