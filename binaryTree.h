#ifndef LAB03_BINARYTREE_H
#define LAB03_BINARYTREE_H

template<class T>
class binaryTree {
private:
    typedef struct node {
        T value;
        int key{};
        int height = 1;
        Node* left;
        Node* right;
    } Node;
    int size;
    Node* root;

public:
    BinaryTree(){
        root = nullptr;
        size = 0;
    }

    void add(int key, T value) {
        auto* temp = new Node;
        temp->key = key;
        temp->value = value;
        if (root == nullptr) {
            root = temp;
            size++;
            return;
        }
        else {
            add(temp);
        }
    }

    void add(Node* node,Node* curr) {
        if (node == nullptr) {
            return;
        }
        if(node->key < curr->key && curr->left){
            add(node, curr->left);
        }
        if(node->key > curr->right && curr->right){
            add(node, curr->right);
        }
        if(curr->key > node->key){
            size++;
            curr->left = node;
        } else {
            size++;
            curr->left = node;
        }
    }

    Node* lesserNode(Node* node){
        if(node == nullptr){
            return nullptr;
        }
        Node* curr = node;
        while(curr && curr->left != nullptr)
            curr = curr->left;
        return curr;
    }

    Node* greaterNode(Node* node){
        if(node == nullptr){
            return nullptr;
        }
        Node* curr = node;
        while(curr && curr->right != nullptr)
            curr = curr->right;
        return curr;
    }

    Node* remove(Node* node, int key) {
        if (node == nullptr)
            return node;

        if (key < node->key) {
            node->left = remove(node->left, key);
            return node;
        } else if (key > node->key) {
            node->right = remove(node->right, key);
            return node;
        }

        if (node->left == nullptr) {
            Node *tmp = node->right;
            delete node;
            return tmp;
        } else if (node->right == nullptr) {
            Node *tmp = node->left;
            delete node;
            return tmp;
        } else {

            Node* successorParent = node;

            Node* successor = node->right;

            while(successor->left != nullptr){
                successorParent = successor;
                successor = successor->left;
            }

            if(successorParent != node){
                successorParent->left = successor->right;
            }
            else{
                successorParent->right = successor->left;
            }
            node->key = successor->key;
            delete successor;
            return node;
        }
    }

    int nodeHeight(Node* node){
        return node ? node->height : 0;
    }

    int heightDelta(Node* node){
        return nodeHeight(node->left) - nodeHeight(node->right);
    }

    void calculateHeight(Node* node){
        int h1 = node->left == nullptr ? 0 : node->height;
        int h2 = node->right == nullptr ? 0 : node->height;
        node->height = h1 > h2 ? h1 + 1 : h2 + 1;
    }

    Node* rotateLeft(Node* node){
        Node* newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;
        calculateHeight(node);
        calculateHeight(newRoot);

        return newRoot;
    }

    Node* rotateRight(Node* node){
        Node* newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;
        calculateHeight(node);
        calculateHeight(newRoot);

        return newRoot;
    }

    Node* balance(Node* node){
        calculateHeight(node);
        int d = heightDelta(node);
        if(d < -1){
            if(node->left != nullptr && heightDelta(node->left) > 0){
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }
        if(d > 1){
            if(node->right != nullptr && heightDelta(node->right) < 0){
                node->right = rotateRight(node->right);
                return node;
            }
        }
        return node;
    }

    Node* search(Node* node, int key){
        if(node == nullptr)
            return nullptr;
        else if (key < node->key){
            return search(node->left, key);
        } else if (key > node->key){
            return search(node->right, key);
        } else
            return node;
    }




};

#endif //LAB03_BINARYTREE_H
