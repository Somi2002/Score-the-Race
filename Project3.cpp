#include <iostream>
using namespace std;

int main() {
    int members = 0;
    int Size = 0;

    while (true) { 
        string result;
        cout << "Enter the race player outcome: ";
        cin >> result;

        int score[27] = { };
        int count[27] = { }; 

        for (int i = 0; i < result.length (); i++) { 
            score[result[i] - 65 + 1] += i+1;
            if (count[result[i] - 65 + 1] == 0) 
                members++;
            count[result[i] - 65 + 1]+= 1;
            Size = max (Size, count[result[i] - 65 + 1]); 
            
        }
        
        while (!(Size == result.length () / members)) { // This checks whether the user input of teams has enough members. 
            cout << "The teams don't have the same number of runners.\n";
            cin >> result;
        }

        string tempTeam = ""; // temp team will help us keep a temporary value to replace it with the team that has the lowest score  // Zubaer {
        double tempScore = result.length () * result.length ();

        for (char i = 65; i <= 90; ++i) { // the numbers is from the ASCII table                                                                           // }
            if (score[i - 65 + 1] != 0) { 
                cout << i << ": " <<  score[i - 65 + 1] / Size << '\n'; // the score will be a decimal hence casting it to a double
                if (score[i - 65 + 1] < tempScore) {
                    tempTeam = i;
                    tempScore = score[i - 65 + 1]; 
                } else if (score[i - 65 + 1] == tempScore) { 
                    tempTeam += i; // this will increase the temporary value by i
                }
            }
        }

        cout << "There are " << members << " teams.\n";
        cout << "Each team has " << Size << " runners.\n";

        if(tempTeam.length() == 1) {
            cout << "Winning team is: " << tempTeam << " with a score: " << tempScore / Size << "\n"; //temp score dividing it by the maxsize to get the points
        }

        return 0;
    } 
}
