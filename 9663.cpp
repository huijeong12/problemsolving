//
// Created by HUIJEONG on 2021/01/05.
//

#include <iostream>
#include <cmath>
using namespace std;

int N, ans = 0;
int arr[16];

bool check(int x) {
	for (int i = 1; i < x; i++)
		if (arr[i] == arr[x] || abs(arr[x] - arr[i]) == abs(x - i))
			return false;

	return true;
}

void dfs(int x) {
	if(x == N + 1)
		ans++;

	else {
		for (int i = 1; i <= N; i++) {
			arr[x] = i;

			if (check(x))
				dfs(x + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	dfs(1);

	cout << ans;

	return 0;
}