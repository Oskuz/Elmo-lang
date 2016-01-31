#ifndef PARSER_HPP
#define PARSER_HPP "0.0.0"
#include <string>
#include <unordered_map>
#include <vector>
#include "lexer.hpp"
using namespace std;

//nodes
struct Node;
struct NodeMetadata;

struct Symbol;
struct Function;
struct Function_call;
struct Procedure;
struct Parameter;
struct Argument;
struct Import;
struct Declaring;
struct Array;
struct Val_Type;
struct Operator;
struct If;
struct Ret;
struct Rec;
struct For;
struct While;
struct LineEnd;
struct HalfPoint;
struct Pointer;
struct Type;
struct Impl;
struct StringLiteral;
struct CharacterLiteral;
struct Interger;
struct Float;
struct ParseError;
struct Module;
struct None;
struct Structure;

enum NodeType {
    NONE,
    NODE,
    NODE_META_DATA,
    SYMBOL,
    FUNCTION,
    FUNCTION_CALL,
    PROCEDURE,
    PARAMETER,
    ARGUMENT,
    IMPORT,
    DECLARING,
    ARRAY,
    VAL_TYPE,
    OPERATOR,
    IF,
    RET,
    REC,
    FOR,
    WHILE,
    LINE_END,
    HALF_POINT,
    POINTER,
    TYPE,
    IMPL,
    STRING_LITERAL,
    CHARACTER_LITERAL
    INTERGER,
    FLOAT,
    BOOLEAN,
    STRUCTURE,
    PARSE_ERROR
};

void report_error(ParseError e);

enum ErrorType {ERROR, WARNING};

typedef struct ParseError
{
    string error;
    Region region;
    ErrorType errorType = ErrorType::ERROR;

    vector<string> notes;

    ParseError(string error, Region region) : error(error), region(region) { }
    ParseError(string error, Region region, ErrorType errorType) :
        error(error),
        region(region),
        errorType(errorType) { }
} ParseError;

typedef union NodeData
{
    None* none;
    NodeMetadata* nodeMetadata;
    Symbol* symbol;
    Function* function;
    Function_call* function_call;
    Scope* scope;
    Parameter* parameter;
    Argument* argument;
    Import* import;
    Declaring* declaring;
    Array* array;
    Val_Type* val_Type;
    Operator* operator_;
    If* if_;
    Ret* ret;
    Rec* rec;
    For* for_;
    While* while_;
    LineEnd* lineEnd;
    HalfPoint* halfPoint;
    Pointer* pointer;
    Type* type;
    Impl* impl;
    StringLiteral* stringLiteral;
    CharacterLiteral* characterLiteral;
    Interger* interger;
    Float* float_;
    ParseError* parseError;
    Module* module;
    Structure* structure;

} NodeData;

typedef struct Scope
{
    unordered_map<string, Node*> values;
    Scope* parent;
    bool isModuleLevel = false;
    bool importsNonStatic = true;

    Scope() : values({}), parent(nullptr) {}
    Scope(unordered_map<string, Node*> _values) :
        values(_values),
        parent(nullptr) { }
    Scope(unordered_map<string, Node*> _values, Scope* _parent) :
        values(_values),
        parent(_parent) { }

    Node* resolve(string s, Region r, bool childImportsNonStatic = true);
} Scope;

typedef struct NodeMetadata
{
    Scope *scope = new Scope();
    vector<Node *> annotations = {};
    void *llvm = nullptr;
    Region region;
} NodeMetadata;
typedef struct Node
{
    NodeType type;
    NodeData data;
    NodeMetadata metadata = {};

    Node();
    Node(Node* node);
    Node(None* none);
    Node(NodeMetadata* nodeMetadata);
    Node(Symbol* symbol);
    Node(Function* function);
    Node(Function_call* function_call);
    Node(Scope* scope);
    Node(Parameter* parameter);
    Node(Argument* argument);
    Node(Import* import);
    Node(Declaring* declaring);
    Node(Array* array);
    Node(Val_Type* val_Type);
    Node(Operator* operator_);
    Node(If* if_);
    Node(Ret* ret);
    Node(Rec* rec);
    Node(For* for_);
    Node(While* while_);
    Node(LineEnd* lineEnd);
    Node(HalfPoint* halfPoint);
    Node(Pointer* pointer);
    Node(Type* type);
    Node(Impl* impl);
    Node(StringLiteral* stringLiteral);
    Node(CharacterLiteral* characterLiteral);
    Node(Interger* interger);
    Node(ParseError* parseError);
    Node(Module* module);
    Node(Structure* structure);

    void insertIntoScope(string key, Node *value)
   {
       // if key already exists then there's an error
       auto found = metadata.scope->values.find(key);
       if (found != metadata.scope->values.end())
       {
           auto error = ParseError{"redeclaration of symbol: " + key, value->metadata.region};
           std::ostringstream s;
           s << found->second->metadata.region;
           error.notes.push_back("previous declaration was here: " + s.str() );
       }

       metadata.scope->values[key] = value;
   }

   void setParentScope(Node *parent)
    {
        // functions get their own scopes
        metadata.scope->parent = parent->metadata.scope;

        // sanity check -- make sure scope's parent or grandparent are not equal to the scope itself.
        if (metadata.scope == metadata.scope->parent)
        {
            assert(false);
        }
        if (metadata.scope->parent != nullptr
            && metadata.scope->parent == metadata.scope->parent->parent)
        {
            assert(false);
        }

        if (type == NodeType::FUNCTION)
        {
            // nothing directly inside a function is at module level
            metadata.scope->isModuleLevel = false;

            // can only import static things from outside this function
            metadata.scope->importsNonStatic = false;

            return;
        }

        metadata.scope->isModuleLevel = parent->metadata.scope->isModuleLevel;
    }

}Node;

typedef struct None {} None;

typedef struct Symbol
{
    string value;
    Node* resolved;

    // TODO(chad): @HACK
    bool needs_resolution;

    Symbol();
    Symbol(string _value);
    Symbol(string _value, Node* resolved);
    Symbol(Symbol* s);
    Symbol(Symbol* s, Node* resolved);
    ~Symbol();
} Symbol;

typedef struct Structure
{
    vector<Node*> values; // should be params
}Structure;

typedef struct Impl{
    Node* values; //should be functions
}Impl;

typedef struct Type
{
    string name;
    Node* value; //Structure?
    Node* impl; // Impl
}Type;

typedef struct Function{
    string name;
    Node* arg; //params
    Node* body;
} Function;

typedef struct Module
{
    string name;
    vector<Node*> statements;
}Module;

enum DeclarationType{
    IMMUTABLE, MUTABLE, HARD
}
typedef struct Declaring
{
    string name;
    Node* type;
    Node* initialValue;
    DeclarationType declarationType

}Declaring;

typedef struct Parameter{
    string name;
    Node* type;
    Node* initialValue;
    unsigned int order;
    Parameter();

    template<typename T,U>
    Parameter(string n,T t, U u, unsigned int o);
}Parameter;
#endif
