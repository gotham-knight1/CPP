/*
For the programming language, use C.

Write a program in which the number N (the number of football teams) and information 
for N football teams are entered from standard input.

A structure for a Football Team (`FootballTeam`) should store the following information:
- Team name (character array)
- Array of players (represented by the structure `FootballPlayer`, where each team will always have 11 players)

In the structure Football Player (`FootballPlayer`), the following information should be stored:
- Player's name (character array)
- Jersey number (int)
- Number of goals scored (int)

Constraint: 0 < N < 100

Your task is to create a function `void bestTeam(FootballTeam * teams, int n)` that prints the team 
with the most goals (in case there are multiple teams with the same number of goals, print the first one entered). 
Input the data in the main function, where the order of input data should be as follows:

N
team_name_1
player_name_1 number_1 goals_1
...
player_name_11 number_11 goals_11
team_name_2
player_name_1 number_1 goals_1
...
player_name_11 number_11 goals_11
...

team_name_n
player_name_1 number_1 goals_1
...
player_name_11 number_11 goals_11
*/

#include <stdio.h>

#define NUMBER_OF_MEMBERS 11

typedef struct FootballPlayer {
    char name[20];
    int number;
    int goals;
} FootballPlayer;

typedef struct FootballTeam {
    char name[20];
    FootballPlayer players[NUMBER_OF_MEMBERS];
} FootballTeam;


int sumGoals(FootballTeam team) {
    int sum = 0;

    for(int i = 0; i < NUMBER_OF_MEMBERS; i++) {
        sum += team.players[i].goals;
    }

    return sum;
}

void bestTeam(FootballTeam * teams, int n) {
    int maxGoals = 0;
    int indexOfBestTeam = 0;

    for(int i = 0; i < n; i++) {
        if(sumGoals(teams[i]) > maxGoals) {
            maxGoals = sumGoals(teams[i]);
            indexOfBestTeam = i;
        }
    }

    printf("Najdobar tim e: %s", teams[indexOfBestTeam].name);
}

void readPlayer(FootballPlayer * player) {
    scanf("%s %d %d", player->name, &player->number, &player->goals);
}

int main() {
    int n;
    scanf("%d", &n);

    FootballTeam teams[n];

    for(int i = 0; i < n; ++i) {
        scanf("%s", teams[i].name);

        for(int j = 0; j < NUMBER_OF_MEMBERS; j++) {
            readPlayer(&teams[i].players[j]);
        }
    }

    bestTeam(teams,n);

    return 0;
}
