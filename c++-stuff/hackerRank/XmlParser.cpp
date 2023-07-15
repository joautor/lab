#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <regex>


namespace tools
{
    std::vector<std::string> splitString(std::string s, std::string delimiter)
    {
        std::vector<std::string> splitted;
        size_t pos = 0;
        std::string token;
        while ((pos = s.find(delimiter)) != std::string::npos)
        {
            token = s.substr(0, pos);
            splitted.push_back(token);
            s.erase(0, pos + delimiter.length());
        }
        if (!s.empty())
        {
            splitted.push_back(s);
        }
        return splitted;
    }
}

class Node {
public:
    Node(const std::string& tagName): _tagName(tagName) {};

    std::string getTagName() const
    {
        return _tagName;
    }

    void setTagName(const std::string& name)
    {
        _tagName = name;
    }

    void setValue(const std::string& value)
    {
        _value = value;
    }

    std::string getValue() const
    {
        return _value;
    }

    void addChild(Node* node)
    {
        _children.push_back(node);
    }

    void addAttribute(const std::string& attributeName, const std::string& attributeValue)
    {
        _attributes.insert(std::make_pair(attributeName, attributeValue));
    }

    void showChildren() const
    {
        std::cout << "Children of " << this->getTagName() << ":" << std::endl;
        for(const auto& child : _children)
        {
            std::cout << "\t-> " << child->getTagName() << " = " << child->getValue() << std::endl;
        }
    }
    void showAttributes()
    {
        std::cout << "Attributes of " << this->getTagName() << ":" << std::endl;
        for(const auto& attr : _attributes)
        {
            std::cout << "\t~ " << attr.first << " = " << attr.second << std::endl;
        }
    }
private:
    std::string _tagName;
    std::string _value;
    std::vector<Node*> _children;
    std::map<std::string, std::string> _attributes;
    //Node* parent;
};

class XmlParser {
public:
    XmlParser() {};

    Node* parse(const std::string& buffer)
    {
        const std::string openBracket = "<";
        const std::string closeBracket = ">";
        const std::string closeTagPrefix = "</";

        Node* parent = nullptr;

        auto openB = buffer.find(openBracket);
        auto closeB = buffer.find(closeBracket);
        auto closeTagPre = buffer.find(closeTagPrefix);

        if (openB != std::string::npos &&  closeB != std::string::npos && closeTagPre != openB)
        {
            std::string tagData = buffer.substr(openB + 1, closeB - openB - 1);
            parent = new Node("default");

            for(auto& token : tools::splitString(tagData, " "))
            {
                std::regex pattern("\"|\'");
                token = std::regex_replace(token, pattern, "");
                size_t pos;
                if ((pos = token.find("=")) == std::string::npos)
                {
                    parent->setTagName(token);
                }
                else
                {
                    parent->addAttribute(token.substr(0, pos), token.substr(pos + 1));
                }
            }
            std::string newBuffer = buffer.substr(closeB + 1);
            Node* child = parse(newBuffer);

            if (child != nullptr)
            {
                parent->addChild(child);
            }
            else if (!newBuffer.empty())
            {
                auto newCloseTagPre = newBuffer.find(closeTagPrefix);
                std::string value = newCloseTagPre != std::string::npos ? newBuffer.substr(0, newCloseTagPre) : newBuffer;
                parent->setValue(value);
            }
        }
        return parent;
    }
};

int main()
{
    std::string xmlData = "(<testtag height=143 size=69 name='customName'> \
                                <child>c1</child>\
                            </testtag>)";
    
    std::cout << xmlData << std::endl;
    XmlParser parser;
    Node* root = parser.parse(xmlData);
    std::cout << "tagname: " << root->getTagName() << std::endl;
    root->showChildren();
    std::cout << "value: " << root->getValue() << std::endl;
    root->showAttributes();

    return 0;
}
