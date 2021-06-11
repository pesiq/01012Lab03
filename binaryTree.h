#ifndef LAB03_BINARYTREE_H
#define LAB03_BINARYTREE_H

template<class T>
class binaryTree {
private:
    struct Node {
        T value;
        int key{};
        int height = 1;
        Node* left;
        Node* right;
    };
    int size;
    Node* root;
public:


    binaryTree(){
        root = nullptr;
        size = 0;
    }

    void deleteFamily(Node* node){
        if(nullptr == node)
            return;
        {
            deleteFamily(node->left);
            deleteFamily(node->right);
            delete node;
        }
    }

    ~binaryTree(){
        deleteFamily(root);
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
            addRecursion(temp, root);
        }
    }

    void addRecursion(Node* node, Node* curr) {
        if (node == nullptr) {
            return;
        }else
        if(node->key < curr->key && curr->left){
            addRecursion(node, curr->left);
        } else
        if(node->key > curr->key && curr->right){
            addRecursion(node, curr->right);
        } else
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

    Node* findNode(Node* node, T value){
        if(!node){
            return nullptr;
        }
        if(value < node->value){
            return findNode(node->left, value);
        }
        if(value > node->value){
            return findNode(node->right, value);
        } else {
            return node;
        }
    }

    bool has(int value){
        Node* node = findNode(root, value);
        return !node ? false : node->value == value;
    }

    void remove(int key){
        remove(root, key);
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
        }else

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


    Node* getRoot(){
        return root;
    }

    T getValue(Node* node){
        return node->value;
    }

    std::string getKeyString(Node* node){
        if(!node)
            return std::string();

        std::string result;
        result += getKeyString(node->right);
        result += std::to_string(node->key);
        result += getKeyString(node->left);

        return result;
    }


    std::string getValueString(Node* node){
        if(!node)
            return std::string();

        std::string result;
        result += getValueString(node->right);
        result += std::to_string(node->value);
        result += getValueString(node->left);

        return result;
    }

    void mapRecursion(Node* node, T(*fun)(T)){
        if(!node)
            return;
        mapRecursion(node->left, fun);
        mapRecursion(node->right, fun);
        node->value = fun(node->value);
    }

    void whereRecursion(bool (*fun)(T),Node* node ,binaryTree<T> &output){
        if(!node){
            return;
        }
        if(fun(node->value)){
            output.add(node->key, node->value);
        }
        whereRecursion(fun, node->left, output);
        whereRecursion(fun, node->right, output);
    }

    binaryTree<T> &map(T (*fun)(T)){
        auto *result = new binaryTree<T>();
        mapRecursion(result->root, fun);
        return *result;
    }

    binaryTree<T> &where(bool (*fun)(T)){
        auto *result = new binaryTree<T>();
        whereRecursion(fun, root, *result);
        return *result;
    }

    bool includesSubtreeRecursion(Node* node, Node* toFind){
        if(!toFind)
            return true;
        if(!node)
            return true;
        if(node->key != toFind->key)
            return false;
        bool rec = includesSubtreeRecursion(node->right, toFind->right) && includesSubtreeRecursion(node->left, toFind->left);
        return rec;
    }

    bool includesSubtree(binaryTree<T> &candidate){
        if(!candidate.root){
            return true;
        }
        auto *node = findNode(root, candidate.root->key);
        return includesSubtreeRecursion(node, candidate.root);
    }

    void subtreeRecursion(Node* node){
        if(!node)
            return;
        this->add(node->key, node->value);
        subtreeRecursion(node->left);
        subtreeRecursion(node->right);
    }


    binaryTree<T> &getSubtree(Node* nRoot){
        auto *result = new binaryTree<T>;
        result->subtreeRecursion(nRoot->key, nRoot->value);
        return *result;
    }


};

#endif //LAB03_BINARYTREE_H
