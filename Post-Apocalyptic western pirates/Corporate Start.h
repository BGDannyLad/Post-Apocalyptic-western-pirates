//#pragma once
//#include <iostream> 
//#include <cstdlib> // For system("pause")
//using namespace std;
//
//void fightYourBoss() {
//    cout << "Your boss shouts at you for sympathizing with the aliens." << endl;
//    cout << "1. Shout back at your boss." << endl; 
//    cout << "2. Keep silent." << endl;
//    cout << "3. Deny it (lie)." << endl;
//    int choice;
//    cin >> choice;
//    if (choice == 1) {
//        cout << "Your boss is furious. \n Boss: This is the end for you!" << endl;
//    }
//    else if (choice == 2) {
//        cout << "Your boss shouts at you again. \n Boss: Well?" << endl;
//    }
//    else if (choice == 3) {
//        cout << "Boss: I have the evidence to prove it! You're a traitor!" << endl;
//    }
//    else {
//        cout << "Invalid choice." << endl;
//    }
//}
//
//int run() {
//    string BossMsg1 = "Captain Fishboneslinkedtogetheronachainbeard: Ha ha me lad, its always a pleasure to see you my boy! \n *whispers in your ear* \n just between you and me, youre the only on in this scurvy crew of flea-infested limb missing greedy drunken wasts of water I can trust. \nRemember that.";
//    string deny = "1. Why do they call you that?";
//    string confess = "2. Aww, youre simply too much";
//    string captainMsg2 = "Captain Fishboneslinkedtogetheronachainbeard: *He turns to you, his complexion visibly darkened* \n my...boy.\n have ye ever tried to pick out a unique name in a videogame where all the good ones were taken?!\n I had to choose this godforsaken name and start wearing these chains of fish bones out of necessity!\n And that toothhlesss fool Jase doesnt help.\n *Jase walks out of his cabin* \n Jase: Hey guys! its a beautiful day, Isnt it?\n Captain Fishboneslinkedtogetheronachainbeard: Shut up Jase, go back into your cabin and pluck out your toe hairs one by one!";
//    string captainMsg3 = "Captain Fishboneslinkedtogetheronachainbeard: Ha ha! You are nothing like that cur of a witless cap-wearing land loving fool of an American called Jase.\n *Jase walks out of his cabin*\n Jase: Hey guys! its a beautiful day, isnt it?\n Captain Fishboneslinkedtogetheronachainbeard: Shut up Jase, Ill wax yer eyebrows and keelhaul ye!";
//    string captainMsg4 = "Captain: I don't believe you. I am going to throw you overboard.";
//    string outlawMsg2 = "Outlaw: I am sorry.";
//    string outlawMsg3 = "Outlaw: I do not regret anything I did!";
//    string captainMsg5 = "Captain: Well, you should.";
//
//    int choice1, choice2;
//
//    cout << captainMsg1 << endl;
//    cout << deny << endl;
//    cout << confess << endl;
//    cin >> choice1;
//
//    if (choice1 == 1) {
//        cout << captainMsg2 << endl;
//        cout << "1. Yeah Jase *Throw bottle*" << endl;
//        cout << "2. Come on, lay off Jase" << endl;
//        cin >> choice2;
//        if (choice2 == 1) {
//            fightYourBoss();
//        }
//        else if (choice2 == 2) {
//            cout << "Captain Fishboneslinkedtogetheronachainbeard: My....boy. \n You are fraternzin with.. defending Jase?!?\n I loved you, you were the only person i could trust..\n but you have betrayed me.\n how about you and this lover of yern take a little dive off the ship." << endl;
//            cout << "1. not like i have a choice in the matter." << endl;
//            cout << "2. aww shucks, here i go." << endl;
//            cout << "3. ";//////////////
//        }
//        else {
//            cout << "Invalid choice." << endl;
//        }
//    }
//    else if (choice1 == 2) {
//        cout << captainMsg3 << endl;
//        cout << "1. I am sorry" << endl;
//        cout << "2. I do not regret anything I did!" << endl;
//        cin >> choice2;
//        if (choice2 == 1) {
//            cout << "Captain makes you walk the plank." << endl;
//        }
//        else if (choice2 == 2) {
//            cout << captainMsg5 << endl;
//            cout << "1. I deserve to be the captain" << endl;
//            cout << "2. Fight the captain" << endl;
//            cin >> choice1;
//            if (choice1 == 1) {
//                cout << "Captain fights you and throws you off the ship." << endl;
//            }
//            else if (choice1 == 2) {
//                cout << "Captain: Stay off my ship. I hope you run out of water and die in the desert ." << endl;
//            }
//            else {
//                cout << "Invalid choice." << endl;
//            }
//        }
//        else {
//            cout << "Invalid choice." << endl;
//        }
//    }
//    else {
//        cout << "Invalid choice." << endl;
//    }
//
//    system("pause"); // For Windows, to keep the console open
//    return 0;
//}#pragma once
