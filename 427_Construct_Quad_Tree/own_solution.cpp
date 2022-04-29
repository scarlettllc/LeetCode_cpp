/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        bool flag = true;
        int first_val = grid[0][0];
        for (int i = 0; i < n && flag; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != first_val) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            return new Node(first_val, 1);
        }
        vector<vector<int>> topLeft_matrix;
        for (int i = 0; i < n/2; ++i) {
            vector<int> temp;
            for (int j = 0; j < n/2; ++j) {
                temp.push_back(grid[i][j]);
            }
            topLeft_matrix.push_back(temp);
        }
        Node* _topLeft = construct(topLeft_matrix);
        vector<vector<int>> topRight_matrix;
        for (int i = 0; i < n/2; ++i) {
            vector<int> temp;
            for (int j = n/2; j < n; ++j) {
                temp.push_back(grid[i][j]);
            }
            topRight_matrix.push_back(temp);
        }
        Node* _topRight = construct(topRight_matrix);
        vector<vector<int>> bottomLeft_matrix;
        for (int i = n/2; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < n/2; ++j) {
                temp.push_back(grid[i][j]);
            }
            bottomLeft_matrix.push_back(temp);
        }
        Node* _bottomLeft = construct(bottomLeft_matrix);
        vector<vector<int>> bottomRight_matrix;
        for (int i = n/2; i < n; ++i) {
            vector<int> temp;
            for (int j = n/2; j < n; ++j) {
                temp.push_back(grid[i][j]);
            }
            bottomRight_matrix.push_back(temp);
        }
        Node* _bottomRight = construct(bottomRight_matrix);
        return new Node(1, 0, _topLeft, _topRight, _bottomLeft, _bottomRight);
    }   
};