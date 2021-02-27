#pragma once
#include <string>
#include "person.h"
#define SIZE 10

class Graph
{
public:
	Graph();

	//добавление вершины
	void addVertex(
		const Person person
		);

	//// удаление вершины
	void delVertex(
		int vnumber
		);

	//// удаление ребра
	void delEdge(
		int v1,
		int v2
		);

	//добавление ребра
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

	////все пары вершин, минимальное расстояние между которыми не превосходит n.
	int findPathCountBetween(
		int v1,
		int v2,
		const int step = 3
		);

	//// поиск кратчайшего расстояния
	int findMinWayDFS(int v1, int v2);

	// //поиск количества путей
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

	int matrix[SIZE][SIZE];//матрица смежности
	Person vertexes[SIZE];//хранилище вершин	
	int vertexCount;//количество добавленных вершин
};
