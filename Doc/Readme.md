## 环境说明

windows MSVC环境：
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
在
ctrl + f5 run
f5 debug

