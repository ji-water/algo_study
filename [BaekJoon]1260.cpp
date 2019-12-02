#include <iostream>
#include <algorithm>
#include <stack>
#include <list>

using namespace std;

static int **adj;
static stack<int> node; //�ǵ��ư� ��� ����
static list<int> visit; //�湮��� ���� ����
static list<int> visit2; //BFS ����� ���� ����

static int N,M,V;

int DFS(int start) { //���� �湮 ��� return (0�̸� ���̻� �����ִ� ������)
	for (int j = 1; j < N + 1; j++) {
		if (adj[start][j] < 1)
			continue;

		//���� ��� j �߰�
		//�湮 �ߴ��� üũ
		int isVisit = 0; 
		for (list<int>::iterator it = visit.begin(); it != visit.end(); it++){
			//�湮 ����
			if (*it == j) {
				isVisit = 1;
				break;
			}
		}
		//�湮����
		if (isVisit > 0)
			continue;
		//�湮������ -> ���� �湮 j
		return j;
	}
	//�湮 ��� ��ã��
	return 0;	
}

void BFS(int start) { 
	for (int j = 1; j < N + 1; j++) {
		if (adj[start][j] < 1)
			continue;
		
		//������� j �߰�
		//�湮�ߴ��� üũ
		int isVisit = 0;
		for (list<int>::iterator it = visit2.begin(); it != visit2.end(); it++) {
			//�湮 ����
			if (*it == j) {
				isVisit = 1;
				break;
			}
		}
		//�湮����
		if (isVisit > 0)
			continue;
		//�湮������
		visit2.push_back(j);
	}
}

int main(int argc, char** argv)
{
	cin >> N; //node��
	cin >> M; //edge��
	cin >> V; //���� node

	adj = new int*[N+1]; //1~N���� ���
	for (int i = 1; i < N+1; i++)
		adj[i] = new int[N+1]; 

	//�ʱ�ȭ
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++)
			adj[i][j] = 0;
	}

	//���� ���� �Է�
	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start;
		cin >> end;
		adj[start][end] = 1;
		adj[end][start] = 1;
	}


	/********DFS*********/
	//����
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