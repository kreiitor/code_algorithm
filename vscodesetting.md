# VSCode C++ 算法开发环境配置指南

> 本指南介绍如何配置 VSCode 使 C++ 程序像 OJ 系统一样一次性读取完整输入，避免逐行交互式输入的麻烦。

## 目录结构
```
CODE_ALGORITHM/
├── input.txt           # 全局测试用例
├── bin/                # 编译输出目录
├── .vscode/
│   └── settings.json   # 关键配置文件
├── hdoj2000-2020/      # 题目分类文件夹
│   └── 2001.cpp
└── hdoj2021-2040/
    └── 2029.cpp        # 你的代码文件
```

## 配置要求

1. **必需扩展**：
   - [Code Runner](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner)
   - [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)

2. **环境要求**：
   - Windows: 安装 MinGW 或 MSYS2
   - 在系统 PATH 中配置好 `g++` 命令

## 配置步骤

### 1. 创建工作区设置

在项目根目录创建 `.vscode/settings.json` 文件，添加以下配置：

```json
{
    "code-runner.runInTerminal": true,
    "code-runner.clearPreviousOutput": true,
    "code-runner.preserveFocus": true,
    "code-runner.fileDirectoryAsCwd": true,
    "code-runner.executorMap": {
        "cpp": "cd $dir ; if (!(Test-Path \"$workspaceRoot\\bin\")) { New-Item -Path \"$workspaceRoot\" -Name \"bin\" -ItemType Directory | Out-Null } ; g++ -std=c++17 \"$fileName\" -o \"$workspaceRoot\\bin\\$fileNameWithoutExt.exe\" ; $inputFile = if (Test-Path \"$dir\\input.txt\") { \"$dir\\input.txt\" } elseif (Test-Path \"$workspaceRoot\\input.txt\") { \"$workspaceRoot\\input.txt\" } else { $null }; if ($inputFile) { Get-Content $inputFile | & \"$workspaceRoot\\bin\\$fileNameWithoutExt.exe\" } else { Write-Host 'No input.txt found. Create in current folder or root:'; & \"$workspaceRoot\\bin\\$fileNameWithoutExt.exe\" }"
    }
}
```

### 2. 配置说明

| 配置项 | 作用 |
|--------|------|
| `runInTerminal: true` | 在终端中运行程序，保持输出可见 |
| `clearPreviousOutput: true` | 每次运行前清空之前的输出 |
| `fileDirectoryAsCwd: true` | 将文件所在目录设为工作目录 |
| **智能输入查找** | 优先级：<br>1. 当前文件夹的 `input.txt`<br>2. 项目根目录的 `input.txt`<br>3. 无文件时提示手动输入 |

## 使用方法

### 1. 创建输入文件

在项目根目录创建 `input.txt`（全局测试用例）：
```
4
level
abcde
noon
haha
```

或者在特定题目文件夹创建 `input.txt`（覆盖全局设置）：
```
3
madam
apple
racecar
```

### 2. 运行代码

- **快捷键**：`Ctrl+Alt+N`
- **右键菜单**：在编辑器中右键选择 "Run Code"

### 3. 预期输出
```
yes
no
yes
no
```

## 推荐代码模板

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    string dummy;
    getline(cin, dummy); // 消耗换行符
    
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        
        int l = 0, r = line.length() - 1;
        bool is_palindrome = true;
        
        while (l < r) {
            if (line[l] != line[r]) {
                is_palindrome = false;
                break;
            }
            l++;
            r--;
        }
        
        cout << (is_palindrome ? "yes" : "no") << endl;
    }
    
    return 0;
}
```

## 常见问题解决

### 问题1：找不到 input.txt
- **现象**：程序提示 "No input.txt found..."
- **解决**：
  1. 检查文件名是否正确（必须是 `input.txt`，不是 `input.TXT` 或 `inputs.txt`）
  2. 检查文件位置：
     - 优先放在当前代码文件的同目录
     - 其次放在项目根目录

### 问题2：编译错误
- **现象**：终端显示编译错误
- **解决**：
  1. 检查代码语法
  2. 确认已安装 C++ 编译器
  3. 在终端运行 `g++ --version` 验证环境

### 问题3：程序卡住无响应
- **现象**：程序运行后不结束
- **解决**：
  1. 检查代码是否有死循环
  2. 确认输入数据格式正确
  3. 按 `Ctrl+C` 终止程序

## 高级技巧

### 1. 多组测试用例
创建多个输入文件，手动重命名：
```
input-1.txt  # 测试用例1
input-2.txt  # 测试用例2
input.txt    # 当前使用的测试用例
```

### 2. 快速切换输入
在代码开头添加注释，记录常用测试用例：
```cpp
/*
测试用例1:
3
hello
world
test

测试用例2:
5
a
aa
aaa
aaaa
aaaaa
*/
```

### 3. 清理编译文件
在项目根目录创建 `clean.bat`：
```bat
@echo off
del /s /q bin\*.exe > nul 2>&1
echo Cleaned all executable files.
```

## 备份配置

> **重要**：定期备份 `.vscode/settings.json` 文件，避免重新配置的麻烦。

```json
// 备份配置 (简化版)
{
    "code-runner.executorMap": {
        "cpp": "cd $dir && g++ -std=c++17 $fileName -o $fileNameWithoutExt.exe && (if exist input.txt (type input.txt | $fileNameWithoutExt.exe) else $fileNameWithoutExt.exe)"
    }
}
```

---

**最后更新**：{{ current_date }}  
**配置验证环境**：VSCode 1.85.1, Code Runner v0.12.0, Windows 11