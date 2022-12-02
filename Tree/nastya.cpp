#include <iostream>
using namespace std;

struct tree{
    int key;
    tree* parent;
    tree* left;
    tree* right;
};
int main(){
    tree* root = NULL, *header = NULL;
    int buf, counter, hight = 0;
    cin >> buf;
    root = new tree; root->key = buf; root->parent = NULL; root->left = NULL; root->right = NULL; hight++;
    while (true){
        cin >> buf; 
        if (buf == 0) break;
        counter = 1; header = root;
        while (true){
            if (buf < header->key) // если новое число меньше header, то идем влево
                if (header->left == NULL){ // если слева от header еще нет чисел
                    header->left = new tree;
                    (header->left)->key = buf;
                    (header->left)->parent = header;
                    (header->left)->left = NULL;
                    (header->left)->right = NULL;
                    counter++;
                    break;
                }
                else{ // если слева от header уже есть числа
                header = header->left; 
                counter++; 
                };
            if (buf > header->key) // если новое число больше header, то идем вправо
                if (header->right == NULL){ // если справа от header еще нет чисел
                    header->right = new tree;
                    (header->right)->key = buf;
                    (header->right)->parent = header;
                    (header->right)->left = NULL;
                    (header->right)->right = NULL;
                    counter++;
                    break;
                }
                else{ // если справа от header уже есть числа
                    header = header->right;
                    counter++; 
                };
            if (buf == header->key) break; // если элемент уже существует, добавлять его не нужно (по условию)
        };
        if (counter > hight) hight = counter;
    }
    cout<< hight;
}
