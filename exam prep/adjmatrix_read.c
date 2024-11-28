int findjindex(int **arr, int ith, int *count, int size) {
    int adjacent_count = 0;
    for (int j = 0; j < size; j++) {
        if (arr[ith][j] == 1) {  
            if (adjacent_count == *count) {
                return j; 
            }
            adjacent_count++;
        }
    }
    return -1;  
} 
 

 for (int t = 0; t < n; t++) {
        char w8string[256];
        fgets(w8string, sizeof(w8string), stdin);
        char *w8word = strtok(w8string, " ");
        int i = atoi(w8word);
        w8word = strtok(NULL, " ");
        int count = 0;
        while (w8word != NULL) {
            int weight = atoi(w8word);
            int jnum = findjindex(arr, i - 1, &count, n);
            w8arr[i - 1][jnum] = weight;  
            count++;
            w8word = strtok(NULL, " "); 
        }
    }