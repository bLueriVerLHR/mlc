# MLC

Machine Learning Compiler using C Syntax

使用的是 C++ 的子集，详细语法可以参见 `project/src/parser/parser.y`。

目前设想如下：

- 高级 ir 为 ast，使用 g++ 编译器验证
- 第二层高级 ir 为 mlir，使用 mlir 工具链验证
- 如果目标为 CPU
    - 中级 ir 为 llvm ir
    - 低级 ir 为 machine ir
    - 最终汇编为 risc-v 

# TODO

- [ ] ast 分析
    - [ ] 符号表
- [ ] ast 转译为 mlir
- [ ] mlir 转译为 低级 ir（目前还没有决定） 