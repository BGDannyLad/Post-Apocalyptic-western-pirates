#include <iostream>
#include <string>
#include "Corporate Start.h"
#include "Menu.h"
#include "Outlaw Start.h"
#include "IntroScene.h"

using namespace std;


int main() {
	CutScreen a;
	a.intro1();
	a.intro2();
	a.intro3();
	a.Shipwave();
	
	CharacterType chosenCharacter = openMenu(1);

	switch (chosenCharacter) {
	case Corporate:

		break;
	case Outlaw:

		break;
	case None:

		break;
	}
	switch (chosenCharacter) {
	case Corporate:
	CorpoIntro c;
	c.corpo1();
	c.corpo2();
	c.corpo3();
	c.corpo4();
	runcorpormsg();
		break;
	
	case Outlaw:
	PirateIntro b;
	b.pie1();
	b.pie2();
	b.pie3();
	b.pie4();
	runpiratemsg();
		break;
	case None:
		break;
	}

	
	
	
	




}
