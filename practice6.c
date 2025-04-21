//蓝桥杯真题
#include <stdio.h>

// 检查一个数字是否是幸运数字的函数
int is_lucky_number(int num) {
    char num_str[20]; // 用于将数字转换为字符串以便处理
    sprintf(num_str, "%d", num);
    int length = strlen(num_str);

    // 如果数字的位数为奇数，则不是幸运数字
    if (length % 2 != 0) {
        return 0; // 返回假
    }

    int half_length = length / 2;
    int first_half_sum = 0, second_half_sum = 0;

    // 计算前半部分数字的和
    for (int i = 0; i < half_length; i++) {
        first_half_sum += num_str[i] - '0'; // 将字符转换为数字
    }

    // 计算后半部分数字的和
    for (int i = half_length; i < length; i++) {
        second_half_sum += num_str[i] - '0';
    }

    // 判断前半部分和后半部分是否相等
    return first_half_sum == second_half_sum;
}

// 计算在给定范围内的幸运数字的数量
int count_lucky_numbers(int start, int end) {
    int count = 0;

    // 遍历给定范围内的所有数字
    for (int num = start; num <= end; num++) {
        // 如果是幸运数字，增加计数
        if (is_lucky_number(num)) {
            count++;
        }
    }

    return count;
}

int main() {
    int start_range = 1;
    int end_range = 100000000;

    // 调用函数计算幸运数字的数量
    int result = count_lucky_numbers(start_range, end_range);

    // 打印结果
    printf("There are %d lucky numbers between %d and %d.\n", result, start_range, end_range);

    return 0;
}
#include <stdio.h>

// 定义最大题目数和最大分数
#define MAX_QUESTIONS 30
#define MAX_SCORE 100

// 计算小蓝所有可能的答题情况数量的函数
long long count_possible_ways() {
    int target_score = 70;
    int num_questions = 30;

    // 初始化动态规划数组
    long long dp[MAX_QUESTIONS + 1][MAX_SCORE + 1] = { 0 };
    dp[0][0] = 1;

    // 遍历每一道题目
    for (int i = 1; i <= num_questions; i++) {
        for (int j = 0; j <= target_score; j++) {
            // 如果不答这道题
            dp[i][j] += dp[i - 1][j];

            // 如果答对这道题，分数增加10
            if (j >= 10) {
                dp[i][j] += dp[i - 1][j - 10];
            }
        }
    }

    return dp[num_questions][target_score];
}

int main() {
    // 调用函数计算小蓝所有可能的答题情况数量
    long long possible_ways = count_possible_ways();

    // 打印结果
    printf("小蓝所有可能的答题情况有 %lld 种。\n", possible_ways);

    return 0;
}
#include <stdio.h>
#include <math.h>

// 判断是否存在整数y和z，使得x = y^2 - z^2
int has_yz(int x) {
    int limit = (int)sqrt(x);

    // 遍历y的可能取值
    for (int y = 1; y <= limit; y++) {
        int z_square = y * y - x;

        // 如果z的平方为非负数且是完全平方数
        if (z_square >= 0 && sqrt(z_square) == (int)sqrt(z_square)) {
            return 1; // 存在满足条件的y和z
        }
    }

    return 0; // 不存在满足条件的y和z
}

// 计算满足条件的x的数量
int count_x(int L, int R) {
    int count = 0;

    // 遍历给定范围内的所有x
    for (int x = L; x <= R; x++) {
        // 如果存在整数y和z，使得x = y^2 - z^2
        if (has_yz(x)) {
            count++;
        }
    }

    return count;
}

int main() {
    int L, R;

    // 输入L和R的值
    printf("Enter the values of L and R: ");
    scanf("%d %d", &L, &R);

    // 调用函数计算满足条件的x的数量
    int result = count_x(L, R);

    // 输出结果
    printf("There are %d numbers x in the range [%d, %d] satisfying the condition.\n", result, L, R);

    return 0;
}
#include <stdio.h>
#include <string.h>

// 计算满足条件的不同子串选择方案的数量
int count_substring_choices(char num_str[]) {
    int n = strlen(num_str);
    int num = atoi(num_str);
    int choices = 0;  // 记录不同的选择方案数量
    char substring[20];  // 假设数字最大长度为20

    // 从左往右遍历，找到第一个递减的位置
    for (int i = 0; i < n - 1; i++) {
        if (num_str[i] > num_str[i + 1]) {
            // 在递减位置及其左侧选择子串
            strncpy(substring, num_str, i + 1);
            substring[i + 1] = '\0';  // 添加字符串结束符
            printf("选择子串: %s\n", substring);
            choices++;
        }
    }

    return choices;
}

int main() {
    char num_str[20];  // 假设数字最大长度为20

    // 输入数字字符串
    printf("请输入数字字符串: ");
    scanf("%s", num_str);

    // 调用函数计算满足条件的不同子串选择方案数量
    int result = count_substring_choices(num_str);

    // 输出结果
    printf("不同的子串选择方案数: %d\n", result);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 1001

// 结点的定义
struct TreeNode {
    int color;
    struct TreeNode* children[1001];
    int num_children;
};

// 创建一个新的结点
struct TreeNode* createNode(int color) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->color = color;
    node->num_children = 0;
    return node;
}

// DFS遍历并统计子树颜色个数
void dfs(struct TreeNode* root, int color_count[MAX_COLORS], int* balanced_trees) {
    int i;
    color_count[root->color]++;

    // 递归地处理子结点
    for (i = 0; i < root->num_children; i++) {
        dfs(root->children[i], color_count, balanced_trees);
    }

    // 检查当前子树是否是颜色平衡树
    int min_count = color_count[root->color];
    int max_count = color_count[root->color];
    for (i = 0; i < MAX_COLORS; i++) {
        if (color_count[i] > 0) {
            if (color_count[i] < min_count) min_count = color_count[i];
            if (color_count[i] > max_count) max_count = color_count[i];
        }
    }

    if (max_count == min_count) (*balanced_trees)++;
    color_count[root->color]--;
}

int main() {
    int n, i;
    int color_count[MAX_COLORS] = { 0 }; // 记录每种颜色的个数
    int balanced_trees = 0; // 颜色平衡子树的数量

    // 读取结点个数
    scanf("%d", &n);

    struct TreeNode* nodes[n + 1]; // 结点数组
    // 初始化结点数组
    for (i = 1; i <= n; i++) {
        int color;
        scanf("%d", &color);
        nodes[i] = createNode(color);
    }

    // 构建树
    for (i = 2; i <= n; i++) {
        int parent;
        scanf("%d", &parent);
        nodes[parent]->children[nodes[parent]->num_children++] = nodes[i];
    }

    // DFS遍历树并统计颜色平衡子树的数量
    dfs(nodes[1], color_count, &balanced_trees);

    printf("%d\n", balanced_trees);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 1001

// 结点的定义
struct TreeNode {
    int color;
    struct TreeNode* children[1001];
    int num_children;
};

// 创建一个新的结点
struct TreeNode* createNode(int color) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->color = color;
    node->num_children = 0;
    return node;
}

// DFS遍历并统计子树颜色个数
void dfs(struct TreeNode* root, int color_count[MAX_COLORS], int* balanced_trees) {
    int i;
    color_count[root->color]++;

    // 递归地处理子结点
    for (i = 0; i < root->num_children; i++) {
        dfs(root->children[i], color_count, balanced_trees);
    }

    // 检查当前子树是否是颜色平衡树
    int min_count = color_count[root->color];
    int max_count = color_count[root->color];
    for (i = 0; i < MAX_COLORS; i++) {
        if (color_count[i] > 0) {
            if (color_count[i] < min_count) min_count = color_count[i];
            if (color_count[i] > max_count) max_count = color_count[i];
        }
    }

    if (max_count == min_count) (*balanced_trees)++;
    color_count[root->color]--;
}

int main() {
    int n, i;
    int color_count[MAX_COLORS] = { 0 }; // 记录每种颜色的个数
    int balanced_trees = 0; // 颜色平衡子树的数量

    // 读取结点个数
    scanf("%d", &n);

    struct TreeNode* nodes[n + 1]; // 结点数组
    // 初始化结点数组
    for (i = 1; i <= n; i++) {
        int color;
        scanf("%d", &color);
        nodes[i] = createNode(color);
    }

    // 构建树
    for (i = 2; i <= n; i++) {
        int parent;
        scanf("%d", &parent);
        nodes[parent]->children[nodes[parent]->num_children++] = nodes[i];
    }

    // DFS遍历树并统计颜色平衡子树的数量
    dfs(nodes[1], color_count, &balanced_trees);

    printf("%d\n", balanced_trees);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 定义无穷大值
#define INF INT_MAX

// 定义设备和连接的结构体
struct Edge {
    int to;
    int weight;
};

// 定义图的结构体
struct Graph {
    int vertices;           // 设备的数量
    struct Edge** adjMatrix; // 邻接矩阵表示的图
};

// 初始化图
struct Graph* initializeGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    // 为邻接矩阵分配内存
    graph->adjMatrix = (struct Edge**)malloc(vertices * sizeof(struct Edge*));
    for (int i = 0; i < vertices; ++i) {
        graph->adjMatrix[i] = (struct Edge*)malloc(vertices * sizeof(struct Edge));
    }

    // 初始化邻接矩阵
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            graph->adjMatrix[i][j].to = -1; // 表示没有连接
            graph->adjMatrix[i][j].weight = INF; // 初始化为无穷大
        }
    }

    return graph;
}

// 添加无向边到图
void addEdge(struct Graph* graph, int from, int to, int weight) {
    graph->adjMatrix[from][to].to = to;
    graph->adjMatrix[from][to].weight = weight;

    // 由于是无向图，需要添加反向边
    graph->adjMatrix[to][from].to = from;
    graph->adjMatrix[to][from].weight = weight;
}

// Dijkstra算法计算从源节点到所有其他节点的最短路径
void dijkstra(const struct Graph* graph, int source, int* dist) {
    int visited[graph->vertices];

    // 初始化距离数组和访问数组
    for (int i = 0; i < graph->vertices; ++i) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0; // 源节点到自身的距离为0

    for (int count = 0; count < graph->vertices - 1; ++count) {
        int u = -1;

        // 选择未访问的节点中距离最小的节点
        for (int i = 0; i < graph->vertices; ++i) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }

        visited[u] = 1; // 标记节点为已访问

        // 更新未访问节点的距离
        for (int v = 0; v < graph->vertices; ++v) {
            if (!visited[v] && graph->adjMatrix[u][v].to != -1 &&
                dist[u] + graph->adjMatrix[u][v].weight < dist[v]) {
                dist[v] = dist[u] + graph->adjMatrix[u][v].weight;
            }
        }
    }
}

// 计算两个设备之间的通信稳定性
int calculateStability(const int* dist, int destination) {
    if (dist[destination] == INF) {
        return -1; // 如果没有路径，则返回-1
    }

    return dist[destination];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m); // 输入设备数量和连接数量

    struct Graph* graph = initializeGraph(n);

    // 输入物理连接的信息
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(graph, u - 1, v - 1, w); // 设备编号从1开始，转换为0开始的索引
    }

    int q;
    scanf("%d", &q); // 查询数量

    for (int i = 0; i < q; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);

        int* distFromX = (int*)malloc(n * sizeof(int));
        dijkstra(graph, x - 1, distFromX);
        int stability = calculateStability(distFromX, y - 1);

        printf("%d\n", stability);

        free(distFromX);
    }

    // 释放内存
    for (int i = 0; i < n; ++i) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);

    return 0;
}
#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 1000

// 表示树的邻接列表
int adjacency_list[MAX_NODES][MAX_NODES];
// 标记边是否被访问过
bool visited[MAX_NODES][MAX_NODES];
// 结果数组，记录断开的边的编号
int result[MAX_NODES];
// 当前断开的边的编号
int result_index;

// 深度优先搜索函数
void dfs(int node, int parent, int a, int b, int n) {
    for (int i = 0; i < n; ++i) {
        if (adjacency_list[node][i] && !visited[node][i]) {
            visited[node][i] = visited[i][node] = true;

            // 如果当前边的两个端点分别为a和b，说明这条边需要断开
            if ((node == a && i == b) || (node == b && i == a)) {
                result[result_index++] = i + 1; // 存储边的编号（从1开始）
            }

            dfs(i, node, a, b, n);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // 初始化邻接列表和visited数组
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        adjacency_list[u - 1][v - 1] = adjacency_list[v - 1][u - 1] = 1;
        visited[u - 1][v - 1] = visited[v - 1][u - 1] = false;
    }

    // 遍历每个数对，进行DFS判断是否可以断开
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);

        // 重置结果数组和结果索引
        result_index = 0;

        // 进行DFS遍历
        dfs(0, -1, a - 1, b - 1, n);

        // 如果结果索引为0，说明没有找到需要断开的边
        if (result_index == 0) {
            printf("-1\n");
        }
        else {
            // 输出断开的边的编号
            for (int j = 0; j < result_index; ++j) {
                printf("%d ", result[j]);
            }
            printf("\n");
        }
    }

    return 0;
}