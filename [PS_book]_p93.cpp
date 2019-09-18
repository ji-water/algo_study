#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main(int argc, char** argv)
{
	int x, y;
	cin >> x;
	cin >> y;
	int **arr = new int*[y];
	for (int i = 0; i < y; i++) {
		arr[i] = new int[x];
		memset(arr[i], 0, sizeof(int)*x); //메모리 초기화
	}
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cin >> arr[i][j];
		}
	}

	//덧셈 연산
	//최단루트로 이동하므로 위, 왼쪽 값만 비교하면됨
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (i ==0 && j ==0) //위, 왼쪽 없음
				break;
			else if (i ==0) { //위 없음
				arr[i][j] += arr[i][j - 1];
			}
			else if (j == 0) { //왼쪽 없음
				arr[i][j] += arr[i - 1][j];
			}
			else {
				arr[i][j] += max(arr[i - 1][j], arr[i][j - 1]);
			}
		}
	}
	cout << endl;
	cout << arr[y-1][x-1] << endl;
	//경로 출력
	for (int i = 0; i < y;) {
		for (int j = 0; j < x;) {
			cout << "(" << j << "," << i << ") ";
			if (i == y - 1 && j == x - 1) //도착
				return 0;
			else if (i == y - 1) { //아래 없음
				j++;
			}
			else if (j == x - 1) { //오른쪽 없음
				i++;
			}
			else {
				if (arr[i][j + 1] >= arr[i + 1][j])
					j++;
				else
					i++;
			}
		}
	}

}