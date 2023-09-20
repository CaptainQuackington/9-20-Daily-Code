#include<iostream>
using namespace std;

class princess {
private:
	string name;
	int age;
	int def;
	int atk;
	int health;
public:
	princess();
	princess(string n, int d, int k, int a, int h);
	int attack();
	void defend(int a);
	int gethealth() { return health; }
    void printinfo();
};
int main() {
	princess rapunzel("rapunzel", 18, 30, 40, 100);
	princess cinderella("cinderella", 19, 40, 25, 100);

    //30, 40, 100 - defense, attack, hp
    //40, 25, 100 - defense, attack, hp

    rapunzel.printinfo();
    cinderella.printinfo();

    while (rapunzel.gethealth() > 0 and cinderella.gethealth() > 0) { //game loop
        rapunzel.defend(cinderella.attack());
        cinderella.defend(rapunzel.attack());
        
    }

}

princess::princess() {
    name = " ";
    atk = 0;
    def = 0;
    age = 0;
    health = 0;
}

//paramaterized constructor
princess::princess(string n, int k, int d, int a, int h) {
    name = n;
    atk = k;
    def = d;
    age = a;
    health = h;

}

int princess::attack() {
    cout << name << " attacks for " << atk << "!" << endl;
    return atk;
}

void princess::defend(int a) {
    int g = ((def / 2) - a);
    if (g >= 0)
        g = -g;

    cout << name << " took " << g << " damage!!" << endl;
    health += g;
    cout << name << "'s health is now " << health << "." << endl;
}

void princess::printinfo() {
    cout << "Princess " << name <<" has entered the arena\n";
    cout << name + "'s age is " << age << '\n';
    cout << "Their defense is " << def << '\n';
    cout << "They have a damage of " <<  atk << '\n';
}
