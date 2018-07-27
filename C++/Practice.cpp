// #pragma once 상속받은 클래스와 부모 클래스를 헤더로 받을 때

/*
클래스 헤더와 클래스 선언 파일을 구현할 때는 :: 범위 결정 연산자 사용을 주의해야한다.
@ 클래스 헤더
ex)
Mammal();
void breathe(){};
virtual talk(){};

@ 클래스 선언 파일 cpp
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
		cout << "=ㅅ=" << endl;
		cout << "=ㅅ=" << endl;
		cout << "=ㅅ=" << endl;
	}

	void IAP(){
		cout << "두 개의 숫자를 각각 입력" << endl;
		cin >> x >> y;
		cout << " x * y = " << x * y << endl;

		if (x > y)
			cout << "x가 y보다 큽니다 : " << x << endl;
		else if (x == y)
			cout << "x와 y는 같습니다" << endl;
		else
			cout << "y가 x보다 큽니다 : " << y << endl;

		cout << "x+y =" << x + y << endl;
	}

};

struct Armor {
	string name;
	int armorClass;
	double durability;
};

struct nPlayer { // struct, class 비슷하지만 struct는 기본 public, class는 private, 따라서 맴버변수가 적거나 C와 호환되어야 하는 경우 구조체를 그 외엔 클래스 사용
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

class Player { // struct, class 비슷하지만 struct는 기본 public, class는 private, 따라서 맴버변수가 적거나 C와 호환되어야 하는 경우 구조체를 그 외엔 클래스 사용
	string name;
	int hp;
	Armor armor;

public:
	// 객체 이름 함수는 생성자, ~객체 이름 함수는 소멸자
	Player() {
		name = "관리자";
		cout << "객체 생성 및 실행 이름 설정 완료" << endl;
	}
	~Player() {
		cout << "객체 종료됨" << endl;
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
		cout << "포유류 태어남" << endl;
	}
	~Mammal() {
		cout << "포유류 죽음" << endl;
	}
	void breathe() {
		cout << "숨을 들이 마시고 내쉽니다." << endl;
	}
	virtual void talk() {
		cout << "포유류는 말했다." << endl;
	}
	virtual void walk() = 0;

};

class dog : public Mammal{
public :
	dog() {
		cout << "개가 태어났다." << endl;
	}
	~dog() {
		cout << "개가 죽었다." << endl;
	}
	virtual void talk() override {
		cout << "멍멍!" << endl;
	}
	virtual void walk() override {
		cout << "왼발 오른발" << speed << " 속도로 움직임 "<< endl;
	}
};

class human : public Mammal {
	bool civilized;
public:
	human() {
		speed = 2.0;
		cout << "사람이 태어났다." << endl;
		civilized = true;

	}
	~human() {
		cout << "사람이 죽었다." << endl;
	}
	virtual void talk() override {
		cout << " 당신이 심연을 들여다보면 심연도 당신을 들여다 봅니다. " << endl;
	}
	virtual void walk() override {
		cout << "왼발 오른발" << speed << " 속도로 움직임 " << endl;
	}
	void attack() {
		if (civilized == true)
			cout << "문명화된 사람은 공격하지 않는다." << endl;
		else
			cout << "이 사람은 원시인으로 공격할지도 모른다. " << endl;
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
			cout << "과자" << endl;
			break;
		case meat:
			cout << "고기1" << endl;
			break;
		case beaf:
			cout << "고기2" << endl;
			break;
	}

	//--------------------------------------------------------------------//

	enum Item
	{
		Coin, Key, Dollar
	};

	Item i = Coin;

	if (i == Coin) {
		cout << "안녕하세요" << endl;
	}
	else if (i == Dollar) {
		cout << "화폐" << endl;
	}

	for (int j = 1; j < 5; j++) {
		for (int a = 0; a < j; a++)
			printf("*");
		cout << " " << endl;
	}

	//--------------------------------------------------------------------//

	string s = "스트링 s는 객체입니다";

	s.append("~!");

	// cout << "오류 발생합니다... 이유는 모릅니다." << s;

	//--------------------------------------------------------------------//

	ST1.print();
	// ST1.IAP(); 입력 과정 생략

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

	Player *p = new Player(); // 동적 할당, delete 구문 없이는 사라지지 않음 따라서 메모리 누출 발생 위험이 있음
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
		cout << n[i] << endl; string은 cout을 통해 출력할 수 없는 오류가 발생한다.
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
	delete[] q; // 배열은 []를 붙여줘야함


	// c에서의 동적 할당 방법, 사용가능함
	int *y = (int*)malloc(InP * sizeof(int));
	for (int i = 0; i < 5; i++) {
		y[i] = i * 2;
		cout << y[i] << endl;
	}
	free(y);

	//--------------------------------------------------------------------//

	system("PAUSE");

	// ---- 끝 / Finish ---- //
}