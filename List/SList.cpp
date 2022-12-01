#include <iostream>

using namespace std;

class SListItem{
public:    
  int value; 
  SListItem *next; 
};

class SList{
    //Вместо base, предложенным у учебнике, я буду различать пограничные элементы так:
    //На первый указывает head, а у последнего указаталь на следующий равен nullptr.
private:
    SListItem *head;
public:
    //Конструктор по умолчанию
    SList() {
        head = nullptr;
    }
    //Добавление элемента в начало списка
    void insert_first(int d){
        SListItem *newItem = new SListItem();
        newItem->value = d;
        newItem->next = head;
        head = newItem;
    }
    //Добавление элемента в конец списка
    void insert_last(int d){
        SListItem *newItem = new SListItem; //Динамически создаём новый объект класса
        newItem->value = d;     //Загрузка данных
        newItem->next = nullptr;     //Последний элемент, поэтому nullptr
        if(head == nullptr)     //Если список пустовал
            head = newItem;
        else{                 
            SListItem *current = head;
            //Ищем конец списка
            while(current->next != nullptr)
                current = current->next;
            //Предшествующий указывает на последний
            current->next = newItem;
        }
    } 
    //Добавление элемента за конкретным другим
    int insert(int now, int d){
        SListItem *newItem = new SListItem;
        newItem->value = d;
        SListItem *current = head;
        //Ищём, где находится нужный элемент
        while(current->value != now){
            if (current->next == nullptr) {
                cerr << "Такого элемента нет в списке" << endl;
                return -1;
            }
            current = current->next;    
        }
        newItem->next = current->next;
        current->next = newItem;
        return 0;
    }
    //Удалить конкретный элемент
    int remove(int d){
        SListItem *current = head;
        //Нам нужен указатель предшествующий нужному элементу
        while((current->next)->value != d){
            if (current->next == nullptr) {
                cerr << "Такого элемента нет в списке" << endl;
                return -1;
            }
            current = current->next;    
        }
        SListItem *temp = current->next;
        current->next = (current->next)->next;
        delete temp;
        return 0;
    }
    //Вывод списка на экран
    void printList(){
        SListItem *current = head;
        while(current != NULL){
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main(){
    SList MyList;
    cout << "Добавляем элементы: 28 в конец, 337 в начало, 488 в конец" << endl; 
    MyList.insert_last(28);
    MyList.insert_first(337);
    MyList.insert_last(488);
    MyList.printList();
    cout << "Вставим 1 после 337" << endl;
    MyList.insert(337, 1);
    MyList.printList();    
    cout << "Удалим 28" << endl;
    MyList.remove(28);
    MyList.printList();   
    return 0;
}
