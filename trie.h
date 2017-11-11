using namespace std;
class node
{
    public:
    char c;
    int weight;
    node* child[128];
    
    node(char x)
    {
        c=x;
        //weight=i;
        for(int j=0;j<128;j++)
        {
            child[j]=NULL;
        }    
    }
    
    node()
    {
    	
	}
};

class trie
{
	public:

void insert(node* root,string s)
{
    node* curnt=root;
    for(int j=0;j<s.size();j++)
    {
        node* d=new node(s[j]);
        int l=0; 
        
        	if(curnt->child[int(s[j])]!=NULL)
        	{
			
    
                
               	
                    	curnt=curnt->child[int(s[j])];
                		l=1;
        	
            }
        
        
        
        if(l==0)
        {
                    curnt->child[int(s[j])]=d;
                    
                    curnt=d;
        }
    }
    
}



int query(node* root,string s)
{
   // node* dfsroot;
  int len=0;
    node* curnt=root;
    for(int j=0;j<s.size();j++)
    {
        int l=0;    
        
        	if(curnt->child[s[j]]!=NULL)
        	{
            
            	{
            	len++;	
                curnt=curnt->child[s[j]];
                //dfsroot=curnt;
                l=1;
                
            	}
            
        	}
        
        
        
        
        if(l==0)
        {
            return len;
        }
    }
    

      return len;
    
}
};


