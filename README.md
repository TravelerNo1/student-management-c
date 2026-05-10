# 学生管理系统（C 语言版）

## 概述
本项目是一个基于命令行的学生管理系统，使用 C 语言开发。
除了添加、查找、删除和显示学生信息等基本功能外，系统还实现了数据持久化特性，支持通过文件 I/O 操作来保存和加载数据。

开发本系统的初衷是为了帮助用户加深对基础编程技术的理解，包括利用结构体进行数据管理、动态内存分配以及文件操作等。

---

## 核心功能
- 添加学生信息
- 显示学生信息
- 查找学生信息（按 ID 查找）
- 删除学生信息
- 保存数据（文件输出）
- 启动时加载数据
- 清屏功能

---

## 所用技术
- C 语言
- 结构体 (`struct`)
- 动态内存管理 (`malloc` / `realloc` / `free`)
- 文件 I/O (`fopen` / `fprintf` / `fscanf` / `fclose`)
- 数组操作（数据移位）

---

## 数据结构

### `Student` 结构体
用于存储每一位学生的具体信息。

- 学生 ID (`ID`)
- 姓名 (`Name`)
- 年龄 (`Age`)
- 分数 (`Score`)

### `StudentList` 结构体
用于管理整个学生数据集。

- 数据数组（动态数组）
- 当前元素数量 (`size`)
- 数组容量 (`capacity`)

---

## 实现亮点

### 基于动态数组的数据管理
为了适应学生人数不断增加的需求，系统采用了动态数组；当数组达到其最大容量时，会自动调用 `realloc` 进行扩容。

### 优化的删除流程
在删除某条学生记录时，位于目标数据之后的所有元素都会向前移位，以确保数组内部数据的连续性。

### 数据持久化
系统利用文件 I/O 技术，确保即使在程序终止运行后，数据依然能够被保存下来。
在程序启动时，系统会自动从文件中加载此前保存的数据。

### 基本的跨平台兼容性
通过条件编译技术，确保清屏功能能够在 Windows 和 Linux 两种操作系统环境下均正常工作。

---

## 运行环境
- 操作系统：Windows / Linux / macOS
- 编译器：GCC（推荐）

---

## 编译与运行方法

### Windows
```bash
gcc student-management.c -o student-management.exe
student-management.exe

```

### Linux / macOS
```bash
gcc student-management.c -o student-management
./student-management

```
## 执行示例
1. Add Student
2. Show Students
3. Search Student
4. Delete Student
5. Save to File
6. Clear the Screen
0. Exit

---
