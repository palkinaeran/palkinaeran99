#include <stdio.h> 
int main() 
{ 
    // P0, P1, P2, P3, P4 are the Process names here 
  
    int n, m, i, j, k; 
    n = 5; // Number of processes 
    m = 4; // Number of resources 
    int alloc[5][4] = { { 0, 0, 1, 2 }, // P0    // Allocation Resources Matrix 
                        { 1, 0, 0, 0 }, // P1 
                        { 1, 3, 5, 4 }, // P2 
                        { 0, 6, 3, 2 }, // P3 
                        { 0, 0, 1, 4 } }; // P4 
  
    int max[5][4] = { { 0, 0, 1, 2 }, // P0    // Max Resources Required Matrix 
                      { 1, 7, 5, 0}, // P1 
                      { 2, 3, 5, 6 }, // P2 
                      { 0, 6, 5, 2 }, // P3 
                      { 0, 6, 5, 6 } }; // P4 
  
    int avail[4] = { 1, 5, 2, 0}; // Available Resources 
  
    int f[n], s[n], x = 0; 
    for (k = 0; k < n; k++) { 
        f[k] = 0; 
    } 
    int need[n][m];             // Required Resources Matrix
    for (i = 0; i < n; i++) { 
        for (j = 0; j < m; j++) 
            need[i][j] = max[i][j] - alloc[i][j]; 
    } 
    int y = 0; 
    for (k = 0; k < 5; k++) { 
        for (i = 0; i < n; i++) { 
            if (f[i] == 0) { 
  
                int g = 0; 
                for (j = 0; j < m; j++) { 
                    if (need[i][j] > avail[j]){ 
                        g = 1; 
                         break; 
                    } 
                } 
  
                if (g == 0) { 
                    s[x++] = i; 
                    for (y = 0; y < m; y++) 
                        avail[y] += alloc[i][y]; 
                    f[i] = 1; 
                } 
            } 
        } 
    } 
  
    printf("Following is the SAFE Sequence\n"); 
    for (i = 0; i < n - 1; i++) 
        printf(" P%d ->", s[i]); 
    printf(" P%d", s[n - 1]); 
  
    return (0);  
} 
