#include "../../../data-structures/graphs/graphs.cpp"
#include <string>
#include <unordered_map>
#include <stack>
#include <unordered_set>

//one use of dfs is for cycle detection in a graph
bool cycleDetection(std::unordered_map<std::string, std::unordered_map<std::string, int>>* ptr, std::string startNode){
    std::unordered_map<std::string, std::unordered_map<std::string, int>> list = *ptr;
    std::unordered_set<std::string> visited;
    std::stack<std::string> stack; //stack is used to determine order nodes are checked 
    stack.push(startNode);
    while(!stack.empty()){
        std::string currNode = stack.top();
        stack.pop();
        if(visited.find(currNode) != visited.end()) return true;
        visited.insert(currNode);
        for(auto kvPair: list[currNode]){
            stack.push(kvPair.first);
        }
    }
    return false;
}

int main(){
    listGraph graph;
    graph.createEdge("0", "1", 1, true);
    graph.createEdge("0", "4", 1, true);
    graph.createEdge("1", "2", 1, true);
    graph.createEdge("1", "3", 1, true);
    graph.createEdge("1", "4", 1, true);
    graph.createEdge("2", "3", 1, true);
    graph.createEdge("3", "4", 1, true);
    std::cout<<cycleDetection(graph.getList(), "0");
    return 0;
}

