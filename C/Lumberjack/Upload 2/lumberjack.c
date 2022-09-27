#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>
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
void sort(int a[], int b[], int k, int l, int h[], int d[], int c[], int p[]){
    int at, bt, ht, dt, ct, pt;
    for (int i = 0; i < k; ++i){
        for (int j = i + 1; j < k; ++j){
            if((l && a[i]>a[j])||(!l && a[i]<a[j])){
                at = a[i];a[i] = a[j];a[j] = at;
                bt = b[i]; b[i] = b[j];b[j] = bt;
                ht = h[i];h[i] = h[j];h[j] = ht;
               dt = d[i];d[i] = d[j];d[j] = dt;
                ct = c[i];c[i] = c[j];c[j] = ct;
                pt = p[i];p[i] = p[j];p[j] = pt;
      }
   }
}}
//Function which gives the number of trees equidistant from present point and their distance
//above information is required for the nearest_tree function
struct equidistant same_distance(int present_x, int present_y, int x[], int y[], int no_of_trees)
{
    float distance, current_distance;
    struct equidistant Equidistant_trees;
    Equidistant_trees.no_of_equidistant_trees = 0;
    for (int i = 0; i < no_of_trees; i++)
    {
        if (x[i] == 0 && y[i] == 0)
        {
            continue;
        }
        else
        {
            distance = abs(x[i] - present_x) + abs(y[i] - present_y);
            break;
        }
    }

    for (int i = 1; i < no_of_trees; i++)
    {
        if (x[i] == 0 && y[i] == 0)
        {
            continue;
        }
        current_distance = abs(x[i] - present_x) + abs(y[i] - present_y);
        if (current_distance < distance)
        {

            distance = current_distance;
        }
    }
    for (int i = 0; i < no_of_trees; i++)
    {
        if (x[i] == 0 && y[i] == 0)
        {
            continue;
        }
        current_distance = abs(x[i] - present_x) + abs(y[i] - present_y);
        if (current_distance == distance)
        {
            Equidistant_trees.no_of_equidistant_trees++;
        }
    }
    Equidistant_trees.distance_from_present_position = distance;

    return Equidistant_trees;
}

//Function gives coordinates of all the equidistant trees from present point
struct coordinates *nearest_tree(int present_x, int present_y, int x[], int y[], int no_of_trees, int no_of_same)
{
    int no_of_equidistant_trees_temp;
    struct equidistant same_distance_details;
    same_distance_details = same_distance(present_x, present_y, x, y, no_of_trees);
    float distance, current_distance;
    distance = same_distance_details.distance_from_present_position;
    no_of_equidistant_trees_temp = same_distance_details.no_of_equidistant_trees;
    struct coordinates *nearest = (struct coordinates *)malloc(no_of_equidistant_trees_temp * sizeof(struct coordinates));
    int j = 0, k = 1;
    for (int i = 0; i < no_of_trees; i++)
    {
        if (x[i] == 0 && y[i] == 0)
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
    for (int i = 0; i < no_of_trees; i++)
    {
        if (x[i] == 0 && y[i] == 0)
        {
            continue;
        }
        current_distance = abs(x[i] - present_x) + abs(y[i] - present_y);
        if (k <= no_of_equidistant_trees_temp && current_distance == distance)
        {
            nearest[j].x = x[i];
            nearest[j].y = y[i];
            j++;
            k++;
        }
        else if (k > no_of_equidistant_trees_temp)
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
    int i, temp_x = present_x, temp_y = present_y;
    for (i = 0; i < k; i++)
    {
        if (x[i] == 0 && y[i] == 0)
        {
            continue;
        }
        if (present_x == x[i] && present_y == y[i])
        {
            break;
        }
    }
    int s_h = h[i], s_w = c[i] * d[i] * h[i], s_v = p[i] * h[i] * d[i];
    dv.time = d[i];
    int j = 0, value_array[4], temp_height = s_h, temp_weight = s_w, temp_value = s_v;
    sort(x, y, k, 1, h, d, c, p);
    for (j = 0; j < k; j++)
    {
        if (x[j] == 0 && y[j] == 0)
        {
            continue;
        }
        if (y[j] == present_y && x[j] > temp_x)
        {
            if (c[j] * d[j] * h[j] < temp_weight && x[j] - temp_x < temp_height)
            {
                temp_weight = c[j] * d[j] * h[j];
                temp_height = h[j];
                temp_value += p[j] * h[j] * d[j];
                temp_x = x[j];
                temp_y = y[j];
            }
            else
            {
                value_array[0] = temp_value;
                break;
            }
        }
        value_array[0] = temp_value;
    }
    temp_height = s_h;
    temp_weight = s_w;
    temp_value = s_v;
    temp_x = present_x;
    temp_y = present_y;
    for (j = k-1; j >= 0; j--)
    {
        if (x[j] == 0 && y[j] == 0)
        {
            continue;
        }
        if (y[j] == present_y && x[j] < temp_x)
        {
            if (c[j] * d[j] * h[j] < temp_weight && temp_x - x[j] < temp_height)
            {
                temp_weight = c[j] * d[j] * h[j];
                temp_height = h[j];
                temp_value += p[j] * h[j] * d[j];
                temp_x = x[j];
                temp_y = y[j];
            }
            else
            {
                value_array[1] = temp_value;
                break;
            }
        }
        value_array[1] = temp_value;
    }
    temp_height = s_h;
    temp_weight = s_w;
    temp_value = s_v;
    temp_x = present_x;
    temp_y = present_y;
    sort(y, x, k, 1, h, d, c, p);
    for (j = k-1; j >= 0; j--)
    {
        if (x[j] == 0 && y[j] == 0)
        {
            continue;
        }
        if (y[j] < temp_y && x[j] == present_x)
        {
            if (c[j] * d[j] * h[j] < temp_weight && temp_y - y[j] < temp_height)
            {
                temp_weight = c[j] * d[j] * h[j];
                temp_height = h[j];
                temp_value += p[j] * h[j] * d[j];
                temp_x = x[j];
                temp_y = y[j];
            }
            else
            {
                value_array[2] = temp_value;
                break;
            }
        }
        value_array[2] = temp_value;
    }
    temp_height = s_h;
    temp_weight = s_w;
    temp_value = s_v;
    temp_x = present_x;
    temp_y = present_y;
    for (j = 0; j < k; j++)
    {
        if (x[j] == 0 && y[j] == 0)
        {
            continue;
        }
        if (y[j] > temp_y && x[j] == present_x)
        {
            if (c[j] * d[j] * h[j] < temp_weight && y[j] - temp_y < temp_height)
            {
                temp_weight = c[j] * d[j] * h[j];
                temp_height = h[j];
                temp_value += p[j] * h[j] * d[j];
                temp_x = x[j];
                temp_y = y[j];
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
    for (j = 0; j < 4; j++)
    {
        if (temp_max < value_array[j])
        {
            temp_max = value_array[j];
            dv.value = value_array[j];
            dv.direction = j;
        }
    }
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
/* Funtion to compare weight and distance to replace relevant tree values(x,y,h,d,c,p) with zero */
int cut_trees(int present_x, int present_y, int x[], int y[], int c[], int h[], int d[], int p[], int k, int n, int cut)
{
    if(cut==0){sort(x, y, k, 1, h, d, c, p);}
    if(cut==1){sort(x, y, k, 0, h, d, c, p);}
    if(cut==2){sort(y, x, k, 0, h, d, c, p);}
    if(cut==3){sort(y, x, k, 1, h, d, c, p);}
    int i=0, temp_x = present_x, temp_y = present_y;
    for (i = 0; i < k; i++)
    {
        if (x[i] == 0 && y[i] == 0)
        {
            continue;
        }
        if (present_x == x[i] && present_y == y[i])
        {
            break;
        }
    }
    int s_h = h[i], s_w = c[i] * d[i] * h[i], s_v = p[i] * h[i] * d[i];
    int j = 0, value_array[4], temp_height = s_h, temp_weight = s_w, temp_value = s_v;
    if(cut==0){
    for (j = 0; j < k; j++)
    {
        if (x[j] == 0 && y[j] == 0)
        {
            continue;
        }
        if (y[j] == present_y && x[j] > temp_x)
        {
            if (c[j] * d[j] * h[j] < temp_weight && x[j] - temp_x < temp_height)
            {
                temp_weight = c[j] * d[j] * h[j];
                temp_height = h[j];
                temp_x = x[j];
                temp_y = y[j];
                x[j] = 0;
                y[j] = 0;
            }
            else
            {
                break;
            }
        }
    }}
    temp_height = s_h;
    temp_weight = s_w;
    temp_value = s_v;
    temp_x = present_x;
    temp_y = present_y;
    if(cut==1){
    for (j = 0; j < k; j++)
    {
        if (x[j] == 0 && y[j] == 0)
        {
            continue;
        }
        if (y[j] == present_y && x[j] < temp_x)
        {
            if (c[j] * d[j] * h[j] < temp_weight && temp_x - x[j] < temp_height)
            {
                temp_weight = c[j] * d[j] * h[j];
                temp_height = h[j];
                temp_x = x[j];
                temp_y = y[j];
                x[j] = 0;
                y[j] = 0;
            }
            else
            {
                break;
            }
        }
    }}
    temp_height = s_h;
    temp_weight = s_w;
    temp_value = s_v;
    temp_x = present_x;
    temp_y = present_y;
    if(cut==2){
    for (j = 0; j < k; j++)
    {
        if (x[j] == 0 && y[j] == 0)
        {
            continue;
        }
        if (y[j] < temp_y && x[j] == present_x)
        {
            if (c[j] * d[j] * h[j] < temp_weight && temp_y - y[j] < temp_height)
            {
                temp_weight = c[j] * d[j] * h[j];
                temp_height = h[j];
                temp_x = x[j];
                temp_y = y[j];
                x[j] = 0;
                y[j] = 0;
            }
            else
            {
                break;
            }
        }
    }}
    temp_height = s_h;
    temp_weight = s_w;
    temp_value = s_v;
    temp_x = present_x;
    temp_y = present_y;
    if(cut==3){
    for (j = 0; j < k; j++)
    {
        if (x[j] == 0 && y[j] == 0)
        {
            continue;
        }
        if (y[j] > temp_y && x[j] == present_x)
        {
            if (c[j] * d[j] * h[j] < temp_weight && y[j] - temp_y < temp_height)
            {
                temp_weight = c[j] * d[j] * h[j];
                temp_height = h[j];
                temp_x = x[j];
                temp_y = y[j];
                x[j] = 0;
                y[j] = 0;
            }
            else
            {
                break;
            }
        }
    }}
    x[i] = 0;
    y[i] = 0;
}
int main()
{
    int t, n, k; // t = time, n = size of grid, k = no. of trees
    scanf("%d%d%d", &t, &n, &k);
    int x[k], y[k], h[k], d[k], c[k], p[k], final_value = 0, present_x = 0, present_y = 0;
    for (int i = 0; i < k; i++)
    {
        scanf("%d%d%d%d%d%d", &x[i], &y[i], &h[i], &d[i], &c[i], &p[i]);
    }
    while (1)
    {
        int equal_0 = 0;
        for (int i = 0; i < k; i++)
        {
            equal_0 = (x[i] == 0 && y[i] == 0) ? equal_0 + 1 : equal_0;
        }
        if (equal_0 == k)
        {
            exit(0);
        }
        int no_of_same_distances;
        struct equidistant temp;
        temp = same_distance(present_x, present_y, x, y, k);
        no_of_same_distances = temp.no_of_equidistant_trees;
        struct coordinates *final_output;
        final_output = nearest_tree(present_x, present_y, x, y, k, no_of_same_distances);
        struct direction_value_time d_v;
        int nearest_x, nearest_y, temp_value = 0, cut_side, temp_time;
        char dir_word[4][10] = {"right", "left", "down", "up"};
        for (int i = 0; i < no_of_same_distances; i++)
        {
            d_v = direction_cut(final_output[i].x, final_output[i].y, x, y, c, h, d, p, k, n);
            if (d_v.value > temp_value)
            {
                temp_value = d_v.value;
                nearest_x = final_output[i].x;
                nearest_y = final_output[i].y;
                cut_side = d_v.direction;
                temp_time = d_v.time;
            }
        }
        t = Transversal(&present_x, &present_y, nearest_x, nearest_y, t);
        if (t - temp_time < 0)
        {
            exit(0);
        }
        if (t == temp_time)
        {
            printf("cut %s\n", dir_word + cut_side);
            exit(0);
        }
        printf("cut %s\n", dir_word + cut_side);
        t -= temp_time;
        final_value += temp_value;
        int value_p = cut_trees(nearest_x, nearest_y, x, y, c, h, d, p, k, n, cut_side);
    }
    return 0;
}
