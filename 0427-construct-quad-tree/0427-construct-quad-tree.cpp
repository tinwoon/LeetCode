class Solution {
public:
    Node* solve(vector<vector<int>>& grid, int x, int y, int length) {
        if (length == 1) {
            return new Node(grid[x][y], true);
        }
        
        Node* topLeft = solve(grid, x, y, length / 2);
        Node* topRight = solve(grid, x, y + length / 2, length / 2);
        Node* bottomLeft = solve(grid, x + length / 2, y, length / 2);
        Node* bottomRight = solve(grid, x + length / 2, y + length / 2, length / 2);
        
        if (topLeft -> isLeaf && topRight -> isLeaf && bottomLeft -> isLeaf && bottomRight -> isLeaf
           && topLeft -> val == topRight -> val && topRight -> val == bottomLeft -> val 
           && bottomLeft -> val == bottomRight -> val) {
            return new Node(topLeft -> val, true);
        }
        
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
    
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid, 0, 0, grid.size());
    }
};