#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void SCAN(int rq[], int head_initial, int n) {
    int seek_time = 0, max_track, direction, temp;
    int current_head = head_initial;
    int i, j;
    printf("Enter the Max Track: ");
    scanf("%d", &max_track);
    rq[n] = 0;
    rq[n + 1] = max_track;
    int total_elements = n + 2;
    for (i = 0; i < total_elements - 1; i++) {
        for (j = 0; j < total_elements - i - 1; j++) {
            if (rq[j] > rq[j + 1]) {
                temp = rq[j];
                rq[j] = rq[j + 1];
                rq[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < total_elements; i++) {
        if (current_head < rq[i]) {
            break;
        }
    }
    printf("Enter the direction (0-left, 1-right): ");
    scanf("%d", &direction);
    printf("\nHead Movement Sequence:\n%d", current_head);
    if (direction == 1) {
        for (j = i; j < total_elements; j++) {
            seek_time += abs(current_head - rq[j]);
            current_head = rq[j];
        }        
        for (j = i - 1; j >= 0; j--) {
            seek_time += abs(current_head - rq[j]);
            current_head = rq[j];
        }
    } 
    else {
        int left_index = i - 1; 
        for (j = left_index; j >= 0; j--) {
            seek_time += abs(current_head - rq[j]);
            current_head = rq[j];
        }
        for (j = i; j < total_elements; j++) {
            seek_time += abs(current_head - rq[j]);
            current_head = rq[j];
        }
    }
    printf("\n\nTotal Seek Time: %d\n", seek_time);
}
int main() {
    int n, head_initial;
    printf("Enter the Number of Disk Tracks: ");
    scanf("%d", &n);   
    int rq[n + 2]; 
    printf("Enter the head_position initially: ");
    scanf("%d", &head_initial);
    printf("Enter all Disk tracks:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &rq[i]);
    }
    SCAN(rq, head_initial, n);
    return 0;
}