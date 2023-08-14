#include <bits/stdc++.h>
using namespace  std;
int play_game(int computer_score){
    int your_score = 0;
    int computer_bowl;
    int player_bat;
    while(1){
        if(your_score > computer_score){
            break;
        }
        else{
            // Computers Random Number from 1 to 6
            computer_bowl = (rand() % 6) + 1;
            cout << "Enter any Number between 1 to 6 :" << endl;
            cin >> player_bat;
            // If you type more than 6, your score will automatically converted into a score which lies between 1 to 6
            if(player_bat > 6){
                if(player_bat % 12 == 0)
                    player_bat = (player_bat % 6) + 1;
                else
                player_bat = (player_bat % 6);
            }

            cout << "Computer Bowl is : " << computer_bowl << endl;
            cout << "Your Bat is : " << player_bat << endl;

            if(player_bat == computer_bowl){
                cout << "Your Current Score is : " << your_score << endl;
                cout << "You are OUT!" << endl;
                break;
            }
            else{
                your_score += player_bat;
                if(your_score >= (computer_score+1)){
                    break;
                }
                cout << "Your Current Score is : " << your_score << endl;
                if(your_score == computer_score){
                    cout << "Match Tied! ";
                    cout << "You need only 1 run to win!" << endl;
                }
                else{
                    cout << "You need " << (computer_score + 1) - your_score << " more runs to win!" << endl;
                }
            }
        }
    }
    return your_score;
}
int main() {
    srand(time(0));
    int computer_score;
    // Generate a Random Number from 1 to 25 for Computer Score
    computer_score = (rand() % 25) + 1;
    cout << "WELCOME TO HAND CRICKET GAME" << endl;
    cout << "Computer already Played the Game" << endl;
    cout << "The Score is : " << computer_score << endl;
    // Your Target
    cout << "Your Target is : " << computer_score + 1 << endl;
    int total_runs = play_game(computer_score);
    if(total_runs < computer_score){
        cout << "Computer Wins!" << endl;
        cout << "Better Luck Next Time!" << endl;
    }
    else if(total_runs == computer_score){
        cout << "Match Drawn!" << endl;
        cout << "Good Effort!" << endl;
    }
    else{ // (total_runs > computer_score)
        cout << "Congratulations You Win!" << endl;
        cout << "Keep it up!" << endl;
    }
    return 0;
}
