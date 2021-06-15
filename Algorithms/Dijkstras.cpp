/*
This needs some more work but it is the general idea


*/
/*
Input: 
        G - 2D graph G as an adjancecny matrix
        src - source node
        v = number nodes
Output: 
        dist array -- will hold shortest distnace from src to all i in graph G

*/
int minDist(int dst[], bool isInc[], int v) {
    int min = INT_MAX;
    int min_index;
    for (int i = 0; i < v; i++) {
        if (isInc[i] == false && dst[v] <= min) {
            min = dst[i];
            min_index = i;
        }
    }     
    return min_index;
}

int * dijkstras(int G[][], int src, int v) {
    int dist[v];
    /* Is node i included in the shortest distance path     */
    bool isInc[v] = {false};   

    /* Parent array to store shortest path tree             */
    int parent[v];  
    /* Initialize all distances to infinity and isInc to false  */
    for (int i = 0; i < v; i++) {
        parent[i] = 0;
        dist[i] = INT_MAX;
        isInc[i] = false;
    }

    dist[src] = 0;
    for (int cnt = 0; cnt < v-1; cnt++) {
        int u = minDist(dst, isInc);
        isInc[u] = true;
        for (int w = 0; w < v - 1; w++) {
            if (!isInc[w] && graph[u][w] && dist[u] + G[u][w] < dist[w]){
                parent[w] = u;
                dist[w] = dist[u] + G[u][w];
            }
        }
    }
    return dist;
}