#include <iostream>
#include "Graph.h"

//#define TIME_LOG_ENABLED
int getTime() { return 1; }

int main()
{
    GraphAdjList graph(11);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);

    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    graph.addEdge(2, 6);
    graph.addEdge(3, 7);

    graph.addEdge(4, 8);
    graph.addEdge(5, 9);
    graph.addEdge(7, 10);
    graph.addEdge(6, 9);
    //graph.addEdge(1, 9); // remove strange links for test number of node on levels
    //graph.addEdge(1, 3); // remove strange links for test number of node on levels

#ifdef TIME_LOG_ENABLED
    int startTime = getTime();
#endif
    std::cout << "----- GRAPH #1 -----" << std::endl;
    graph.BFS();

#ifdef TIME_LOG_ENABLED
    int endTime = getTime();
    int diff = endTime - startTime;
    std::cout << "Time used for BFS: " << diff << std::endl;
#endif

    std::cout << std::endl;
    std::cout << "Number of nodes in Level[1]: " << graph.numberOfNodesInLevel(0) << std::endl;
    std::cout << "Number of nodes in Level[2]: " << graph.numberOfNodesInLevel(1) << std::endl;
    std::cout << "Number of nodes in Level[3]: " << graph.numberOfNodesInLevel(2) << std::endl;
    std::cout << "Number of nodes in Level[4]: " << graph.numberOfNodesInLevel(3) << std::endl;
    std::cout << "Strongly connected components:" << std::endl;
    std::cout << "Is Graph strongly connected: " << (graph.isStronglyConnected() ? "YES" : "NO") << std::endl;

    GraphAdjList graph2(11);

    graph2.addEdge(0, 1);
    graph2.addEdge(0, 2);
    graph2.addEdge(0, 3);

    graph2.addEdge(1, 4);
    graph2.addEdge(2, 5);
    graph2.addEdge(2, 6);
    //graph2.addEdge(3, 7); // drop 1 edge for test NON strongly connection 

    graph2.addEdge(4, 8);
    graph2.addEdge(5, 9);
    graph2.addEdge(7, 10);
    graph2.addEdge(6, 9);
    graph2.addEdge(1, 9);
    graph2.addEdge(1, 3);

    std::cout << std::endl << "----- GRAPH #2 -----" << std::endl;
    std::cout << "Number of nodes in Level[1]: " << graph2.numberOfNodesInLevel(0) << std::endl;
    std::cout << "Number of nodes in Level[2]: " << graph2.numberOfNodesInLevel(1) << std::endl;
    std::cout << "Number of nodes in Level[3]: " << graph2.numberOfNodesInLevel(2) << std::endl;
    std::cout << "Number of nodes in Level[4]: " << graph2.numberOfNodesInLevel(3) << std::endl;
    std::cout << "Strongly connected components:" << std::endl;
    std::cout << "Is Graph strongly connected: " << (graph2.isStronglyConnected() ? "YES" : "NO") << std::endl;
}