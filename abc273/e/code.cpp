#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

struct Query
{
    enum Type
    {
        ADD,
        DELETE,
        SAVE,
        LOAD
    };

    Type type;
    int index;
    int count;
};

int main()
{
    int q;
    std::cin >> q;
    std::stack<int32_t> as;
    std::unordered_map<int32_t, std::stack<int32_t>> note;
    std::vector<Query> queries(q);
    for (int i = 0; i < q; ++i)
    {
        std::string query;
        std::cin >> query;
        if (query == "DELETE")
        {
            queries[i] = Query{Query::DELETE, -1, -1};
        }
        else
        {
            int32_t v;
            std::cin >> v;
            if (query == "ADD")
            {
                queries[i] = Query{Query::ADD, v, -1};
            }
            else if (query == "SAVE")
            {
                queries[i] = Query{Query::SAVE, v, -1};
            }
            else
            {
                queries[i] = Query{Query::LOAD, v, -1};
            }
        }
    }
    std::unordered_set<int> need_to_save;
    std::unordered_map<int, int> load_count;
    for (int i = q - 1; i >= 0; --i)
    {
        if (queries[i].type == Query::LOAD)
        {
            need_to_save.emplace(queries[i].index);
            ++load_count[queries[i].index];
        }
        else if (queries[i].type == Query::SAVE)
        {
            if (need_to_save.count(queries[i].index) == 0)
            {
                queries[i].index = -1;
            }
            else
            {
                queries[i].count = load_count[queries[i].index];
                load_count.erase(queries[i].index);
                need_to_save.erase(queries[i].index);
            }
        }
    }

    load_count.clear();
    for (int i = 0; i < q; ++i)
    {
        const Query::Type query = queries[i].type;
        const int32_t v = queries[i].index;
        if (query == Query::ADD)
        {
            as.emplace(v);
            std::cout << v;
        }
        else if (query == Query::DELETE)
        {
            if (!as.empty())
            {
                as.pop();
            }

            if (as.empty())
            {
                std::cout << -1;
            }
            else
            {
                std::cout << as.top();
            }
        }
        else if (query == Query::SAVE)
        {
            if (v != -1)
            {
                note[v] = as;
                load_count[v] = queries[i].count;
            }

            if (as.empty())
            {
                std::cout << -1;
            }
            else
            {
                std::cout << as.top();
            }
        }
        else
        {
            if (note.count(v) == 0)
            {
                as = std::stack<int>();
            }
            else
            {
                as = note[v];
                --load_count[v];
                if (load_count[v] == 0)
                {
                    note.erase(v);
                    load_count.erase(v);
                }
            }
            if (as.empty())
            {
                std::cout << -1;
            }
            else
            {
                std::cout << as.top();
            }
        }
        if (i != q - 1)
        {
            std::cout << ' ';
        }
        else
        {
            std::cout << std::endl;
        }
    }

    return 0;
}
