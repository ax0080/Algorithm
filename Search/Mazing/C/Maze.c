// read maze
bool **read_maze(const char *file_path, int *rows, int *cols) {
  FILE *file = fopen(file_path, "r");
  if (file == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  bool **maze = NULL;
  *rows = 0;
  *cols = 0;

  char buffer[1024];
  while (fgets(buffer, sizeof(buffer), file)) {
    int current_cols = 0;
    bool *row_data = NULL;

    // 解析一行數據
    char *token = strtok(buffer, " ");
    while (token != NULL) {
      row_data = realloc(row_data, (current_cols + 1) * sizeof(bool));
      row_data[current_cols] = (atoi(token) != 0); // 0 為 false，其他為 true
      current_cols++;
      token = strtok(NULL, " ");
    }

    // 設定或檢查列數
    if (*cols == 0) {
      *cols = current_cols; // 第一行決定列數
    } else if (*cols != current_cols) {
      fprintf(stderr, "Error: Inconsistent number of columns in row %d\n",
              *rows + 1);
      fclose(file);
      exit(EXIT_FAILURE);
    }

    // 新增行數據到迷宮
    maze = realloc(maze, (*rows + 1) * sizeof(bool *));
    maze[*rows] = row_data;
    (*rows)++;
  }

  fclose(file);
  return maze;
}

// 函式：顯示迷宮
void display_maze(bool **maze, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", maze[i][j]); // 使用 %d 輸出 true(1)/false(0)
    }
    printf("\n");
  }
}

// 函式：釋放迷宮記憶體
void free_maze(bool **maze, int rows) {
  for (int i = 0; i < rows; i++) {
    free(maze[i]);
  }
  free(maze);
}

int main() {
  const char *file_path = "../maze.txt"; // 迷宮檔案路徑
  int rows = 0, cols = 0;

  // 讀取迷宮
  bool **maze = read_maze(file_path, &rows, &cols);

  // 顯示迷宮
  printf("Maze loaded successfully (%d rows, %d columns):\n", rows, cols);
  display_maze(maze, rows, cols);

  // 釋放記憶體
  free_maze(maze, rows);

  return 0;
}