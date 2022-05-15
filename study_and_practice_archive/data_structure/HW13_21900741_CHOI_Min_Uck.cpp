#include <iostream>
#include <string>
using namespace std;

class bst_node {
public:
    string s_id;
    string name;
    double score;
    bst_node* left, * right;
    bst_node();
    bst_node(string s1, string s2, double n);
    void set_data(string s1, string s2, double n);
};

bst_node::bst_node() {
    s_id = "00000000";
    name = "None";
    score = 0.0;
}

bst_node::bst_node(string s1, string s2, double n) {
    s_id = s1;
    name = s2;
    score = n;
}

void bst_node::set_data(string s1, string s2, double n) {
    s_id = s1;
    name = s2;
    score = n;
}

class bst_tree {
    bst_node* root;
    int csize;
public:
    bst_tree();
    bst_node search(string tid);
    void insert_node(bst_node t);
    bool empty();
    int size();
    void show_inorder();
};

bst_tree::bst_tree() {
    root = NULL;
    csize = 0;
}

bst_node bst_tree::search(string tid) {
    bst_node* p;
    p = root;

    bst_node tmp;
    tmp.set_data("00000000", "None", -1);

    if (root == NULL) {
        cout << "The key" << tid << "does noe exist/\n";
        return tmp;
    }

    while (1) {
        if (p->s_id == tid) {
            return (*p);
        }
        if (p->s_id < tid) {
            if (p->right = NULL) {
                cout << "The key" << tid << "does noe exist/\n";
                return tmp;
            }
            else {
                p = p->right;
            }
        }
        else {
            if (p->left == NULL) {
                cout << "The key" << tid << "does noe exist/\n";
                return tmp;
            }
            else {
                p = p->left;
            }
        }
    }

    return *p;
}

void bst_tree::insert_node(bst_node t) {
    bst_node* p;
    bst_node* tmp;

    tmp = new bst_node;
    *tmp = t;
    tmp->left = NULL;
    tmp->right = NULL;

    if (root == NULL) {
        root = tmp;
        return;
    }
    
    p = root;

    while (1) {
        if (p->s_id == t.s_id) {
            cout << "Insertion Failed : the Key" << t.s_id << " already exists.\n";
            return;
        }
        if (p->s_id < t.s_id) {
            if (p->right == NULL) {
                p->right = tmp;
                csize++;
                return;
            }
            else {
                p = p->right;
            }
        }
        else {
            if (p->left == NULL) {
                p->left = tmp;
                csize++;
                return;
            }
            else {
                p = p->left;
            }
        }
    }
}

void print_inorder(bst_node* p) {
    if (p == NULL) {
        cout << "There is no data.";
        return;
    }
    print_inorder(p->left);
    cout << p->s_id << " : " << p->name << " : " << p->score << "\n";
    print_inorder(p->right);
}

void bst_tree::show_inorder() {
    print_inorder(root);
}

bool bst_tree::empty() {
    if (root == NULL) {
        return true;
    }
    else {
        return false;
    }
}

int bst_tree::size() {
    return csize;
}

int main(){
    bst_node temp;
    bst_tree t1;

    temp.set_data("21900013", "Kim", 6.5);
    t1.insert_node(temp);
    temp.set_data("21900136", "Lee", 8.8);
    t1.insert_node(temp);
    temp.set_data("21900333", "Park", 9.2);
    t1.insert_node(temp);
    temp.set_data("21800442", "Choi", 7.1);
    t1.insert_node(temp);
    temp.set_data("21900375", "Ryu", 5.4);
    t1.insert_node(temp);
    temp.set_data("21700248", "Cho", 6.3);
    t1.insert_node(temp);

    cout << "\n\nNode List : inorder sequence \n";

    t1.show_inorder();

    string s_key = "21800442";
    temp = t1.search(s_key);

    cout << "\n -- " << s_key << "'s record ---" << endl;
    cout << " Student ID   : " << temp.s_id << endl;
    cout << " Student Name : " << temp.name << endl;
    cout << " Score        : " << temp.score << endl;

    return 0;
}

/*
<  예상 출력 결과 >

Node List : inorder sequence
21700248 : Cho : 6.3
21800442 : Choi : 7.1
21900013 : Kim : 6.5
21900136 : Lee : 8.8
21900333 : Park : 9.2
21900375 : Ryu : 5.4

 -- 21800442's record ---
 Student ID   : 21800442
 Student Name : Choi
 Score        : 7.1
*/