# Что происходит при запуске бинаря до начала функции main, а также после ее окончания?
```text
# objdump -d example

0000000000001060 <_start>:
    1060:	f3 0f 1e fa          	endbr64
    1064:	31 ed                	xor    %ebp,%ebp
    1066:	49 89 d1             	mov    %rdx,%r9
    1069:	5e                   	pop    %rsi
    106a:	48 89 e2             	mov    %rsp,%rdx
    106d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1071:	50                   	push   %rax
    1072:	54                   	push   %rsp
    1073:	45 31 c0             	xor    %r8d,%r8d
    1076:	31 c9                	xor    %ecx,%ecx
    1078:	48 8d 3d ca 00 00 00 	lea    0xca(%rip),%rdi        # 1149 <main>
    107f:	ff 15 5b 2f 00 00    	call   *0x2f5b(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.34>
    1085:	f4                   	hlt
    1086:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    108d:	00 00 00
    
    ...
    ...
    ...
    
0000000000001149 <main>:
    1149:	f3 0f 1e fa          	endbr64
    114d:	55                   	push   %rbp
    114e:	48 89 e5             	mov    %rsp,%rbp
    1151:	48 8d 05 ac 0e 00 00 	lea    0xeac(%rip),%rax        # 2004 <_IO_stdin_used+0x4>
    1158:	48 89 c6             	mov    %rax,%rsi
    115b:	48 8d 05 de 2e 00 00 	lea    0x2ede(%rip),%rax        # 4040 <_ZSt4cout@GLIBCXX_3.4>
    1162:	48 89 c7             	mov    %rax,%rdi
    1165:	e8 e6 fe ff ff       	call   1050 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
    116a:	b8 00 00 00 00       	mov    $0x0,%eax
    116f:	5d                   	pop    %rbp
    1170:	c3                   	ret
```

# Как попросить g++ поставить точку старта программы на конкретную функцию?

Можно указать через флаг `-e` функцию начала, тогда программа точка старта будет не на `_start`.

```shell
  # Ставим поинт на другую функцию
  g++ -e start_point -nostartfiles nomain.cpp -o nomain
```

```text
Disassembly of section .text:

0000000000001050 <_Z11start_pointv>:
    1050:	f3 0f 1e fa          	endbr64
    1054:	55                   	push   %rbp
    1055:	48 89 e5             	mov    %rsp,%rbp
    1058:	48 8d 05 a1 0f 00 00 	lea    0xfa1(%rip),%rax        # 2000 <_Z11start_pointv+0xfb0>
    105f:	48 89 c6             	mov    %rax,%rsi
    1062:	48 8d 05 97 2f 00 00 	lea    0x2f97(%rip),%rax        # 4000 <_ZSt4cout@GLIBCXX_3.4>
    1069:	48 89 c7             	mov    %rax,%rdi
    106c:	e8 bf ff ff ff       	call   1030 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
    1071:	bf 00 00 00 00       	mov    $0x0,%edi
    1076:	e8 c5 ff ff ff       	call   1040 <exit@plt>
```
