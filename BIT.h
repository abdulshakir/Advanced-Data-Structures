
template<class T>
class fenwicktree
{
	
public:

	T* bit;
	int size;
	T tdefault;
	fenwicktree(int a,T b)
	{
		size=a;
		tdefault=b;
		bit=new T[size +1];
			for(int i=1;i<=a;i++)
			bit[i]=tdefault;
	}
	
virtual T assign(T a,T val)
{
a+=val;
return a;	
}
	
virtual T combine(T tdefault,T a)
{
tdefault+=a;
return tdefault;	
}
	
void update(int x,T val)
{
      for(; x <= size; x += x&-x)
      {
	  	T a=bit[x];
        bit[x]=assign(a,val);
   	  }
}

T query(int x)
{
     T tdefaul=tdefault;
     for(; x > 0; x -= x&-x)
     {
	 	T a=bit[x];
        tdefaul=combine(tdefaul,a);
 	 }
	 return tdefaul;
}

};


