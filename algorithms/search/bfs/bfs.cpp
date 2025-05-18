#include "../../../data-structures/graphs/graphs.cpp"
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <deque>

void lvlOrderTravsersal(adjList* ptr, std::string startNode){
    adjList list = *ptr;
    std::deque<std::string> q;
    std::unordered_set<std::string> visited;
    q.push_back(startNode);
    while (!q.empty()){
        std::string currNode = q.front();
        q.pop_front();
        std::cout<<currNode<<" ";
        visited.insert(currNode);
        for(auto kvPair: list[currNode]){
            if(visited.find(kvPair.first) == visited.end()) q.push_back(kvPair.first);
        }
    }
    std::cout<<"\n"<<"done";
}

int main(){}