#ifndef COMPUTERVISION_CONTEXT_H
#define COMPUTERVISION_CONTEXT_H

#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
class Context {
public:
    Context() = default;
    explicit Context(T obj) {
        object = obj;
    }

    string ObjectType() {
        string type = typeid(object).name();
        if ((type == "i") || (type == "b") || (type == "Ss") || (type == "d")) {
            return "Scalar";
        } else if (type.substr(0, 19) == "St6vectorI7ContextI") {
            return "Vector";
        } else if (type.substr(0, 18) == "St3mapISs7ContextI") {
            return "Map";
        } else {
            return "None";
        }
    }

    Context& operator=(const Context<T>& other) {
        object = other.object;
        return *this;
    }

    auto &operator[](const string& key) {
        return object[key];
    }
    auto &operator[](const size_t& index) {
        return object[index];
    }

    T GetScalar() {
        if (ObjectType() == "Scalar") {
            return object;
        } else {
            cout << "Not a Scalar quantity" << endl;
        }
    }

    void Delete() {
        if ((ObjectType() == "Map") || (ObjectType() == "Vector")) {
            object.clear();
        }
    }
    void Move(Context<T>& other) {
        object = other.object;
        other.Delete();
    }

    auto Begin() {
        if ((ObjectType() == "Map") || (ObjectType() == "Vector")) {
            return object.begin();
        }
    }
    auto End() {
        if ((ObjectType() == "Map") || (ObjectType() == "Vector")) {
            return object.end();
        }
    }
    auto &operator++() {
        if ((ObjectType() == "Map") || (ObjectType() == "Vector")) {
            return object.begin()+1;
        }
    }
    T& operator*() {
        return object;
    }

private:
    T object;
};
#endif //COMPUTERVISION_CONTEXT_H
