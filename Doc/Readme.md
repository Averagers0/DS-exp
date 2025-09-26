# 环境说明

## MinGW环境
### step1
确认MinGW在环境变量里面

### step2
在本项目的DataStructure下创建一个DS-build文件夹

在本项目的experiment目录下创建一个exp-build文件夹

在本项目根目录下
创建一个.vscode的文件夹
然后新建两个文件


1.tasks.json
```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build DataStructure",
            "type": "shell",
            "command": "g++",
            "args": [
                "-std=c++17",
                "-g",
                "${workspaceFolder}/DataStructure/src/*.cpp",
                "${file}",
                "-I${workspaceFolder}/DataStructure/include",
                "-o",
                "${workspaceFolder}/DataStructure/DS-build/${fileBasenameNoExtension}.exe"
            ],
            "group": "build",
            "problemMatcher": [
                "$gcc"
            ],
            "detail": "编译 DataStructure 项目"
        },
        {
            "label": "build exp",
            "type": "shell",
            "command": "g++",
            "args": [
                "-std=c++17",
                "-g",
                "${file}",
                "-I${workspaceFolder}/experiment/include",
                "-o",
                "${workspaceFolder}/experiment/exp-build/${fileBasenameNoExtension}.exe"
            ],
            "group": "build",
            "problemMatcher": [
                "$gcc"
            ],
            "detail": "编译 experiment 项目"
        }
    ]
}

```

2.launch.json
```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "调试 DataStructure 示例",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/DataStructure/DS-build/${fileBasenameNoExtension}.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}/DataStructure",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "preLaunchTask": "build DataStructure"
        },
        {
            "name": "调试 exp",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/experiment/exp-build/${fileBasenameNoExtension}.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}/experiment",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "preLaunchTask": "build exp"
        }
    ]
}
```

### step3
- 点击example里面的某个cpp文件
- 右上角运行按钮
- 选择我们定义的任务
  - experiment文件的cpp就是build exp

  - DataStructure文件下的就是build DataStructure

## windows MSVC环境（目前不对，先别配置）：
### step1
确认MSVC在环境变量里面

### step2
在本项目根目录下
创建一个.vscode的文件夹
然后新建两个文件

1.tasks.json
```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "编译整个项目1",
            "type": "shell",
            "command": "cl",
            "args": [
                "/EHsc",
                "/Zi",
                "/Fe:${workspaceFolder}\\msvc_build\\${fileBasenameNoExtension}.exe",

                // 当前文件
                "${file}",

                // DataStructure 下的所有 cpp
                "${workspaceFolder}\\DataStructure\\src\\*.cpp",

                // experiment 下的所有 cpp
                "${workspaceFolder}\\experiment\\src\\*.cpp",

                // 包含头文件的目录
                "/I",
                "${workspaceFolder}\\DataStructure\\include",
                "/I",
                "${workspaceFolder}\\experiment\\include"
            ],
            "options": {
                "shell": {
                    "executable": "cmd.exe",
                    "args": ["/c"]
                }
            },
            "problemMatcher": ["$msCompile"],
            "group": { "kind": "build", "isDefault": true }
        }
    ]
}

```

2.launch.json
```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "运行当前 example (Windows)",
            "type": "cppvsdbg",
            "request": "launch",
            "program": "${workspaceFolder}\\msvc_build\\${fileBasenameNoExtension}.exe",
            "args": [],
            "cwd": "${workspaceFolder}",
            "stopAtEntry": false,
            "preLaunchTask": "编译整个项目1"
        }
    ]
}
```

### step 3
运行，选择对应的项目

