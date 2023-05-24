#include <stdio.h>

#define MAX_CANDIDATES 10

typedef struct {
    char name[50];
    int votes;
} Candidate;

void initializeCandidates(Candidate candidates[], int numCandidates) {
    for (int i = 0; i < numCandidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

void castVote(Candidate candidates[], int numCandidates) {
    int candidateNumber;
    printf("Enter the candidate number you want to vote for (1-%d): ", numCandidates);
    scanf("%d", &candidateNumber);

    if (candidateNumber >= 1 && candidateNumber <= numCandidates) {
        candidates[candidateNumber - 1].votes++;
        printf("Your vote has been cast successfully!\n");
    } else {
        printf("Invalid candidate number. Please try again.\n");
    }
}

void printResults(Candidate candidates[], int numCandidates) {
    printf("Voting Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s: %d votes\n", i + 1, candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int numCandidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);

    if (numCandidates <= 0 || numCandidates > MAX_CANDIDATES) {
        printf("Invalid number of candidates. Please try again.\n");
        return 1;
    }

    Candidate candidates[MAX_CANDIDATES];
    initializeCandidates(candidates, numCandidates);

    int choice;
    do {
        printf("\nVoting System Menu:\n");
        printf("1. Cast Vote\n");
        printf("2. Print Results\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                castVote(candidates, numCandidates);
                break;
            case 2:
                printResults(candidates, numCandidates);
                break;
            case 3:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
