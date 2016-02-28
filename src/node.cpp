/**
* @Author: Oskari Mieskolainen <oskari>
* @Date:   2016-02-15T10:35:42+02:00
* @Email:  oskuz@outlook.com
* @Last modified by:   oskari
* @Last modified time: 2016-02-28T14:24:54+02:00
*/


#include <cassert>
#include "node.hpp"

Node::Node(){

}
Node::Node(Node* node){
    type = NodeType::NODE;
    data.node = node;
}
Node::Node(None* none){
    type = NodeType::NONE_;
    data.none = none;
}
Node::Node(NodeMetadata* nodeMetadata){
    type = NodeType::NODE_META_DATA;
    data.nodeMetadata = nodeMetadata;
}
Node::Node(Symbol* symbol){
    type = NodeType::SYMBOL;
    data.symbol = symbol;
}
Node::Node(Function* function){
    type = NodeType::FUNCTION;
    data.function = function;
}
Node::Node(Function_call* function_call){
    type = NodeType::FUNCTION_CALL;
    data.function_call = function_call;
}
Node::Node(Scope* scope){
    type = NodeType::SCOPE;
    data.scope = scope;
}
Node::Node(Parameter* parameter){
    type = NodeType::PARAMETER;
    data.parameter = parameter;
}
Node::Node(Argument* argument){
    type = NodeType::ARGUMENT;
    data.argument = argument;
}
Node::Node(Declaring* declaring){
    type = NodeType::DECLARING;
    data.declaring = declaring;
}
Node::Node(Array* array){
    type = NodeType::ARRAY;
    data.array = array;
}
Node::Node(Val_Type* val_Type){
    type = NodeType::VAL_TYPE;
    data.val_Type = val_Type;
}
Node::Node(Operator* operator_){
    type = NodeType::OPERATOR_;
    data.operator_ = operator_;
}
Node::Node(If* if_){
    type = NodeType::IF;
    data.if_ = if_;
}
Node::Node(Ret* ret){
    type = NodeType::RET;
    data.ret = ret;
}
Node::Node(Rec* rec){
    type = NodeType::REC;
    data.rec = rec;
}
Node::Node(For* for_){
    type = NodeType::FOR;
    data.for_ = for_;
}
Node::Node(While* while_){
    type = NodeType::WHILE;
    data.while_ = while_;
}
Node::Node(LineEnd* lineEnd){
    type = NodeType::LINE_END;
    data.lineEnd = lineEnd;
}
Node::Node(HalfPoint* halfPoint){
    type = NodeType::HALF_POINT;
    data.halfPoint = halfPoint;
}
Node::Node(Pointer* pointer){
    type = NodeType::POINTER;
    data.pointer = pointer;
}
Node::Node(Dereference* dereference){
    type = NodeType::DEREFERENCE;
    data.dereference = dereference;
}
Node::Node(Type* type_){
    type = NodeType::TYPE;
    data.type = type_;
}
Node::Node(Impl* impl){
    type = NodeType::IMPL;
    data.impl = impl;
}
Node::Node(StringLiteral* stringLiteral){
    type = NodeType::STRING_LITERAL;
    data.stringLiteral = stringLiteral;
}
Node::Node(CharacterLiteral* characterLiteral){
    type = NodeType::CHARACTER_LITERAL;
    data.characterLiteral = characterLiteral;
}
Node::Node(Interger* interger){
    type = NodeType::INTERGER;
    data.interger = interger;
}
Node::Node(ParseError* parseError){
    type = NodeType::PARSE_ERROR;
    data.parseError = parseError;
}
Node::Node(Module* module){
    type = NodeType::MODULE;
    data.module = module;
}
Node::Node(Structure* structure){
    type = NodeType::STRUCTURE;
    data.structure = structure;
}
