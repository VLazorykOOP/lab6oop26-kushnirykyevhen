#include <iostream>
#include <string>
#include <list>

using namespace std;

// ======================================================
// TASK 1
// Virtual and non-virtual inheritance
// ======================================================

// ---------- WITHOUT VIRTUAL INHERITANCE ----------

class A1 {
public:
    int a;

    A1() : a(1) {}
};

class B1 : public A1 {
public:
    int b;

    B1() : b(2) {}
};

class C1 : public A1 {
public:
    int c;

    C1() : c(3) {}
};

class D1 : public B1, public C1 {
public:
    int d;

    D1() : d(4) {}
};

// ---------- WITH VIRTUAL INHERITANCE ----------

class A2 {
public:
    int a;

    A2() : a(1) {}
};

class B2 : virtual public A2 {
public:
    int b;

    B2() : b(2) {}
};

class C2 : virtual public A2 {
public:
    int c;

    C2() : c(3) {}
};

class D2 : public B2, public C2 {
public:
    int d;

    D2() : d(4) {}
};

void task1() {
    cout << "========== TASK 1 ==========\n\n";

    D1 obj1;
    D2 obj2;

    cout << "WITHOUT virtual inheritance:\n";
    cout << "Size of A1: " << sizeof(A1) << " bytes\n";
    cout << "Size of B1: " << sizeof(B1) << " bytes\n";
    cout << "Size of C1: " << sizeof(C1) << " bytes\n";
    cout << "Size of D1: " << sizeof(D1) << " bytes\n\n";

    cout << "WITH virtual inheritance:\n";
    cout << "Size of A2: " << sizeof(A2) << " bytes\n";
    cout << "Size of B2: " << sizeof(B2) << " bytes\n";
    cout << "Size of C2: " << sizeof(C2) << " bytes\n";
    cout << "Size of D2: " << sizeof(D2) << " bytes\n\n";
}

// ======================================================
// TASK 2
// List, Stack, Queue
// ======================================================

class List {
protected:
    list<int> data;

public:
    virtual void insert(int value) = 0;
    virtual int remove() = 0;

    virtual void show() {
        for (int x : data) {
            cout << x << " ";
        }
        cout << endl;
    }

    virtual ~List() {}
};

// ---------- STACK ----------

class Stack : public List {
public:
    void insert(int value) override {
        data.push_back(value);
    }

    int remove() override {
        if (data.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }

        int value = data.back();
        data.pop_back();

        return value;
    }
};

// ---------- QUEUE ----------

class Queue : public List {
public:
    void insert(int value) override {
        data.push_back(value);
    }

    int remove() override {
        if (data.empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }

        int value = data.front();
        data.pop_front();

        return value;
    }
};

void task2() {
    cout << "========== TASK 2 ==========\n\n";

    Stack st;
    Queue qu;

    st.insert(10);
    st.insert(20);
    st.insert(30);

    qu.insert(100);
    qu.insert(200);
    qu.insert(300);

    cout << "Stack elements: ";
    st.show();

    cout << "Removed from stack: ";
    cout << st.remove() << endl;

    cout << "Stack after remove: ";
    st.show();

    cout << endl;

    cout << "Queue elements: ";
    qu.show();

    cout << "Removed from queue: ";
    cout << qu.remove() << endl;

    cout << "Queue after remove: ";
    qu.show();

    cout << endl;
}

// ======================================================
// TASK 3
// Operating system and software
// ======================================================

// ---------- OPERATING SYSTEM ----------

class OperatingSystem {
protected:
    string osName;
    int version;

public:
    OperatingSystem(string n = "", int v = 0) {
        osName = n;
        version = v;
    }

    OperatingSystem(const OperatingSystem& other) {
        osName = other.osName;
        version = other.version;
    }

    virtual ~OperatingSystem() {}

    virtual void input() {
        cout << "Enter OS name: ";
        cin >> osName;

        cout << "Enter OS version: ";
        cin >> version;
    }

    virtual void output() const {
        cout << "OS name: " << osName << endl;
        cout << "Version: " << version << endl;
    }

    friend ostream& operator<<(ostream& out, const OperatingSystem& obj) {
        out << "OS name: " << obj.osName << endl;
        out << "Version: " << obj.version << endl;

        return out;
    }

    friend istream& operator>>(istream& in, OperatingSystem& obj) {
        cout << "Enter OS name: ";
        in >> obj.osName;

        cout << "Enter version: ";
        in >> obj.version;

        return in;
    }
};

// ---------- SOFTWARE ----------

class Software {
protected:
    string softwareName;
    double size;

public:
    Software(string n = "", double s = 0) {
        softwareName = n;
        size = s;
    }

    Software(const Software& other) {
        softwareName = other.softwareName;
        size = other.size;
    }

    virtual ~Software() {}

    virtual void input() {
        cout << "Enter software name: ";
        cin >> softwareName;

        cout << "Enter software size: ";
        cin >> size;
    }

    virtual void output() const {
        cout << "Software name: " << softwareName << endl;
        cout << "Size: " << size << " GB" << endl;
    }

    friend ostream& operator<<(ostream& out, const Software& obj) {
        out << "Software name: " << obj.softwareName << endl;
        out << "Size: " << obj.size << " GB" << endl;

        return out;
    }

    friend istream& operator>>(istream& in, Software& obj) {
        cout << "Enter software name: ";
        in >> obj.softwareName;

        cout << "Enter software size: ";
        in >> obj.size;

        return in;
    }
};

// ---------- WINDOWS ----------

class Windows : public OperatingSystem, public Software {
private:
    string edition;

public:
    Windows(string os = "", int ver = 0,
        string soft = "", double sz = 0,
        string ed = "")
        : OperatingSystem(os, ver),
        Software(soft, sz) {

        edition = ed;
    }

    Windows(const Windows& other)
        : OperatingSystem(other),
        Software(other) {

        edition = other.edition;
    }

    virtual ~Windows() {}

    void input() override {
        OperatingSystem::input();

        cout << "Enter software name: ";
        cin >> softwareName;

        cout << "Enter software size: ";
        cin >> size;

        cout << "Enter Windows edition: ";
        cin >> edition;
    }

    void output() const override {
        OperatingSystem::output();

        cout << "Software name: "
            << softwareName << endl;

        cout << "Size: "
            << size << " GB" << endl;

        cout << "Edition: "
            << edition << endl;
    }

    friend ostream& operator<<(ostream& out, const Windows& obj) {
        out << "OS name: " << obj.osName << endl;
        out << "Version: " << obj.version << endl;
        out << "Software name: " << obj.softwareName << endl;
        out << "Size: " << obj.size << " GB" << endl;
        out << "Edition: " << obj.edition << endl;

        return out;
    }

    friend istream& operator>>(istream& in, Windows& obj) {
        cout << "Enter OS name: ";
        in >> obj.osName;

        cout << "Enter version: ";
        in >> obj.version;

        cout << "Enter software name: ";
        in >> obj.softwareName;

        cout << "Enter software size: ";
        in >> obj.size;

        cout << "Enter Windows edition: ";
        in >> obj.edition;

        return in;
    }
};

void task3() {
    cout << "========== TASK 3 ==========\n\n";

    Windows w;

    cin >> w;

    cout << endl;
    cout << "Entered information:\n";
    cout << w << endl;
}

// ======================================================
// MENU
// ======================================================

void menu() {
    int choice;

    do {
        cout << "\n========== MAIN MENU ==========\n";
        cout << "1 - Task 1\n";
        cout << "2 - Task 2\n";
        cout << "3 - Task 3\n";
        cout << "0 - Exit\n";
        cout << "Choose option: ";

        cin >> choice;

        cout << endl;

        switch (choice) {
        case 1:
            task1();
            break;

        case 2:
            task2();
            break;

        case 3:
            task3();
            break;

        case 0:
            cout << "Program finished.\n";
            break;

        default:
            cout << "Wrong option!\n";
        }

    } while (choice != 0);
}

// ======================================================
// MAIN
// ======================================================

int main() {
    menu();

    return 0;
}