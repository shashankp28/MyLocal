        int ans=0;
        int v=numsSize, d=-1;
        struct adj list[v];
        for(int i=0; i<v; i++)
        {
            list[i].head = NULL;
            list[i].status = 0;
            list[i].dist = d;
        }
        for(int i=0; i<v-1; i++)
        {
            for(int j=i+1; j<v; j++)
            {
                if(gcd(nums[i], nums[j])!=1)
                {
                    enqueue(&(list[i].head), j);
                    enqueue(&(list[j].head), i);
                }
            }
        }
        for(int j=0; j<v; j++)
        {
            struct node *queue = newnode(j);
            int count=1;
            list[j].dist = 0;
            list[j].status = 1;
            while(queue!=NULL)
            {
                int temp = dequeue(&queue);
                struct node *p = list[temp].head;
                list[temp].status = 2;
                int temp_dist = list[temp].dist;
                while(p!=NULL)
                {
                    if(list[p->data].status == 0)
                    {
                        enqueue(&(queue), p->data);
                        list[p->data].dist = temp_dist+1;
                        list[p->data].status = 1;
                        count++;
                    }
                    p = p->next;
                }
            }
            for(int i=0; i<v; i++)
            {
                list[i].head = NULL;
                list[i].status = 0;
                list[i].dist = d;
            }
            if(count>ans) ans=count;
        }
        return ans;