#include <iostream>

int main(int argc, char *argv[]) {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		std::cin >> n;
		int prev = 0;
		int cur;
		
		int largest = 0;
		int second_largest = 0;

		for (int j = 0; j < n; j++) {
			std::cin >> cur;
			int cur_len = cur - prev;
			if (cur_len > largest) {
				second_largest = largest;
				largest = cur_len;
			} else if (cur_len > second_largest) {
				second_largest = cur_len;
			}
			prev = cur;
		}

		int cur_len = 1440 - prev;
		if (cur_len > largest) {
			second_largest = largest;
			largest = cur_len;
		} else if (cur_len > second_largest) {
			second_largest = cur_len;
		}
		prev = cur;


		if ((largest >= 120 && second_largest >= 120) || largest >= 240) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}

	return 0;
}