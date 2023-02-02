#include <algorithm>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

int main() {
	srand(time(NULL));

	int TRIALS = 1000000;
	int wins = 0;
	for (int i = 0; i < TRIALS; i++) {
		// Choose car door
		vector<int> nums = { 0, 1, 2, 3, 4, 5, 6 };
		int car = rand() % 7;
		int choice = rand() % 7;
		if (car == choice) continue; // Auto loss if same since door chosen will switch to other three

		// Remove three doors (not car or choice) at random
		nums.erase(nums.begin() + max(car, choice));
		nums.erase(nums.begin() + min(car, choice));
		random_shuffle(nums.begin(), nums.end());
		nums.erase(nums.begin(), nums.begin() + 3);

		// Add back car door option and shuffle for randomness
		nums.push_back(car);
		random_shuffle(nums.begin(), nums.end());

		// Choose out of doors that are not the originally chosen and check if win
		choice = rand() % 3;
		wins += (nums[choice] == car);
	}

	cout << (double)wins / (double)TRIALS << endl;

	return 0;
}