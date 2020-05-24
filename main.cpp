#include <iostream>
#include <vector>

using namespace std;

enum TOPPING {
    Choclate,
    Caramel,
    Strawberry,
};

string getToping(TOPPING topping) {
    switch (topping) {
        case TOPPING::Choclate:
            return "Choclate";
        case TOPPING::Caramel:
            return "Caramel";
        case TOPPING::Strawberry:
            return "Strawberry";

    }
}

class Coffee {
    string sort;
    unsigned int roasting;
    TOPPING topping;
public:
    Coffee(string sort,  unsigned int roasting, TOPPING topping) :
            sort(sort), roasting(roasting),
            topping(topping) {
    }

    const string &getSort() const {
        return sort;
    }

    const unsigned int &getRoasting() const {
        return roasting;
    }

    TOPPING getTopping() const {
        return topping;
    }

    string getDescription() {
        return sort + " " + to_string(roasting) + " " + ::getToping(topping) ;
    }

    static Coffee *CoffeeWithCaramel() {
        return new Coffee("Americano", 9, TOPPING ::Caramel);
    }

    static Coffee *CoffeeWithChoclate() {
        return new Coffee("Latte", 2, TOPPING ::Choclate);
    }

};

int main() {
    vector<Coffee *> cup1, cup2;

    cup1.push_back(Coffee::CoffeeWithCaramel());

    cout << "Coffee for you : " << endl;
    for (int i = 0, len = cup1.size(); i < len; i++) {
        cout << cup1[i]->getDescription() << endl;
    }

    for (int i = 0; i < 2; i++) {
        cup2.push_back(Coffee::CoffeeWithChoclate());
    }

    cout << "Coffee for your friends: " << endl;
    for (int i = 0, len = cup2.size(); i < len; i++) {
       cout << cup2[i]->getDescription() << endl;
    }

    return 0;
}