#ifndef DSTRING_H
#define DSTRING_H

#include <iostream>

class Dstring {
    private:
        // init data in header file to avoid unitialized value warning
        char* data = nullptr;
        int length;

    public:
        Dstring();
        Dstring(const Dstring& rhs);
        Dstring(const char* s);
        ~Dstring();

        Dstring& operator=(const Dstring& obj);
        Dstring& operator=(const char* s);
        Dstring operator+(Dstring const& obj);
        Dstring operator-(Dstring const& obj); 

        bool operator==(const Dstring& obj) const;
        bool operator>(const Dstring& obj) const;
        bool operator<(const Dstring& obj) const;

        void cleanup();
        int getLength();
        char* getData(); // be careful when playing with the pointer

        friend std::ostream& operator<<(std::ostream& os, const Dstring& ds);
        friend std::istream& operator>>(std::istream& is, Dstring& ds);
};

inline std::ostream& operator<<(std::ostream& os, const Dstring& ds) {
    for (int i = 0; i < ds.length; i++) {
        os << ds.data[i];
    }
    return os;
}

inline std::istream& operator>>(std::istream& is, Dstring& ds) {
    ds.cleanup();
    ds.data = new char[1]{'\0'};

    Dstring dtemp;
    dtemp.data = new char[1]{'\0'};
    dtemp.length = 1;

    char ctemp;
    while (is.get(ctemp)) {
        if (ctemp == '\n') { break; }
        dtemp.data[0] = ctemp;
        ds = ds + dtemp;
    }

    dtemp.cleanup();
    return is;
}

#endif // DSTRING_H