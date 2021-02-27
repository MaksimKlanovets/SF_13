#include "graph.h"

#include <iostream>

Graph::Graph()
{
	for (size_t i = 0; i < SIZE; i++)
	{
		for (size_t j = 0; j < SIZE; j++)
		{
            matrix[i][j] = {};
		}
		vertexes[i] = {};
	}
	vertexCount = 0;
}

int Graph::findMinWayDFS(
    int from, 
    int to
    ) 
{
  int  minWay = 10000000000;
    bool visited[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        visited[i] = false;
    }
    int max = 0;
    findMinWayDFSInner(from, to, visited, minWay, max);

    return minWay;
}

void Graph::findMinWayDFSInner(
    int v1, 
    int v2, 
    bool  visited[],
    int &minWay,
    int max
    )
{
    visited[v1] = true;
    
    if (v1 == v2 && minWay > max)
    {
        minWay = max;
    }
    else
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (!visited[i] && edgeExists(v1, i))
            {
                max += matrix[v1][i];
                findMinWayDFSInner(i, v2, visited, minWay,max);
                max -= matrix[v1][i];
            }
        }
    }

    visited[v1] = false;
}

// поиск количества путей
int Graph::findPathCountBetween(
    int v1,
    int v2,
    const int step
    ) 
{
    int counter = 0;
    int countPath = 0;
    bool visited[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        visited[i] = false;
    }
    findPathBetweenInner(v1, v2, visited, counter, countPath, step );

    return countPath;
}

void Graph::findPathBetweenInner(
    int v1,
    int v2, 
    bool visited[],
    int &count, 
    int& path,
    const int step
    )
{
    visited[v1] = true;

    if (v1 ==  v2  && count <= step)
    {
        path++;
    }
    else
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (count <= step && !visited[i] && edgeExists(v1, i))
            {
                count++;
                findPathBetweenInner(i, v2, visited, count,path,step);
                count--;
            }
        }
    }

    visited[v1] = false;
}

void Graph::addVertex(
    const Person person
    )
{
	vertexes[vertexCount++] = person;
}

void Graph::addEdge(
	 Person v1,
	 Person v2,
    int weight
    )
{
    
	matrix[v1.getId()][v2.getId()] = weight;
	matrix[v2.getId()][v1.getId()] = weight;
}
void Graph::depth(  
    int start
    )
{
    bool visited[SIZE]; // список посещенных вершин
    for (int i = 0; i < SIZE; i++)
        visited[i] = false; // инициализируем как непосещенные
    depthInner(start, visited); // запуск алгоритма 

    std::cout << std::endl;
}
void Graph::depthInner(
    int current, 
    bool visited[]
    )
{
    std::cout << "v" << vertexes[current].getId() << " -> " <<
        vertexes[current].getName() << std::endl; // вывод текущей
    visited[current] = true; // помечаем как посещенную
    for (int i = 0; i < SIZE; i++)
    {
        if (edgeExists(current, i) && !visited[i])
            depthInner(i, visited); // если существует ребро и вершина не посещалась, то пройдем по нему в смежную вершину

    }
}
bool Graph::edgeExists(
    int v1, 
    int v2
    )
{
    return matrix[v1][v2] != 0;
}
bool Graph::vertexExists(
    int v
    )
{
    for (int i = 0; i < vertexCount; i++)
        if (vertexes[i].getId() == v)
            return true;
    return false;
}
//// удаление вершины
void Graph::delVertex(
    int vnumber
    ) 
{
    if (!vertexExists(vnumber))
    {
        return;
    }
    int current = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (vertexes[i].getId() == vnumber)
        {
            current = vertexes[i].getId();
            break;
        }

    }
    for (int i = 0; i < vertexCount; i++)
    {
        matrix[current][i] = 0;
        matrix[i][current] = 0;
    }
    vertexCount--;
    for (int i = current; i < vertexCount; i++)
    {
        vertexes[i] = vertexes[i + 1];
    }
    
}
//// удаление ребра
void Graph::delEdge(
    int v1,
    int v2
) 
{
    // Ваш код должен быть здесь     
    if (!edgeExists(v1, v2))
    {
        return;
    }
    matrix[v1][v2] = 0;
    matrix[v2][v1] = 0;
}

//// поиск количества путей
int Graph::findPathCount(
    int v1,
    int v2
    ) 
{
    int counter = 0;
    bool visited[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        visited[i] = false;
    }
    findPathInner(v1, v2, visited, counter);

    return counter;
}

void Graph::findPathInner(
    int v1,
    int v2,
    bool visited[],
    int& count
    )
{
    visited[v1] = true;
    if (v1 == v2)
    {
        count++;
    }
    else
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (!visited[i] && edgeExists(v1, i))
            {
                findPathInner(i, v2, visited, count);
            }
        }
    }

    visited[v1] = false;
}