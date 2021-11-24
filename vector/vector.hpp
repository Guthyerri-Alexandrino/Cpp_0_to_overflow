#pragma once

template <class Type>
class Vector {
public:
    Vector() {
        this->container = new Type[10];
        this->capacity = 10;
        this->size = 0;
    }

    Vector(int size) {
        this->container = new Type[size];
        this->capacity = size;
        this->size = size;
    }

    ~Vector() {
        delete[] this->container;
    }

    void push_back(const Type& value) {
        if (this->size >= this->capacity) {
            Type* new_container = new Type[this->capacity * 2];

            for (int i = 0; i < this->capacity; i++) {
                new_container[i] = this->container[i];
            }

            this->capacity *= 2;
            delete[] this->container;

            this->container = new_container;
        }
        this->container[this->size++] = value;
    }

    Type pop_back() {
        Type tmp = this->container[this->size - 1];
        this->size--;
        return tmp;
    }

    void erase(int index) {
        for (int i = index; i < this->size - 1; i++) {
            this->container[i] = this->container[i + 1];
        }

        this->size--;
    }

    Type& get(int index) {
        if (index <= size) {
            return this->container[index];
        }
    }

    Type& operator[](int index) {
        return this->get(index);
    }

    int get_capacity() {
        return this->capacity;
    }

    int get_size() {
        return this->size;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector& vetor) {
        os << "[ ";
        for (int i = 0; i < vetor.size; i++) {
            os << vetor.container[i] << " ";
        }
        os << "]";
        return os;
    }

private:
    Type* container;
    int capacity;
    int size;
};

