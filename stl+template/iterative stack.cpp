template<typename T, typename Container = std::deque<T>>
class iterable_stack
: public std::stack<T, Container>
{
    using std::stack<T, Container>::c;

public:

    // expose just the iterators of the underlying container
    auto begin() { return std::begin(c); }
    auto end() { return std::end(c); }

    auto begin() const { return std::begin(c); }
    auto end() const { return std::end(c); }
};

int main()
{
    iterable_stack<int> st;

    st.push(2);
    st.push(5);
    st.push(3);
    st.push(7);
    st.push(9);

    for(auto i: st)
        std::cout << i << ' ';
    std::cout << '\n';
}
