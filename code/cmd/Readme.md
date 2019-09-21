gcc -Og -S mstore.c
-S:编译成汇编代码,生成*.s汇编文件
gcc -Og -c mstore.c
-c:编译并汇编该代码，生成*.o目标代码文件
查看二进制文件：
vim -b mstore.o  打开文件
输入命令：%!xxd -g 1   切换到十六进制显示
-Os:优化级别
反汇编器：根据机器代码产生类似汇编代码的格式
objdump -d mstore.o

-o:生成可执行文件
gcc -Og -c prog main.c mstore.c
prog:不仅包含了两个文件代码，还包含了用来启动和终止程序的代码，以及用来和操作系统交互的代码。
objdump -d prog
反编译prog中multstore的反编译代码与mstore.o的反编译代码基本一直，主要区别：
1、地址不一样，连接器将这一段代码地址移到了一段不同的地址范围中；
2、连接器填上了callq调用函数mult2需要使用的地址，连接器的任务之一就是为函数调用找到匹配的函数的可执行代码的位置；
3、最后多了两行代码，这两条指令对程序没有影响，插入这两条指令是为了使函数代码变为16字节，使得就存储器系统性能而言，能更好的放置下一个代码块





