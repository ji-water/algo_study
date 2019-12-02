#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

long long Answer;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;

	for (test_case = 0; test_case<T; test_case++) {
		int N, P;
		cin >> N;
		cin >> P;

		Answer = pow(2,N);
		//cout << Answer << endl;

		vector<string> prefix;
		for (int i = 0; i < P; i++) {
			//PÀÔ·Â
			string p;
			cin >> p;
			prefix.push_back(p);
			
			Answer -= pow(2, N-p.length());
		}

		sort(prefix.begin(), prefix.end());
		//for (int i=0; i<P; i++)
			//cout << prefix.at(i) << endl;

		for (int i = 1; i < P; i++) {
			string A = prefix.at(i - 1);
			string B = prefix.at(i);
			if (A.size() < B.size()) {
				if (B.find(A)==0) {
					Answer += pow(2, N - B.length());
					//cout << Answer << endl;
					prefix.erase(prefix.begin()+i);
					prefix.insert(prefix.begin()+i, A);
				}
			}
		}

		cout << "Case #" << test_case + 1<<": " <<Answer<< endl;

	}


}