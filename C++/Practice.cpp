// #pragma once ��ӹ��� Ŭ������ �θ� Ŭ������ ����� ���� ��

/*
Ŭ���� ����� Ŭ���� ���� ������ ������ ���� :: ���� ���� ������ ����� �����ؾ��Ѵ�.
@ Ŭ���� ���
ex)
Mammal();
void breathe(){};
virtual talk(){};

@ Ŭ���� ���� ���� cpp
ex)
#include <Mammal.h>
Mammal :: Mammal(){
 Mammal::breathe(){
  ~~~
 }
  ~~~
}
*/

#include <iostream>
#include <string.h>

using namespace std;

struct ST {
	
	int x, y;

	void print() {
		cout << "=��=" << endl;
		cout << "=��=" << endl;
		cout << "=��=" << endl;
	}

	void IAP(){
		cout << "�� ���� ���ڸ� ���� �Է�" << endl;
		cin >> x >> y;
		cout << " x * y = " << x * y << endl;

		if (x > y)
			cout << "x�� y���� Ů�ϴ� : " << x << endl;
		else if (x == y)
			cout << "x�� y�� �����ϴ�" << endl;
		else
			cout << "y�� x���� Ů�ϴ� : " << y << endl;

		cout << "x+y =" << x + y << endl;
	}

};

struct Armor {
	string name;
	int armorClass;
	double durability;
};

struct nPlayer { // struct, class ��������� struct�� �⺻ public, class�� private, ���� �ɹ������� ���ų� C�� ȣȯ�Ǿ�� �ϴ� ��� ����ü�� �� �ܿ� Ŭ���� ���
private:
	string name;
	int hp;
	Armor armor;

public:
	void damege(int damegeA) {
		int reduction = damegeA - armor.armorClass;
		if (reduction < 0) {
			reduction = 1;
		}
		hp -= reduction;
	}
};

class Player { // struct, class ��������� struct�� �⺻ public, class�� private, ���� �ɹ������� ���ų� C�� ȣȯ�Ǿ�� �ϴ� ��� ����ü�� �� �ܿ� Ŭ���� ���
	string name;
	int hp;
	Armor armor;

public:
	// ��ü �̸� �Լ��� ������, ~��ü �̸� �Լ��� �Ҹ���
	Player() {
		name = "������";
		cout << "��ü ���� �� ���� �̸� ���� �Ϸ�" << endl;
	}
	~Player() {
		cout << "��ü �����" << endl;
	}

	void damege(int damegeA) {
		int reduction = damegeA - armor.armorClass;
		if (reduction < 0) {
			reduction = 1;
		}
		hp -= reduction;
	}

	string getName() const {
		return name;
	}
	string setName(string newName) {
		name = newName;
	}
};

class Mammal {
protected:
	int hp;
	double speed;

public :
	Mammal() {
		hp = 100;
		speed = 1.0;
		cout << "������ �¾" << endl;
	}
	~Mammal() {
		cout << "������ ����" << endl;
	}
	void breathe() {
		cout << "���� ���� ���ð� �����ϴ�." << endl;
	}
	virtual void talk() {
		cout << "�������� ���ߴ�." << endl;
	}
	virtual void walk() = 0;

};

class dog : public Mammal{
public :
	dog() {
		cout << "���� �¾��." << endl;
	}
	~dog() {
		cout << "���� �׾���." << endl;
	}
	virtual void talk() override {
		cout << "�۸�!" << endl;
	}
	virtual void walk() override {
		cout << "�޹� ������" << speed << " �ӵ��� ������ "<< endl;
	}
};

class human : public Mammal {
	bool civilized;
public:
	human() {
		speed = 2.0;
		cout << "����� �¾��." << endl;
		civilized = true;

	}
	~human() {
		cout << "����� �׾���." << endl;
	}
	virtual void talk() override {
		cout << " ����� �ɿ��� �鿩�ٺ��� �ɿ��� ����� �鿩�� ���ϴ�. " << endl;
	}
	virtual void walk() override {
		cout << "�޹� ������" << speed << " �ӵ��� ������ " << endl;
	}
	void attack() {
		if (civilized == true)
			cout << "����ȭ�� ����� �������� �ʴ´�." << endl;
		else
			cout << "�� ����� ���������� ���������� �𸥴�. " << endl;
	}
};

void main() {

	struct ST ST1;

	//--------------------------------------------------------------------//

    enum Food {
		snack, meat, beaf
	};

	Food a = snack;
	switch (a) {
		case snack :
			cout << "����" << endl;
			break;
		case meat:
			cout << "���1" << endl;
			break;
		case beaf:
			cout << "���2" << endl;
			break;
	}

	//--------------------------------------------------------------------//

	enum Item
	{
		Coin, Key, Dollar
	};

	Item i = Coin;

	if (i == Coin) {
		cout << "�ȳ��ϼ���" << endl;
	}
	else if (i == Dollar) {
		cout << "ȭ��" << endl;
	}

	for (int j = 1; j < 5; j++) {
		for (int a = 0; a < j; a++)
			printf("*");
		cout << " " << endl;
	}

	//--------------------------------------------------------------------//

	string s = "��Ʈ�� s�� ��ü�Դϴ�";

	s.append("~!");

	// cout << "���� �߻��մϴ�... ������ �𸨴ϴ�." << s;

	//--------------------------------------------------------------------//

	ST1.print();
	// ST1.IAP(); �Է� ���� ����

	//--------------------------------------------------------------------//
	
	dog D;
	D.breathe();
	D.talk();
	D.walk();

	human H;
	H.breathe();
	H.talk();
	H.walk();
	H.attack();

	//--------------------------------------------------------------------//

	Player *p = new Player(); // ���� �Ҵ�, delete ���� ���̴� ������� ���� ���� �޸� ���� �߻� ������ ����
	delete p;

	//--------------------------------------------------------------------//

	int array[5];

	array[0] = 0;
	array[1] = 1;
	array[2] = 2;
	array[3] = 3;
	array[4] = 4;

	for (int i=0; i < 5; i++)
		cout << array[i] << endl;

	string n[5];

	n[0] = "h";
	n[1] = "e";
	n[2] = "l";
	n[3] = "l";
	n[4] = "o";
	/*
	for (int i; i < 5; i++)
		cout << n[i] << endl; string�� cout�� ���� ����� �� ���� ������ �߻��Ѵ�.
	*/
	double o[5];

	//--------------------------------------------------------------------//
	int InP;
	cin >> InP;
	int *q = new int[InP];
	for (int i=0; i < 5; i++) {
		q[i] = i * 2;
		cout << q[i] << endl;
	}
	delete[] q; // �迭�� []�� �ٿ������


	// c������ ���� �Ҵ� ���, ��밡����
	int *y = (int*)malloc(InP * sizeof(int));
	for (int i = 0; i < 5; i++) {
		y[i] = i * 2;
		cout << y[i] << endl;
	}
	free(y);

	//--------------------------------------------------------------------//

	system("PAUSE");

	// ---- �� / Finish ---- //
}