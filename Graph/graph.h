#pragma once
#include <string>
#include "person.h"
#define SIZE 10

class Graph
{
public:
	Graph();

	//���������� �������
	void addVertex(
		const Person person
		);

	//// �������� �������
	void delVertex(
		int vnumber
		);

	//// �������� �����
	void delEdge(
		int v1,
		int v2
		);

	//���������� �����
	void addEdge(
		 Person  v1,
		 Person v2,
		int weight
		);

	void depth(
		int start
		);
	
	void depthInner(
		int current,	
		bool visited[]
		);

	////��� ���� ������, ����������� ���������� ����� �������� �� ����������� n.
	int findPathCountBetween(
		int v1,
		int v2,
		const int step = 3
		);

	//// ����� ����������� ����������
	int findMinWayDFS(int v1, int v2);

	// //����� ���������� �����
	int findPathCount(
		int v1,
		int v2
		);
private:
	void findMinWayDFSInner(
		int v1,
		int v2,
		bool  visited[],
		int& minWay,
		int max
		);

	void findPathInner(
		int v1,
		int v2, 
		bool visited[],
		int& count
		);

	void findPathBetweenInner(
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
	Person vertexes[SIZE];//��������� ������	
	int vertexCount;//���������� ����������� ������
};
