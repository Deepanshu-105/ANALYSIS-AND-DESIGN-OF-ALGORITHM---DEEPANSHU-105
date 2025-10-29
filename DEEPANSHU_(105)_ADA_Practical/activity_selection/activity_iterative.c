#include <stdio.h>
#include <stdlib.h> 

typedef struct {
    int start;
    int finish;
    int index;
} Activity;


void merge(Activity activities[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    Activity *L = (Activity *)malloc(n1 * sizeof(Activity));
    Activity *R = (Activity *)malloc(n2 * sizeof(Activity));
    for (i = 0; i < n1; i++)
        L[i] = activities[l + i];
    for (j = 0; j < n2; j++)
        R[j] = activities[m + 1 + j];    
    i = 0; 
       j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i].finish <= R[j].finish) {
            activities[k] = L[i];
            i++;
        } else {
            activities[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        activities[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        activities[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}


void mergeSort(Activity activities[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(activities, l, m);
        mergeSort(activities, m + 1, r);
        merge(activities, l, m, r);
    }
}

int activitySelection_MergeSort(Activity activities[], int n) {
    if (n <= 0) return 0;
    mergeSort(activities, 0, n - 1);
    printf("Selected Activities (Original Index, Start, Finish):\n");
    int i = 0; 
    printf("Activity %d: (%d, %d)\n", activities[i].index, activities[i].start, activities[i].finish);
    int selected_count = 1;
    for (int j = 1; j < n; j++) {
        if (activities[j].start >= activities[i].finish) {
            printf("Activity %d: (%d, %d)\n", activities[j].index, activities[j].start, activities[j].finish);
            i = j;
            selected_count++;
        }
    }
    return selected_count;
}


int main() {
    Activity activities[] = {
        {1, 4, 1}, {3, 5, 2}, {0, 6, 3}, {5, 7, 4},
        {3, 9, 5}, {5, 9, 6}, {6, 10, 7}, {8, 11, 8},
        {8, 12, 9}, {2, 14, 10}, {12, 16, 11}
    };
    int n = sizeof(activities) / sizeof(activities[0]);

    int max_activities = activitySelection_MergeSort(activities, n);
    printf("\nMaximum non-overlapping activities: %d\n", max_activities);
    
    return 0;
}