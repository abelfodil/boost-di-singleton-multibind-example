# Boost.DI multiple bind singleton example

## What does it do?

Suppose you have one or multiple clients needing the same instances of multiples classes,
this example shows how to create a single instance of each class and inject it into multiple other classes.a

## How does it work?

- Magic
- `OperationBase *[]` https://boost-experimental.github.io/di/examples/index.html#multiple-bindings
- `std::shared_ptr` ensures the lifetime of the object is a singleton https://boost-experimental.github.io/di/tutorial/index.html#3-basic-decide-the-life-times
