#include<stdio.h> 
 
int main()  //this is main function
{ 
      int i, n, t = 0, x, count = 0, quantum,j; 
      
	  int waitt = 0, tat = 0,pos,z,p[10],prio[10], a_time[10], b_time[10], temp[10],b; 
      
	  float avgwtime, avgtat;
      
	  printf("\nEnter Number of Processes:"); 
      
	  scanf("%d", &n); 
      
	  x = n; 
      for(i = 0; i < n; i++) 
      {
	    p[i]=i+1;
	   
	    prio[i]=0;
            printf("\nEnter All Details of Process[%d]\n", i + 1);
            printf("Arrival Time:\t");
            scanf("%d", &a_time[i]);
            printf("Burst Time:\t");
            scanf("%d", &b_time[i]); 
            temp[i] = b_time[i];
      }
	   
	quantum = 4; 
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\t Priority\n");
      for(t = 0, i = 0; x != 0;) 
      { 

		    for(z=0;z<n;z++)
		    {
			int temp1;
			pos=z;
			for(j=z+1;j<n;j++)
			{
			    if(prio[j]<prio[pos])
				pos=j;
			}
		 
		temp1=prio[z];
	
		prio[z]=prio[pos];
	
		prio[pos]=temp1;
		 
			temp1=b_time[z];
			b_time[z]=b_time[pos];
			b_time[pos]=temp1;
		 			temp1=a_time[z];
				a_time[z]=a_time[pos];
			a_time[pos]=temp1;

			temp1=p[z];
				p[z]=p[pos];
			p[pos]=temp1;

			temp1=temp[z];
				temp[z]=temp[pos];
			temp[pos]=temp1;
		    }
		{
		}
            
			if(temp[i] <= quantum && temp[i] > 0) 
            { 
                  t = t + temp[i]; 
                  temp[i] = 0; 
                  count = 1; 
            } 
            
			else if(temp[i] > 0) 
            { 
                  temp[i] = temp[i] - quantum; 
                  t = t + quantum; 
            } 

	for(b=0;b<n;b++)
		{
			if(b==i)
			prio[b]+=1;
			else
			prio[b]+=2;
		}

            if(temp[i] == 0 && count == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t\t %d\t\t %d\t\t   %d\n", p[i], b_time[i], t - a_time[i], t - a_time[i] - b_time[i],prio[i]);
                  waitt = waitt + t - a_time[i] - b_time[i]; 
                  tat = tat + t - a_time[i]; 
                  count = 0; 
            } 
            if(i == n - 1) 
            {
                  i = 0; 
            
			}
            else if(a_time[i + 1] <= t) 
            {
                  i++;
            
			}
            else 
            {
                  i = 0;
            
			}		
      } 
      return 0; 
}
