#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int is_con(int **v_arr, int *is_c_arr, int cur_v, int v_count) {
    int ans = 0;
    for (int j = 0; j < v_count; ++j) {
        if (v_arr[cur_v][j] && !is_c_arr[j]) {
            is_c_arr[j] = 1;
            ans++;
            ans += is_con(v_arr, is_c_arr, j, v_count);
        }
    }
    return ans;
}

int compare(const void *a, const void *b) {

    return *(int*)a - *(int*)b;
}

int main(int argc, char **argv) {
    FILE *file1;
    FILE *file2;
    file1 = fopen("graph1.dot", "w");
    file2 = fopen("graph2.dot", "w");
    fprintf(file1, "graph g {\n");
    fprintf(file2, "graph g {\n");

    int v_count = 0;
    printf("Enter the number of vertices in the graph: ");
    scanf_s("%d", &v_count);
    for (int i = 0; i < v_count; ++i) {
        fprintf(file1, "%d;\n", i + 1);
        fprintf(file2, "%d;\n", i + 1);
    }

    printf("Enter the adjacency matrix of a %d by %d graph:\n", v_count, v_count);
    int *is_c_arr = (int*)malloc(v_count * sizeof(int));
    int **v_arr = (int**)malloc(v_count * sizeof(int*));
    for (int i = 0; i < v_count; ++i) {
        is_c_arr[i] = 0;
        v_arr[i] = (int*)malloc(v_count * sizeof(int));
        for (int j = 0; j < v_count; ++j) {
            int cur = 0;
            scanf_s("%d", &v_arr[i][j]);
            if (j >= i) {
                int sup = v_arr[i][j];
                while (sup > 0) {
                    fprintf(file1, "%d -- %d;\n", i + 1, j + 1);
                    sup--;
                }
            }
        }
    }

    fprintf(file1, "}\n");


    is_c_arr[0] = 1;

    if (is_con(v_arr, is_c_arr, 0, v_count) == v_count - 1) {
        printf("The given graph turned out to be connected\n");
    }
    else {
        printf("The given graph turned out to be unconnected\n");
    }
    int v1 = 0, v2 = 0;

    printf("Enter the edge you want to delete:");

    scanf_s("%d%d", &v1, &v2);
    v1--;
    v2--;
    
    if (v_arr[v1][v2] == 0 || v_arr[v2][v1] == 0) {
        printf("There is no specified edge in the graph\n");
        return 1;
    }
    
    v_arr[v1][v2]--;
    v_arr[v2][v1]--;

    for (int i = 0; i < v_count; ++i) {
        
        for (int j = i; j < v_count; ++j) {

            int sup = v_arr[i][j];
            while (sup > 0) {
                fprintf(file2, "%d -- %d;\n", i + 1, j + 1);
                sup--;
            }
        }
    }

    fprintf(file2, "}\n");

    int **degree_ed_arr = (int**)malloc(v_count * sizeof(int*));

    for (int i = 0; i < v_count; ++i) {
        degree_ed_arr[i] = malloc(sizeof(int) * 2);
        degree_ed_arr[i][1] = i;
    }
   
    for (int i = 0; i < v_count; ++i) {

        degree_ed_arr[i][0] = 0;
       
        for (int j = 0; j < v_count; ++j) {

            degree_ed_arr[i][0] += v_arr[i][j];
        }
    }
    
    qsort(degree_ed_arr, v_count, sizeof(int*), compare);
    
    for (int i = 0; i < v_count; ++i) {
       
        printf("Vertex number %d has degree %d\n", degree_ed_arr[i][1] + 1, degree_ed_arr[i][0]);
    }
    

    for (int i = 0; i < v_count; ++i) {

        free(v_arr[i]);
    }

    fclose(file1);
    fclose(file2);
    system("dot -Tpng graph1.dot -o graph1.png");
    system("graph1.png");
    system("dot -Tpng graph2.dot -o graph2.png");
    system("graph2.png");

    return 0;
}