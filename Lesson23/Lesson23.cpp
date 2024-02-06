// Lesson 23

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <set>
#include <map>


// 1 calculate number of unique words in string
unsigned int uniqueWordsCount(const std::string& line)
{
    std::set<std::string> myset;
    std::istringstream inputString;
    inputString.str(line);

    for (std::string word; std::getline(inputString, word, ' ');) {
        myset.insert(word);
        // std::cout << word << std::endl;
    }

    int count = 0;
    for (auto& word : myset) {
        // std::cout << myset.count(word) << std::endl;
        if (myset.count(word) > 0) {
            count++;
        }
    }

    return count;
}

// 2 return the most often used word
std::string mostOccuredWord(const std::string& line)
{
    std::map<std::string, int> mymap;
    std::istringstream inputString;
    inputString.str(line);

    std::pair<std::map<std::string, int>::iterator, bool> tmp;
    for (std::string word; std::getline(inputString, word, ' ');) {
        tmp = mymap.insert(std::pair<std::string, int>(word, 1));
        if (!tmp.second) {
            mymap.at(word) += 1;
        }
        //std::cout << tmp.first << " " << tmp.second << std::endl;
    }

    int max = 0;
    std::string maxKey;
    for (const auto& element : mymap) {
        std::cout << element.first << " " << element.second << std::endl;
        if (element.second >= max) {
            max = element.second;
            maxKey = element.first;
        }
    }

    return maxKey;
}

// 3 check balance of brackets
bool checkOppositeBracket(const char open, const char close) {
    if ((open == '(' && close == ')') ||
        (open == '{' && close == '}') ||
        (open == '[' && close == ']') ||
        (open == '<' && close == '>')) {
        return true;
    }

    return false;
}
bool isBracketsBalanced(const std::string& line)
{
    std::stack<char> braceStack;

    for (auto& ch : line)
    {
        //std::cout << e << std::endl;
        if (ch == '(' || ch == '{' || ch == '[' || ch == '<')
        {
            //std::cout << "opened" << std::endl;
            braceStack.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']' || ch == '>')
        {
            //std::cout << "closed" << std::endl;
            if (checkOppositeBracket(braceStack.top(), ch))
            {
                braceStack.pop();
            }
            else
            {
                //std::cout << "NOT OK" << std::endl;
                return false;
                break;
            }
        }
    }

    //std::cout << braceStack.top() << std::endl;

    return true;
}

// 4 check cycle in linked list
class Node 
{
public:
    int data;
    Node* next;
    bool visited = false;

    Node() : data(0),next(nullptr) { }
    Node(int dt, Node* node) : data(dt), next(node) {}
    ~Node() {}
};

bool has_cycle(Node* head) 
{
    while (head != nullptr) {
        if (head->visited) {
            return true;
        }
        head->visited = true;
        head = head->next;
    }
    return false;
}

int main()
{
    std::cout << "Unique Words Count: " << uniqueWordsCount("Hello Hey Hello Bye Hey Bye Hey Hello Hello") << std::endl;
    std::cout << "Most Occured Word: " << mostOccuredWord("Hello Hey Hello Bye Hey Bye Hey Hello Hello") << std::endl;
    std::cout << "Is Brackets Balanced: " << (isBracketsBalanced("{[() ] [ ]}()") ? "OK" : "NOT OK") << std::endl;
    std::cout << "Is Brackets Balanced: " << (isBracketsBalanced("[{]}") ? "OK" : "NOT OK") << std::endl;

    Node node4(4, nullptr);
    Node node3(3, &node4);
    Node node2(2, &node3);
    Node node1(1, &node2);

    std::cout << "Has Cycle: " << (has_cycle(&node1) ? "YES" : "NO") << std::endl;
    node4.next = &node3;
    node1.visited = node2.visited = node3.visited = node4.visited = false; // reset visited flag
    std::cout << "Has Cycle: " << (has_cycle(&node1)? "YES":"NO") << std::endl;
    node4.next = nullptr;
    node1.visited = node2.visited = node3.visited = node4.visited = false; // reset visited flag
    std::cout << "Has Cycle: " << (has_cycle(&node1) ? "YES" : "NO") << std::endl;

}