#include "stack.h"

int main() {
    StackWrapper stackWrapper = createStackWrapper(2);  // 初始容量 2

    stackWrapper.push(&stackWrapper.stack, 10);
    stackWrapper.push(&stackWrapper.stack, 20);
    stackWrapper.push(&stackWrapper.stack, 30);  // 這次 push 會觸發擴展

    printf("Top element is %d\n", stackWrapper.peek(&stackWrapper.stack));

    stackWrapper.pop(&stackWrapper.stack);
    stackWrapper.pop(&stackWrapper.stack);

    printf("Stack is %s\n", stackWrapper.isEmpty(&stackWrapper.stack) ? "empty" : "not empty");

    stackWrapper.free(&stackWrapper.stack);  // 釋放記憶體
    return 0;
}
