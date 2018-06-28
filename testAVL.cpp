#include <bits/stdc++.h>
#include "AVLTree.h"
using namespace std;


int main() {
    int n;
    cin >> n;
    AVLTree tree;
    while(n--){
        int tmp;
        cin >> tmp;
        tree.insert(tmp);
    }
    tree.in_order();
    int tmp;
    cin >> tmp;
    tree.remove(tmp);
    tree.in_order();
}