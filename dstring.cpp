#include "dstring.h"


Dstring::Dstring(): data(nullptr), length(0) {
    // std::cout << "DEFAULT CONSTRUCTOR\n";
}

Dstring::Dstring(const Dstring& rhs) {
    // std::cout << "DEEP COPY CONSTRUCTOR\n";
    this->cleanup();
    this->length = rhs.length;
    this->data = new char[this->length + 1];
    for (int i = 0; i < this->length + 1; i++) {
        this->data[i] = rhs.data[i];
    }
}

Dstring::Dstring(const char* s) {
    // std::cout << "CHAR CONSTRUCTOR\n";
    this->cleanup();
    this->length = 0;
    for (; (*s) != '\0'; s++) {
        this->length++;
    }
    s -= length; // could also use a temp char*
    if (length == 0) { return; }
    this->data = new char[this->length + 1];
    for (int i = 0; i < this->length + 1; i++) {
        this->data[i] = s[i];
    }
}

Dstring::~Dstring() {
    this->cleanup();
}

Dstring& Dstring::operator=(const Dstring& obj) {
    // std::cout << "DSTRING ASSIGNMENT OPERATOR\n";
    this->cleanup();
    this->length = obj.length;
    this->data = new char[this->length + 1];
    for (int i = 0; i < this->length + 1; i++) {
        this->data[i] = obj.data[i];
    }
    return *this;
}

Dstring& Dstring::operator=(const char* s) {
    // std::cout << "CHAR ASSIGNMENT OPERATOR\n";
    this->cleanup();
    this->length = 0;
    for (; (*s) != '\0'; s++) {
        this->length++;
    }
    s -= length; // could also use a temp char*
    if (length == 0) { return *this; }
    this->data = new char[this->length + 1];
    for (int i = 0; i < this->length + 1; i++) {
        this->data[i] = s[i];
    }
    return *this;
}

Dstring Dstring::operator+(Dstring const& obj) {
    Dstring result;
    result.length = this->length + obj.length;
    if (result.length == 0) { return result; }
    result.data = new char[result.length + 1];
    for (int i = 0; i < this->length; i++) {
        result.data[i] = this->data[i];
    }
    for (int j = 0; j < obj.length; j++) {
        result.data[j + this->length] = obj.data[j];
    }
    result.data[result.length] = '\0';
    return result;
}

Dstring Dstring::operator-(Dstring const& obj) {
    // std::cout << "UNDEFINED BEHAVIOR\n";
    Dstring result;
    return result;
}

bool Dstring::operator==(const Dstring& obj) const {
    if (this->length != obj.length) { return false; }
    for (int i = 0; i < this->length; i++) {
        if (this->data[i] != obj.data[i]) { return false; }
    }
    return true;
}

bool Dstring::operator>(const Dstring& obj) const {
    if (this->length == 0 && obj.length == 0) { return false; }
    if (this->length != 0 && obj.length == 0) { return true; }
    if (this->length == 0 && obj.length != 0) { return false; }

    for (int i = 0; i < std::min(this->length, obj.length); i++) {
        if (this->data[i] > obj.data[i]) { return false; }
        else if (this->data[i] < obj.data[i]) { return true; }
    }

    if (this->length == obj.length || this->length < obj.length) { return false; }

    return true;
}

bool Dstring::operator<(const Dstring& obj) const {
    if (this->length == 0 && obj.length == 0) { return false; }
    if (this->length != 0 && obj.length == 0) { return false; }
    if (this->length == 0 && obj.length != 0) { return true; }

    for (int i = 0; i < std::min(this->length, obj.length); i++) {
        if (this->data[i] < obj.data[i]) { return false; }
        else if (this->data[i] > obj.data[i]) { return true; }
    }

    if (this->length == obj.length || this->length > obj.length) { return false; }
    return true;
}

void Dstring::cleanup() {
    // std::cout << "CLEANUP\n";
    delete[] this->data;
    this->data = nullptr;
    this->length = 0;
}

int Dstring::getLength() {
    return this->length;
}

char* Dstring::getData() {
    return this->data;
}