/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*,Node*> clones;
    
    Node* cloneGraph(Node* node) {
        if(!node)return node;
        if(clones.find(node)==clones.end()){
            clones[node]=new Node(node->val,{});   
            for(auto& neighbor:node->neighbors){
                clones[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return clones[node];
    }
};