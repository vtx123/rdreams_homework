#include "Graph.h"

GraphAdjList::GraphAdjList(int Vertixes, ConnectionType type)
    : Graph(Vertixes, type)
{
    m_list.resize(Vertixes);
}

void GraphAdjList::addEdge(int v, int w)
{
    m_list[v].push_back(w);
    if (m_connectionType == ConnectionType::undirected)
    {
        m_list[w].push_back(v);
    }
}

void GraphAdjList::BFS(int vertex)
{
    // Mark all the vertices as not visited
    std::vector<bool> visited;
    visited.resize(m_vertixes, false);

    std::list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[vertex] = true;
    queue.push_back(vertex);

    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        int currentVertex = queue.front();

        //or make anything else with it: push to vector, string, pass to another object, whatever
        std::cout << currentVertex << " ";

        queue.pop_front();

        // Get all adjacent vertices
        for (int adjacent : m_list[currentVertex])
        {
            if (!visited[adjacent])
            {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }
}
