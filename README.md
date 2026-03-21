# 学生管理システム（C言語）

## 概要
本プロジェクトは、C言語で開発したコマンドライン型の学生管理システムです。  
学生情報の追加・検索・削除・表示などの基本機能に加え、ファイル入出力によるデータの保存・読み込み機能を実装しています。

本システムは、構造体によるデータ管理、動的メモリ確保、ファイル操作などの基礎技術の理解を目的として開発しました。

---

## 主な機能
- 学生情報の追加
- 学生情報の表示
- 学生情報の検索（IDによる検索）
- 学生情報の削除
- データの保存（ファイル出力）
- 起動時のデータ読み込み
- 画面クリア機能

---

## 使用技術
- C言語
- 構造体（struct）
- 動的メモリ管理（malloc / realloc / free）
- ファイル入出力（fopen / fprintf / fscanf / fclose）
- 配列操作（データのシフト処理）

---

## データ構造

### Student構造体
各学生の情報を保持します。

- 学籍番号（ID）
- 名前（Name）
- 年齢（Age）
- 成績（Score）

### StudentList構造体
学生データ全体を管理します。

- データ配列（動的配列）
- 現在の要素数（size）
- 配列容量（capacity）

---

## 実装上の工夫

### 動的配列によるデータ管理
学生数の増加に対応するため、動的配列を使用し、容量不足時には `realloc` による拡張を行っています。

### 削除処理の最適化
学生削除時には、対象データ以降の要素を前方にシフトすることで、配列の連続性を維持しています。

### データの永続化
ファイル入出力を用いて、プログラム終了後もデータが保持されるように実装しました。  
起動時には自動的にファイルからデータを読み込みます。

### 簡易的なクロスプラットフォーム対応
WindowsとLinuxの両方で画面クリアが行えるよう、条件コンパイルを利用しています。

---

## 実行環境
- OS: Windows / Linux / macOS
- コンパイラ: GCC 推奨

---

## コンパイルと実行方法

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
## 実行例
1. Add Student
2. Show Students
3. Search Student
4. Delete Student
5. Save to File
6. Clear the Screen
0. Exit
