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

#define PRINT(NODE) printf("%s : %d\n",#NODE, NODE->val);

class Solution {
public:
    std::map<Node*, Node*> connected;
    
    void copy_node(Node* new_node, Node* refer){
        connected[refer] = new_node;
        new_node->val = refer->val;
        auto Node_vector = new_node -> neighbors;
        for(int k=0; k < (refer -> neighbors).size(); k++){
            if(connected.count((refer->neighbors)[k]) == 0){
                Node* next_new_node = new Node;
                (new_node -> neighbors).push_back(next_new_node);
                copy_node(next_new_node, (refer->neighbors)[k]);
            }else{
                (new_node -> neighbors).emplace_back(connected[(refer->neighbors)[k]]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        Node* new_node = nullptr;
        if(node != nullptr){
            new_node = new Node;
            copy_node(new_node, node);
        }
        
        return new_node;
    }
};