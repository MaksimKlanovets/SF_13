#pragma once
#define SIZE 10

class Graph
{
public:
	Graph();

	//добавление вершины
	void addVertex(
		int vnumber	
		);

	// удаление вершины
	void delVertex(
		int vnumber
		);

	// удаление ребра
	void delEdge(
		int v1,
		int v2
		);

	//добавление ребра
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

	//поиск количества путей между двумя вершинами
	int findPathCountBetween(
		int v1,
		int v2,
		const int step = 3
		);


	// поиск кратчайшего расстояния
	int findMinWayDFS(int v1, int v2);
	void findMinWayDFSInner(int v1, int v2, bool  visited[], int &minWay, int max);

	//все пары вершин, минимальное расстояние между которыми не превосходит 3.
	
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

	int matrix[SIZE][SIZE];//матрица смежности
	int vertexes[SIZE];//хранилище вершин	
	int vertexCount;//количество добавленных вершин
};
