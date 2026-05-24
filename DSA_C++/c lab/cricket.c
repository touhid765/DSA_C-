#include <stdio.h>
#include <string.h>

struct Cricket {
    char player[50];
    char team[50];
    float average;
};

int main() {
    struct Cricket c[5];
    int i, highIndex = 0;

    for (i = 0; i < 5; i++) {
        printf("\nEnter details of player %d\n", i + 1);
        printf("Name: ");
        scanf("%s", c[i].player);
        printf("Team: ");
        scanf("%s", c[i].team);
        printf("Batting average: ");
        scanf("%f", &c[i].average);
    }

    for (i = 1; i < 5; i++)
        if (c[i].average > c[highIndex].average)
            highIndex = i;

    printf("\nPlayer with highest batting average:\n");
    printf("Name: %s\nTeam: %s\nAverage: %.2f", c[highIndex].player, c[highIndex].team, c[highIndex].average);
    return 0;
}
