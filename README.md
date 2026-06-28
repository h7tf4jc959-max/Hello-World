# Copilot Memories

此仓库用于同步 VS Code Copilot Chat 的记忆文件（/memories/）。

## 使用方法

### 在本机推送记忆文件
```powershell
# 克隆到本地
cd $env:APPDATA\Code\User\globalStorage\github.copilot-chat\memory-tool

# 初始化为 git 仓库（如果尚未初始化）
git init
git remote add origin https://github.com/h7tf4jc959-max/Hello-World.git

# 添加并推送
git add memories/
git commit -m "更新记忆文件"
git push origin master
```

### 在另一台电脑拉取
```powershell
cd $env:APPDATA\Code\User\globalStorage\github.copilot-chat\memory-tool

# 如果已有记忆文件先备份，然后删除原目录
Remove-Item memories -Recurse -Force

# 克隆 memories 目录
git clone https://github.com/h7tf4jc959-max/Hello-World.git temp
Move-Item temp\memories\* memories\
Remove-Item temp -Recurse -Force
```
