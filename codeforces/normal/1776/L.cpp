#include <iostream>
#include <algorithm>
#define int long long

int32_t main() {
	int n;

	std::cin >> n;

	int a = 0;
	int b = 0;
	for (int i = 0; i < n; i++) {
		char cur;
		std::cin >> cur;
		if (cur == '+') {
			a++;	
		} else if (cur == '-') {
			b++;
		} else {
			//std::cout << "ERROR";
		}
	}
	if (b > a) {
		std::swap(a,b);
	}

	int q;
	std::cin >> q;
	for (int i = 0; i < q; i++) {
		int x,y;
		std::cin >> x;
	        std::cin >> y;
		if (x > y) {
			int tmp = x;
			x = y;
			y = tmp;
		}
		if (x == y) {
			if ((a-b)*x == 0) {
				std::cout << "YES\n";
			} else {
				std::cout << "NO\n";
			}
			continue;	
		}
		int d = y-x;
		long long div = (long long)  (a-b)*x/d;
		//std::cout << "a: " << a << " b: " << b << " x: " << x << " y: " << y << " div: " << div << "\n";
		if (((long long) (a-b)*x) % d == 0 && div <= b) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
			//std::cout << ((a-b)*x) % d << '\n';
		}
	}

	return 0;
}