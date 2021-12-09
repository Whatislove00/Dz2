# Dz4

## 22. Удалить заданное ребро и в модифицированном графе отсортировать вершины по возрастанию степени вершины.

## Алгоритм:

- проверка в глубину графа на связность

``` C
int is_con(int **v_arr, int *is_c_arr, int cur_v, int v_count){
    int ans = 0;
    for(int j = 0; j < v_count; ++j){
        if(v_arr[cur_v][j] && !is_c_arr[j]){
            is_c_arr[j] = 1;
            ans++;
            ans += is_con(v_arr, is_c_arr, j, v_count);
        }
    }
    return ans;
}

```

- Считывание введеного ребра графа и его удаление

``` C
    int v1 = 0, v2 = 0;
    printf("Enter the edge you want to delete:");
    scanf("%d%d", &v1, &v2);
    v1--;
    v2--;
    if (v_arr[v1][v2] == 0 || v_arr[v2][v1] == 0){
        printf("There is no specified edge in the graph\n");
        return 1;
    }
    
    v_arr[v1][v2]--;
    v_arr[v2][v1]--;
```

- Создание массива для сортировки и быстрая сортировка вершин по возрастанию степени вершин

``` C

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
```

## Структурная схема алгоритма

![Alt-текст](https://github.com/KirillKhus/dz4-3sem/blob/main/diagram_dz.jpg)

## Результат работы

## Исходный граф

![Alt-текст](https://github.com/KirillKhus/dz4-3sem/blob/main/graph1.png)

## Модифицированный граф

![Alt-текст](https://github.com/KirillKhus/dz4-3sem/blob/main/graph2.png)
