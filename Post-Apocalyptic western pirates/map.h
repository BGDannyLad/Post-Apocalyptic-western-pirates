#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Map {
private:
    unordered_map<int, string> locations;

public:
    Map() {
        // Initialize the locations
        locations[1] = "Pirate";
        locations[2] = "Corporate";
        locations[3] = "Aliens Ship";
        locations[4] = "Desert";
    }

    void displayLocations() {
        cout << "Choose your destination:" << endl;
        for (const auto& pair : locations) {
            cout << pair.first << ". " << pair.second << endl;
        }
    }

    bool isValidDestination(int choice) {
        return locations.find(choice) != locations.end();
    }

    string getLocationName(int choice) {
        return locations[choice];
    }

    void displaymap() {
        cout << "\n"
            "\n#YJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ????JJJJJJJJJJJJJJJJJJJJJJJJJJJJ?5BPJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ&"
            "\n#^                                                                    ~!~:                            ~B#BJ                                         .#"
            "\n#^                                                                    ?&BY5Y!^. ..^~^                !##!!&J                                        .&"
            "\n#^                                                              :?PP5YP#Y .~?Y55PGGPGG^             :B&7  Y&~                                       .&"
            "\n#^                                                            :J##J^:~77^^^^^^~~...:G&!             Y&5   .BG.                                      .&"
            "\n#^                                                 :~^       7B&Y:  !7~^^::..~7?   Y&J             .B#^    !&J                                      .&"
            "\n#^                                              :7P#G5P?.   7&G^    7.  ..::7~.7 .7B#!             ~&P      P#~.                                    .&"
            "\n#^                                            !P#BY~. :JP?^:Y@Y     7.      ~^.7 ?@P:              ?&J      ^GG55~                                  .&"
            "\n#^                                          .P&G~.      :7Y5BP~     7.      !^.7 :YP7.             J&?       .. J&!                                 .&"
            "\n#^                                          ?&G.            7.      7.      !^.7   :JPJ^           Y&7          .BG                                 .&"
            "\n#^                                       ?GPBG^            :7       7.      !^.7     .!5PJ7^.     .G&~           ~#Y                                .&"
            "\n#^                                  .?GG?B#~:.             !^       7.      !^.7       ~!!?YP?:  ^P&P.            ^B5.                              .&"
            "\n#^                                  5&5~P&G                7        ~~^^:::.!!!~      !~    :J55GBG?.              !&Y                              .&"
            "\n#^                                 !&G.  ~^               ^7...        ..:::~~.      !^        ::.                 ^#G                              .&"
            "\n#^                                :G&7                    .::^^^^^^^::...           !^                             .GB:                             .&"
            "\n#^                              :?##J                              ..::^^^^^^^^::..!^                               :JPY?!:                         .&"
            "\n#^                       .:~7J5GBBY^                          CORPOR H. Q.  ..:::^^^                                  .^!J55?:                      .&"
            "\n#^                 .^!?YPGGG5J7~:                                                                                          :7BJ.                    .&"
            "\n#^           :~7Y5GGGPY?!^.                                                                                                  !&Y                    .&"
            "\n#^        ~YGBG5J7~:.                                       .:^.                                                             ^&P                    .&"
            "\n#^      :P&G7:                                            :^^~::~^~7::^~!:                                                   .GB~~~^.               .&"
            "\n#^     .G&?                                               .  ^ ^^..^~~^~^^^::                                                 .7YYY5G!              .&"
            "\n#^     !&P                                                     .  .:. :^:.  ..                                                      G#:             .&"
            "\n#^     ~&5                                                  .    .:     .^^                                                         .J5J~           .&"
            "\n#^      G#:                                              .:^7!:::~?^:     !^:.                                                        .~5P~         .&"
            "\n#^      ^BP.                                           :^^: .!~^^^~^^~^^^^. .                                                            ?#7        .&"
            "\n#^       7&J                                           .  :^^:.. .:. ~.   . .  .                                                          Y#^       .&"
            "\n#^      .5&Y                                            .!.     :!^             DESERT                                                    :#P       .&"
            "\n#^      !&P                   :^^                        ::. .:^:~^^:   ::                                                                 7&7      .&"
            "\n#^       5B^         :^^~~!!JJ7^~?Y7~!~~^:                  .:. :~:.:^~^~!::::...                                                           J#~     .&"
            "\n#^        PB:       7PJ7!~^!?:   .7?^~!7?Y5                       !~ ^:  ~^^:..:::.                                                          5#^    .&"
            "\n#^        .BG.      !?!~~^~~~~!!!~~~^^^~!!J                   ..^~:.   .^: .::.                                                             :G&!    .&"
            "\n#^         ~&Y        :^~!!!~^^^^^~~!!!^:.                 .:^::!~:^:.  .:.                                                                ~B&J     .&"
            "\n#^          Y&~            .::J~!7:.                           .^:   ^:^:~~^::.                            PIRATE COVE                    ~##!      .&"
            "\n#^          :BG              .7  7                               .        ...                                                             Y&J       .&"
            "\n#^           J&!              .  .                                                                             ::^^!:                     Y&7       .&"
            "\n#^           :#P                                         ..:^~~~~~~^^:..                                      :57   !^                   .G&!       .&"
            "\n#^            P&~         ALIEN SHIP             .^~7JY5PGGPP55YYYYY55555YJ!:                                 ^??^   ?                  ~G&Y        .&"
            "\n#^            Y&?                           .~J5GGGPYJ7!^:..           .:^~?GJ.        .?~                    ^??~  :7                ^5&B7         .&"
            "\n#^           :G&!                         ~5BB5?~:.                         :GG:      :5&B.          .!^^^^!  ~J?^^^!:      ...::~~ .J#B7.          .&"
            "\n#^         .Y#B?            :!YPP55Y7~:^?G#P!.                               .5B~   ~5###P           :7    !!^~7!^^~^^^^^^^^^:::7?. ?&G:            .&"
            "\n#^          ~PP!:        :7P#B57^::^7Y5PPJ^                                    J#7?G#P5##?5Y:         ~~  .!!::!7.7!~        .~!:   P&!             .&"
            "\n#^            ^?55YJJJY5GBGY~.                                                  7BBJ~J#&BB&&?          ~!:...  .. ..   ...::~!:    :B#^             .&"
            "\n#^               .^!777!~:                                                       .. ?BBPYG#&J           .:^^^^^^^^^^^^^^^::..     !B&J              .&"
            "\n#^                                                                                   ..  .^~5G:               .....             .5&G~               .&"
            "\n#^                                                                                          :#P                                 J&5                 .&"
            "\n#^                                                                                           J&!                               :P&!                 .&"
            "\n#^                                                                                            ?PY?7!~:.       ~J?:      :7Y55PPGGJ.                 .&"
            "\n#^                                                                                             .^!?JY55Y?~^:~Y&BBB^..^?PBGJ!~^:.                    .&"
            "\n#^                                                                                                    .^!JY5PP?::J5PPGP?^                           .&"
            "\n#^                                                                                                                 ...                              .&"
            "\n#^                                                                                                              :.                                  .&"
            "\n#^                                                                                                            .5BGP7::^^^~?J!                       .&"
            "\n#^                                                                                                            .G#!7PGBBGGGP#&~                      .&"
            "\n#^                                                                                                             .PB^ .:...  G#:                      .&"
            "\n#^                                                                                                              :#P      .Y&5                       .&"
            "\n#^                                                                                                               5&~    .P&J.                       .&"
            "\n#^                                                                                                               .5BPY??G&J                         .&"
            "\n#^                                                                                                                 :!?YYJ~                          .&"
            "\nPJ?????????????????????????????????????????????????????????????????????????????????????????????????????????????????7777777???????????????????????????G";
    }
};

// Add these lines to the main code to update the map
// 
//int main() {
//    Map map;
//
//    // Display available locations
//    map.displayLocations();
//
//    int choice;
//    cout << "Enter your choice (1-4): ";
//    cin >> choice;
//
//    if (map.isValidDestination(choice)) {
//        string destination = map.getLocationName(choice);
//        cout << "You are traveling to: " << destination << endl;
//    }
//    else {
//        cout << "Invalid choice." << endl;
//    }
//
//    return 0;
//}