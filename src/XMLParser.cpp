#include "XMLParser.h"

utils::XMLParser::XMLParser() {
    head = 0;
}

utils::XMLParser::XMLParser(const std::string& rootName, const std::map<std::string,std::string>& docMap)
{
    using std::string;
    head = new XMLNode(rootName,"");
    
    XMLNode* currNode = 0;
    for(std::map<string,string>::const_iterator it = docMap.begin();it != docMap.end();it++)
    {
        if(currNode == 0)
        {
            currNode = new XMLNode(it->first,it->second);
            head->children = currNode;
        }
        else
        {
            currNode->replaceSiblings(new XMLNode(it->first,it->second));
            currNode = currNode->siblings;
        }
    }
}

utils::XMLParser::XMLParser(const std::map<std::string,std::string>& docMap)
{
    using std::string;
    head = new XMLNode("NULL","");

    XMLNode* currNode = 0;
    for(std::map<string,string>::const_iterator it = docMap.begin();it != docMap.end();it++)
    {
        if(currNode == 0)
        {
            currNode = new XMLNode(it->first,it->second);
            head->children = currNode;
        }
        else
        {
            currNode->replaceSiblings(new XMLNode(it->first,it->second));
            currNode = currNode->siblings;
        }
    }
}


utils::XMLParser::~XMLParser() {
    delete head;
}

void utils::XMLParser::parse(const std::string& xmlFilename) throw (XMLParserException)
{
    delete head;head = 0;
    std::fstream xmlFile(xmlFilename.c_str(),std::ios::in);
    if(!xmlFile.good())
      throw XMLParserException("utils::XMLParser::parse: Could not open xml file: " + xmlFilename,DavidException::IO_ERROR_CODE);
    head = parse(xmlFile);
    if(head == 0)
      throw XMLParserException("utils::XMLParser::parse: Could not open xml file: " + xmlFilename,DavidException::IO_ERROR_CODE);
    xmlFile.close();
}

utils::XMLNode* utils::XMLParser::parse(std::iostream& xmlFile)
{

    using utils::trimString;
    using std::string;
    using std::pair;
    using utils::XMLNode;

    bool isClosedTag = false;
    pair<string,string> currLine = parseLine(getNextLine(xmlFile),isClosedTag);

    XMLNode* head = new XMLNode(currLine.first,currLine.second);
    XMLNode* currNode = head;
    if(isClosedTag)
        currNode = 0;
    while(!xmlFile.eof())
    {
        currLine = parseLine(getNextLine(xmlFile),isClosedTag);
        if(currLine.first.size() > 0)
        {
            if(currNode == 0)
            {
                std::string error = "utils::XMLParser::parse: Missing top level tag. " + head->getName() + " should "
                        "not have a sibling without a parent.";
                throw XMLParserException(error,DavidException::BAD_XML_TAG);
            }
            if(currLine.first == currNode->getName())
            {
                currNode = currNode->parent;//in this case, we're closing what was until now an unclosed tag.
                continue;
            }
            XMLNode* newNode = new XMLNode(currLine.first,currLine.second);
            currNode->insertChild(newNode);
            if(!isClosedTag)
                currNode = newNode;
        }
        else
        {
            if(currLine.second.size() == 0)
                continue;
            currNode->setText(currNode->getText() + currLine.second);
        }
    }
    if(currNode != 0)
    {
        std::string error = "utils::XMLParser::parse: is a malformed XML file. Missing an end tag "
                "to go with " + head->getName();
        throw XMLParserException(error,DavidException::BAD_XML_TAG);
    }

    return head;
}

std::pair<std::string,std::string> utils::XMLParser::parseLine(const std::string& _line,
        bool& isClosedTag) throw (XMLParserException)
{
    std::pair<std::string,std::string> returnMe("","");
    using std::string;
    string line = utils::trimString(_line);
    while(line.find(CR_CHAR) != string::npos)//CR char
    	line.erase(line.find(CR_CHAR),1);

    if(line.size() == 0)
        return returnMe;
    if(line[0] != '<' || line.find_first_of('>') == string::npos)
    {
        returnMe.second = line;
        isClosedTag = false;
        return returnMe;
    }

    size_t tagEnd = line.find_first_of('>');
    returnMe.first = line.substr(1,tagEnd-1);
    line.erase(0,tagEnd+1);
    if(line[0] == '?')
        return std::pair<string,string>("","");

    if(returnMe.first[returnMe.first.size()-1] == '/' || returnMe.first[0] == '/')
    {
        isClosedTag = true;
        returnMe.first.erase(0,1);
        return returnMe;
    }

    size_t endTagPos = line.find_first_of('<');
    if(endTagPos == string::npos)
    {
        isClosedTag = false;
        return returnMe;
    }

    returnMe.second = line.substr(0,endTagPos);
    endTagPos = line.find_first_of('/',endTagPos);
    line = line.substr(endTagPos+1);
    line.erase(line.end()-1);
    if(line.size() > 0 && line != returnMe.first)
    {
        string error = "XML Parser does not yet support multiple tags on one line.\n"
                + _line;
        throw XMLParserException(error,DavidException::BAD_XML_TAG);
    }

    isClosedTag = true;
    return returnMe;
}

void utils::XMLParser::write(const char* fileName)const throw (XMLParserException)
{
    std::fstream outfile(fileName,std::ios::out);
    if(!outfile.good())
    {
        char error[256];
        sprintf(error,"Could not open: %s",fileName);
        throw XMLParserException(error,DavidException::IO_ERROR_CODE);
    }
    outfile << toString();
    outfile.close();
}

std::string utils::XMLParser::toString()const
{
    if(head == 0)
        return "";
    return head->toString();
}

std::map<std::string,std::string> utils::XMLParser::mapNode(XMLNode const * const theNode) throw (XMLParserException)
{
    if(theNode == 0)
        throw XMLParserException("Null XMLNode pointer provided to "
				 "mapNode",DavidException::DATA_FORMAT_ERROR);
    
    std::map<std::string,std::string> returnMe;
    if(theNode->children == 0)
        return returnMe;
    
    for(XMLNode* currNode = theNode->children;currNode != 0;currNode = currNode->siblings)
        returnMe[currNode->getName()] = currNode->getText();

    return returnMe;
}

std::string utils::XMLParser::mainTag()
{
    if(this->head)
        return this->head->getName();

    return "";
}

utils::XMLNode* utils::XMLParser::detachHead()
{
	utils::XMLNode* detached = head;
	head = 0;
	return detached;
}
