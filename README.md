# Elmo-language
Elmo is small (toy) system language.
Example code:
```
module main import "io", "math" {
    let main = (){   #fibonacci
                     [1 ..8] |> (n:i32){ 
                                    if n <= 1 { ret 1}
                                    else {ret rec(n-1) + rec(n-2)}
                                    } | println;
                 }

#struct
type vector = {i:i j:i},
    impl{ 
        let lenght = (self){ math.sqr math.pow self.i 2 + math.pow self.j 2 }
    }
}   
```
```
module containers {
   type List = {value:i next:List*} , impl{ 
             let add = (self x:i){ 
                       if self.next == nil { 
                          self.next = new List(x)
                       } else{ 
                              self.next.add(x)
                             }
                      }
            }
}
```
## Specification~
```
$()
```
Marks a optional value in code.

### Variables
you would declare variables a four way:
 * mutable, not assigned  ``` let <name>:<type> ```
 * constant ``` let <name>$(:<type>) = <value> ```
 * mutable ``` let <name>$(:<type>) := <value> ```
 * constant, name changet to value in every place where it exist ```let const <name>$(:<type>) = <value> ```
 
### Module
Module is basic namespace.
```
module <name> $(import <libs>) { <statements> }
```
### functions
All functions are lamdas, they are nameless.
```
($(<args>))$(-> <type>){ <body> }
```
####rec-keyword
rec-keyword let function call itself. ``` rec(<statement>) ```

##Todo-list:
- [x] lexer
- [ ] write better specification
- [ ] parser
- [ ] ast 
- [ ] type check
- [ ] gode generation, llmv?
