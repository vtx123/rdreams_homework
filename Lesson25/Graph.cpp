#include "Graph.h"

int GraphAdjList::numberOfNodesInLevel(int level)
{
    // Mark all the vertices as not visited & all levels counters as 0
    std::vector<bool> visited;
    visited.resize(m_vertixes, false);
    std::vector<int> levels;
    levels.resize(m_vertixes, 0);

    std::list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[0] = true;
    queue.push_back(0);
    levels[0] = 0;

    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        int currentVertex = queue.front();

        queue.pop_front();

        // Get all adjacent vertices
        for (int adjacent : m_list[currentVertex])
        {
            if (!visited[adjacent])
            {
                visited[adjacent] = true;
                queue.push_back(adjacent);
                levels[adjacent] = levels[currentVertex] + 1;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < m_vertixes; i++) {
        if (levels[i] == level) {
            count++;
        }
    }

    return count;
}

GraphAdjList GraphAdjList::transpose() const {
    GraphAdjList g(m_vertixes);

    for (int s = 0; s < m_vertixes; s++) {
        for (int adjacent : m_list[s])
        {
            g.m_list[adjacent].push_back(s);
        }
    }
    return g;
}

void GraphAdjList::fillOrder(int s, bool visitedV[], std::stack<int>& Stack) const {
    visitedV[s] = true;

    for (int adjacent : m_list[s]) {
        if (!visitedV[adjacent]) {
            fillOrder(adjacent, visitedV, Stack);
        }
    }
    Stack.push(s);
}

void GraphAdjList::DFS(int s, bool visitedV[]) {
    visitedV[s] = true;
    std::cout << s << " ";

    for (int adjacent : m_list[s])
    {
        if (!visitedV[adjacent])
        {
            DFS(adjacent, visitedV);
        }
    }
}

bool GraphAdjList::isStronglyConnected() const
{
    unsigned componentsCount = 0;
    std::stack<int> Stack;

    bool* visitedV = new bool[m_vertixes];
    for (int i = 0; i < m_vertixes; i++) {
        visitedV[i] = false;
    }

    for (int i = 0; i < m_vertixes; i++) {
        if (visitedV[i] == false) {
            fillOrder(i, visitedV, Stack);
        }
    }

    GraphAdjList gr = transpose();

    for (int i = 0; i < m_vertixes; i++) {
        visitedV[i] = false;
    }

    while (Stack.empty() == false) {
        int s = Stack.top();
        Stack.pop();

        if (visitedV[s] == false) {
            gr.DFS(s, visitedV);
            std::cout << std::endl;
            componentsCount++;
        }
    }

    return componentsCount == 1;
}

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
