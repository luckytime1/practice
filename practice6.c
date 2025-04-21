//���ű�����
#include <stdio.h>

// ���һ�������Ƿ����������ֵĺ���
int is_lucky_number(int num) {
    char num_str[20]; // ���ڽ�����ת��Ϊ�ַ����Ա㴦��
    sprintf(num_str, "%d", num);
    int length = strlen(num_str);

    // ������ֵ�λ��Ϊ������������������
    if (length % 2 != 0) {
        return 0; // ���ؼ�
    }

    int half_length = length / 2;
    int first_half_sum = 0, second_half_sum = 0;

    // ����ǰ�벿�����ֵĺ�
    for (int i = 0; i < half_length; i++) {
        first_half_sum += num_str[i] - '0'; // ���ַ�ת��Ϊ����
    }

    // �����벿�����ֵĺ�
    for (int i = half_length; i < length; i++) {
        second_half_sum += num_str[i] - '0';
    }

    // �ж�ǰ�벿�ֺͺ�벿���Ƿ����
    return first_half_sum == second_half_sum;
}

// �����ڸ�����Χ�ڵ��������ֵ�����
int count_lucky_numbers(int start, int end) {
    int count = 0;

    // ����������Χ�ڵ���������
    for (int num = start; num <= end; num++) {
        // ������������֣����Ӽ���
        if (is_lucky_number(num)) {
            count++;
        }
    }

    return count;
}

int main() {
    int start_range = 1;
    int end_range = 100000000;

    // ���ú��������������ֵ�����
    int result = count_lucky_numbers(start_range, end_range);

    // ��ӡ���
    printf("There are %d lucky numbers between %d and %d.\n", result, start_range, end_range);

    return 0;
}
#include <stdio.h>

// ���������Ŀ����������
#define MAX_QUESTIONS 30
#define MAX_SCORE 100

// ����С�����п��ܵĴ�����������ĺ���
long long count_possible_ways() {
    int target_score = 70;
    int num_questions = 30;

    // ��ʼ����̬�滮����
    long long dp[MAX_QUESTIONS + 1][MAX_SCORE + 1] = { 0 };
    dp[0][0] = 1;

    // ����ÿһ����Ŀ
    for (int i = 1; i <= num_questions; i++) {
        for (int j = 0; j <= target_score; j++) {
            // ������������
            dp[i][j] += dp[i - 1][j];

            // ����������⣬��������10
            if (j >= 10) {
                dp[i][j] += dp[i - 1][j - 10];
            }
        }
    }

    return dp[num_questions][target_score];
}

int main() {
    // ���ú�������С�����п��ܵĴ����������
    long long possible_ways = count_possible_ways();

    // ��ӡ���
    printf("С�����п��ܵĴ�������� %lld �֡�\n", possible_ways);

    return 0;
}
#include <stdio.h>
#include <math.h>

// �ж��Ƿ��������y��z��ʹ��x = y^2 - z^2
int has_yz(int x) {
    int limit = (int)sqrt(x);

    // ����y�Ŀ���ȡֵ
    for (int y = 1; y <= limit; y++) {
        int z_square = y * y - x;

        // ���z��ƽ��Ϊ�Ǹ���������ȫƽ����
        if (z_square >= 0 && sqrt(z_square) == (int)sqrt(z_square)) {
            return 1; // ��������������y��z
        }
    }

    return 0; // ����������������y��z
}

// ��������������x������
int count_x(int L, int R) {
    int count = 0;

    // ����������Χ�ڵ�����x
    for (int x = L; x <= R; x++) {
        // �����������y��z��ʹ��x = y^2 - z^2
        if (has_yz(x)) {
            count++;
        }
    }

    return count;
}

int main() {
    int L, R;

    // ����L��R��ֵ
    printf("Enter the values of L and R: ");
    scanf("%d %d", &L, &R);

    // ���ú�����������������x������
    int result = count_x(L, R);

    // ������
    printf("There are %d numbers x in the range [%d, %d] satisfying the condition.\n", result, L, R);

    return 0;
}
#include <stdio.h>
#include <string.h>

// �������������Ĳ�ͬ�Ӵ�ѡ�񷽰�������
int count_substring_choices(char num_str[]) {
    int n = strlen(num_str);
    int num = atoi(num_str);
    int choices = 0;  // ��¼��ͬ��ѡ�񷽰�����
    char substring[20];  // ����������󳤶�Ϊ20

    // �������ұ������ҵ���һ���ݼ���λ��
    for (int i = 0; i < n - 1; i++) {
        if (num_str[i] > num_str[i + 1]) {
            // �ڵݼ�λ�ü������ѡ���Ӵ�
            strncpy(substring, num_str, i + 1);
            substring[i + 1] = '\0';  // ����ַ���������
            printf("ѡ���Ӵ�: %s\n", substring);
            choices++;
        }
    }

    return choices;
}

int main() {
    char num_str[20];  // ����������󳤶�Ϊ20

    // ���������ַ���
    printf("�����������ַ���: ");
    scanf("%s", num_str);

    // ���ú����������������Ĳ�ͬ�Ӵ�ѡ�񷽰�����
    int result = count_substring_choices(num_str);

    // ������
    printf("��ͬ���Ӵ�ѡ�񷽰���: %d\n", result);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 1001

// ���Ķ���
struct TreeNode {
    int color;
    struct TreeNode* children[1001];
    int num_children;
};

// ����һ���µĽ��
struct TreeNode* createNode(int color) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->color = color;
    node->num_children = 0;
    return node;
}

// DFS������ͳ��������ɫ����
void dfs(struct TreeNode* root, int color_count[MAX_COLORS], int* balanced_trees) {
    int i;
    color_count[root->color]++;

    // �ݹ�ش����ӽ��
    for (i = 0; i < root->num_children; i++) {
        dfs(root->children[i], color_count, balanced_trees);
    }

    // ��鵱ǰ�����Ƿ�����ɫƽ����
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
    int color_count[MAX_COLORS] = { 0 }; // ��¼ÿ����ɫ�ĸ���
    int balanced_trees = 0; // ��ɫƽ������������

    // ��ȡ������
    scanf("%d", &n);

    struct TreeNode* nodes[n + 1]; // �������
    // ��ʼ���������
    for (i = 1; i <= n; i++) {
        int color;
        scanf("%d", &color);
        nodes[i] = createNode(color);
    }

    // ������
    for (i = 2; i <= n; i++) {
        int parent;
        scanf("%d", &parent);
        nodes[parent]->children[nodes[parent]->num_children++] = nodes[i];
    }

    // DFS��������ͳ����ɫƽ������������
    dfs(nodes[1], color_count, &balanced_trees);

    printf("%d\n", balanced_trees);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 1001

// ���Ķ���
struct TreeNode {
    int color;
    struct TreeNode* children[1001];
    int num_children;
};

// ����һ���µĽ��
struct TreeNode* createNode(int color) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->color = color;
    node->num_children = 0;
    return node;
}

// DFS������ͳ��������ɫ����
void dfs(struct TreeNode* root, int color_count[MAX_COLORS], int* balanced_trees) {
    int i;
    color_count[root->color]++;

    // �ݹ�ش����ӽ��
    for (i = 0; i < root->num_children; i++) {
        dfs(root->children[i], color_count, balanced_trees);
    }

    // ��鵱ǰ�����Ƿ�����ɫƽ����
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
    int color_count[MAX_COLORS] = { 0 }; // ��¼ÿ����ɫ�ĸ���
    int balanced_trees = 0; // ��ɫƽ������������

    // ��ȡ������
    scanf("%d", &n);

    struct TreeNode* nodes[n + 1]; // �������
    // ��ʼ���������
    for (i = 1; i <= n; i++) {
        int color;
        scanf("%d", &color);
        nodes[i] = createNode(color);
    }

    // ������
    for (i = 2; i <= n; i++) {
        int parent;
        scanf("%d", &parent);
        nodes[parent]->children[nodes[parent]->num_children++] = nodes[i];
    }

    // DFS��������ͳ����ɫƽ������������
    dfs(nodes[1], color_count, &balanced_trees);

    printf("%d\n", balanced_trees);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// ���������ֵ
#define INF INT_MAX

// �����豸�����ӵĽṹ��
struct Edge {
    int to;
    int weight;
};

// ����ͼ�Ľṹ��
struct Graph {
    int vertices;           // �豸������
    struct Edge** adjMatrix; // �ڽӾ����ʾ��ͼ
};

// ��ʼ��ͼ
struct Graph* initializeGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    // Ϊ�ڽӾ�������ڴ�
    graph->adjMatrix = (struct Edge**)malloc(vertices * sizeof(struct Edge*));
    for (int i = 0; i < vertices; ++i) {
        graph->adjMatrix[i] = (struct Edge*)malloc(vertices * sizeof(struct Edge));
    }

    // ��ʼ���ڽӾ���
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            graph->adjMatrix[i][j].to = -1; // ��ʾû������
            graph->adjMatrix[i][j].weight = INF; // ��ʼ��Ϊ�����
        }
    }

    return graph;
}

// �������ߵ�ͼ
void addEdge(struct Graph* graph, int from, int to, int weight) {
    graph->adjMatrix[from][to].to = to;
    graph->adjMatrix[from][to].weight = weight;

    // ����������ͼ����Ҫ��ӷ����
    graph->adjMatrix[to][from].to = from;
    graph->adjMatrix[to][from].weight = weight;
}

// Dijkstra�㷨�����Դ�ڵ㵽���������ڵ�����·��
void dijkstra(const struct Graph* graph, int source, int* dist) {
    int visited[graph->vertices];

    // ��ʼ����������ͷ�������
    for (int i = 0; i < graph->vertices; ++i) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0; // Դ�ڵ㵽����ľ���Ϊ0

    for (int count = 0; count < graph->vertices - 1; ++count) {
        int u = -1;

        // ѡ��δ���ʵĽڵ��о�����С�Ľڵ�
        for (int i = 0; i < graph->vertices; ++i) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }

        visited[u] = 1; // ��ǽڵ�Ϊ�ѷ���

        // ����δ���ʽڵ�ľ���
        for (int v = 0; v < graph->vertices; ++v) {
            if (!visited[v] && graph->adjMatrix[u][v].to != -1 &&
                dist[u] + graph->adjMatrix[u][v].weight < dist[v]) {
                dist[v] = dist[u] + graph->adjMatrix[u][v].weight;
            }
        }
    }
}

// ���������豸֮���ͨ���ȶ���
int calculateStability(const int* dist, int destination) {
    if (dist[destination] == INF) {
        return -1; // ���û��·�����򷵻�-1
    }

    return dist[destination];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m); // �����豸��������������

    struct Graph* graph = initializeGraph(n);

    // �����������ӵ���Ϣ
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(graph, u - 1, v - 1, w); // �豸��Ŵ�1��ʼ��ת��Ϊ0��ʼ������
    }

    int q;
    scanf("%d", &q); // ��ѯ����

    for (int i = 0; i < q; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);

        int* distFromX = (int*)malloc(n * sizeof(int));
        dijkstra(graph, x - 1, distFromX);
        int stability = calculateStability(distFromX, y - 1);

        printf("%d\n", stability);

        free(distFromX);
    }

    // �ͷ��ڴ�
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

// ��ʾ�����ڽ��б�
int adjacency_list[MAX_NODES][MAX_NODES];
// ��Ǳ��Ƿ񱻷��ʹ�
bool visited[MAX_NODES][MAX_NODES];
// ������飬��¼�Ͽ��ıߵı��
int result[MAX_NODES];
// ��ǰ�Ͽ��ıߵı��
int result_index;

// ���������������
void dfs(int node, int parent, int a, int b, int n) {
    for (int i = 0; i < n; ++i) {
        if (adjacency_list[node][i] && !visited[node][i]) {
            visited[node][i] = visited[i][node] = true;

            // �����ǰ�ߵ������˵�ֱ�Ϊa��b��˵����������Ҫ�Ͽ�
            if ((node == a && i == b) || (node == b && i == a)) {
                result[result_index++] = i + 1; // �洢�ߵı�ţ���1��ʼ��
            }

            dfs(i, node, a, b, n);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // ��ʼ���ڽ��б��visited����
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        adjacency_list[u - 1][v - 1] = adjacency_list[v - 1][u - 1] = 1;
        visited[u - 1][v - 1] = visited[v - 1][u - 1] = false;
    }

    // ����ÿ�����ԣ�����DFS�ж��Ƿ���ԶϿ�
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);

        // ���ý������ͽ������
        result_index = 0;

        // ����DFS����
        dfs(0, -1, a - 1, b - 1, n);

        // ����������Ϊ0��˵��û���ҵ���Ҫ�Ͽ��ı�
        if (result_index == 0) {
            printf("-1\n");
        }
        else {
            // ����Ͽ��ıߵı��
            for (int j = 0; j < result_index; ++j) {
                printf("%d ", result[j]);
            }
            printf("\n");
        }
    }

    return 0;
}