#include <stdio.h>
#include <stdlib.h>

#define MAXEDGE 20
#define MAXVEX 20
#define INIFINTY 65535

typedef struct {
    
    int arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
    
}MGraph;

/**
 * ����ͼ
 */
void CreateMGraph(MGraph * G){
    
    int i, j;
    
    G->numVertexes = 9;  // 9������
    G->numEdges = 15;  // 15����
    
    for (i = 0; i < G->numVertexes; i++) {  // ��ʼ��ͼ
        for (j = 0; j < G->numVertexes; j++) {
            if (i == j)
                G->arc[i][j] = 0;
            else
                G->arc[i][j] = G->arc[j][i] = INIFINTY;
        }
    }
    
    G->arc[0][1] = 10;
    G->arc[0][5] = 11;
    
    G->arc[1][2] = 18;
    G->arc[1][8] = 12;
    G->arc[1][6] = 16;
    
    G->arc[2][3] = 22;
    G->arc[2][8] = 8;
    
    G->arc[3][4] = 20;
    G->arc[3][7] = 16;
    G->arc[3][6] = 24;
    G->arc[3][8] = 21;
    
    G->arc[4][5] = 26;
    G->arc[4][7] = 7;
    
    G->arc[5][6] = 17;
    
    G->arc[6][7] = 19;
    
    // �����ڽӾ���ĶԳ���
    for (i = 0; i < G->numVertexes; i++)
        for (j = 0; j < G->numVertexes; j++)
            G->arc[j][i] = G->arc[i][j];
}


/**
 * Prime�㷨������С������
 */
void MiniSpanTree_Prim(MGraph G){
    
    int min,i,j,k;
    
    int adjvex[MAXVEX]; // ������ض�����±�
    int lowcost[MAXVEX]; // ������ض����ߵ�Ȩֵ
    
    lowcost[0] = 0;  // ��ʼ����һ��ȨֵΪ0����v0����������
    adjvex[0] = 0; // ��ʼ����һ�������±�Ϊ0
    
    for (i = 1; i < G.numVertexes; i++) {  // ѭ�����±�Ϊ0���ȫ������
        lowcost[i] = G.arc[0][i];  // ��v0������֮�ұߵ�Ȩֵ��������
        adjvex[i] = 0; // ��ʼ����Ϊv0���±�
    }
    
    for (i = 1; i < G.numVertexes; i++) {
        
        min = INIFINTY; //��ʼ����СȨֵ
        j = 1;
        k = 0;
        
        while (j < G.numVertexes) { // ѭ��ȫ������
            if (lowcost[j] != 0 && lowcost[j] < min) {
                min = lowcost[j];  // �õ�ǰȨֵ��Ϊ��Сֵ
                k = j;  // ����ǰ��Сֵ���±����k
            }
            j++;
        }
        
        printf("(%d, %d)\n", adjvex[k], k);  // ��ӡ��ǰ������Ȩֵ��С�ı�
        lowcost[k] = 0;             // ����ǰ�����Ȩֵ����Ϊ0����ʾ�˶����Ѿ��������
        
        for (j = 1; j < G.numVertexes; j++) {  // ѭ�����ж���
            if (lowcost[j]!= 0 && G.arc[k][j] < lowcost[j]) {  // ����±�Ϊk�������ȨֵС�ڵ�ǰ��Щ����δ������������Ȩֵ
                lowcost[j] = G.arc[k][j]; // ����С��Ȩֵ����lowcost��Ӧ��λ��
                adjvex[j] = k;   // ���±�Ϊk�Ķ������adjvex
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    MGraph G;
    CreateMGraph(&G);
    MiniSpanTree_Prim(G);
    
    return 0;
}

