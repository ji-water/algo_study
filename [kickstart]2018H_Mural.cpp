#include <iostream>
#include <string>


using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;

	for (test_case = 0; test_case<T; test_case++) {
		Answer = 0;

		int N;
		cin >> N;
		string input;
		cin >> input;

		int window=(N-1)/2 +1;
		int i_len = 0;

		int * wall = new int[N];
		for (int i = 0; i < N; i++) {
			wall[i] = input.at(i)-'0';
			if (i < window) {
				i_len += wall[i];
			}
		}

		Answer = i_len;
		int i_end = window;
		if (N % 2 == 1)
			i_end -= 1;
		for (int i = 1; i <= i_end; i++) {
			i_len = i_len - wall[i - 1] + wall[i + window - 1];
			if (i_len > Answer)
				Answer = i_len;
		}


		cout << "Case #" << test_case + 1 << ": " << Answer << endl;

	}


}