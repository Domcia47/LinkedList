#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <stdexcept>
class List {
public:   
    List();
    ~List(); 
    void push_front(int x); // Dołącza element na początek listy
    int pop_front(); // Usuwa i zwraca element z początku listy
    void push_back(int x); // Dołącza element na koniec listy
    int pop_back(); // Usuwa i zwraca element z końca listy
    int size_(); // Zwraca liczbę elementów w liście
    bool empty(); // Zwraca 'true' gdy lista jest pusta
    void clear(); // Czyści listę
    int find(int x); // Zwraca pozycję pierwszego elementu o wartości 'x'
    int erase(int i); // Usuwa i zwraca element na pozycji 'i'
    void insert(int i, int x); // Wstawia element 'x' przed pozycję 'i'
    int remove(int x); // Usuwa wystąpienia 'x' i zwraca ich liczbę
    
private:
    int size;
    
    struct Node{
        
        int data;
        Node* next;
        Node* prev;

        Node(int value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* guard;     //wskażnik na węzeł pomocniczy, ktorego next wskazuje na pierwszy element, a prev na ostatni
    
};
    //konstruktor
    List::List() : size(0) {
        guard = new Node(0);
        guard->next = guard;
        guard->prev = guard;
    }

    List::~List() {
        clear();
        delete guard;
    }

void List::push_front(int x) {
    Node* newNode = new Node(x); //tworzymy nowy węzeł
    newNode->prev = guard; //wsakźnik prev nowego pierwszego węzła wskazuje na guarda
    newNode->next = guard->next; //wskaźnik next nowego pierwszego węzła wskazuje na drugi element
    guard->next->prev = newNode; //prev drugiego elementu wskazuje na pierwszy
    guard->next = newNode; //next guarda wskazuje na nowy pierwszy element
    size++; //zwiększamy rozmiar
}

int List::pop_front() {
    if (empty()) {
        throw std::out_of_range("The list is empty");
    }

    int value = guard->next->data;
    Node* temp = guard->next;//zapamiętujemy wskaźnik do pierwszego elementu
    guard->next = temp->next; //nowym pierwszym elementem staje się drugi element
    temp->next->prev = guard; //wskaźnik prev nowego pierwszego elementu wskazuje na guarda
    delete temp;
    size--;
    return value;
}

void List::push_back(int x) {
    Node* newNode = new Node(x); //towrzymy nowy węzeł
    newNode->prev = guard->prev; //prev nowego ostatniego węzła wskazuje na przedostatni węzeł
    newNode->next = guard; //next nowego węzła wskazuje na guarda
    
    guard->prev->next = newNode; //next dawnego ostatniego elementu wskazuje na nowy ostatni element
    guard->prev = newNode; //pev guarda wskazuje na nowy ostatni element
    
    size++;
}

int List::pop_back() {
    if (empty()) {
        throw std::out_of_range("The list is empty");
    }

    int value = guard->prev->data;
    Node* temp = guard->prev;
    guard->prev = temp->prev;
    temp->prev->next = guard;
    size--;
    
    delete temp;
    return value;
}
int List::size_(){
    return size;
}

bool List::empty() {
    return size == 0;
}

void List::clear() {
    while (!empty()) {
        pop_front();
    }
}

int List::find(int x) {
    int i = 0;
    Node* node = guard->next;
    while (node != guard) {
        if (node->data == x) {
            return i;
        }
        node = node->next;
        i++;
    }
    return -1;
}

int List::erase(int i) {
    if (i >= size || i < 0) {
        throw std::out_of_range("Bad index");
    }

    Node* node = guard->next; //wskaźnik na pierwszy element
    for (int j = 0; j < i; j++) {
        node = node->next; //przechodzimy po koljnych węzłach 
    }

    int result = node->data;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
    size--;
    return result;
}

void List::insert(int i, int x) {
    if (i < 0 || i > size) {
        throw std::out_of_range("Index out of bounds");
    }

    Node* newNode = new Node(x);
    Node* node = guard->next;
    for (int j = 0; j < i; j++) {
        node = node->next;
    }

    newNode->prev = node->prev;
    newNode->next = node;
    node->prev->next = newNode;
    node->prev = newNode;
    size++;
}

int List::remove(int x) {
    int counter = 0;
    Node* node = guard->next;
   
    while (node != guard) {
        if (node->data == x) {
            Node* temp = node;
            node->next->prev = node->prev;
            node->prev->next = node->next;
            node = node->next;
            
            size--;
            counter++;
            delete temp;
        } 
        else {
            node = node->next;
        }
    }
    return counter;
}

#endif