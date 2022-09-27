#include<stdio.h>
#include <math.h>
#include<malloc.h>
#include<stdlib.h>
struct coordinates
{
    int x;
    int y;
};
struct equidistant
{
    int no_of_equidistant_trees;
    float distance_from_present_position;
};
struct direction_value_time
{
    int direction;
    int value;
    int time;
};
//Function which gives the number of trees equidistant from present point and their distance
//above information is required for the nearest_tree function
struct equidistant same_distance(int present_x, int present_y, int x[],int y[], int no_of_trees)
{
    float distance, current_distance;
    struct equidistant Equidistant_trees;
    Equidistant_trees.no_of_equidistant_trees = 0;
    for(int i = 0; i< no_of_trees; i++)
    {
        if(x[i] == 0 && y[i] == 0)
        {
            continue;
        }
        else
        {
            distance = abs(x[i] - present_x) + abs(y[i] - present_y);
            break;
        }
    }

    for(int i = 1; i< no_of_trees; i++)
    {
        if(x[i] == 0 && y[i] == 0)
        {
            continue;
        }
        current_distance = abs(x[i] - present_x) + abs(y[i] - present_y);
         if(current_distance < distance)
         {

             distance = current_distance;
         }
    }
    for(int i = 0; i< no_of_trees; i++)
    {
        if(x[i] == 0 && y[i] == 0)
        {
            continue;
        }
        current_distance = abs(x[i] - present_x) + abs(y[i] - present_y);
         if(current_distance == distance)
         {
            Equidistant_trees.no_of_equidistant_trees++;
         }
    }
    Equidistant_trees.distance_from_present_position = distance;
    return Equidistant_trees;
}
struct coordinates* nearest_tree(int present_x, int present_y, int x[],int y[], int no_of_trees,int no_of_same)
{
    int no_of_equidistant_trees_temp;
    struct equidistant same_distance_details;
    same_distance_details = same_distance(present_x,present_y,x,y,no_of_trees);
    float distance, current_distance;
    distance = same_distance_details.distance_from_present_position;
    no_of_equidistant_trees_temp = same_distance_details.no_of_equidistant_trees;
    struct coordinates* nearest = (struct coordinates*)malloc(no_of_equidistant_trees_temp * sizeof(struct coordinates));
    int j=0,k=1;

    for(int i = 0; i< no_of_trees; i++)
    {
        if(x[i] == 0 && y[i] == 0)
        {
            continue;
        }
        else
        {
            nearest[0].x = x[i];
            nearest[0].y = y[i];
            break;
        }
    }

    for(int i = 0; i< no_of_trees; i++)
    {
        if(x[i] == 0 && y[i] == 0)
        {
            continue;
        }
        current_distance = abs(x[i] - present_x) + abs(y[i] - present_y);
        if(k<=no_of_equidistant_trees_temp && current_distance == distance)
        {
            nearest[j].x = x[i];
            nearest[j].y = y[i];
            j++;
            k++;
        }
        else if(k>no_of_equidistant_trees_temp)
        {
            break;
        }
    }
    return nearest;
}
//Function to give direction and value of cut
struct direction_value_time direction_cut(int present_x, int present_y, int x[], int y[], int c[], int h[], int d[], int p[], int k, int n)
{
    struct direction_value_time dv;
    int i;
    for(i=0; i<k; i++)
    {
        if(x[i] == 0 && y[i] == 0)
        {
            continue;
        }
        if(present_x == x[i] && present_y == y[i])
        {
            break;
        }
    }
    dv.time = d[i];
    int j=0, value_array[4], temp_height=h[i], temp_weight=c[i]*d[i]*h[i], temp_value=p[i]*h[i]*d[i];
    for(j=0; j<k; j++)
    {
        if(x[j] == 0 && y[j] == 0)
        {
            continue;
        }
        if(y[j]==present_y && x[j]>present_x)
        {
            if(c[j]*d[j]*h[j]<temp_weight && x[j]-present_x<temp_height)
            {
                temp_weight = c[j]*d[j]*h[j];
                temp_height = h[j];
                temp_value += p[j]*h[j]*d[j];
            }
            else
            {
                value_array[0] = temp_value;
                break;
            }
        }
        value_array[0] = temp_value;
    }
    temp_height=h[i]; temp_weight=c[i]*d[i]*h[i]; temp_value=p[i]*h[i]*d[i];
    for(j=0; j<k; j++)
    {
        if(x[j] == 0 && y[j] == 0)
        {
            continue;
        }
        if(y[j]==present_y && x[j]<present_x)
        {
            if(c[j]*d[j]*h[j]<temp_weight && present_x-x[j]<temp_height)
            {
                temp_weight = c[j]*d[j]*h[j];
                temp_height = h[j];
                temp_value += p[j]*h[j]*d[j];
            }
            else
            {
                value_array[1] = temp_value;
                break;
            }
        }
        value_array[1] = temp_value;
    }
    temp_height=h[i]; temp_weight=c[i]*d[i]*h[i]; temp_value=p[i]*h[i]*d[i];
    for(j=0; j<k; j++)
    {
        if(x[j] == 0 && y[j] == 0)
        {
            continue;
        }
        if(y[j]<present_y && x[j]==present_x)
        {
            if(c[j]*d[j]*h[j]<temp_weight && present_y-y[j]<temp_height)
            {
                temp_weight = c[j]*d[j]*h[j];
                temp_height = h[j];
                temp_value += p[j]*h[j]*d[j];
            }
            else
            {
                value_array[2] = temp_value;
                break;
            }
        }
        value_array[2] = temp_value;
    }
    temp_height=h[i]; temp_weight=c[i]*d[i]*h[i]; temp_value=p[i]*h[i]*d[i];
    for(j=0; j<k; j++)
    {
        if(x[j] == 0 && y[j] == 0)
        {
            continue;
        }
        if(y[j]>present_y && x[j]==present_x)
        {
            if(c[j]*d[j]*h[j]<temp_weight && y[j]-present_y<temp_height)
            {
                temp_weight = c[j]*d[j]*h[j];
                temp_height = h[j];
                temp_value += p[j]*h[j]*d[j];
            }
            else
            {
                value_array[3] = temp_value;
                break;
            }
        }
        value_array[3] = temp_value;
    }
    int temp_max = 0;
    for(j=0; j<4; j++)
    {
        if(temp_max<value_array[j])
        {
            temp_max = value_array[j];
            dv.value = value_array[j];
            dv.direction = j;
        }
    }
    dv.time = d[i];
    return dv;
}
int Transversal(int *present_x, int *present_y, int nearest_x, int nearest_y, int time)
{
    int p_x = *present_x, p_y = *present_y;
    while (p_x < nearest_x)
    {
        if (time <= 0)
        {
            exit(0);
        }
        printf("move right\n");
        p_x++;
        time--;
    }
    while (p_x > nearest_x)
    {
        if (time <= 0)
        {
            exit(0);
        }
        printf("move left\n");
        p_x--;
        time--;
    }
    while (p_y < nearest_y)
    {
        if (time <= 0)
        {
            exit(0);
        }
        printf("move up\n");
        p_y++;
        time--;
    }
    while (p_y > nearest_y)
    {
        if (time <= 0)
        {
            exit(0);
        }
        printf("move down\n");
        p_y--;
        time--;
    }
    *present_x = p_x;
    *present_y = p_y;
    return time;
}
int main()
{
    int t, n, k; // t = time, n = size of grid, k = no. of trees
    scanf("%d%d%d", &t, &n, &k);
    int x[k], y[k], h[k], d[k], c[k], p[k], final_value=0, present_x=0, present_y=0;
    for(int i=0; i<k; i++)
    {
        scanf("%d%d%d%d%d%d", &x[i], &y[i], &h[i], &d[i], &c[i], &p[i]);
    }
    int no_of_same_distances;
    struct equidistant temp;
    temp = same_distance(present_x,present_y,x,y,k);
    no_of_same_distances = temp.no_of_equidistant_trees;
    struct coordinates* final_output;
    final_output = nearest_tree(present_x,present_y,x,y,k,no_of_same_distances);
    struct direction_value_time d_v;
    int nearest_x, nearest_y, temp_value=0, cut_side, temp_time;
    char dir_word[4][10] = {"right", "left", "down", "up"};
    d_v = direction_cut(final_output[0].x, final_output[0].y, x, y, c, h, d, p, k, n);
    if(d_v.value>temp_value)
    {
        temp_value = d_v.value;
        nearest_x = final_output[0].x;
        nearest_y = final_output[0].y;
        cut_side = d_v.direction;
        temp_time = d_v.time;
    }
    t = Transversal(&present_x, &present_y, nearest_x, nearest_y, t);
    if(t-d_v.time<0)
    {
        exit(0);
    }
    if(t==d_v.time)
    {
        printf("cut %s\n", dir_word+cut_side);
        exit(0);
    }
    printf("cut %s\n", dir_word+cut_side);
    t -= d_v.time;
    final_value += temp_value;
    return 0;
}
