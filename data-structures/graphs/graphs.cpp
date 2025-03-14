#include <string>
#include <vector>
#include <utility>
#include <unordered_map>
#include <iostream>
// graph representations:
//- adjacency matrix
//- adjacency list

//- a adjacency matrix representation of a graph
//- arr[x][y] represents a edge
//- x represents start vertex
//- y represents end vertex

class matrixGraph
{
private:
    int numVertex;

public:
    std::vector<std::vector<int>> matrix;

    matrixGraph(int n) : numVertex(n), matrix(n, std::vector<int>(n, 0)) {}

    void createEdge(int start, int end, int weight, bool isDirected)
    {
        if (start < 0 || start >= numVertex || end < 0 || end >= numVertex)
            throw "invalid input";
        matrix[start][end] = weight;
        if (!isDirected)
            matrix[end][start] = weight;
    }

    void deleteEdge(int start, int end, int weight, bool isDirected)
    {
        if (start < 0 || start >= numVertex || end < 0 || end >= numVertex)
            throw "invalid input";
        matrix[start][end] = 0;
        if (!isDirected)
            matrix[end][start] = 0;
    }

    void createVertex(int numNew)
    {
        for (auto row: matrix)
        {
           row.resize(numVertex + numNew, 0);
        }
        numVertex += numNew;
        matrix.resize(numVertex, std::vector<int>(numVertex, 0));
    }

    std::vector<std::vector<int>> *const getMatrix()
    {
        return &matrix;
    }
};
// adjacency list representation of a graph
//- list[v] is a unordered_map containing endVertex-weight pairs that is connected to startVertex v

class listGraph
{
private:
public:
    std::unordered_map<std::string, std::unordered_map<std::string, int>> list;
    listGraph() {}

    void createEdge(std::string startV, std::string endV, int weight, bool isDirected)
    {
        list[startV][endV] = weight;
        if (!isDirected)
            list[endV][startV] = weight;
    }

    void deleteEdge(std::string startV, std::string endV, bool isDirected)
    {
        if (list.find(startV) != list.end())
        {
            list[startV].erase(endV);
        }
        else
        {
            throw "start vertex does not exist";
        }
        if (!isDirected && list.find(endV) != list.end()){
            list[endV].erase(startV);
        }
    }

    std::unordered_map<std::string, std::unordered_map<std::string, int>> *const getList()
    {
        return &list;
    }
};

int main()
{}