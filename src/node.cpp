/**
* @Author: Oskari Mieskolainen <oskari>
* @Date:   2016-02-15T10:35:42+02:00
* @Email:  oskuz@outlook.com
* @Last modified by:   oskari
* @Last modified time: 2016-02-15T11:31:06+02:00
*/



#include "node.hpp"

Node::Node(){

}
Node::Node(Node* node){
    type = NODE;
    data = node;
}
Node::Node(None* none){
    type = NONE;
    data = none;
}
Node::Node(NodeMetadata* nodeMetadata){
    type = NODE_META_DATA;
    data = nodeMetadata;
}
Node::Node(Symbol* symbol){
    type = SYMBOL;
    data = symbol;
}
Node::Node(Function* function){
    type = FUNCTION;
    data = function;
}
Node::Node(Function_call* function_call){
    type = FUNCTION_CALL;
    data = function_call;
}
Node::Node(Scope* scope){
    type = SCOPE;
    data = scope;
}
Node::Node(Parameter* parameter){
    type = PARAMETER;
    data = parameter;
}
Node::Node(Argument* argument){
    type = ARGUMENT;
    data = argument;
}
Node::Node(Declaring* declaring){
    type = DECLARING;
    data = declaring;
}
Node::Node(Array* array){
    type = ARRAY;
    data = array;
}
Node::Node(Val_Type* val_Type){
    type = VAL_TYPE;
    data = val_Type;
}
Node::Node(Operator* operator_){
    type = OPERATOR;
    data = operator_;
}
Node::Node(If* if_){
    type = IF;
    data = if_;
}
Node::Node(Ret* ret){
    type = RET;
    data = ret;
}
Node::Node(Rec* rec){
    type = REC;
    data = rec;
}
Node::Node(For* for_){
    type = FOR;
    data = for_;
}
Node::Node(While* while_){
    type = WHILE;
    data = while_;
}
Node::Node(LineEnd* lineEnd){
    type = LINE_END;
    data = lineEnd;
}
Node::Node(HalfPoint* halfPoint){
    type = HALF_POINT;
    data = halfPoint;
}
Node::Node(Pointer* pointer){
    type = POINTER;
    data = pointer;
}
Node::Node(Dereference* dereference){
    type = DEREFERENCE;
    data = dereference;
}
Node::Node(Type* type){
    type = TYPE;
    data = type;
}
Node::Node(Impl* impl){
    type = IMPL;
    data = impl;
}
Node::Node(StringLiteral* stringLiteral){
    type = STRING_LITERAL;
    data = stringLiteral;
}
Node::Node(CharacterLiteral* characterLiteral){
    type = CHARACTER_LITERAL;
    data = characterLiteral;
}
Node::Node(Interger* interger){
    type = INTERGER;
    data = interger;
}
Node::Node(ParseError* parseError){
    type = PARSE_ERROR;
    data = parseError;
}
Node::Node(Module* module){
    type = MODULE;
    data = module;
}
Node::Node(Structure* structure){
    type = STRUCTURE;
    data = structure;
}
