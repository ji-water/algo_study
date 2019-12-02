#include <iostream>
#include <algorithm>
#include <stack>
#include <list>

using namespace std;

static int **adj;
static stack<int> node; //되돌아갈 노드 저장
static list<int> visit; //방문노드 순서 저장
static list<int> visit2; //BFS 방몬노드 순서 저장

static int N,M,V;

int DFS(int start) { //다음 방문 노드 return (0이면 더이상 갈수있는 노드없음)
	for (int j = 1; j < N + 1; j++) {
		if (adj[start][j] < 1)
			continue;

		//인접 노드 j 발견
		//방문 했는지 체크
		int isVisit = 0; 
		for (list<int>::iterator it = visit.begin(); it != visit.end(); it++){
			//방문 했음
			if (*it == j) {
				isVisit = 1;
				break;
			}
		}
		//방문했음
		if (isVisit > 0)
			continue;
		//방문안했음 -> 다음 방문 j
		return j;
	}
	//방문 노드 못찾음
	return 0;	
}

void BFS(int start) { 
	for (int j = 1; j < N + 1; j++) {
		if (adj[start][j] < 1)
			continue;
		
		//인접노드 j 발견
		//방문했는지 체크
		int isVisit = 0;
		for (list<int>::iterator it = visit2.begin(); it != visit2.end(); it++) {
			//방문 했음
			if (*it == j) {
				isVisit = 1;
				break;
			}
		}
		//방문했음
		if (isVisit > 0)
			continue;
		//방문안했음
		visit2.push_back(j);
	}
}

int main(int argc, char** argv)
{
	cin >> N; //node수
	cin >> M; //edge수
	cin >> V; //시작 node

	adj = new int*[N+1]; //1~N까지 사용
	for (int i = 1; i < N+1; i++)
		adj[i] = new int[N+1]; 

	//초기화
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++)
			adj[i][j] = 0;
	}

	//연결 정보 입력
	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start;
		cin >> end;
		adj[start][end] = 1;
		adj[end][start] = 1;
	}


	/********DFS*********/
	//스택
	node.push(V);
	visit.push_back(V);

	int next = V;
	while (visit.size() < N) {
		next = DFS(next);
		if (next > 0) {
			node.push(next);
			visit.push_back(next);
		}
		else {
			if (!node.empty()) {
				next = node.top();
				node.pop();
			}
			else {
				break;
			}
		}
	}

	for (list<int>::iterator it = visit.begin(); it != visit.end(); it++)
		cout << *it << " ";
	cout << endl;

	/********BFS*********/
	visit2.push_back(V);
	list<int>::iterator next_p = visit2.begin();

	while (visit2.size() < N) {
		BFS(*next_p);
		next_p++;
		if (next_p == visit2.end())
			break;
	}
	for (list<int>::iterator it = visit2.begin(); it != visit2.end(); it++)
		cout << *it << " ";
	

}