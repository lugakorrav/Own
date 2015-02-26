using namespace std;
template <class T> class stack
{
private:
	int MaxSize;
	int Size;
	T* data;
public:
	stack(int setsize)
	{
		data = new T[setsize];
		MaxSize = setsize;
		Size = 0;
	};
	int size()
	{
		return Size;
	};
	int maxsize()
	{
		return MaxSize;
	};
	void add(T& elem)
	{
		data[Size] = elem;
		Size++;
	};
	void del(int index)
	{
		for (int i = index; i < Size; i++)
			data[i] = data[i + 1];
		Size--;
	};
	friend ostream& operator << (ostream& out, stack arr)
	{
		for (int i = 0; i < arr.Size; i++)
			out << arr.data[i];
		return out;
	};
};
