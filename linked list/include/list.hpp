#include <node.hpp>
#include <sstream>

template <class Type>
class List {
public:
    List() {
        this->head = nullptr;
        this->size = 0;
    }

    ~List() {
        this->free(this->head);
    }

    void push_front(Type data) {
        Node<Type> *new_node = new Node<Type>(data);

        new_node->next = this->head;
        this->head = new_node;

        ++this->size;
    }

    void push_back(Type data) {
        ++this->size;

        if (this->head == nullptr) {
            this->head = new Node<Type>(data);

            return;
        }

        Node<Type> *current_node {this->head};

        while (current_node->next != nullptr) {
            current_node = current_node->next;
        }

        current_node->next = new Node<Type>(data);
    }

    void insert(Type data, int index) {
        if (this->head == nullptr) {
            this->head = new Node<Type>(data);

            return;
        }

        if (index == 0) {
            Node<Type> *new_node {new Node<Type>(data)};

            new_node->next = this->head;

            this->head = new_node;

            return;
        }

        if (index < 0 || index > this->size) {
            return;
        }

        Node<Type> *current_node {this->head};

        while (--index) {
            current_node = current_node->next;
        }

        Node<Type> *new_node {new Node<Type>(data)};

        new_node->next = current_node->next;

        current_node->next = new_node;

        ++this->size;
    } 

    int get_size() const  {
        return this->size;
    }

    void remove(Type data) {
        this->remove(this->head, data);
    }

    friend std::ostream& operator<<(std::ostream &os, const List<Type>& list) {
        Node<Type> *current_node {list.head};

        int count {0};

        while (current_node != nullptr) {
            if (count++ > 0) {
                os << " ";
            }

            os << current_node->data;
            
            current_node = current_node->next;
        }

        return os;
    }

private:
    Node<Type> *head;
    int size;

    void remove(Node<Type> *&current_node, Type data) {
        if (current_node == nullptr) {
            return;
        }

        if (current_node->data == data) {
            Node<Type> *next = current_node->next;

            delete current_node;

            current_node = next;

            --this->size;

            return;
        }

        remove(current_node->next, data);
    }

    void free(Node<Type> *current_node) {
        if (current_node == nullptr) {
            return;
        }

        if (current_node->next != nullptr) {
            this->free(current_node->next);
        }

        delete current_node;
    }
};