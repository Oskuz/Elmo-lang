/**
* @Author: Oskari Mieskolainen <oskari>
* @Date:   2016-02-15T10:35:42+02:00
* @Email:  oskuz@outlook.com
* @Last modified by:   oskari
* @Last modified time: 2016-02-15T10:35:42+02:00
*/



#include "node.hpp"

Node::Node(){

}
Node::Node(Node* node){
    type = NodeType::NODE
}
Node::Node(None* none);
Node::Node(NodeMetadata* nodeMetadata);
Node::Node(Symbol* symbol);
Node::Node(Function* function);
Node::Node(Function_call* function_call);
Node::Node(Scope* scope);
Node::Node(Parameter* parameter);
Node::Node(Argument* argument);
Node::Node(Declaring* declaring);
Node::Node(Array* array);
Node::Node(Val_Type* val_Type);
Node::Node(Operator* operator_);
Node::Node(If* if_);
Node::Node(Ret* ret);
Node::Node(Rec* rec);
Node::Node(For* for_);
Node::Node(While* while_);
Node::Node(LineEnd* lineEnd);
Node::Node(HalfPoint* halfPoint);
Node::Node(Pointer* pointer);
Node::Node(Dereference* dereference);
Node::Node(Type* type);
Node::Node(Impl* impl);
Node::Node(StringLiteral* stringLiteral);
Node::Node(CharacterLiteral* characterLiteral);
Node::Node(Interger* interger);
Node::Node(ParseError* parseError);
Node::Node(Module* module);
Node::Node(Structure* structure);
