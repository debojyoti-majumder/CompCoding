// Problem URL: https://www.hackerrank.com/challenges/attribute-parser/problem

#include <iostream>
#include <vector>
#include <string>
#include <map>

struct XMLTreeNode {
	std::vector<XMLTreeNode*>				children;
	std::map<std::string, std::string>		attributes;
	std::string								nodeName;

	XMLTreeNode(const std::string& nd) : nodeName(nd) {}
};

class TreeBuilder {
private:
	XMLTreeNode*				_root;
	std::vector<XMLTreeNode*>   _stack;

public:
	TreeBuilder() : _root(nullptr) {
	};

	void addTag(const std::string& tagName) {
		if (_root == nullptr) {
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

	void addAttribute(const std::string& name, const std::string& value) {
		auto currentNode = _stack.back();
		currentNode->attributes.insert(std::make_pair(name, value));
	}
};

class MyXMLParser {
private:
	TreeBuilder _builder;

public:
	// TODO 1: Remove all the new line and tabs
	void parseXML(const std::string& xmlData) {
		bool backSlashSeen = false;
		bool openingTagSeen = false;
		bool openingQuotesSeen = false;
		bool spaceSeen = false;
		bool equalsSeen = false;
		bool tagAdded = false;

		std::string tagAccumulator{ "" };
		std::string attributeAccumulator{ "" };
		std::string valueAccumulator{ "" };
		std::string parsedString{};

		for (auto& token : xmlData) {
			parsedString += token;

			switch (token) {
			case '\\':
				backSlashSeen = true;
				break;

			case '<':
				openingTagSeen = true;
				break;

			case ' ':
				spaceSeen = true;

				if (openingTagSeen && tagAdded == false) {
					_builder.addTag(tagAccumulator);
					tagAdded = true;

					tagAccumulator = "";
					attributeAccumulator = "";
				}

				break;

			case '=':
				equalsSeen = true;
				tagAccumulator = "";
				break;

			case '\n':
				break;

			case '"':
				if (openingQuotesSeen == true) {
					openingQuotesSeen = false;
					equalsSeen = false;

					_builder.addAttribute(attributeAccumulator, valueAccumulator);
					valueAccumulator = "";
					attributeAccumulator = "";
					tagAccumulator = "";
				}
				else {
					openingQuotesSeen = true;
				}

				break;

			case '>':
				openingTagSeen = false;
				if (tagAdded)	tagAdded = false;

				if (backSlashSeen == true) {
					_builder.popTag();
					backSlashSeen = false;
				}
				else if( spaceSeen == false ) {
					_builder.addTag(tagAccumulator);
				}

				tagAccumulator = "";
				break;

			default:
				if (openingTagSeen)		tagAccumulator += token;
				if (openingQuotesSeen)	valueAccumulator += token;
				
				if ( spaceSeen && equalsSeen == false )			
					attributeAccumulator += token;
				
				break;
			}
		}
	}

	bool isPathPresent(const std::string& pathQuery) {
		return true;
	}
};

int main() {
	MyXMLParser simpleParser;

	auto inpString{ "<root> <element1 attrib1=\"value1\" attrib2=\"Value\"><\\element1> <element2 attrib1=\"value1\" attrib2=\"Value\"><\\element2> <\\root>" };

	simpleParser.parseXML(inpString);
	std::cout << simpleParser.isPathPresent("root~element1") << "\n";
	std::cout << simpleParser.isPathPresent("root~element2.attrib1") << "\n";

	return 0;
}
