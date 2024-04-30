#pragma once
#include <iostream>
#include <vector>

using namespace std;

//functions
//struct TreeNode* GetNewNode(int data);
//void addChild(TreeNode* node, int data);
//void Print(TreeNode* root);

struct TreeNode {
	int data;
	vector <TreeNode> children;
};

TreeNode* GetNewNode(int data) {
	TreeNode* newNode = new TreeNode();
	newNode->data = data;
	return newNode;
}

void addChild(TreeNode* node, int data) {
	TreeNode* newNode = GetNewNode(data);
	node->children.push_back(newNode);
}

int main() {
	return 0;
}