#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

struct Node
{
    int value;
    std::weak_ptr<Node> parent;
    std::vector<std::shared_ptr<Node>> children;

    Node() : value(-1) {}
    Node(const int v, std::shared_ptr<Node> &node) : value(v), parent(node) {}
};

int main()
{
    int q;
    std::cin >> q;
    std::shared_ptr<Node> root = std::make_shared<Node>();
    std::shared_ptr<Node> current = root;
    std::unordered_map<int, std::shared_ptr<Node>> note;
    for (int i = 0; i < q; ++i)
    {
        std::string query;
        std::cin >> query;
        if (query == "ADD")
        {
            int x;
            std::cin >> x;
            auto next = std::make_shared<Node>(x, current);
            current->children.emplace_back(next);
            current = next;
        }
        else if (query == "DELETE")
        {
            if (std::shared_ptr<Node> tmp = current->parent.lock())
            {
                current = tmp;
            }
        }
        else if (query == "SAVE")
        {
            int y;
            std::cin >> y;
            note[y] = current;
        }
        else
        {
            int32_t z;
            std::cin >> z;
            if (note.count(z) == 0)
            {
                current = root;
            }
            else
            {
                current = note[z];
            }
        }

        std::cout << current->value;
        if (i == q - 1)
        {
            std::cout << std::endl;
        }
        else
        {
            std::cout << ' ';
        }
    }

    return 0;
}
