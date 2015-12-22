# IOT41_TA
codes when I was TA of IOT 41 of XJTU

## Max Queue
- we know that we can implement a max/min stack with two normal stacks easily, and we can implement a queue with two stack easily. So, to implement a max queue, we can first implement a max stack with two normal stacks, and then implement a max queue with two max stacks.
- There is another kind of method which can be used to implement a max queue. For more detailed information, please refer to deng's books.
- Compared with deng's method, this kind of implementation is quite easy to understand. As for efficiency, both methods can complete pop and push operation in O(1) time(amortized meaning).


## Tips
- when I was implementing max queue, read a char from stdin is really a tricky problem, it often reads something weird. I solve this problem by add a space before reading format when I call scanf function. For more detailed information, please see the test_scanf.c file under the same directory.

- in c89, you can not initialize variable in for loop, but you can do this in c99

- there is no bool type in c89. bool type was included from c99 in stdbool.h header file

- yes, you can compile cpp file with gcc, but use g++ will make your life easier

## What to do
- change the zuma from c++ style to pure c style 
