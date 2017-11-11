#include<bits/stdc++.h>
using namespace std;
template<class T>

class segmenttree
{
	T* tree;
	T* lazy;
	int size;
public:
	T default1;
	T default2;
	//int* arr;
	virtual T assign(T arr[],int start)
	{
		return arr[start];
	}
	virtual T combine(T a,T b)
	{
		return	min(a,b);
	}
	virtual T update(T a,int start,int end,T val)
	{
		   a+=val;
		   return a;
	}
	virtual T propagate(T a,T val)
	{
		   a+=val;
		   return a;
	}
	
void build(int node,int start,int end,T arr[])
{
    if(start==end)
    {
    
		tree[node]=assign(arr,start);
        //tree[node]=arr[start];
        return;
    }
    else
    {
    int mid=(start+end)/2;
    build(2*node,start,mid,arr);
    build(2*node+1,mid+1,end,arr);
    
    tree[node]=combine(tree[node*2],tree[node*2+1]);
   // tree[node]=min(tree[2*node],tree[2*node+1]);
    
    
    }
}

void updaterange(int node, int start, int end, int l, int r, T val)
{
    if(lazy[node] != default1)//0)
    { 
    	tree[node]=update(tree[node],start,end,lazy[node]);
       // tree[node] +=lazy[node];    
       if(start != end)
        {
        lazy[node*2]=propagate(lazy[2*node],lazy[node]);
        lazy[node*2+1]=propagate(lazy[2*node+1],lazy[node]);
            //lazy[node*2] += lazy[node];                  
            //lazy[node*2+1] += lazy[node];                
        }
        
        lazy[node] = default1;//0;                                  
    }
    if((start > end)||(start > r)||(end < l))              
        return;
    if((start >= l)&&(end <= r))
    {
    	tree[node]=update(tree[node],start,end,val);
        //tree[node] +=val;
        if(start != end)
        {
    		lazy[node*2]=propagate(lazy[2*node],val);
        	lazy[node*2+1]=propagate(lazy[2*node+1],val);
           // lazy[node*2] += val;
           // lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updaterange(node*2, start, mid, l, r, val);       
    updaterange(node*2 + 1, mid + 1, end, l, r, val); 


		 tree[node]=combine(tree[node*2],tree[node*2+1]);
   // tree[node] = min(tree[node*2],tree[node*2+1]);       
}

T queryrange(int node, int start, int end, int l, int r)
{
    if((start > end )|| (start > r) ||( end < l))
        return  default2;///1000000000;        
    if(lazy[node] != default1)
    {
    	tree[node]=update(tree[node],start,end,lazy[node]);
           // tree[node] +=lazy[node];            
        if(start != end)
        {
        	lazy[node*2]=propagate(lazy[2*node],lazy[node]);
        	lazy[node*2+1]=propagate(lazy[2*node+1],lazy[node]);
          //  lazy[node*2] += lazy[node];         
          //  lazy[node*2+1] += lazy[node];    
        }
        
        lazy[node] = default1;//0;                    
	 }
    if((start >= l)&&(end <= r))            
        return tree[node];
    int mid = (start + end) / 2;
    T p1 = queryrange(node*2, start, mid, l, r);        
    T p2 = queryrange(node*2 + 1, mid + 1, end, l, r); 
    return combine(p1,p2);//min(p1,p2);
}

void build(T arr[])
{
	build(1,1,size,arr);
}
void updaterange(int l,int r,T val)
{
	updaterange(1,1,size,l,r,val);
}
T queryrange(int l,int r)
{
	return	queryrange(1,1,size,l,r);
}

	segmenttree(int a,T b,T c)
	{
		size=a;
		tree=new T[4*a];
		lazy=new T[4*a];
		
	//	build(1,1,a,tree,arr);
		default1=b;
		default2=c;	
		for(int i=0;i<a*4;i++)
			lazy[i]=default1;
	}
};




