/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#include "patterns/interpreter.h"
#include <iostream>
#include "String.h"
namespace interpreter {
Context::Context(std::string text) {
    tokens_ = String::split(text, " ");
    index_ = 0;
    NextToken();
}

std::string Context::NextToken() {
if (index_ < tokens_.size()) {
    currentToken_ = tokens_[index_];
    ++ index_;
}
else {
    currentToken_ = "";
}
return currentToken_;
}

void Context::SkipToken(std::string token) {
    if (0 == token.compare(currentToken_)) {
    }
    NextToken();
}

int Context::GetCurrentNumber() {
    int number = 0;
    char * end;
    number = static_cast<int>(strtol(currentToken_.c_str(),&end,10));
    std::cout << "number " << number << std::endl;
    return number;
}

 void ExpressionNode::Interpret(Context * context) {
    while (true) {
        if (context->GetCurrentToken().empty()) {
            break;
        }
        else if (0 == context->GetCurrentToken().compare("END")) {
            context->SkipToken("END"); 
            std::cout << "Token... " << context->GetCurrentToken() << std::endl;
            break;
        }
        else { 
        Node* node = new CommandNode();
        node->Interpret(context);
        nodeList_.push_back(node);
        } 
    }
}
void ExpressionNode::Execute() {
    for (auto node : nodeList_) {
        node->Execute();
    }
}

ExpressionNode::~ExpressionNode() {
    for (auto node : nodeList_) {
        free(node);
    }
}
void LoopCommand::Interpret(Context * context) {
    context->SkipToken("LOOP");
    number_ = context->GetCurrentNumber();
    context->NextToken();
    commandNode_ = new ExpressionNode();
    commandNode_->Interpret(context);
}

void LoopCommand::Execute() {
    for (int i = 0; i < number_; i++) {
    commandNode_->Execute();
    }
}

void PrimitiveCommand::Interpret(Context *context)
{
    name_ = context->GetCurrentToken();
    context->SkipToken(name_);

    if (!name_.compare("PRINT") && !name_.compare("BREAK") && !name_.compare("SPACE")) {
        std::cout << "illegal!" << std::endl;
    }

    if (0 == name_.compare("PRINT")) {
        text_ = context->GetCurrentToken(); 
        context->NextToken();
    }
}

void PrimitiveCommand::Execute()
{
    if (0 == name_.compare("PRINT")) {
        std::cout << text_;
    }
    else if (0 == name_.compare("SPACE")) {
        std::cout << " ";
    }
    else if (0 == name_.compare("BREAK")) {
    std::cout << "\r\n";
    }
}

void CommandNode::Interpret(Context *context) {
if (0 == context->GetCurrentToken().compare("LOOP")) {
node_ptr = new LoopCommand();
node_ptr->Interpret(context);
}
else
{
node_ptr = new PrimitiveCommand();
node_ptr->Interpret(context);
}
}

void CommandNode::Execute() {
node_ptr->Execute();
}
}


/*
template <class T>
class Singleton
{
public:
    static T* Instance()
    {
        return instance;
    }
    static T* getInstance()
    {
        return instance;
    }

protected:
    Singleton()
    {
        if( 0 != instance )
            throw std::exception;

        instance = static_cast<T *>(this);
    }
    virtual ~Singleton()
    {
        instance = 0;
    }

private:
    static T   *instance;
};

template <class T>
T* Singleton<T>::instance = 0;

*/
