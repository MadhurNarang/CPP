template<typename T>
class binarytreenode
{
    public :
    T data;
    binarytreenode<T> *left;
    binarytreenode<T> *right;

    binarytreenode(T data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }

    ~binarytreenode()
    {
        delete left;
        delete right;
    }
};