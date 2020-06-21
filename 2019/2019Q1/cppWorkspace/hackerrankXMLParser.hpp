#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct XMLTreeNode {
    vector<XMLTreeNode*>    children;
    map<string, string>     attributes;
    string                  nodeName;

    XMLTreeNode(const string& nd) : nodeName(nd) {}     
};

class TreeBuilder {
private:
    XMLTreeNode*            _root;
    vector<XMLTreeNode*>    _stack;

public:
    TreeBuilder() : _root(nullptr) {
    };

    void addTag(const string& tagName) {
        if( _root == nullptr ) {
            _root = new XMLTreeNode(tagName);
            _stack.emplace_back(_root);

            return;
        }

        auto currentNode = _stack.back();
        auto newNode = new XMLTreeNode(tagName);

        currentNode->children.emplace_back(newNode);
        _stack.emplace_back(newNode);
    }

    void popTag() {
        _stack.pop_back();
    }

    void addAttribute(const string& name, const string& value) {
        auto currentNode = _stack.back();
        currentNode->attributes.insert(make_pair(name,value));
    }
};

class MyXMLParser {
public:
    void parseXML(const string& xmlData) {
        for(auto& token : xmlData) {
            string tagAccumulator{""};
            string attributeAccumulator{""};
            string valueAccumulator{""};
            
            bool backSlashSeen = false;
            bool openingTagSeen = false;

            switch (token) {
                case '\\':
                    backSlashSeen = true;
                    break;
                
                case '<':
                    openingTagSeen = true;
                    break;

                case ' ':
                    break;

                case '\n':
                    break;

                case '>':
                    openingTagSeen = false;
                    if( backSlashSeen == true ) 
                    break;

                default:
                    if( openingTagSeen )    tagAccumulator += token;
                    break;
            }
        }
    }

    bool isPathPresent(const string& pathQuery) {
        return true;
    }
};