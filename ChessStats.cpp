#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include <boost>

using namespace std;

struct game {
        enum Result {White, Black, Draw};
        Result result;
        int numMoves;
        int wElo;
        int bElo;
        string wMoves[];
        string bMoves[];
};

ifstream file;

int main() {

    char line[100000];
    vector<game> g;

    int wWins = 0;
    int bWins = 0;
    int draws = 0;
    int games = 0;

    string block = "";

    void handleGame(game g, string s);
//    int count = 0;

//    ifstream file;
    file.open("ChessData.pgn");
    
    while (!file.eof()) {
        string str(line);
        file.getline(line, 100000);
        if (str.find("[Event") != string:: npos) {
            game game;
            g.push_back(game);
            handleGame(game, block);
            games++;
            block = "";
        } else {
            block += line;
        }
//        checkMoves(line);
        if (str.find("\"1-0\"]") != string:: npos) {
             wWins++;
//             games++;
        }
        else if (str.find("\"0-1\"]") != string:: npos) {
             bWins++;
//             games++;
        }
        else if (str.find("\"1/2-1/2\"]") != string:: npos) {
             draws++;
//             games++;
        }
//        count++;
//        cout << count << endl;
    }

    cout << "Total games: " << games << endl; 
    cout << "White Wins: " << wWins << endl;
    cout << "Black Wins: " << bWins << endl;
    cout << "Draws: " << draws << endl;
}

void handleGame(game ga, string s) {
    char curr = s[s.find("Black Elo")];
    String elo = "":
    while (curr != "\"")
    cout << s.find("Black Elo") << endl;
}
