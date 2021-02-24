#pragma once
#define SIZE 10

class Graph
{
public:
	Graph();

	//���������� �������
	void addVertex(
		int vnumber	
		);

	// �������� �������
	void delVertex(
		int vnumber
		);

	// �������� �����
	void delEdge(
		int v1,
		int v2
		);

	//���������� �����
	void addEdge(int v1,
		int v2,
		int weight
		);

	void depth(
		int start
		);
	
	void depthInner(
		int current,	
		bool visited[]
		);

	//����� ���������� ����� ����� ����� ���������
	int findPathCountBetween(
		int v1,
		int v2,
		const int step = 3
		);


	// ����� ����������� ����������
	int findMinWayDFS(int v1, int v2);
	void findMinWayDFSInner(int v1, int v2, bool  visited[], int &minWay, int max);

	//��� ���� ������, ����������� ���������� ����� �������� �� ����������� 3.
	
private:
	
	void findPathInnner(
		int v1,
		int v2,
		bool visited[],
		int& count,
		int& path,
		const int step
	);

	bool edgeExists(
		int v1,
		int v2
		);

	bool vertexExists(
		int v
		);

	int matrix[SIZE][SIZE];//������� ���������
	int vertexes[SIZE];//��������� ������	
	int vertexCount;//���������� ����������� ������
};
