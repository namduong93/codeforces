#include <bits/stdc++.h>
using namespace std;

class First_Fit_Allocator {
private:
    char* _buffer;
    int _maximum_size = 0;
    set< pair<int, int> > _container;

    int take_size(char* c) {
        char* run = c;
        int size = 0;
        while(*run != '\0') {
            size++;
            run++;
        }
        return size;
    }
    void copy_to_buffer(char* a, char* b) {
        char* run = b;
        while(*run != '\0') {
            *a = *run;
            run++;
            a++;
        }
    }
public:
    First_Fit_Allocator(int maximum_size) {
        this->_buffer = new char[maximum_size];
        this->_maximum_size = maximum_size;
    }
    int get_size() {
        return _maximum_size;
    }
    char* get_buffer() {
        return this->_buffer;
    }
    char* allocate(char *c) {
        int pre = 0;
        int size = take_size(c);
        for(auto element : this->_container) {
            if(element.first - pre >= size) {
                copy_to_buffer(this->_buffer + pre, c);
                this->_container.insert({pre, pre + size});
                return this->_buffer + pre;
            }
            pre = element.second;
        }
        if(this->_maximum_size - pre >= size) {
            copy_to_buffer(this->_buffer + pre, c);
            this->_container.insert({pre, pre + size});
            return this->_buffer + pre;
        }
        return "Error";
    }
    char* deallocate(char *c, int size) {
        auto it = this->_container.find({c - this->_buffer, c - this->_buffer + size});
        if(it != this->_container.end()) {
            this->_container.erase(it);

            return "Success";
        }
        return "Can not find that";
    }
};

int main() {
    First_Fit_Allocator ffa = First_Fit_Allocator(1000);
    char *c = "hahaha";
    char *b = "hehe";
    char* cc = ffa.allocate(c); //hahaha
    ffa.allocate(b); //hahahahehe
    ffa.deallocate(cc, 6); //......hehe
    char* first_b = ffa.allocate(b); // hehe..hehe
}