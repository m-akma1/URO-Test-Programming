#include<bits/stdc++.h>
using namespace std;

void delay (int milliseconds) {
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

class Robot {
    public :
        int robotID;
        string robotName;
        int health;
        int power;
        
        Robot(int ID, string name, int health, int power) 
            : robotID(ID), robotName(name), health(health), power(power) {}

        void attack(Robot &enemy) {
            cout << robotName << " attacks " << enemy.robotName << " for " << power << " damages!\n";
            delay(500);
            enemy.takeDamage(power);
            cout << enemy.robotName << "'s remaining health: " << enemy.health << "\n";
            delay(1000);
        }

        void takeDamage(int damage) {
            health -= damage;
        }
};

// List of All Available Robots
Robot Alpha(1, "Alpha", 1, 10);
Robot Beta(2, "Beta", 5, 6);
Robot Gamma(3, "Gamma", 4, 7);
Robot Delta(4, "Delta", 3, 8);
Robot Epsilon(5, "Epsilon", 8, 3);
Robot Zeta(6, "Zeta", 9, 2);
Robot Eta(7, "Eta", 10, 1);
Robot Theta(8, "Theta", 6, 5);
Robot Iota(9, "Iota", 7, 4);
Robot Kappa(10, "Kappa", 2, 9);
Robot allRobots[10] {
    Alpha, Beta, Gamma, Delta, Epsilon, Zeta, Eta, Theta, Iota, Kappa
};

class Player {
    public :
        string playerName;
        deque<Robot> robotOrder; //Queue of current robots ready to fight for each Player

        Player(string name) : playerName(name) {
            if (name == "Computer") playerName = "Computer";
            else {
                cout << "Enter your name: ";
                cin >> playerName;
                cout << "Welcome " << playerName << "!\n\n";
                delay(1000);
            }            
        }
        
        void selectRobot(Robot robot) {
            robotOrder.push_back(robot);
        }

        void updateRobot() {
            if(robotOrder.front().health <= 0) robotOrder.pop_front();
        }

        void showRobot() {
            cout << "\n" << playerName << "\'s Team:\n";
            delay(500);
            for (auto robot : robotOrder) {
                cout << robot.robotName << ": Health = " << robot.health << ", Power = " << robot.power << "\n";
                delay(250);
            }
            cout << endl;
            delay(1000);
        }

};

class Game {
    public :
        string gameMode;

        Game() {
            string mode;
            cout << "\n--------------------------------\n";
            delay(500);
            cout << "Welcome to the Battle of Robots!\n";
            delay(500);
            cout << "--------------------------------\n\n";
            delay(1500);
            cout << "Select Mode:\n";
            delay(250);
            cout << "[P] Player vs Player\n";
            delay(250);
            cout << "[C] Play Against Computer\n";
            delay(250);
            cout << "Select : ";
            while (cin >> mode) {
                if (mode == "P" || mode == "C") {
                    gameMode = mode;
                    break;
                } else cout << "Invalid Input! Try again: ";
            }
            cout << "You have selected " << (gameMode == "P" ? "Player vs Player" : "Play Against Computer") << " mode!\n\n";
            delay(1000);
        }

        void availableRobot() {
            cout << "Available Robots:\n";
            delay(500);
            for (int i = 0; i < 10; i++) {
                cout << "[" << i + 1 << "]" << allRobots[i].robotName;
                cout << ": Health = " << allRobots[i].health << ", Power = " << allRobots[i].power << "\n";
                delay(250);
            }
            cout << endl;
            delay(1000);
        }

        void addRobot(Player& player) {
            set<int> selectedRobots = {};
            cout << "Choose 4 different robots:\n";
            for (int i = 0; i < 4; i++) {
                cout << "Robot " << i + 1 << ": ";
                int choice;
                while (cin >> choice) {
                    if (0 < choice && choice < 11 && selectedRobots.find(choice) == selectedRobots.end()) {
                        player.selectRobot(allRobots[choice - 1]);
                        selectedRobots.insert(choice);
                        break;
                    } else cout << "Invalid Input! Please select again: ";
                }
            }
        }

        void checkWinner(Player& player1, Player& player2) {
            delay(1000);
            cout << "\n+--------------+\n";
            cout <<   "|  GAME OVER!  |\n";
            cout <<   "+--------------+\n\n";
            delay(1000);
            if (player1.robotOrder.empty() && !player2.robotOrder.empty()) cout << player2.playerName << " WINS!\n\n";
            else if (player2.robotOrder.empty() && !player1.robotOrder.empty()) cout << player1.playerName << " WINS!\n\n";
            else cout << "IT'S A DRAW!\n\n";
            delay(1000);
            cout << "+------------------------+\n";
            cout << "| Thank you for playing! |\n";
            cout << "+------------------------+\n\n";
        }
        
};

class Battle {
    private:
        Player& player1;
        Player& player2;
        Robot& robot1;
        Robot& robot2;

    public :
        Battle (Player& p1, Player& p2) 
            : player1(p1), player2(p2), robot1(p1.robotOrder.front()), robot2(p2.robotOrder.front()) {}

        void startFight(Robot& r1, Robot& r2) {
            delay(500);
            cout << "\nStart Battle " << r1.robotName << " vs " << r2.robotName << "!\n";
            delay(250);
            while (r1.health > 0 && r2.health > 0) {
                r1.attack(r2);
                r2.attack(r1);
            }
            if (r1.health <= 0 && r2.health > 0) cout << r1.robotName << " has been defeated!\n";
            if (r2.health <= 0 && r1.health > 0) cout << r2.robotName << " has been defeated!\n";
            else if (r1.health <= 0 && r2.health <= 0) cout << r1.robotName << " and " << r2.robotName << " have been defeated!\n";
            delay(500);
        }

        void startBattle(Game& game) {
            while (!player1.robotOrder.empty() && !player2.robotOrder.empty()) {
                startFight(player1.robotOrder.front(), player2.robotOrder.front());
                player1.updateRobot();
                player2.updateRobot();
            }
            game.checkWinner(player1, player2);
        }
};

int main () {
    //Random Seed for Selecting Robot
    srand(time(0));

    //Start the Game
    Game newGame;

    //Initialize Player 1 
    if (newGame.gameMode == "P") cout << "Initializing Player 1...\n";
    Player gamePlayer1("");
    newGame.availableRobot();
    newGame.addRobot(gamePlayer1);
    gamePlayer1.showRobot();
    
    //Initialize Player 2
    if (newGame.gameMode == "P") {
        cout << "Initializing Player 2...\n";
        Player gamePlayer2("");
        newGame.availableRobot();
        newGame.addRobot(gamePlayer2);
        gamePlayer2.showRobot();

        //Start the Battle
        Battle newBattle(gamePlayer1, gamePlayer2);
        newBattle.startBattle(newGame);

    } else {
        Player computer("Computer");
        set<int>tmpRbt = {};
        while (computer.robotOrder.size() < 4) {
            int random = rand() % 10;
            if (tmpRbt.find(random) == tmpRbt.end()) {
                computer.selectRobot(allRobots[random]);
                tmpRbt.insert(random);
            }
        }
        computer.showRobot();

        //Start the Battle
        Battle newBattle(gamePlayer1, computer);
        newBattle.startBattle(newGame);
    }

    return 0;
}