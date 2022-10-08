#ifndef PERSON_H
#define PERSON_H

#include <stdlib.h>
#include <vector>
#include "constants.h"

enum class is_alive{
	dead,
	alive
};

struct Person {
	int energy;

    double prob_hunt;
	double prob_child;
	double prob_help;

	Person():
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



	int want_to_hunt() {
		return rand()/(float)RAND_MAX < prob_hunt;
	}

	int want_child() {
        return rand() / (float) RAND_MAX < prob_child;
	}

	std::vector<double> give_child_gens() {
		// самая простенькая реализация пускай пока тут будет
        double mutability = 1e-2;
		double pr_ht = rand()/(2. * RAND_MAX - 1) * mutability + this->prob_hunt;
		double pr_ch = rand()/(2. * RAND_MAX - 1) * mutability + this->prob_child;
		double pr_hp = rand()/(2. * RAND_MAX - 1) * mutability + this->prob_help;

		return {pr_ht, pr_ch, pr_hp};
	}


	int want_to_help() {
		return rand()/(float)RAND_MAX < prob_help;
	}
};

#endif
