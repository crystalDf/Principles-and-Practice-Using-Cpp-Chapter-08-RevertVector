#include <iostream>
#include <vector>
#include <string>

template<typename T>
std::vector<T> revert_with_new_vector(const std::vector<T>& vt);
template<typename T>
void revert_vector(std::vector<T>& vt);
template<typename T>
void print_vector(const std::string& prompt, const std::vector<T>& vt);

int main()
{
    std::vector<int> vi = { 1, 3, 5, 7, 9 };
    print_vector("original vi: ", vi);
    print_vector("revert with new vector: ", revert_with_new_vector(vi));
    revert_vector(vi);
    print_vector("reverted vi: ", vi);

    std::vector<std::string> vs = { "Alice", "Bob", "Catherine", "Donald", "Elizabeth" };
    print_vector("original vs: ", vs);
    print_vector("revert with new vector: ", revert_with_new_vector(vs));
    revert_vector(vs);
    print_vector("reverted vs: ", vs);

    std::cin.get();
}

template<typename T>
std::vector<T> revert_with_new_vector(const std::vector<T>& vt)
{
    std::vector<T> result;

    for (int i = vt.size() - 1; i >= 0; --i)
    {
        result.push_back(vt[i]);
    }

    return result;
}

template<typename T>
void revert_vector(std::vector<T>& vt)
{
    for (int i = 0; i < vt.size() / 2; ++i)
    {
        std::swap(vt[i], vt[vt.size() - 1 - i]);
    }
}

template<typename T>
void print_vector(const std::string& prompt, const std::vector<T>& vt)
{
    std::cout << prompt;

    for (T i : vt)
    {
        std::cout << " " << i;
    }

    std::cout << std::endl;
}