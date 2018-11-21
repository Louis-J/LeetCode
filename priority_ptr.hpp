template<typename T>
class priority_ptr{
    int priority;
    priority_ptr *priv, *next;
    T t;

    template<class... Args>
    priority_ptr(Args&&... args)
    {
        T *p = (T*)MemPool<T, count>::Allocate();
        if (p != NULL)
        {
            if (!std::is_pod<T>::value)
            {
                for (size_t i = 0; i < count; ++i)
                {
                    new (&p[i]) T(std::forward<Args>(args)...);
}
template<typename T>
class inner_ptr{
private:
    int priority;
    priority_ptr *head;
    T *t;
public:
    template<class... Args>
    inner_ptr(bool exist, Args&&... args)
    {
        if(exist == false){
            t = nullptr;
        }else{
            t = new T(std::forward<Args>(args)...);
        }
    }
}
