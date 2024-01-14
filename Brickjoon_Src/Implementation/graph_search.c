/*
void bfs_s1(char** arr1,int** arr2)
{
    data_t root = {x,y};
    arr2[y][x] = 1;
    queue* q1 = initqueue();
    enqueue(q1, root);
    while(q1->front != NULL)
    {
        data_t d2 = q1->front->data;
        dequeue(q1);
        for(int i = 0; i < 4; i++)
        {
            int nx = d2.x+D1[i].x, ny = d2.y+D1[i].y;
            if(0 <= nx && nx < M && 0 <= ny && ny < N)
            {
                if(arr2[ny][nx] == 0 && arr1[ny][nx] != 'X')
                {
                    arr2[ny][nx] = 1;
                    data_t d3 = {nx,ny};
                    enqueue(q1,d3);
                    if(arr1[ny][nx] == 'P') a++;
                }
            }
        }
    }
    free(q1);
    q1 = NULL;
}
*/