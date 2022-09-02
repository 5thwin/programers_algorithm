#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

struct Node;
class Tree{
    public:
    Tree(){
        root = nullptr;
    }
    Tree(Node* r){
        root = r;
    }
    Node *root;
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    int N = nodeinfo.size();
    Node root = {nullptr, nullptr, nullptr, 1, nodeinfo[0][1], nodeinfo[0][0]};//루트노드 만들기
    Tree tree(&root);
    for (int i = 1; i < N; i++){

    }


    return answer;
}

struct Node{
    Node *left;
    Node *right;
    Node *parent;
    int num;
    int y;
    int x;
};
