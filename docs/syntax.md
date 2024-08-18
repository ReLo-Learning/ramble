# Variable Declaration
```rust
let ident: (type) = (value)
let ident: (type)
let ident = (value)

const ident: (type) = (value)
const ident = (value)
```

# Function Declaration
```go
func ident(param: type) -> (RetType, RetType) {}
func ident(param: type) -> RetType {}
func ident(param: type) {}

func<T> ident(param: T) {}
```

# Call C Functions

```c++
extern func puts(const char *) -> int

func main()
{
    puts("Hello, World!")
}
```