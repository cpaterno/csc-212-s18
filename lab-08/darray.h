class DArray {
    private:
        int cap;
        int length;
        int* content;
        void grow();
        void shrink();
        bool index_in_bounds(int);

    public:
        DArray();
        DArray(int);
        ~DArray();

        int size();
        int capacity();
        int at(int);
        int front();
        int back();
        void set(int, int);
        void push_back(int);
        int pop_back();
        void insert(int, int);
        void erase(int);
        bool empty();
};
