/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    Node* copyRandomList(Node* head) {
        Node* node = head;
        std::set<Node*> visited;
        std::map<Node*, Node*> origin_copy_map;
        
        while(node != nullptr){
            Node* c_node; 
            if(!visited.count(node)){
                c_node = (Node*)malloc(sizeof(Node));
                c_node->val = node->val;
                c_node->next = nullptr;
                c_node->random = nullptr;
                visited.emplace(node);
                origin_copy_map[node] = c_node;
            }else c_node = origin_copy_map[node];
            
            if(node->next != nullptr){
                if(!visited.count(node->next)){
                        Node* c_n_node =(Node*)malloc(sizeof(Node));
                        c_n_node->val = node->next->val;
                        c_node->next = c_n_node;
                        c_n_node->next = nullptr;
                        c_n_node->random = nullptr;
                        visited.emplace(node->next);
                        origin_copy_map[node->next] = c_n_node;
                    }else c_node->next = origin_copy_map[node->next];
                }
                
                if(node->random != nullptr){
                    if(!visited.count(node->random)){
                        Node* c_r_node =(Node*)malloc(sizeof(Node));
                        c_r_node->val = node->random->val;
                        c_node->random = c_r_node;
                        c_r_node->next = nullptr;
                        c_r_node->random = nullptr;
                        visited.emplace(node->random);
                        origin_copy_map[node->random] = c_r_node;
                    }else c_node->random = origin_copy_map[node->random];
                }
            
            node = node->next;
        }
        
        return origin_copy_map[head];
    }
};