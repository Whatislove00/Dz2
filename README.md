# Dz4

## 22. Удалить заданное ребро и в модифицированном графе отсортировать вершины по возрастанию степени вершины.

## Алгоритм:

- Считывание введеного ребра графа и его удаление

``` C
    int v1 = 0, v2 = 0;
    printf("Enter the edge you want to delete:");
    scanf("%d%d", &v1, &v2);
    v1--;
    v2--;   
    v_arr[v1][v2]--;
    v_arr[v2][v1]--;
```

- Создание массива для сортировки и быстрая сортировка вершин по возрастанию степени вершин

``` C

 int** degree_ed_arr = (int**)malloc(v_count * sizeof(int*));

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

    bubbleSort(degree_ed_arr, 8);

    for (int i = 0; i < v_count; ++i) {   

        printf("Vertex number %d has degree %d\n", degree_ed_arr[i][1] + 1, degree_ed_arr[i][0]);

    }
```
