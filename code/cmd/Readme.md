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
gcc -Og -o prog main.c mstore.c
prog:不仅包含了两个文件代码，还包含了用来启动和终止程序的代码，以及用来和操作系统交互的代码。
objdump -d prog
反编译prog中multstore的反编译代码与mstore.o的反编译代码基本一直，主要区别：
1、地址不一样，连接器将这一段代码地址移到了一段不同的地址范围中；
2、连接器填上了callq调用函数mult2需要使用的地址，连接器的任务之一就是为函数调用找到匹配的函数的可执行代码的位置；
3、最后多了两行代码，这两条指令对程序没有影响，插入这两条指令是为了使函数代码变为16字节，使得就存储器系统性能而言，能更好的放置下一个代码块

数据格式:
大多数GCC生成的汇编指令都有一个字符的后缀，表明操作数的大小。
C声明:char ——> Intel数据类型:字节 ——> 汇编代码后缀:b ——> 大小(字节):1
short ——>     字 ——> w ——> 2
int   ——>   双字 ——> l ——> 4
long  ——>   四字 ——> q ——> 8
char* ——>   四字 ——> q ——> 8
float ——> 单精度 ——> s ——> 4
double——> 双精度 ——> l ——> 8
比如传送指令：movb(传送字节),movw(传送字),movl(传送双字),movq(传送四字)

访问信息:
x86-64的中央处理器包含一组16存储64位值的通用目的寄存器，这些寄存器用来存储整数数据和指针。
如图"res/3-2.png"
嵌套的寄存器方框表明，指令可以对这16个寄存器的低位字节中存放不同大小的数据进行操作。字节级可以访问最低的字节，16位操作可以访问最低的2个字节，32位操作可以访问最低的4个字节，64位操作可以访问整个寄存器；
栈指针寄存器(%rsp):用来指明运行时栈的结束位置；

操作数指示符：






