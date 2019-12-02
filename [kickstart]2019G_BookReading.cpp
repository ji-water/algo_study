#include <iostream>
#include <vector>

using namespace std;

int Answer;

//small case only
int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;

	for (test_case = 0; test_case<T; test_case++) {

		Answer = 0;

		int N, M, Q;

		cin >> N; //��������
		cin >> M; //����� ��������
		cin >> Q; //������ ���ڼ�

		if (N == M) {
			cout << "Case #" << test_case + 1 << ": " << Answer << endl;
			continue;
		}

		int *P = new int[M]; //����� ������
		int *R = new int[Q]; //������ ���ڰ� �б� ������ ������

		for (int i = 0; i < M; i++) {
			cin >> P[i];
		}
		for (int i = 0; i < Q; i++) {
			cin >> R[i];
		}
		
		//���д� ��������
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < Q; j++) {
				if (P[i] % R[j] == 0)
					Answer -= 1;
			}
		}

		//���ڰ� ���� ��������
		for (int i = 0; i < Q; i++) {
			int pageN = 1;
			while(true){
				if (R[i] * pageN < N)
					pageN++;
				else if (R[i] * pageN == N)
					break;
				else if (R[i] * pageN > N) {
					pageN--;
					break;
				}		
			}
			Answer += pageN;
		}
		

		cout << "Case #" << test_case + 1 << ": " << Answer << endl;

	}


}