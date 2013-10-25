#include <iostream>
using namespace std;
#include <vector>

class BinaryTreeNode{
private:
    float val;
    BinaryTreeNode *left, *right;
public:
    BinaryTreeNode(){
        val=0.0;
        left=NULL;
        right=NULL;
    }
    BinaryTreeNode(float v){
        val=v;
        left=NULL;
        right=NULL;
    }
    BinaryTreeNode(float v, BinaryTreeNode *l, BinaryTreeNode *r){
        val=v;
        left=l;
        right=r;
    }
    float getVal(){
        return val;
    }
    BinaryTreeNode *getLeft(){
        return left;
    }
    BinaryTreeNode *getRight(){
        return right;
    }
    void setVal(float v){
        val=v;
    }
    void setLeft(BinaryTreeNode *l){
        left=l;
    }
    void setRight(BinaryTreeNode *r){
        right=r;
    }
    
};

class BinarySearchTree{
private:
    BinaryTreeNode *root;
    bool lookupHelper(BinaryTreeNode *root, float v){
        if(root==NULL) return false;
        if(root->getVal()==v) return true;
        if(v<root->getVal()){
            return lookupHelper(root->getLeft(), v);
        }
        else{
            return lookupHelper(root->getRight(), v);
        }
    }
    void insertHelper(BinaryTreeNode* root, float v){
        if(v==root->getVal()) return;
        if(v<root->getVal()){
            if(root->getLeft()==NULL){
                root->setLeft(new BinaryTreeNode(v, NULL, NULL));
            }
            else insertHelper(root->getLeft(), v);
        }
        else{
            if(root->getRight()==NULL){
                root->setRight(new BinaryTreeNode(v, NULL, NULL));
            }
            else insertHelper(root->getRight(), v);
        }
    }
    BinaryTreeNode *smallestTreeNode(BinaryTreeNode *root){
        if(root->getLeft()==NULL) return root;
        else return smallestTreeNode(root->getLeft());
    }
    BinaryTreeNode *deleteHelper(BinaryTreeNode* root, float v){
        if(root==NULL) return NULL;
        if(root->getVal()==v){
            if(root->getLeft()==NULL&&root->getRight()==NULL) return NULL;
            if(root->getLeft()==NULL) return root->getRight();
            if(root->getRight()==NULL) return root->getLeft();
            
            BinaryTreeNode *tmp=smallestTreeNode(root->getRight());
            root->setVal(tmp->getVal());
            root->setRight(deleteHelper(root->getRight(), tmp->getVal()) );
            return root;
            
        }
        if(root->getVal()>v){
            root->setLeft(deleteHelper(root->getLeft(), v));
            return root;
        }
        else{
            root->setRight(deleteHelper(root->getRight(), v));
            return root;
        }
    }
    
    
    
public:
    void insertTreeNode(float v){
        if(root==NULL){
            root=new BinaryTreeNode(v, NULL, NULL);
        }
        else{
            insertHelper(root, v);
        }
    }
    void deleteTreeNode(float v){
        root=deleteHelper(root, v);
        
    }
    bool lookupTreeNode(float v){
        return lookupHelper(root, v);
    }
    void printTree(){
        
    }
    
};