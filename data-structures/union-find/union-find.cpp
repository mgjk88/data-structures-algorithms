#include <string>
#include <vector>
#include <unordered_map>

class unionFind
{
private:
    //link[node] holds next element in the set from node
    //size[node] indicates the size of the set containing the node when if is the leader
    std::unordered_map<std::string, std::string> link;
    std::unordered_map<std::string, int> size;
    bool isCompression = false;
public:
    unionFind(){}

    unionFind(std::unordered_map<std::string, std::unordered_map<std::string, int>> adjList, bool compression = false) {
        for(auto kvPair: adjList){
            link[kvPair.first] = kvPair.first;
            size[kvPair.first] = 1;
        }
        isCompression = compression;
    }

    void updateCompression(bool compression){
        isCompression = compression;
    }

    //finds leader of the set
    std::string find(std::string node) {
        if(!isCompression){
            while(node != link[node]) node = link[node];
            return node;
        }
        else{
            if(link[node] == node) return node;
            return link[node] = find(link[node]); 
        }
    }

    //set smaller set leader to point to bigger set leader
    void unite(std::string nodeA, std::string nodeB) {
        nodeA = find(nodeA);
        nodeB = find(nodeB);
        if(nodeA == nodeB) return;
        if(size[nodeA] < size[nodeB]) std::swap(nodeA, nodeB);
        size[nodeA] += size[nodeB];
        link[nodeB] = nodeA;
    }

    //check if same set
    bool same(std::string nodeA, std::string nodeB){
        return find(nodeA) == find(nodeB);
    }

    
    void createNode(std::string node){
        if (link.find(node) != link.end()) return;
        link[node] = node;
        size[node] = 1;
    }
};
