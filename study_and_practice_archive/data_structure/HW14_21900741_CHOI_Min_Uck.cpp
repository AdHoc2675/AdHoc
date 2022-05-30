// HW14_21900741_CHOI_Min_Uck.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
using namespace std;

class bst_node {
public:
    string birthday;
    string name;
    string p_num;
    bst_node* left, * right;
    bst_node();
    bst_node(string s1, string s2, string s3);
    void set_data(string s1, string s2, string s3);
};

bst_node::bst_node() {
    birthday = "0000-00-00";
    name = "None";
    p_num = "000-0000-0000";
}

bst_node::bst_node(string s1, string s2, string s3) {
    birthday = s1;
    name = s2;
    p_num = s3;
}

void bst_node::set_data(string s1, string s2, string s3) {
    birthday = s1;
    name = s2;
    p_num = s3;
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

    if (root == NULL) {
        bst_node tmp;
        tmp.set_data("0000-00-00", "None", "000-0000-0000");
        cout << "The key " << tid << " does not exist\n";
        return tmp;
    }

    while (1) {
        if (p->name == tid) {
            return (*p);
        }
        if (p->name < tid) {
            if (p->right = NULL) {
                bst_node tmp;
                tmp.set_data("0000-00-00", "None", "000-0000-0000");
                cout << "The key " << tid << " does not exist\n";
                return tmp;
            }
            else {
                p = p->right;
            }
        }
        else {
            if (p->left == NULL) {
                bst_node tmp;
                tmp.set_data("0000-00-00", "None", "000-0000-0000");
                cout << "The key " << tid << " does not exist\n";
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
        if (p->p_num == t.p_num) {
            cout << "Insertion Failed : the phone number " << t.p_num << " already exists.\n";
            return;
        }
        if (p->birthday < t.birthday) {
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
        return;
    }

    print_inorder(p->left);
    cout << p->birthday << " : " << p->name << " : " << p->p_num << "\n";
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

int main()
{
    bst_node temp;
    bst_tree t1;

    int order;
    string input_birth;
    string input_name;
    string input_p_num;
    string key;

    while (1) {
        cout << "What are you want to do?\n";
        cout << "Please enter the number.\n";
        cout << "1. Insert a New Node\n";
        cout << "2. Search existing nodes with Name\n";
        cout << "3. See Whole List\n"; //inorder 방식
        cout << "4. End Program\n";

        cin >> order;

        if (order == 1) { //노드 입력, insert 기능
            cout << "To insert a New Node, Please enter the Birthday, Name, and Phone Number\n";
            cout << "Enter the Birthday in form of 0000-00-00\n";
            cin >> input_birth;
            cout << "Enter the Name\n";
            cin >> input_name;
            cout << "Enter the Phone Numbe in form of 000-0000-0000\n";
            cin >> input_p_num;

            temp.set_data(input_birth, input_name, input_p_num);
            t1.insert_node(temp);
        }
        else if (order == 2) { //노드 조회, search 기능
            cout << "Please enter the Name\n";

            cin >> key;

            temp = t1.search(key);

            cout << "\n -- " << key << "'s record ---" << endl;
            cout << " Birthday     : " << temp.birthday << endl;
            cout << " Name         : " << temp.name << endl;
            cout << " Phone Number : " << temp.p_num << endl;

        }
        else if (order == 3) { //inoder 방식으로 출력
            cout << "\nNode List : inorder sequence \n";
            t1.show_inorder();
        }
        else if (order == 4) {
            cout << "Program Ended.\n";
            break;
        }
        else {
            cout << "Wrong Input. Please enter the number again.\n\n";
        }
    }
    
    return 0;
}
